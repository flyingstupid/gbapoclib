/*
 * $Author: phaedrus $
 * $Revision: 1.1 $
 * $Date: 2003/11/21 22:08:30 $
 *
 * Purpose:
 *
 *
 */

#pragma strict_types
#pragma no_clone
#pragma no_inherit

#include "/include/config.h"
#include "/include/mudlib.h"

#include "/secure/simul/add_ansi.c"
#include "/secure/simul/compat.c"
#include "/secure/simul/add_worth.c"
#include "/secure/simul/base_file.c"
#include "/secure/simul/create_wizard.c"
#include "/secure/simul/log_file.c"
#include "/secure/simul/living_handlers.c"
#include "/secure/simul/living.c"
#include "/secure/simul/rooms.c"
#include "/secure/simul/rtime.c"
#include "/secure/simul/snoop.c"
#include "/secure/simul/subst.c"
#include "/secure/simul/type_handlers.c"
#include "/secure/simul/strings.c"
#include "/secure/simul/objects.c"
#include "/include/fn/shout.h"
void shout(string str) {
  check_shout(str,0);
}

/*
 * $Log: simul_efun.c,v $
 * Revision 1.1  2003/11/21 22:08:30  phaedrus
 * initial revision
 *
 * Revision 1.3  2003/11/01 21:22:18  phaedrus
 * most of the mudlib works with LDMud
 *
 * Revision 1.2  2003/10/26 16:39:33  phaedrus
 * removed simul unique_array and included shout()
 *
 * Revision 1.1  2003/10/26 04:54:11  phaedrus
 * Initial LDMud support
 *
 */
 
