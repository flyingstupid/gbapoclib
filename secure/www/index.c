
#include "www.h"

string www_main(string *args)
{
    string html;

    html = "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML//EN\">\n"+
    "<HTML><HEAD><TITLE>Heaven7 Dynamic WWW Server (LPC)</TITLE></HEAD>\n"+
    "<BODY>\n"+
    "<H1 align=center>Under Construction</H1>\n"+
    "<HR>\n"+
    "<P>Put some text here!</P>\n"+
    "<HR>\n"+
    "</BODY></HTML>\n"+
    "\n"+
    "\n";

    return header(html, args[0]);
}
    
status clean_up(status arg) { destruct(this_object()); }

