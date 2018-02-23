/* Ice Storm */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status ice(string targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(!targ || !(targ == "storm" || sscanf(targ,"storm %s",targ))) {
    notify_fail("ice storm?\n");
    return 0;
  }

  if(!alt_type) alt_type = "evocation";
  if(!class) class = "mage";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(7) + 1);
  if(dam > 60) dam = 60;  

  file = file_name(this_object());
  sscanf(file,"%s#%d", file, i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Ice Storm",
  "sphere",            alt_type, 
  "cost",              15,
  "damage",            dam,
  "immune",            "cold",
  "level",             17,
  "cast time",         2,
  "area",
  "casting msg",       "A chilling wind starts to blow around you...\n",
  "casting msg room",  "A chilling wind starts to blow around "+NAME+"...\n",
  "class",             class,
  "msg target",       "You are hit by bolder sized chunks if ice!\n",
  "spell object",      file,
/*  other spell options...
  "msg room",         0,
  "msg caster",       0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}


/*************************************************************************/
/* when cloned to player */

status cast_spell(object caster,object target,object prev,int dam) {
  destruct(this_object());
  return (caster == target) ? 1 : 0; /* don't hit caster */
}

    

