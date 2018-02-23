/** CONE OF COLD  **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status coc(mixed targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(5) + 1);
  if(dam > 40) dam = 40;  

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Cone of Cold",
  "sphere",            alt_type, 
  "cost",              10,
  "damage",            dam,
  "immune",            "cold",
  "level",             10,
  "class", class,
  "cast time",         1,
  "msg target",       "Ice flies from "+ NAME +"'s hands, smiting you, "+
                      "freezing you cold!\n",
  "msg room",         "Ice flies from "+ NAME +"'s hands, smiting "+ TARG +
                      ", freezing it cold!\n",
  "msg caster",       "Ice flies from your hands smiting "+ TARG +
                      ", freezing it cold.\n",
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

