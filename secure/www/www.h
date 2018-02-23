
#include <httpd.h>

#define TZSECS (-60*60)

string gmtime()
{
  string ctim;
  string gmtim;
  string zero;

  ctim = ctime();
  gmtim = ctim[0..2];
  return gmtim + ", "+to_string(ctim[8..9])+" "+ctim[4..6]+" 20"+ctim[22..23]+" "+
    ctim[11..18]+" GMT";
}

string header(string html, string file) {
  string header;
  header = sprintf("HTTP/1.0 302 Found \n"
           "Date: %s \n"
           "Server: %s %s \n"
//           "Location: %s \n"
           "Content-type: text/html \n"
           "Content-length: %d \n\n\n", 
	   gmtime(),
           MUDNAME, LIBVERSION,
//	   sprintf("http://%s:%d/%O", MUDHOME, WWWPORT, file),
           strlen(html));

  return header+html;
}

