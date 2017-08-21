
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char **argv)
{
    xmlDocPtr xml_doc_soap_request = xmlNewDoc(BAD_CAST "1.0");    
    xmlChar *s = NULL;
    int length;
	xmlNodePtr xml_node_soap_envelope = xmlNewNode(NULL, BAD_CAST "soapenv:Envelope");
	xmlNewProp(xml_node_soap_envelope, BAD_CAST "xmlns:soapenv", BAD_CAST "http://schemas.xmlsoap.org/soap/envelope/");
	xmlNewProp(xml_node_soap_envelope, BAD_CAST "xmlns:ser", BAD_CAST "urn:idm.openiam.org/srvc/am/service");
	xmlDocSetRootElement(xml_doc_soap_request, xml_node_soap_envelope);
	xmlNewChild(xml_node_soap_envelope, NULL, BAD_CAST "soapenv:Header", NULL);
	xmlNodePtr xml_node_soap_body = xmlNewChild(xml_node_soap_envelope, NULL, BAD_CAST "soapenv:Body", NULL);
	xmlNewChild(xml_node_soap_body, NULL, BAD_CAST "ser:federateProxyURI", NULL);

    xmlDocDumpFormatMemoryEnc(xml_doc_soap_request, &s, &length, "UTF-8", 0);
    
    xmlFreeDoc(xml_doc_soap_request);
    printf("%s", (char *)s);
    return 0;

}
