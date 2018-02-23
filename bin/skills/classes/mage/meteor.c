	
/** METEOR SWARM **/

#define NAME  "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG  "@@query_name:$this_object()$@@"


status meteor(mixed targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(!targ || !(targ == "swarm" || sscanf(targ,"swarm %s",targ))) {
    notify_fail("meteor swarm?\n");
    return 0;
  }

  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(10) + 1);
  if(dam > 95) dam = 95;  

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Metoer Swarm",
  "sphere",            alt_type, 
  "cost",              27,
  "damage",            dam,
  "immune",            "fire",
  "level",             27,
  "class", class,
  "cast time",         2,
  "area",
  "spell object",      file,
  "casting msg",      "Fiery spheres fly from your hand...\n",
  "casting msg room", "Fiery spheres fly from "+ NAME +"'s hand...\n",
  "msg target",       "You are hit by a large fiery sphere!\n",
  "msg room",         TARG +" is hit by a large fiery sphere.\n",
  "msg caster",       "You hit "+ TARG +" with a fiery sphere.\n",
/* other spell options...
  "passive",
  "component",        0,
 */
  }));
  return 1;
}

/********************************************************************/
/* when cloned to target */

status cast_spell(object caster,object target,object prev,int dmg) {

  if((string)caster->query_party() &&
     (string)caster->query_party() == (string)target->query_party()) {
    destruct(this_object());
    return 1;
  }
  destruct(this_object());
  return (caster == target) ? 1 : 0; /* no hit to caster */
}

