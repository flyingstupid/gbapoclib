/* spell immunity */

inherit "inherit/timer";

#define NAME "@@query_name:$this_player()$@@"

string spell_immune;

status spell(string spell_type, mixed alt_type, string class) {
  int i, time;
  string file;

  if(!spell_type || sscanf(spell_type,"immunity %s", spell_type) != 1) {
    notify_fail("spell immunity?\n");
    return 0;
  }
  spell_type = lower_case(spell_type);
  if(!alt_type) alt_type = "abjuration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
       ? (int)alt_type->query_cast_level()
       : (int)call_other(this_player(),"query_"+ alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
   "name",		"spell immunity",
  "sphere",            alt_type, 
  "cost",              14,
  "level",             14,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "damage",            time,
  "casting msg",       "You start to bind a magical field.\n",
  "casting msg room",  "You see "+ NAME +" chant.\n",
  "argument",          spell_type,
  "passive",
  }));
  return 1;
}


/*******************************************************************/
/* called when this is cloned to target */


status cast_spell(object caster,object target,object prev,int dmg) {
  spell_immune = (string)target->query_spell_argument();
  write("A magical field forms that makes you immune to the spell, "+
        capitalize(spell_immune) +".\n");
  adj_time(dmg * 30);
  return 1;
}  

status spell_capture(object cast,object targ,object spell,object prev,int i) {
  string spellname;

  spellname = (string)cast->query_spell_name();
  if(spellname && lower_case(spellname) == spell_immune) {
    tell_object(environment(),"The "+ capitalize(spell_immune) 
                             +" spell has no effect on you.\n");
    if(spell) destruct(spell);
    return 1;
  }
  return 0;
}

void time_out() {
  tell_object(environment(),"Your immunity to "+ spell_immune +" fades.\n");
  ::time_out();
}

void extra_long() {
  if(this_player() == environment()) {
    write("A field of magic, to absorb \""+ capitalize(spell_immune) +
          "\" surrounds you.\n");
  }
}

void dispel_magic() { time_out(); }

status id(string str) {
  return str == "spell"
      || str == "external"
      || str == "spell immunity";
}

