/** Burning Hands **/


#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status burning(string targ, mixed alt_type, string class) {
  int dam;

  if(!targ || !(targ == "hands" || sscanf(targ,"hands %s",targ))) {
    notify_fail("burning hands?\n");
    return 0;
  }
  if(targ == "hands") targ = 0;
  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(2) + 1);
  if(dam > 15) dam = 15;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Burning Hands",
  "sphere",            alt_type, 
  "cost",              1,
  "damage",            dam,
  "immune",            "fire",
  "level",             2,
  "class", class,
  "cast time",         1,
  "msg target",       "Flames shoot from "+NAME+"'s fingers burning you.\n",
  "msg room",         "Flames shoot from "+NAME+"'s fingers burning "+
                      TARG +".\n",
  "msg caster",       "Flames shoot from your fingers burning "+ TARG +".\n",
  }));
  return 1;
}


