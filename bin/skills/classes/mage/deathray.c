/* Pointer's Deathray 
 * A player submitted spell.
 * (c) Pointer.May 1998 rtcpa@bellsouth.net 
 */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status deathray(mixed targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  dam *= random(8);
  if(dam > 80) dam = 80;

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Pointer's Deathray",
  "sphere",            alt_type, 
  "cost",              20,
  "damage",            dam,
  "immune",            "draining",
  "level",             20,
  "class", 	       class,
  "cast time",         1,
  "msg target",       "Your soul shivers as the "+NAME+"'s black energy bolt"+
                      "shoots through your body\n",
  "msg room",         ""+NAME+" launches a black bolt of negative energy at "+TARG+"!\n",
  "msg caster",       "You send "+TARG+" back ten feet with your black bolt "+
                      "of negative energy.\n",

/* other spell options...
  "area",
  "spell object",     0,
  "casting msg",      0,
  "casting msg room", 0,
  "passive",
  "component",        0,        
 */

  }));

  return 1;
}
