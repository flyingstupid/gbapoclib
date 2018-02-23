/*
 * $Author: phaedrus $
 * $Revision: 1.1 $
 * $Date: 2003/11/21 22:08:30 $
 * 
 * Purpose:
 * 
 */
 
#include <httpd.h>


object sock_ob;

static string parse_request(string file);
void listen_call(object sock_obj, int action, mixed extra1, mixed extra2, mixed extra3);
void callback(object connection, int act, mixed a, mixed b, mixed c);

void reset(int arg)
{
	if(arg) return;
    if(clonep(this_object())) return;
    sock_ob = (object) SOCKETD->New(TCP_LISTEN,0,WWWPORT,#'listen_call,SOCKET_ASCII);
    debug("httpd started.\n");
}


void listen_call(object sock_obj, int action, mixed extra1, mixed extra2, mixed extra3)
{
    debug(sprintf("listen_call(%O,%d,%O,%O,%O)\n",sock_obj,action,extra1,extra2,extra3));
    object new_connection;
    switch(action) {
    case SOCKET_READY:
	return;
    case SOCKET_ACCEPT:
	new_connection = sock_obj->Accept(#'callback);
	return;
    case SOCKET_ERROR:
	debug(sprintf("Primary httpd socket error: %s \n Description: %O \n Closing...\n",extra1,extra3));
	sock_obj->Close();
	return;
    case SOCKET_CLOSE:
	sock_obj->Close();
	return;
    }
}

void callback(object connection, int act, mixed a, mixed b, mixed c)
{
    debug(sprintf("callback(%O,%d,%O,%O,%O)\n",connection,act,a,b,c));
    switch(act) {
    case SOCKET_READY:
	debug("Ready for an httpd connection\n");
	return;
    case SOCKET_READ: {
	    string file, *tmp;
	    tmp=explode(a, "\r\n");
	    tmp=explode(tmp[0], " ");
	    if (tmp[0]!="GET") {
		connection->Close();
		return;
	    }
	    file=tmp[1];
	    a=parse_request(file);
	    connection->Write(a);
	    connection->Close();
	    return;
	}
    case SOCKET_ERROR: {
	    debug(sprintf("Connection socket error: %s\nDescription: %O\nClosing...\n",a,c));
	    connection->Close();
	}
    }
}

static string parse_request(string file)
{
    string data, tmp, *args;

    args=explode(file, "/")-({""});
    if (!sizeof(args)) return ERROR;
    
    printf("args: %O", args);

    file=sprintf("%s/%s.c", WWW_PATH, args[0]);

    if (file_size(file) > 0) {
	if (tmp=catch(data=call_other(file, "www_main", args[0..]))) {
	    return ERROR;
	}
	return data;
    }
    return ERROR;
}

void destructor()
{
    debug("Emergency Removal, closing main socket!!!\n");
    if(sock_ob->Close()) debug("Successful\n");
    else debug("unsuccessful\n");
}

/*
* $Log: http_d.c,v $
* Revision 1.1  2003/11/21 22:08:30  phaedrus
* initial revision
*
* Revision 1.2  2003/11/02 19:17:38  phaedrus
* removed sockets for now
*
* Revision 1.1  2003/10/26 04:54:12  phaedrus
* Initial LDMud support
*
* Revision 1.3  2003/10/14 20:46:27  phaedrus
* *** empty log message ***
*
*/
