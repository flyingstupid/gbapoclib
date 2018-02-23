#include "path.h"
#define TP this_player()

inherit "obj/skills/sp_weap";
inherit "obj/skills/sp_arm";  


/* Same as Bless Spell */
status combatmind(string str, mixed alt_type, string class) {
  int i;
  string file;
  string targ, spellname;
  object ob;
  int cl;

  if(!str) {
    notify_fail("Combat mind?\n");
    return 0;
  }


  
  if(!alt_type) { 
    if(!this_player()->query_psi_skills("combat mind")) {
      notify_fail("You have not yet learned the 'Combat Mind'"+
                  " yet.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "fighting";
  if(!class)    class    = "pointman";

  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);

  this_player()->load_spell(({
  "target",            TP->query_name(1),
  "name",              "Combat Mind",
  "sphere",            alt_type,
  "cost",              0,
  "level",             1,
  "class",             class,
  "cast time",         1,
  "spell object",      file,
  "damage",            cl,  /* as time */
  "passive",
  }));
  return 1;
}

/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int dmg) {
  object bless;

  bless = present("combat mind", target);

  if(bless) {
    write("You extend the time of your Combat Mind.\n");
    bless->adj_time(dmg*60);
    destruct(this_object());
    return 1;
  }

  write("You enter a Combat frame of Mind.\n");
  say(caster->query_name() + " enters a trance-like state.\n", caster);
  set_name("combat mind");
  set_alt_extra_long("You are in a combat trance\n");
  set_extra_long("@@query_name:$environment()$@@ is in a combat trance.\n");
  set_wc_bonus(1);
  set_ac_bonus(1);
  adj_time(dmg * 60);
  target->recalc_ac();
  target->recalc_wc();
  return 1; /* don't do damage */
}


status id(string str) {
  return str == "Psionic" ||
         str == "combat mind";
}
