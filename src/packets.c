#include <stdio.h>
#include <stdlib.h>
#include <linux/ip.h>
#include "resources.h"


static const t_packet_type             g_packet_types[] = {
  #include "protocols.c.inc"
};
void                            process_packet(void *packet)
{
    struct iphdr                *iph = (struct iphdr*)packet;
    unsigned int                i = 0;

    for (i = 0 ; g_packet_types[i].ptype != NULL ; ++i)
    {
      if (iph->protocol == g_packet_types[i].id)
      {
        printf("Found packet id %d '%s' '%s'\n",
               g_packet_types[i].id,
               g_packet_types[i].ptype,
               g_packet_types[i].pdesc);
        break;
      }
    }
}
