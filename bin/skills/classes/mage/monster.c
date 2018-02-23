/** monster summon 1, 2, 3  **/

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status monster(string targ, mixed alt_type, string class) {
  int type, level, spell_level;

  if(!targ || sscanf(targ,"summon %d", type) != 1) {
    notify_fail("monster summon 1, monster summon 2, monster summon 3?\n");
    return 0;
  }

  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";
  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);

  switch(type) {
    case 1:
      spell_level = 11;
    break;

    case 2:
      spell_level = 16;
    break;

    case 3:
      spell_level = 22;
    break;

    default:
      notify_fail("monster summon 1, monster summon 2, monster summon 3?\n");
      return 0;
    break;
  }
      
  this_player()->load_spell(({
  "target",            environment(this_player()),
  "name",              "Monster Summon "+ type,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "class",             class,
  "damage",            level,
  "level",             spell_level,
  "cast time",         2,
  "casting msg",       "You send out a silent call...\n",
  "spell object",      "obj/skills/mon_sum"+ type,
  "passive",
  }));
  return 1;
}


