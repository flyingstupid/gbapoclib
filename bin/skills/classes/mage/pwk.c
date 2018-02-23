/* POWER WORD KILL. Orpheus, Oct 1993 */

/* update - dec 93 */

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status pwk(mixed targ, mixed alt_type, string class) {
  int i;
  string file;

  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            targ,
  "name",              "Power Word Kill",
  "sphere",            alt_type, 
  "cost",              30,
  "damage",            2000,
  "immune",            "death",
  "level",             30, /* instant kill spell */
  "class", class,
  "cast time",         1,
  "msg target",        "The word kills you.\n",
  "msg room",          TARG +" is slain with a word and a gesture...\n",
  "msg caster",        TARG +" is slain with a word and a gesture...\n",
  "spell object",      file,
/* other spell options...
  "area",
  "casting msg",       0,
  "casting msg room",  0,
  "passive",
  "component",         0,
 */
  }));
  return 1;
}


/****************************************************************/
/* when cloned to target */

status cast_spell(object caster,object target,object prev,int dmg) {
  if(((int)target->query_max_hp() > 750 && target->query_npc())
  || ((int)target->query_max_hp() > 130 && !target->query_npc())
  || !dmg) {
    tell_room(environment(target),"Nothing Happens....\n");
    destruct(this_object());
    return 1; /* do not do damage */
  }
  destruct(this_object());
  return 0; /* do damage */
} 

