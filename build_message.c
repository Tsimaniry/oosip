#include "build_message.h"

osip_message_t*  sip_register( const char * sip_username, short timeout, short wlocal_port, const char *local_ip, const char * proxy_ip, const char * from_tag, const char * via_branch, const char * call_id, int cseq) {

 	char local_port[10];
	sprintf(local_port,"%i",wlocal_port);
   	// Message URI
	osip_message_t *request;
	osip_message_init(&request);

	// FIXME -- Should use the "force_update" function.
	request->message_property = 2; // buffer is not synchronized with object
	request->sip_method = strdup("REGISTER");
    osip_message_set_version(request, strdup("SIP/2.0"));
   	osip_uri_init(&request->req_uri);
	osip_uri_set_host(request->req_uri, strdup(proxy_ip));


	// VIA
	osip_via_t * via;
	osip_via_init(&via);
	via_set_version(via, strdup("2.0"));
	via_set_protocol(via, strdup("UDP"));
	via_set_host(via, strdup(local_ip));
	via_set_port(via, strdup(local_port));

	// VIA BRANCH
	osip_via_set_branch(via, strdup(via_branch));

	// MAX FORWARDS
	osip_message_set_max_forwards(request, strdup("70"));

	char  * via_str;
	osip_via_to_str(via, &via_str);
	osip_message_set_via(request, via_str);
	//printf(" \n sip_message_request: %d", request->vias->nb_elt );

	// set via
	osip_list_add(request->vias, via, -1);


	// FROM
	osip_from_init(&request->from);
	osip_from_set_displayname(request->from, strdup(sip_username));

	// FROM TAG
	osip_from_set_tag(request->from, strdup(from_tag));
	osip_uri_init(&request->from->url);
	osip_uri_set_host(request->from->url, strdup(proxy_ip));
	osip_uri_set_username(request->from->url, strdup(sip_username));

	// TO
	osip_to_init(&request->to);
	osip_to_set_displayname(request->to, strdup(sip_username));
	osip_uri_init(&request->to->url);
	osip_uri_set_host(request->to->url, strdup(proxy_ip));
	osip_uri_set_username(request->to->url, strdup(sip_username));

	// CALL ID
	osip_call_id_init(&request->call_id);
	osip_call_id_set_host(request->call_id, strdup(local_ip));
	osip_call_id_set_number(request->call_id, strdup(call_id));

	// CSEQ
	osip_cseq_init(&request->cseq);
	osip_cseq_set_method(request->cseq, strdup("REGISTER"));
	char temp_buf[14];
	sprintf(temp_buf,"%i",cseq);
	osip_cseq_set_number(request->cseq, strdup(temp_buf));

	// CONTACT
	osip_contact_t * con;
	osip_to_init(&con);

	// CONTACT URI
	osip_uri_init(&con->url);
	osip_uri_set_host(con->url, strdup(local_ip));
	osip_uri_set_port(con->url, strdup(local_port));
	osip_uri_set_username(con->url, strdup(sip_username));
	char numbuf[10];
	sprintf(numbuf,"%d",timeout);
	osip_contact_param_add(con, strdup("expires"), strdup(numbuf) );

	// add contact
	osip_list_add(request->contacts, con, -1);

	printf(" \n Request address: %p", request);


	// If dont need authentication, return.


	return request;
}
