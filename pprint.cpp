#include "pprint.h"
#include <netinet/in.h>
#include <iostream>
#include <format>
#define endl "\n"
using namespace std;

string mac_format(uint8_t* mac){
	return format("{:02X}:{:02X}:{:02X}:{:02X}:{:02X}:{:02X}", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

string ipv4_format(uint32_t add){
	add = ntohl(add);
	return format("{}.{}.{}.{}", (add >> 24) & 0xFF, (add >> 16) & 0xFF, (add >> 8) & 0xFF, add & 0xFF);
}

void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp, uint8_t* data, uint16_t len){
	cout << "src MAC: " << mac_format(eth->sMAC) << endl;
	cout << "dst MAC: " << mac_format(eth->dMAC) << endl;
	cout << "src IP: " << ipv4_format(ip->sIP) << endl;
	cout << "dst IP: " << ipv4_format(ip->dIP) << endl;
	cout << "src port: " << dec << ntohs(tcp->sport) << endl;
	cout << "dst port: " << dec << ntohs(tcp->dport) << endl;
	cout << "Data: ";
	for(int i=0;i<len && i<20;i++) cout << hex << (int)data[i];
	cout << endl << endl;
}

