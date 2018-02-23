#include <mudlib.h>
inherit MAGIC_WEAPON;

#include <rnd_name.h>

string command_word;

void reset(status arg) {
  if(arg) return;
  command_word = make_name("tanarri");

  set_name("staff");
  set_short("A long staff");
  set_type("crush");

  set_long(
"This ornately-carved staff of leather-like horn is inscribed \n"+
"with fell black runes and vile images of fanged, many-tentacled\n"+
"cruel horned monsters. It is topped with a many-horned skull \n"+
"with grim, interlocking fangs.\n");

  set_info("A staff of the Abyss.\n"+
        "This evil weapon has the power to summon Tanar'ri.\n"+
        "There are @@query_charges:$this_object()$@@ charges left.\n"+
        "The word '"+command_word+"' activates the staff.\n");
  set_light(1);
  set_length(80);
  set_wc(14);
  set_weight(5);
  set_value(2500);
  set_hit_func(this_object());
  set_charges(10);
  set_max_charges(10);
  set_enchanted(1);


}



/* note that the original item, from AD&D does 2-24
   points of damage. A typical staff would do anywhere
   from d6-d8. Hence, this staff returns wc*3 total damage
 */

int weapon_hit(object o) {
  object ob;
  ob = environment();

  if(!random(5)) { /* doesn't happen ALL the time! */
    tell_object(ob,
        "Amber flames flair from the eyes in the staff.\n");
    say(ob->query_name()+"'s staff flairs flames from "+
        "the eyes in it's top.\n", environment());
    return 24;
  }
  return 12;
}


void init() {
  ::init();
  add_action("summon1", command_word);
}

status summon1() {
  object ob;
  ob = this_player();

  if(!query_wielded()) return 0;

  if(!query_charges()) {
    notify_fail("The staff has no more charges.\n");
    return 0;
  }
  if(!(status)environment()->query_npc()) adj_charges(-1);
  write("The eyes in the staff flair an amber flame!\n");
  say(ob->query_name()+"'s staff flairs amber flames from it's eyes.\n", ob);
  call_out("summon2", 1);
  return 1;
}



void summon2() {
  object ob;

  ob = clone_object("skills/obj/summoned");
  move_object(ob, environment(environment()));
  ob -> set_name("vrock");
  ob -> set_short("huge, ugly vrock");
  ob -> set_race("tannr'ri");
  ob -> set_alias("summoned");
  ob -> set_long(
"This vrock is an especially ugly beast, with the head of vulture \n"+
"and the body of a huge human. It has claws and fangs and a large \n"+
"tail, and looks very powerful!\n");
  ob -> add_class("thief");
  ob -> add_class("fighter");
  ob -> set_level(20);
  ob -> cast_spell(environment(), 0, 0, 30);
  environment() -> add_followers(ob);
  return;
}


status wield(string str) {
  ::wield(str);
  if(id(str)) {
    if((int)this_player()->query_alignment() > 100) {
      tell_object(environment(), 
	"The "+query_name()+" sparks in your hands!\n");
      environment()->hit_player(20 + random(20)); /* ouch! */
      drop();
    }

    return 1;
  }
}

string query_command_word() { return command_word; }
