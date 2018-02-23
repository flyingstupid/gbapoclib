/* combat object */

inherit "obj/shadows/shadow";
inherit "inherit/timer";

object who;
int combat;

void shadow_combat(object ob, int i) {
  who = ob;
  if(!who) { 
    destruct(this_object());
    return;
  }
  combat = i;
  shadow_object(who);
}  

int query_combat() { return combat; }

object query_combat_object() {  return this_object(); }

void time_out() {
  tell_object(who,"You don't feel strong in combat anymore...\n");
  ::time_out();
}

void dispel_magic() { time_out(); }

int query_old_combat() { return (int)who->query_combat(); }

