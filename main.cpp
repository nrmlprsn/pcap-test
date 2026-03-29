#include <pcap.h>
#include <stdbool.h>
#include <stdio.h>
#include "pprint.h"

void usage() {
        printf("syntax: pcap-test <interface>\n");
        printf("sample: pcap-test wlan0\n");
}

typedef struct {
        char* dev_;
} Param;

Param param = {
        .dev_ = NULL
};

bool parse(Param* param, int argc, char* argv[]) {
        if (argc != 2) {
                usage();
                return false;
        }
        param->dev_ = argv[1];
        return true;
}

int main(int argc, char* argv[]) {
        if (!parse(&param, argc, argv))
                return -1;

        char errbuf[PCAP_ERRBUF_SIZE];
        pcap_t* pcap = pcap_open_live(param.dev_, BUFSIZ, 1, 1000, errbuf);
        if (pcap == NULL) {
                fprintf(stderr, "pcap_open_live(%s) return null - %s\n", param.dev_, errbuf);
                return -1;
        }

        while (true) {
                struct pcap_pkthdr* header;
                const u_char* packet;
                int res = pcap_next_ex(pcap, &header, &packet);
                if (res == 0) continue;
                if (res == PCAP_ERROR || res == PCAP_ERROR_BREAK) {
                        printf("pcap_next_ex return %d(%s)\n", res, pcap_geterr(pcap));
                        break;
                }
                
		eth_hdr* eth = (eth_hdr*)packet;
		if(ntohs(eth->type) != 0x0800) continue;
		
		ipv4_hdr* ip = (ipv4_hdr*)(packet + sizeof(eth_hdr));
		uint8_t ihl = ((ip->v_ihl) & 0x0f) << 2;
		if(ip->protocol != 6) continue;

		tcp_hdr* tcp = (tcp_hdr*)((uint8_t*)ip + ihl);
		uint8_t thl = (((tcp->off_res) >> 4) & 0x0f) << 2;

		uint8_t* data = (uint8_t*)tcp + thl;
		uint16_t data_len = (ntohs(ip->len) > ihl + thl) ? ntohs(ip->len) - ihl - thl : 0;

		print_info(eth, ip, tcp, data, data_len);
        }

        pcap_close(pcap);
}
