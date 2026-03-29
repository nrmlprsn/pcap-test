#include "hdr.h"
#include "pprint.h"
#include <iostream>
#define endl "\n"
using namespace std;

string mac_format(uint8_t* mac){
	return format("%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

string ipv4_format(uint32_t add){
	add = ntohl(add);
	return format("%u.%u.%u.%u", (add >> 24) & 0xFF, (add >> 16) & 0xFF, (add >> 8) & 0xFF, add & 0xFF);
}

void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp, uint8_t* data, uint16_t len){
	cout << "src MAC: " << mac_format(eth->src) << endl;
	cout << "dst MAC: " << mac_format(eth->dst) << endl;
	cout << "src IP: " << ipv4_format(ip->src) << endl;
	cout << "dst IP: " << ipv4_format(ip->dst) << endl;
	cout << "src port: " << ntohs(tcp->src) << endl;
	cout << "dst port: " << ntohs(tcp->dst) << endl;
	for(int i=0;i<len;i++) cout << data[i];
	cout << endl;
}

