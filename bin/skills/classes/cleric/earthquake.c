/* Earthquake */
 
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

 
status earthquake(string targ, mixed alt_type, string class){
  int dam, i;
  string file;
 
  if(!alt_type) alt_type = "nature_sphere";
  if(!class) class = "cleric";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()     /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
 
  dam *= (random(10) + 1);
  if(dam > 100) dam = 100;
  
  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
 
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Earthquake",
  "sphere",            alt_type, 
  "cost",              20,
  "level",             20,
  "class",             class,
  "damage",            dam,
  "cast time",         4,
  "area",
  "casting msg",      ({
     "The ground around you shakes.\n",
     "The ground around you trembles with the might of the Gods.\n",
     "The whole area around you shakes and trembles.\n"
  }),
  "casting msg room", ({
     "The ground around "+NAME+" shakes.\n",
     "The ground around "+NAME+" trembles with the might of the Gods.\n",
     "The whole area around "+NAME+" shakes and trembles.\n"
  }),
  "msg target",  "You are knocked to the quaking ground.\n",
  "msg room",    "You see "+ TARG +" fall to the quaking ground.\n",
  "msg caster",  "You see "+ TARG +" fall to the quaking ground.\n",
  "spell object", file,
  }));
  return 1;
}
 
/********************************************************************/
/* when cloned to target */
 
status cast_spell(object caster,object target,object prev,int dmg) {
  if(target == caster || (caster->query_party()
  && (string)caster->query_party() == (string)target->query_party())) { 
    destruct(this_object());
    return 1;
  }
  destruct(this_object());
  return 0;
}

