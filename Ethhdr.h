#pragma once
#include "Mac.h"
#pragma pack(push,1)
class Ethhdr {
public:
	Mac dmac_;
	Mac smac_;
	uint16_t type_;
	Mac dmac() { return dmac_; }
	Mac smac() { return smac_; }

	uint16_t type() { return type_; }
	
	typedef enum {
		Ip4 = 0x0800,
		Arp = 0x0806,
		Ip6 = 0x86DD,

	}Type;

};
typedef Ethhdr *PEthhdr;
#pragma pack(pop)