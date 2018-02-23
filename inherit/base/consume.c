#include <mudlib.h>
inherit BASE;

string consumer_msg;          /* message to consumer */
string room_msg;              /* message to room */
int strength;                 /* healing strength of consumable */

/* food, drinks cannot be put into bags */

status get() { return 1; }

prevent_insert() {
  write("You don't want to ruin "+(string)this_object()->short()+".\n");
  return 1;
}

                                        
status consume(string str) {
  this_player()->heal_self(strength);
  write(process_msg(consumer_msg));
  say(process_msg(room_msg));
  return 1;
}

/*********************************************************************/
/* sets */


int set_strength(int s)            { return strength = s; }

string set_room_msg(string em)     { return room_msg = em; }
string set_consumer_msg(string em) { return consumer_msg = em; }


/*********************************************************************/
/* query */

mapping query_specs() {
  return ([
	"strength" : strength,
	"room_msg" : room_msg,
	"consumer_msg" : consumer_msg,
  ]);
}


int query_strength()        { return strength; }

string query_room_msg()     { return room_msg; }
string query_consumer_msg() { return consumer_msg; }

