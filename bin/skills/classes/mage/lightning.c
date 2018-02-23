/* lightning bolt */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status lightning(mixed targ, mixed alt_type, string class) {
  int dam;

  if(!targ || !(targ == "bolt" || sscanf(targ,"bolt %s", targ))) {
    notify_fail("lightning bolt?\n");
    return 0;
  }
  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(4) + 1);
  if(dam > 35) dam = 35;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Lightning Bolt",
  "sphere",            alt_type, 
  "cost",              10,
  "damage",            dam,
  "immune",            "lightning",
  "level",             9,
  "class", class,
  "cast time",         2,
  "area",
  "casting msg",      "You are blinded as lightning leaps from your hands..\n",
  "casting msg room", "You are blinded as lightning leaps from "+NAME+
                      "'s hands...\n",

  "msg target",       "Your hair crackles as the lightning hits you.\n",
  "msg room",         TARG +" is hit by lightning, and glows!\n",
  "msg caster",       "Flames shoot from your fingers burning "+ TARG +".\n",
  }));
  return 1;
}

