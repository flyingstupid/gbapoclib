/* Deep pocket; by Serepion */

/* update - dec 93 */

#include <mudlib.h>
inherit CONTAINER;
inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status deep(string str, mixed alt_type) {
  int i;
  string file;
  int sp_pts, time;

  if(!str || !(str == "pocket" || sscanf(str,"pocket %s",str))) {
    notify_fail("deep pocket?\n");
    return 0;
  }
  if(str == "pocket") str = 0;
  if(!alt_type) alt_type = "alteration";
  sp_pts = (objectp(alt_type))
         ? (int)alt_type->query_charges() /* wand */
         : (int)call_other(this_player(),"query_"+alt_type+"_points");
  if(sp_pts < 5) {
     write("You feel too weak to cast that spell...\n"); 
     return 1; 
  } 
  if(str) sscanf(str,"%d", time);
  if(!time || time > sp_pts) time = sp_pts;

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Deep Pocket",
  "sphere",            alt_type, 
  "cost",              time,
  "damage",            time, /* no dmg, use as time */ 
  "level",             5,
  "cast time",         1,
  "spell object",      file,
  "msg room",          NAME+" casts a spell, you don't see any effect.\n",
  "passive",
/* other spell options...
  "immune",            0,
  "area",
  "casting msg",       0,
  "casting msg room",  0,
  "msg target",        0,
  "msg caster",        0,
  "component",         0,
 */
  }));
  return 1;
}


/************************************************************************/
/* when cloned */

status cast_spell(object caster,object target,object prev, int dmg) {
  mixed *spell;
  object pocket;
  int max_weight; 
  
  pocket = present("pocket 2", target);
  if(pocket) {
    pocket->adj_time(dmg * 120);
    write("You extend your deeppocket spell time.\n");
    destruct(this_object());
    return 1;
  }
  set_extra_long((string)target->query_name()+
                  " has a small bulging pocket.\n");
  set_alt_extra_long("You have a small bulging pocket.\n");
  set_long("Hmmm, it looks bigger on the inside then the outside.\n");
  set_extra_info("It is a magically enchanted pocket. Its dweomer indicates\n"+
                 "that it will disappear shortly.\n");
  set_info("This was created by a deep pocket spell. It only has\n"+
           "@@query_approx_time:"+file_name(this_object())+"@@ left "+
           "before it disappears.\n");
  set_max_weight(dmg);
  adj_time(dmg * 120);
  write("You conjure a magical pocket...\n"); 
  return 1;
} 

status id(string str) { return (str == "spell"
                             || str == "deeppocket"
                             || str == "pocket"); }


void time_out() {
  object *inv, env;
  int i;
  
  if((env = environment())) {
    inv = all_inventory();
    for(i = 0; i < sizeof(inv); i++) move_object(inv[i],env);
    tell_object(env,"Your deep pocket disappears.\n");
    env->recalc_carry();
  } 
  ::time_out();
}

void dispel_magic() { time_out(); }

status drop(status quit) {
 if(quit) time_out();
 return 1;
}



string query_name() { return "deep pocket"; }
string short(status wiz) {
  if(this_player() == environment())
    return "a magical pocket";
  else
    return 0;
}
