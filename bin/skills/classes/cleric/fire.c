/** Fire Storm   **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status fire(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(targ != "storm") {
    notify_fail("fire storm?\n");
    return 0;
  }
  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(6) + 1);
  if(dam > 100) dam = 100;  

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Fire Storm",
  "sphere",            alt_type, 
  "cost",              18,
  "damage",            dam,
  "immune",            "fire",
  "level",             18,
  "class", class,
  "cast time",         3,
 "area",
  "casting msg", ({
    "The heavens overhead begin to roar...\n",
    "The ground beneath you begins to shake...\n",
    "The sky above you opens up and fire storms from the heavens!!\n",
   }),
  "casting msg room",  ({
    "The heavens overhead begin to roar...\n",
    "The ground beneath you begins to shake violently...\n",
    "The sky above you opens up and fire storms from the heavens!!\n",
   }),
  "msg target",        "Fire from the sky sears your skin.\n",
  "msg caster",        "You see the fire engulf "+ TARG +".\n",
  "spell object",      file,
  }));
  return 1;
}

      
status cast_spell(object caster,object target,object prev,int dmg) {
  destruct(this_object());
  return (caster == target) ? 1 : 0;
}

