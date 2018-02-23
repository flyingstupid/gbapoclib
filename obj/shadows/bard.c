inherit "obj/shadows/shadow";

#define CHANCE 25
#define SPELL_FAILURE 100 /* yes, bad, but dwarves can't cast spells! */

object who;

void shadow_bard(object ob) {
  who = ob;
  if(!who) { 
    destruct(this_object());
    return;
  }
  shadow_object(who);
}  


status query_language(string str) {
  int linguistics;

  if(!str) return 0;

  if(who->query_language(str)) return 1;

  if(who->query_language_attempted(str)) {
    tell_object(who, "You've not had much luck with this language before.\n");
    return 0;
  }

  linguistics = (int)who->query_linguistics();

  /* failed to read the language */
  if(random(CHANCE) > random(linguistics)) {
    tell_object(who, "You try to make sense of it, but fail to understand.\n");
    who -> add_languages_attempted(str);
    return 0; 
  }
  tell_object(who, "It starts to make sense to you . . .\n");
  return 1;
}

void cast_spell_at_target() {
  string tmp1, tmp2;
  string race;
  string *races_that_misscast;

  races_that_misscast = ({
    "dwarf", "giant", "troll", "halfling", "kender",
  });


  race = (string)who->query_race();
  if(sscanf(race, "%s %s", tmp1, tmp2)) race = tmp2;

  if(member_array(race, races_that_misscast) != -1) {
    if(random(SPELL_FAILURE) > random((int)who->query_song())) {
      write("Your song magic goes awry...\n");
      say((string)who->query_name()+"'s song suddenly turns sour...\n");
      who->unload_spell();
      return;
    }
  }
  who->cast_spell_at_target();
  return;
}

object query_bard_object() {  return this_object(); }
object query_bard_aura_object() { return this_object(); }
