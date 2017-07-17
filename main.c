#include <winsock2.h>
#include <osip2/osip.h>
#include <osipparser2/osip_list.h>
#include <osipparser2/osip_uri.h>
#include "build_register.h"


int main (int argc, char **argv)
{
  int i, j;
	osip_t *osip;
	i=osip_init(&osip);
    if (i!=0)
	return -1;
	j=sizeof(osip);

	printf(" address osip %p", osip );
	osip_transaction_t *transaction;
	//transaction = malloc(10*sizeof(osip_transaction_t));
    osip_message_t **sip_register_message= {0};
    // sip_register_message = osip_malloc (5*sizeof (osip_message_t));

	//sip_register_message = (osip_message_t*) malloc(sizeof(osip_message_t));
    sip_register_message = malloc(sizeof(osip_message_t));
	osip_event_t       *sipevent;
	printf(" \n adresse sip_register_message %d", sip_register_message );
	application_build_register(sip_register_message);

    printf(" \n sip_register_message: %s", (*sip_register_message)->sip_method );
    printf(" \n VERSION: %s", (*sip_register_message)->sip_version );
    printf(" \n URI_SCHEME: %s", (*sip_register_message)->req_uri->scheme );
    printf(" \n URI_user: %s", (*sip_register_message)->req_uri->username );
    printf(" \n URI_pass: %s", (*sip_register_message)->req_uri->password );
    printf(" \n status_code: %d", (*sip_register_message)->status_code);
    printf(" \n reason_phrase is : %s", (*sip_register_message)->reason_phrase);

    free(sip_register_message);
    //osip_transaction_init(&transaction, NICT, osip, sip_register_message);
    //sipevent = osip_new_outgoing_sipmessage (sip_register_message);
    //sipevent->transactionid =  transaction->transactionid;
    //osip_transaction_add_event (transaction, sipevent);




	//osip_transaction_init(&transaction, NICT, osip, sip_register_message);

}
