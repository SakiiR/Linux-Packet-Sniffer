#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "resources.h"

static void     init(t_sniffer *sniffer, char *interface_name)
{
  sniffer->socket = -1;
  sniffer->addr_size = -1;
  sniffer->interface_name = interface_name;
  memset(&sniffer->addr, 0, sizeof(sniffer->addr));
}

int             main(int argc, char **argv)
{
  t_sniffer     sniffer;

  if (argc < 2)
  {
    printf("USAGE: %s INTERFACE_NAME\n", argv[0]);
    printf("Here is all availables network interfaces:\n");
    list_net_interfaces();
    return RETURN_FAILURE;
  }
  init(&sniffer, argv[1]);
  printf("[~] Let's listen on %s\n", sniffer.interface_name);
  if (setup_socket(&sniffer) == RETURN_FAILURE)
    return RETURN_FAILURE;
  printf("[~] Socket: %d\n", sniffer.socket);
  sniff_packets(&sniffer, 500);
  close(sniffer.socket);
  printf("[~] Closed socket\n");
  return RETURN_SUCCESS;
}
