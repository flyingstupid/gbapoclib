/* Magic Effects File. v1.0
 * (c) Angel, Nov 1996.
 * Designed for the Heaven7 mudlib
 *
 * Note: This file is used in conjunction with the affiliations
 * of the 'robes of alignment'.
 * Robed Mages do not have misc. malevolent effects befall them, but
 * other mages who do not obey the laws of magic, do
 */

#include <spell.h>

#define MIN_LEVEL	3	/* beyond this level magic goes awry */
#define NAME		(string)this_player()->query_name()



void kill_off_fauna();

void misc_magic(object caster) {
  string *robes;
  int i;
  status is_member;
  mixed *loaded_spell;
  string *affiliations;


  if((int)caster->query_level() < MIN_LEVEL) return;
  if(!caster) caster = this_player();
  if(!caster->query_class("mage")) return;

  loaded_spell = (mixed *)caster->query_loaded_spell();
  is_member = 1;
  if(SPELL_CLASS != "renegade mage") return;


  if(random(SPELL_LEVEL) > random(call_other(caster, "query_"+SPELL_TYPE))) { 
    write("Your spell goes awry.\n");
    kill_off_fauna();
  }


}

void kill_off_fauna() {
  write("You feel the life essence in your surroundings corrupt...\n");
  say("All the fauna around "+NAME+" wilts and dies...\n");
}

