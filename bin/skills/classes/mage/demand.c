/** demand **/

#define  NAME       "@@query_name:$this_player()$@@"
#define  TARGET_WIS (int)target->query_wisdom()
#define  CASTER_CHR (int)caster->query_charisma()

status demand(string targ, mixed alt_type) {
  int level, i;
  string cmd, file;
  string tmp1, tmp2;

  if(!targ || sscanf(targ,"%s %s",targ,cmd) != 2) {
    notify_fail("demand who what?\n");
    return 0;
  }

  if(sscanf(targ, "%sleave%s", tmp1, tmp2) ||
     sscanf(targ, "%swithdraw%s", tmp1, tmp2) ||
     sscanf(targ, "%salias%s", tmp1, tmp2) ||
     sscanf(targ, "%skill%s",     tmp1, tmp2)) {
    notify_fail("You can't demand someone to 'leave' something.\n");
    return 0;
  }


  if(!alt_type) alt_type = "charm";
  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);
 
  this_player()->load_spell(({
  "target",            targ,
  "name",              "Demand",
  "sphere",            alt_type,
  "cost",              15,
  "damage",            level,
  "immune",            "charm",
  "level",             15,
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
  "component",        0,
 */
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int level) {
  string cmd;       
  string tempstr;

  if(caster->query_security_level() < target->query_security_level()) {
   write("You cannot demand people of such high statue.\n");
   return 1;
   }
  if((int)caster->query_spell_dmg() == level) {
    cmd = (string)caster->query_spell_argument();
    if(sscanf(cmd, "alias%s", tempstr) == 1
      || sscanf(cmd, "leave%s", tempstr) == 1
    || sscanf(cmd, "quit%s", tempstr) == 1
    || sscanf(cmd, "Quit%s", tempstr) == 1) {
      notify_fail("You can't demand a player to do that!\n");
      return 0;
    }
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
    target->hit_player(0);
  }
  destruct(this_object()); /* get rid of cloned object */
  return 1; /* do damage */
}

status id(string str) { return (str == "spell"); }

/* Native Mode Move */
