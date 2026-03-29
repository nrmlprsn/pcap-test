#include <stdint.h>

typedef struct{
	uint8_t dst[6];
	uint8_t src[6];
	uint16_t type;
}eth_hdr;

typedef struct{
	uint8_t v_ihl;
	uint8_t a[8];
	uint8_t protocol;
	uint16_t csum;
	uint32_t src;
	uint32_t dst;
}ipv4_hdr;

typedef struct{
	uint16_t src;
	uint16_t dst;
	uint32_t seq;
	uint32_t ack;
	uint8_t off_res;
}tcp_hdr;
