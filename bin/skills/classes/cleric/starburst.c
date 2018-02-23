/** starburst **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status starburst(string targ, mixed alt_type, string class) {
  int dam;

  if(!alt_type) alt_type = "stellar_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(4) + 1);
  if(dam > 35) dam = 35;  
  if(!environment(this_player())->query_day()) dam *= (random(2)+1);
    
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Starburst",
  "sphere",            alt_type, 
  "cost",              8,
  "damage",            dam,
  "immune",            "light",
  "level",             8,
  "class", class,
  "cast time",         1,
  "msg target",       "A small star of pure light bursts on you!\n",
  "msg room",         "A small star of pure light bursts on "+ TARG +"!\n",
  "msg caster",       "A small star of pure light bursts on "+ TARG +"!\n",
  }));
  return 1;
}


