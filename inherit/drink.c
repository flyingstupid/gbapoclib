#pragma strict_types
#pragma save_types
#pragma combine_strings
#include <mudlib.h>

inherit "inherit/base/consume";


string empty_container;  /* drink container name when empty */
status empty;            /* 1 == empty */
status soft;             /* 1 == soft drink */
status alco;             /* 1 == alco drink */
status pub;              /* 1 == a pub drink */


void init() {
  ::init();
  if(!empty_container) empty_container = "bottle";
  if(environment(this_object()) != this_player()) return;
  if(!empty) {
    add_action("drink", "drink");
    add_action("drink", "quaff");
  }
}

void reset(status arg) {
  if(arg) return;

  set_sell_destruct(1);
  set_weight(1);
  set_name("beer");
  set_short("A bottle of beer");
  set_long("A Bottle Of Home Brew Beer.\n");
  set_room_msg("You see @@query_name:$this_player()$@@ slam down a bottle"+
               " of @@query_possessive:$this_player()$@@ home brew beer.\n");
  set_consumer_msg("You slam down a bottle of home brew beer.\n"+
                   "The world spins a little as it quenches your thirst.\n");
  set_strength(3);
}
  
status prevent_insert() {
  if(empty_container) return 0;
  ::prevent_insert();
  return 1;
}

status id(string str) {
  return (!empty) ? ::id(str) : str == empty_container;
}


/* support parse_command */
string *parse_command_id_list() {
	return (!empty) ? ::parse_command_id_list() : 
	::parse_command_id_list() + ({ empty_container });
}


string short(status wiz) { 
  return (!empty) ? ::short(wiz) : "An empty " + empty_container;
}

void long(status wiz) {
  if(!empty) {
    ::long(wiz);            
  }
  else {
    write(short(wiz) + "\n");
  }
}


void extra_info(status wiz) { 
  ::extra_info(wiz);
  if(empty) {
   write("It looks like an empty "+empty_container+" of "+query_name()+".\n");
  }
}


status drink(string str) {
  object tp, ob;
     
  if(!this_object()->query_full()) {
    notify_fail("The "+query_name()+" is empty!\n");
    return 0;
  }
  if(!str) { 
    notify_fail("Drink what?\n");
    return 0;
  }
  tp = this_player();
  if(!(ob = present(str, tp))) {
    notify_fail("You don't have a "+ str +" to drink.\n");
    return 0;
  }
  if(ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if(tp->query_attack()) {
    write("You can't possibly drink and fight at the same time!\n");
    return 1;
  }
  if(((int)tp->query_constitution()*8) < strength) {
    tell_object(tp, "This is much to much for you to drink!\n"+
       "You drool most of it on the ground.\n");
    say(tp->query_name()+" tries to drink "+short(0)+ 
     " but drools most of it on the ground.\n");
    empty = 1;
    return 1;
  }
  if(soft) {
    if(!tp->drink_soft(strength)) return 1;
  }
  else {
    if(!tp->drink_alcohol(strength)) return 1; 
  }
  ::consume(lower_case(str));
  empty = 1;
  return 1;
}

/****************************************************************/
/* sets */


string set_empty_container(string ec) { return empty_container = ec; }
status set_full(status i)             { return empty = (i) ? 0 : 1; }
status set_pub_drink(status i)        { return pub = (i) ? 1 : 0;  }
status set_soft_drink(status i)       { return soft = (i) ? 1 : 0; }
status set_alco_drink(status i)       { return alco = (i) ? 1 : 0; }


/******************************************************************/
/* query */
status query_full()            { return !empty;     }
string query_empty_container() { return empty_container; }

mapping query_specs() {
  return ([
	"empty_container" 	: empty_container,
	"full" 			: query_full(),
	"pub_drink" 		: pub, 
	"soft_drink" 		: soft,
	"alco_drink" 		: alco,
	"strength" 		: strength, 
	"room_msg" 		: room_msg,
	"consumer_msg" 	: consumer_msg,
  ]);
} 

string query_object_type()     { return "Drink"; }
status query_pub_drink() {
  if(pub) {
    if(!empty) return 1;
  }
  else
    return 0;
}

status query_drink()           { return 1; }
status query_alco_drink()      { return (alco) ? 1 : 0; }
status query_soft_drink()      { return (soft) ? 1 : 0; }

int query_value() {
  return (!empty) ? (strength*4 + (strength*strength)/10) : 5+random(10);
}

