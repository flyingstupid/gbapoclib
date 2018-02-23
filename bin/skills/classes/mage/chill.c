/*** Chill Touch, Drakken Jan 1994 ***/
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"
 
status chill(string target, mixed alt_type, string class) {
  int dam;
  
  if(!target || !(target == "touch" || sscanf(target,"touch %s",target))) {
    notify_fail("chill touch?\n");
    return 0;
  } 
  if(target == "touch") target = 0;
  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(4) + 1);
  if(dam > 40) dam = 40;
 
  this_player()->load_spell(({
  "target",            target,
  "name",              "Chill Touch",
  "sphere",            alt_type, 
  "cost",              5,
  "damage",            dam,
  "level",             5,
  "class", class,
  "cast time",         2,
  "casting msg",       ({
                        "Your hand is encompassed with a blue glowing aura.\n",
                       }),
  "casting msg room",  ({ 
                         NAME +"'s hand is encompassed with a blue "+
                         "glowing aura.\n",
                       }),
  "msg caster",        TARG +" jumps backward as you touch him with "+
                       "your glowing hand.\n",
  "msg target",        "Your skin starts to turn freezing cold...\n",
  "msg room",          TARG +" shrieks in pain.\n"
  }));
  return 1;
}

