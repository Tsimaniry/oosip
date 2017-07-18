#include "build_message.h"

void application_build_register1(osip_message_t **sip_message)
{
   const char *sip_username="usernametest";
   short timeout = 30;
   short  wlocal_port = 5060;
   const char *local_ip = "192.168.255.1";
   const char *proxy_ip = "192.168.244.1";
   const char *from_tag = "35422341";
   const char *via_branch ="z9hG4bK767a1d12";
   const char *call_id = "1234987";
   int cseq =1;
   //osip_message_init(&sip_message);
   *sip_message=sip_register( sip_username,timeout,wlocal_port,local_ip,proxy_ip,from_tag,via_branch,call_id,cseq);
   printf(" \n Request address dans REG: %p", *sip_message);


}
