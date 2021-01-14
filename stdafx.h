#pragma once
#include <WinSock2.h>
#include <map>
#include "EthIpPacket.h"
#include <tuple>
#pragma comment(lib,"ws2_32.lib")
std::map<class Ip, std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>> ipv4_key; //key == ip
std::map<std::pair<class Ip,class Mac>, std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>> ipv4_keys; //after report
void usage() {
	printf("syntax : packet-stat <pcap file> \n");
	printf("example: packet-stat test.pcap \n");
}
void hextoipaddr(uint32_t r) {
	unsigned char data[4];
	memcpy(data, &r, 4);
	for (int i = 0; i < 4; i++) {
		if (i != 3) {
			printf("%u.", data[i]);
		}
		else {
			printf("%u   ", data[i]);
		}
	}
	
}
//std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;//송신패킷수 ,수신 패킷수, 송신바이트,수신 바이트
void insertsourcevalue(EthIpPacket * ethippacket, uint8_t len) {
//find source ip
	auto ipv4_value = ipv4_key.find(ethippacket->ip_.ip_src);
	if (ipv4_value != ipv4_key.end())
	{
		std::get<0>(ipv4_value->second)++;
		std::get<2>(ipv4_value->second) += len;


	}else {
		
		std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> temp;
		temp = std::make_tuple(1, 0, len, 0);
		ipv4_key.insert(std::make_pair(ethippacket->ip_.ip_src,temp));

	}

}
void insertdestvalue(EthIpPacket* ethippacket,uint8_t len) {

	//find destination ip
	auto ipv4_value = ipv4_key.find(ethippacket->ip_.ip_dst);

	if (ipv4_value != ipv4_key.end())
	{
		
		std::get<1>(ipv4_value->second)++;
		std::get<3>(ipv4_value->second) += len;
		
	}
	else {
		
		std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> temp;
		temp = std::make_tuple(0, 1, 0, len);
		ipv4_key.insert(std::make_pair(ethippacket->ip_.ip_dst, temp));
	
	}
}