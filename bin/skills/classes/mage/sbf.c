/** Sin's Black Flames. Sin, Dec 1993 **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status sbf(mixed targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "necromancy";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(2) + 1);
  if(dam > 10) dam = 10;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Sin's Black Flame",
  "sphere",            alt_type, 
  "cost",              1,
  "damage",            dam,
  "immune",            "poison",
  "level",             1,
  "class", class,
  "cast time",         1,
  "msg target",       "You reel in horror as you feel the searing evil of "+
                      "the black eldritch flames cast by "+NAME+" penetrate "+
                      "deep into your chest.\n",
  "msg room",         "You watch in horror as black flames of elemental "+
                      "evil stream out from "+NAME+"'s fingers to strike "+
                      " "+TARG+".\n",
  "msg caster",       "Black eldritch flames stream from your fingers in a "+
                      "wave of undiluted evil towards your victim. \n",
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
