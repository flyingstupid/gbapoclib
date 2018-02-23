/* scryer object */

inherit "inherit/timer";
#include <process.h>

#define SCRY_NAME (string)scryed->query_name()

object scryer;
object scryed;
object scry_controller;

void reset(status arg) {
  if(arg) return;
  set_living_name("scry");
  enable_commands();
}

status query_npc() { return 1; }

status id(string str) {
  return str == "spell"
      || str == "scryer";
}


void scry(object who, object caster) {
  if(!(who || caster) || !objectp(who) || !objectp(caster)) {
    destruct(this_object());
    return;
  }
  scryed = who;
  scryer = caster;
  set_heart_beat(1);
}


void time_out() {
  if(scryer) {
    tell_object(scryer,"The scry spell dispels.\n");
  }
  if(scry_controller) destruct(scry_controller);
  ::time_out();
}


void dispel_magic() { time_out(); }


void heart_beat() {
  string room_long;

  if(!(scryed && scryer)) {
    time_out();
    return;
  }
  if(environment(scryed) != environment()) {
    move_object(this_object(), environment(scryed));
    room_long = process_msg((string)environment()->query_long());
    if(room_long == "") room_long = "Unknown Regions.\n";
    tell_object(scryer,
"####################################################################\n"+
"Scry "+ SCRY_NAME +" Moving->\n"+
room_long +"\n"+
"####################################################################\n");
  }
}


void catch_tell(string str) {
  if(!scryed || !scryer) {
    time_out();
    return;
  }
  if(environment(scryer) != environment(scryed)) {
    tell_object(scryer,
"####################################################################\n"+
"Scry "+ SCRY_NAME +"->\n"+
str +"\n"+
"####################################################################\n");

  }
}


status cast_spell(object caster,object target,object prev,int
level) {
  object ob;
  string who;

  if((ob = present("scry", caster))) {
    if(ob->query_scry()) {
      ob = (object)ob->query_scry();
      write("You extend the time of your scry spell.\n");
      ob->adj_time(level * 60);
      destruct(this_object());
      return 1;
    }
    else {
      destruct(ob);
    }
  }
  who = (string)caster->query_spell_argument();
  if(!(ob = find_living(who)) || ob->query_security_level()) {
    write("You cannot scry "+ capitalize(who) +".\n");
    destruct(this_object());
  }
  else if(ob->query_invis() || present("No Scry", ob)) {
    write("Something prevents you from scrying "+ capitalize(who)
+".\n");
    destruct(this_object());
  }
  else {
    scry_controller = clone_object("obj/skills/scry");
    scry_controller->set_scry(this_object());
    move_object(scry_controller, caster);
    scry(ob,caster);
    adj_time(level * 60);
  }
  return 1;
}

