#include <osip2/osip.h>
#include <osipparser2/osip_uri.h>
osip_message_t * sip_register( const char * sip_username, short timeout, short local_port, const char * local_ip,
const char * proxy_ip, const char * from_tag, const char * via_branch, const char * call_id, int cseq);
