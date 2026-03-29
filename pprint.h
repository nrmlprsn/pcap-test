#pragma once

#include "hdr.h"

void mac_format(eth_hdr* eth);
void ipv4_format(ipv4_hdr* ip);
void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp);
