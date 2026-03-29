#pragma once

#include <stdint.h>

typedef struct{
	uint8_t dMAC[6];
	uint8_t sMAC[6];
	uint16_t type;
}eth_hdr;

typedef struct{
	uint8_t v_ihl;
	uint8_t dscp;
	uint16_t len;
	uint32_t id_frag;
	uint8_t ttl;
	uint8_t protocol;
	uint16_t csum;
	uint32_t sIP;
	uint32_t dIP;
}ipv4_hdr;

typedef struct{
	uint16_t sport;
	uint16_t dport;
	uint32_t seq;
	uint32_t ack;
	uint8_t off_res;
}tcp_hdr;
