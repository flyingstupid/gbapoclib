/** Phantom Armour **/

inherit "inherit/base/base_obj";
inherit "inherit/timer";

#define NAME  "@@query_name:$this_player()$@@"

int ac_bonus;

status phantom(string str, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!str || !(str == "armor" || str == "armour")) {
    write("phantom armour?\n");
    return 1;
  }
  if(!alt_type) alt_type = "illusion";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level() 
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Phantom Armour",
  "sphere",            alt_type, 
  "cost",              4,
  "damage",            time,
  "level",             4, /* 3 + 5 no component - 4 cast time */
  "cast time",         2,
  "class", class,
  "spell object",      file,
  "casting msg",      "A shimmering platemail starts to form about you.\n",
  "casting msg room", "A shimmering arua starts to surround "+ NAME +".\n",
  "passive",
/* other spell options... 
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int time) {
  object ob;

  ob = present("phantom armour 2", caster);
  if(ob) {
    write("You extend the time of your phantom armour spell.\n");
    ob->adj_time(time*60);
    destruct(this_object());
  }
  else {
    write("You find yourself wearing platemail.\n");
    say((string)caster->query_name() +" is now wearing platemail.\n");
    ac_bonus = (time+3)/4;
    if(ac_bonus > 4) ac_bonus = 4;
    caster->recalc_ac();
    set_name("platemail");
    set_short("Platemail (worn)");
    set_long("The platemail looks real, but has a translucent quality "+
             "about it. It glows with a soft light.\n");
    adj_light(1);
    set_info("The platemail is an illusion. Its magical dweomer causes\n"+
             "the attacker to miss more often. The dweomer has "+
             "@@query_approx_time:$this_object()$@@ left.\n");
  }
  return 1;
}

int armour_class_bonus() { return ac_bonus; }

void time_out() {
  ac_bonus = 0;
  environment()->recalc_ac();
  tell_object(environment(),"The platemail fades...\n");
  ::time_out();
}

void dispel_magic() { time_out(); }

status drop(status quit) {
  if(quit) time_out();
  return 1;
}
  
status id(string str) {
  return str == "spell"
      || str == "phantom armour"
      || str == "external"
      || ::id(str);
}

