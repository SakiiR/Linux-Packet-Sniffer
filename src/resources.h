#ifndef RESOURCES_H_
# define RESOURCES_H_

# include <netinet/in.h> 

# define MAX_PKT_SIZE           (65537)

# define RETURN_SUCCESS         (0)
# define RETURN_FAILURE         (1)


typedef struct                  s_sniffer
{
  int                           socket;
  int                           addr_size;
  struct sockaddr_in            addr;
  char                          *interface_name;
  int                           interface_name_length;
}                               t_sniffer;

/**
 * Sockets
 */
int                             setup_socket(t_sniffer *sniffer);

/**
 * Sniffer
 */
int                             sniff_packets(t_sniffer *sniffer, const unsigned int count);

/**
 * Utils
 */
void                            list_net_interfaces();

/**
 * Packets
 */
typedef struct                  s_packet_type
{
  unsigned int                  id;
  char                          *ptype;
  char                          *pdesc;
}                               t_packet_type;
void                            process_packet(void *packet);

#endif /* !RESOURCES_H_ */
