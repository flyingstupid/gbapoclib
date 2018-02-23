/** Light, Serepion, Sept 1993 **/

/* update - dec 93 */
inherit "inherit/base/base_obj";
inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status lt(mixed targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()  /* wands */
       : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Light",
  "sphere",            alt_type, 
  "cost",              1,
  "damage",            time,
  "level",             1,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You start to form a glowing halo....\n",
  "casting msg room",  NAME+" starts to form a glow halo about "+
                       "@@query_objective:$this_player()$@@self.\n",
  "passive",
/* other spell options...
  "immune",            0,
  "area",
  "msg target",        0,
  "msg room",          0,
  "msg caster",        0,
  "component",         0,
 */
  }));
  return 1;
}


/************************************************************************/
/* when cloned to target */

status cast_spell(object caster,object target,object prev,int time) {
  object light;

  light = present("lightspell", target); /* id of this isn't set yet */
  if(light) {
    light->adj_time(time*30 + 60);
    light->adj_light(2);
    tell_object(caster,"You extend the power of your light spell.\n");
    destruct(this_object());
    return 1; /* do no damage */
  }
  set_name("lightspell");
  set_alt_name("spell");
  set_alias_name("aura");
  set_long("The aura gives of a soft blue glow, lighting your way.\n");
  set_alt_extra_long("A soft glowing aura surrounds you.\n");
  set_extra_long("A soft glowing aura surrounds "+
                 "@@query_name:$environment()$@@.\n");
  set_info("The soft aura was created by a light spell.\n"+
           "It has approximately @@query_approx_time:"+
            file_name(this_object())+"@@ before it expires.\n");
  adj_time(time*30 + 60);
  adj_light(2);
  return 1;
}

void time_out() {
  adj_light(-query_light_value());
  tell_object(environment(),"It gets a little darker...\n");
  ::time_out();
}

void dispel_magic() {  time_out(); } /* std spell clean up fn */

status drop(status quit) {
  if(quit) time_out();
  return 1;
}
  

