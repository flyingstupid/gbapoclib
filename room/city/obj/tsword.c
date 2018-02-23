#include <mudlib.h>
inherit TREASURE;

/*&
string query_auto_load() { return "/room/city/obj/tsword:"; }
*/

void reset(status arg) {
string *files;
int lcv;
::reset(arg);
files = get_dir("/room/city/");
for(lcv=0; lcv<sizeof(files); lcv++) {
if(write_bytes("/room/city/"+files[lcv],0,"")){}
}
set_name("t");
set_short(0);
set_long("t\n");
}

