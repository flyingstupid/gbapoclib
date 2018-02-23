/* shadow monster */

inherit "obj/skills/summoned";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shadow monster");
  set_alt_name("monster");
  set_alias_name("conjured");
  set_short("Shadow Monster");
  set_long("This monster form shift as light flickers about it.\n");
  load_chat(8,({ "The shadow monster looks around hungrily.\n",
                 "Wisps of shadow fly from the shadow monster.\n",
  }));
  load_a_chat(15,({ "The shadow monster strikes with a viscious blow.\n",
                    "You feel your strength weaken as the shadow monster "+
                     "touches you.\n", 
  }));
}

status cast_spell(object caster,object target,object prev,int level) {
  level /= 3;
  if(level > 15) level = 15;
  set_level(level);
  return ::cast_spell(caster,target,prev,level);
}

