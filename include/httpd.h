
#ifndef __httpd_H__
#define __httpd_H__

#include "config.h"
#include "socket.h"

#define WWWPORT	7005

#if 0
#define debug(x) printf("%O", x)
#else
#define debug(x)
#endif

#define WWW_PATH "secure/www"
#define MUDHOME       "heaven7mud.org"
#define MUDHOMEPAGE   "http://www."+MUDHOME
#define MUDFTP        "ftp://"+MUDHOME
#define MUDPICTURE    MUDHOMEPAGE+"/images/index_01_01.gif"
#define MUDPICS       MUDHOMEPAGE+"/images/"

#define ERROR "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\"> \n" \
              "<html><head><title>404 Not Found</title></head><body> \n" \
              "<h1>Not Found</h1>\n" \
              "The requested URL was not found on this server.<p> \n" \
              "<hr><address>"+MUDNAME+" "+LIBVERSION+" Web Server at " \
              MUDHOMEPAGE+"</address> \n" \
              "</body></html> \n"

#endif // __httpd_H__