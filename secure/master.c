/*
**  secure/master.c  
**
**  $Author: phaedrus $
**  $Revision: 1.1 $
**  $Date: 2003/11/21 22:08:30 $
**
** The master is the gateway between the gamedriver and the mudlib to perform
** actions with mudlib specific effects.
** Calls to the master by the gamedriver have an automatic catch() in effect.
**
**
*/
#define TRANSFER(a,b) funcall(symbol_function('transfer), a,b)
#define FILE_NAME(a)   funcall(symbol_function('file_name), a)

#include "/include/config.h"
#include "/include/mudlib.h"
#include "/include/cfg/levels.h"
#include "/include/cfg/master.cfg"

#include "/include/sys/wizlist.h"
#include "/include/sys/driver_hook.h"
#include "/include/sys/functionlist.h"
#include "/include/sys/erq.h"
#include "/include/sys/objectinfo.h"


static mixed current_time;		        // Saved start time of epilog,
private int time_of_last_error;                 // last error time
void save_wiz_file(); 			        // forward
int query_player_level (string what); 	        // forward
string normalize_path(string path, object obj); // forward

#include "/secure/master/connections.c"
#include "/secure/master/security.c"
#include "/secure/master/creators.c"
#include "/secure/master/ed_support.c"
#include "/secure/master/runtime.c"
#include "/secure/master/error_handling.c"
#include "/secure/master/hooks.c"
#include "/secure/master/initialisation.c"
#include "/secure/master/parse_command.c"
#include "/secure/master/permissions.c"























