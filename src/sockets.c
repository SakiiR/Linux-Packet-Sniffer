#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/if.h>
#include <string.h>
#include "resources.h"

int                             setup_socket(t_sniffer *sniffer)
{
  int                           r;

  if ((sniffer->socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1)
  {
    perror("socket");
    return RETURN_FAILURE;
  }
  if ((sniffer->interface_name_length = strnlen(sniffer->interface_name, IFNAMSIZ)) == IFNAMSIZ)
  {
    fprintf(stderr, "[-] Interface name '%s' too long !\n", sniffer->interface_name);
    return RETURN_FAILURE;
  }
  if ((r = setsockopt(sniffer->socket, SOL_SOCKET, SO_BINDTODEVICE, sniffer->interface_name, sniffer->interface_name_length)) == -1)
  {
    perror("setsockopt");
    close(sniffer->socket);
    return RETURN_FAILURE;
  }
  return RETURN_SUCCESS;
}
