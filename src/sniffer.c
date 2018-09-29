#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include "resources.h"

int                     sniff_packets(t_sniffer *sniffer, const unsigned int count)
{
  char                  *buffer = NULL;
  ssize_t               nread = 0;
  unsigned int          i = 0;
  socklen_t             saddr_size;
  struct sockaddr       saddr;

  if ((buffer = malloc(sizeof(*buffer) * MAX_PKT_SIZE)) == NULL)
  {
    fprintf(stderr, "[-] malloc()\n");
    return RETURN_FAILURE;
  }
  for (i = 0 ; i < count ; ++i)
  {
    memset(buffer, 0, MAX_PKT_SIZE);
    saddr_size = sizeof(saddr);
    if ((nread = recvfrom(sniffer->socket,
                          buffer,
                          MAX_PKT_SIZE - 1,
                          0,
                          &saddr,
                          &saddr_size)) == -1)
    {
      perror("recvfrom");
      return RETURN_FAILURE;
    }
    process_packet((void *)buffer);
  }
  free(buffer);
  return RETURN_SUCCESS;
}
