#pragma once
#include "Ip.h"
#include <cstdint>
#ifndef IPHDR_H
#define IPHDR_H

#endif // IPHDR_H
#pragma pack(push,1)
class IpHdr final {
public :
	uint8_t ip_hl : 4, ip_v : 4;
	uint8_t tos;
	uint16_t ip_len;
    uint16_t ip_id;          
    uint16_t ip_off;

    uint8_t ip_ttl;        
    uint8_t ip_p;        
    uint16_t ip_sum;
    Ip ip_src;
    Ip ip_dst;
};
#pragma pack(pop)