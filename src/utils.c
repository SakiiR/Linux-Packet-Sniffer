#include <stdio.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include "resources.h"


void                    list_net_interfaces()
{
  struct ifaddrs        *addrs;
  struct ifaddrs        *tmp;

  getifaddrs(&addrs);
  tmp = addrs;
  while (tmp)
  {
    if (tmp->ifa_addr && tmp->ifa_addr->sa_family == AF_PACKET)
      printf("\t%s\n", tmp->ifa_name);
    tmp = tmp->ifa_next;
  }
  freeifaddrs(addrs);
}
