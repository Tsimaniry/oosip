#include "build_register.h"
#include "build_uri.h"
void application_build_register(osip_message_t **sip_message)
{
char *registerSip="REGISTER";
char *versionSip= "sip v2";
char *schemeSip= "sip:";
char *usernameSip= "usertest";
char *passworSip= "passwdtest";
char *reasonPhraseSip="tsimaniry";

*sip_message=malloc(sizeof(osip_message_t));

(*sip_message)->sip_method= registerSip;
(*sip_message)->sip_version= versionSip;
(*sip_message)->req_uri=malloc(sizeof(osip_uri_t));
(*sip_message)->req_uri->scheme= schemeSip;
(*sip_message)->req_uri->username= usernameSip;
(*sip_message)->req_uri->password= passworSip;
(*sip_message)->status_code=200;
(*sip_message)->reason_phrase=reasonPhraseSip;

//free (*sip_message);


}

