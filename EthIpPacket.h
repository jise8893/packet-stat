#pragma once
#include "Ethhdr.h"
#include "Iphdr.h"
class EthIpPacket {
public:
	Ethhdr eth_;
	IpHdr ip_;
};