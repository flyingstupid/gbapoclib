/* remove curse */

#define SPELLNAME (string)caster->query_spell_name()

status remove(string spell_type, mixed alt_type, string class) {
  int i;
  string file;
  string targ;
  string spell_name;
  int spell_level;

  if(!spell_type) {
    notify_fail("remove curse?\n");
    return 0;
  }

  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  sscanf(spell_type,"%s %s", spell_type, targ);
  spell_type = lower_case(spell_type);
  switch(spell_type) {
    case "curse":
      spell_name = "Remove Curse";
      spell_level = 6;
    break;

    default:
      notify_fail("remove curse?\n");
      return 0;
    break;
  }

  this_player()->load_spell(({
  "target",            targ,
  "name",              spell_name,
  "sphere",            alt_type, 
  "cost",              spell_level,
  "level",             spell_level,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;
  status flag;

  if(SPELLNAME == "Remove Curse") {
    while((ob = present("Curse", target))) {
      flag = 1;
      destruct(ob);
    }
    if(target->id("Curse")) {
      flag = 1;
      destruct(target);
    }
    if(!flag) {
      write("There is no curse.\n");
    }
    else {
      write("You remove the curse.\n");
      if(caster != target) {
        tell_object(target,caster->query_name()+" removes your curse.\n");
      }
      say(caster->query_name() +" removes a curse on "+ target->query_name()
          +".\n", target);
    }
  }
  destruct(this_object());
  return 1;
}  

status id(string str) { return str == "spell"; }
