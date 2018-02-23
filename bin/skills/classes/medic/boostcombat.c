/* Boost Combat Enhancing Power */

inherit "obj/skills/sp_weap";
inherit "obj/skills/sp_arm";

#define NAME  "@@query_name:$this_player()$@@"

status boostcombat(string targ, mixed alt_type, string class) {
  int level, i;
  string file;

  if(!alt_type) alt_type = "enhancing";
  if(!class) class = "medic";
  level = (objectp(alt_type))
        ? (int)alt_type->query_cast_level()
        : (int)call_other(this_player(), "query_"+ alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Boost Combat",
  "sphere",            alt_type, 
  "cost",              0,
  "level",             15,
  "class",             class,
  "damage",            level,
  "cast time",         2,
  "spell object",      file,
  "casting msg",       "You feel your skin hardening and your reflexes improve.\n",
  "casting msg room",  NAME +"'s skin hardens and they begin to move more gracefully.\n",
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
 object enhancecombat;
 object kit;
 if(kit = present("medic_kit",caster))
 {
    if(kit->query_combatserum() < 0)
    {
        write("You don't have enough combat serum to enhance someone!\n");
        return 1;
    }
    kit->set_combatserum(query_combatserum()-1);
  enhancecombat = present("enhancecombat", target);
  if(enhancecombat) {
      if(target != caster) {
        tell_object(caster,"You inject "+
                    (string)target->query_name()+" again in order to extend its duration.\n");
      }
      else {
        write("You extend the time of your combat enhacement.\n");
      }
      enhancecombat->adj_time(dmg*60);
      destruct(this_object());
      return 1;
  }
  if(caster == target) {
    write("You are enhancecombated by the gods.\n");
    say(caster->query_name() + " enhancecombates "+
      caster->query_objective() +"self.\n", caster);
  }
  else {
    write("You inject "+ target->query_name() + " with a combat drug!\n");
  
    say(caster->query_name() +" injects "+ target->query_name() + " with a combat drug!\n"); 
  
    tell_object(target, caster->query_name() + " injects with with something. Your blood feels on fire!\n");  
  }
  set_name("enhancecombat");
  set_alt_extra_long("You are Combat Enhanced!\n");
  set_extra_long("@@query_name:$environment()$@@ is Combat Enhanced!.\n");
  set_wc_bonus(caster->query_enhancing()/10);
  set_ac_bonus(caster->query_enhancing()/10);
  adj_time(dmg * 60);
  target->recalc_ac();
  target->recalc_wc();
  return 1; /* don't do damage */
  }
  else
  {
    write("You need your kit!\n");
    return 1;
  }