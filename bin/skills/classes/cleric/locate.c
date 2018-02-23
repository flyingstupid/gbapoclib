/* remove curse */

#define SPELLNAME (string)caster->query_spell_name()

status locate(string str, mixed alt_type, string class) {
  int i;
  string file;

  if(!str) {
    notify_fail("locate who?\n");
    return 0;
  }

  if(!alt_type) alt_type = "divination_sphere";
  if(!class) class = "cleric";

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Locate",
  "sphere",            alt_type, 
  "cost",              6,
  "level",             6,
  "class", class,
  "cast time",         1,
  "spell object",      file,
  "argument",          str,
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;
  string rname;

  rname = (string)caster->query_spell_argument();
  if(!(ob = find_living(rname))) {
    write("You cannot locate "+ capitalize(rname) +".\n");
  }
  else if(ob->query_invis()) {
    if(ob->query_security_level())
      write("You cannot locate "+ capitalize(rname) +".\n");
    else
      write(capitalize(rname) +" is somewhere about, but their invisibility\n"+
            "disrupts the locating ability of the spell.\n");
  }
  else if(environment(ob)) {
    if(environment(ob)->query_no_track()) {
      write("Your mind cannot seem to get a firm grim upon " +
            capitalize(rname) + ".\n");
      destruct(this_object());
      return 1;
    }
    write("Your mind peers across the domains, you get a picture of\n"+
          "the area where "+ capitalize(rname) +" is located:\n\n");
    environment(ob)->long();
  }
  else {
    if(!target->query_npc())
      write(capitalize(rname) +" is logging in!\n");
    else
      write(capitalize(rname) +" is in a semi-existant state.\n");
  }
  destruct(this_object());
  return 1;
}  

status id(string str) { return str == "spell"; }

