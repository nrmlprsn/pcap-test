#pragma once

#include <string>
#include "hdr.h"

std::string mac_format(uint8_t* mac);
std::string ipv4_format(uint32_t add);
void print_info(eth_hdr* eth, ipv4_hdr* ip, tcp_hdr* tcp, uint8_t* data, uint16_t len);
