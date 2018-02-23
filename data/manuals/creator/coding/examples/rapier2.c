#include <mudlib.h>
#define MONST_WC	20
#define WEAPN_WC	13

inherit MONSTER;
inherit WEAPON;

static int counter;
static status am_attacking;
static object monster, wielder;
object attack;

void reset(status arg) {
  monster::reset(arg);
  weapon::reset(arg);

  if(arg) return;

  weapon::set_type("slash");
  set_name("rapier");
  set_alias("scalion");
  set_level(15);
  is_npc = 0;

  set_info(
    "This rapier, Scalion, is a Sword of Dancing.\n");


  weapon::set_short("A fancy rapier");

  set_long(
    "This rapier is made from steel and fashioned in a tradition\n"+
    "forgotten by modern weaponsmiths. The guard is made from   \n"+
    "several strips of steel and platinum, giving the over all \n"+
    "impression of an ornate weave to the basket hilt. \n");

  set_type("slash");
  set_wc(13); /* +1 rapier */
  set_hit_func(this_object());
  set_heart_ob(this_object());
  set_weight(5);
  set_value(1800);
  enable_commands();
  set_attack_msg(
	({ "missed",          "",
           "lightly touched", "with a light graze",
           "wounded",         "with a weak blow",  
           "cut",             "with a fairly deep wound", 
           "sliced",          "with a strike to the head",
           "slashed",         "with a slice to the chest",
           "devestated",      "with a severe wound to the body",
           "mutilated",       "\b, severely disabling a limb",
        }));

  set_dead_ob(this_object());
}

void monster_died() {
  tell_room(environment(), query_name()+" shatters...!\n");
  destruct(this_object());
}

void init() {
  weapon::init();
  monster::init();
}


void query_dam() {

  counter ++;
  if(environment()->query_npc()) return;
  if(!random(5))
    tell_object(environment(), "Scalion's blade grows brighter...\n");   
  if(am_attacking) return;

  if(counter > 10) {
    tell_object(environment(), "Scalion jumps out of your hands!\n");
    counter = 0;
    am_attacking = 1;
    wielder = environment(this_object());
    attack = (object)wielder->query_attack();
    move_object(this_object(), environment(wielder));
    say(wielder->query_name()+"'s sword leaps out of "+
	wielder->query_possessive()+" hands.\n", wielder);
    drop();
    return;
  }
  return;
}


int weapon_hit(object ob) {
  if(am_attacking) return 0;
  if(counter) return counter/3; /* approximates up to +3 */
}



void monster_heart_beat() {

  if(wielder == environment()) return;
  if(!wielder) return;
  if(!am_attacking) return;
  set_wc(MONST_WC);

  if(!present(wielder, environment())) {
    say("Rapier jumps back into "+wielder->query_name()+"s "+
	"inventory!\n", wielder);
    tell_object(wielder, "Scalion jumps back into your inventory.\n");
    move_object(this_object(), wielder);
    set_wc(WEAPN_WC);
    command("wield rapier", wielder);
    am_attacking = 0;
    return;
  }

  counter ++;
  if(attack == this_object()) return;

  if(attack) {
    if(attack != query_primary_attack()) {
      add_secondary_attacker(attack);
      attack->add_secondary_attacker(this_object());
      wielder->add_secondary_attacker(attack);
      attack->hit_player(1); /* just in case its an npc vs a player */
    }
    if(counter > 20) {
      say(query_name()+" jumps back into "+wielder->query_name()+
	"'s inventory!\n", wielder);
      tell_object(wielder, "Scalion jumps back into your inventory.\n");
      attack->add_secondary_attacker(wielder);
      wielder->add_secondary_attacker(attack);
      am_attacking = 0;
      counter = 0;
      move_object(this_object(), wielder);
      command("wield rapier", wielder);
      set_wc(WEAPN_WC);
    }
    return;
  }

  if(!attack) {
    say(query_name()+" jumps back into "+wielder->query_name()+"'s "+
	"inventory.\n", wielder);
    tell_object(wielder, "Scalion jumps back into your inventory.\n");
    counter = 0;
    am_attacking = 0;
    move_object(this_object(), wielder);
    set_wc(WEAPN_WC);
    command("wield rapier", wielder);
  }
}

string short(status wiz) { 
  return weapon::short(wiz);
}

get(arg) {
  if(wielder && wielder != this_player()) {
    return 0;
  }
  return weapon::get(arg);
}

drop(arg) {
  return weapon::drop(arg);
}

