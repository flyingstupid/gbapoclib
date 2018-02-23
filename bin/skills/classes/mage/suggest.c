/** suggestion **/

#include <humanoid.h>

#define  NAME       "@@query_name:$this_player()$@@"
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status suggest(string targ, mixed alt_type, string class) {
  int level, i;
  string cmd, file;

  if(!targ || sscanf(targ,"%s %s",targ,cmd) != 2) {
    notify_fail("suggest who what?\n");
    return 0;
  }

  if(!alt_type) alt_type = "charm";
  if(!class) class = "mage";
  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);
 
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Suggest",
  "sphere",            alt_type,
  "cost",              10,
  "damage",            level,
  "immune",            "charm",
  "level",             10,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You start to feel commanding...\n",
  "casting msg room",  NAME +" starts to look very commanding.\n",
  "argument",          cmd,
  "passive",

/* other spell options... 
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
  "passive",
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int level) {
  string cmd;

#ifndef PLAYER_KILL
  if(!(caster->query_npc() || target->query_npc())) {
    write(target->query_name() +" gets upset with you!!\n");
    tell_object(target,caster->query_name() +" tried to suggest you.\n");
    destruct(this_object()); /* get rid of cloned object */
    return 1; 
  }
#endif

  if(humanoid(target) && !target->query_made_my_save()) {
    cmd = (string)caster->query_spell_argument();
    if(cmd && command(cmd, target)) {
      destruct(this_object());
      return 1;
    }
  }
  if(random(TARGET_WIS) < random(CASTER_CHR)) {
    write(target->query_name() +" does not take any notice of you.\n");
  }
  else {
    write(target->query_name() +" gets upset with you!!\n");
    target->add_secondary_attacker(caster);
  }
  destruct(this_object()); /* get rid of cloned object */
  return 1; /* do damage */
}

status id(string str) { return (str == "spell"); }

