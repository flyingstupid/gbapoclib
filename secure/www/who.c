
#include "www.h"

string www_main(string *args)
{
    string data, info;
    info = "";
    foreach(object usr : users()) {
        info += "<P>";
	info += (string)(objectp(usr) ? capitalize(usr->query_account_name()) : "NONAME");
    }

    data=sprintf("<HTML><TITLE> %s Who List</TITLE>\n"
"<BODY>\n"
"<H1 align=center> %s Who List</H1>\n"
"\n"
"There are %d people currently logged in.\n"
"<HR>\n"
"%s\n"
"<HR>\n"
"</BODY></HTML>\n", MUDNAME, MUDNAME, sizeof(users()), info);

    return header(data, args[0]);	
}

status clean_up(status arg) { destruct(this_object()); }
