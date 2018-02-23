/*****************************************************************/
/*** /obj/soul.c   --    The Player Soul    --    Heaven7      ***/
/***                                                           ***/
/*** New Implementation (with adverbs) by Mumbles, August 1993 ***/
/***                                                           ***/
/*** Previous Updates:                                         ***/
/***         Far-call Implementation by Zilanthius, Dec. 1992  ***/
/***         Modified for genders: padrone, Oct 22 1990        ***/
/***                                                           ***/
/*****************************************************************/
#include <mudlib.h>

#define SOUL_FN "/obj/soul_fcn"

status loaded;

id(str) { return str == "soul";}
string query_name() { return "soul"; }
drop()  { return 1; }
get()   { return 1; }


void reset(int arg) {
   if(arg) return;
   loaded = 0;
}

init() {
   add_action("soul_command", "", 1);
}

soul_command(str) {
   string verb, cap_name;
   object soul_daemon;
   
   verb = query_verb();
   if (!verb)
	return (0);
   if (!(soul_daemon = find_object(SOUL_FN)))
		return (0);
   if (function_exists(verb, soul_daemon)) {
      if (this_player()->query_ghost()) {
         notify_fail("That is impossible in your immaterial state.\n");
         return 0;
       }
      cap_name = this_player()->query_name();
      call_other(soul_daemon, "soul_command", verb, str, cap_name);
      return 1;
   }
   return 0;
}

status query_domain_safe() { return 1; }
