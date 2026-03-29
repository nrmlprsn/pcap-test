#pragma once

#include <string>
#include "hdr.h"

string mac_format(uint8_t* mac);
string ipv4_format(uint32_t add);
void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp);
