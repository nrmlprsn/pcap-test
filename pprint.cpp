#include "hdr.h"
#include "pprint.h"
#include <iostream>
using namespace std;

string mac_format(uint8_t* mac){
	return format("%02x:%02x:%02x:%02x:%02x:%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

string ipv4_format(uint32_t add){
	
}

void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp){

}

