/** flamestrike **/


#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status flamestrike(string targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "combat_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(7) + 1);
  if( dam > 70) dam = 70;

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Flamestrike",
  "sphere",            alt_type, 
  "cost",              18,
  "damage",            dam,
  "immune",            "fire",
  "level",             18,
  "class", class,
  "cast time",         1,
  "msg target",       "Flames shoot from "+NAME+"'s fingers burning you.\n",
  "msg room",         "Flames shoot from "+NAME+"'s fingers burning "+
                      TARG +".\n",
  "msg caster",       "Flames shoot from your fingers burning "+ TARG +".\n",
  }));
  return 1;
}


