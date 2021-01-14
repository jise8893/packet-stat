#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include "pcap.h"
#include <iostream>
#include "stdafx.h"

int main(int argc,char* argv[])
{
	pcap_t* handle;
	const u_char* packet;
	char* pcapfile = argv[1];
	char errbuf[PCAP_ERRBUF_SIZE];
	
	if (argc != 2)
	{
		usage(); 
		return -1;
	}


	handle = pcap_open_offline(pcapfile,errbuf);
	if (handle == NULL)
	{
		fprintf(stderr, "pcap 파일을 찾을 수 없습니다.\n%s",errbuf);
		return -1;
	}


		struct pcap_pkthdr* header;

		while (true) {
			EthIpPacket* ethippacket;
			int res = pcap_next_ex(handle, &header, &packet);
			if (res==0||res == -1 || res == -2)
			{
				break;
			}
			
			printf("Catched packet length [%d]\n", header->caplen);
			
			ethippacket = (EthIpPacket*)(packet);
		
		
			insertsourcevalue(ethippacket, header->caplen);
			insertdestvalue(ethippacket, header->caplen);
			
			std::cout << std::endl;
			
		
		}
		for (auto k : ipv4_key) {
			 hextoipaddr(k.first);
			 printf("tx:%d rx:%d tx bytes:%d rx bytes:%d\n", std::get<0>(k.second), std::get<1>(k.second), std::get<2>(k.second), std::get<3>(k.second));
		}
		
	
}

