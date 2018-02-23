/** Beltyn's Burning Blood, by Orpheus, Nov 1993  **/

/* update - dec 93 */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status bb(string targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "destroying";
  if(!class) class = "techman";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
  if(dam > 60) dam = 60;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Boil Blood",
  "sphere",            alt_type, 
  "cost",              0,
  "damage",            dam,
  "immune",            "fire",
  "level",             10,
  "class", class,
  "cast time",         2,
  "casting msg",      "You start to feel power emanating from your gaze!\n",
  "casting msg room", "You feel the air crackle around "+NAME+".\n",
  "msg target",       "A glance and word from "+NAME+" and your blood boils.\n",
  "msg room",         NAME+" utters a word and gestures a hand and the "+
                      "veins in "+ TARG +" pulsate.\n",
  "msg caster",       "You speak a word and make a gesture and the blood "+
                      "of "+ TARG +" boils.\n",
/* other spell options...
  "area",
  "spell object",      0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}
