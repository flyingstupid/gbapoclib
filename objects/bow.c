#include <mudlib.h>

#define NAME            (string)environment()->query_name()
#define DEX             (int)environment()->query_dexterity()
#define ARROW_DMG       40  /* well... u only have limited shots! */
#define ELF_BONUS       2
#define BOWYER_MOD      3
#define MOD             4  /* prof mod from living.c, make sure its the same */

#define CHANCE_TO_BREAK 15 /* 1 in 15 chance */

inherit WEAPON;

static int dmg;
static mixed *last_arrow;
static string ammunition;

void find_fate_of_last_arrow(object ob, int i);

string set_ammunition(string str) { return ammunition = str; }
void reset(status arg) {
  if(arg) return;
  set_name("longbow");
  set_alias("bow");
  set_wc(0);
  set_ammunition("arrow");
  set_length(10000);
  set_type("missile");
  set_short("A fine longbow");
  set_long(
	"This fine longbow is made in the traditional elvish design.\n");
  set_info(
	"A bow requires "+ammunition+"s in a quiver.\n");
  set_weight( 5);
  set_value(1100);
  set_hit_func(this_object());
  set_attack_msg(({
        "missed", "",
        "grazed", "lightly with an "+ammunition+" shot",
	"pierced", "with an "+ammunition+"",
        "pierced", "deeply with an "+ammunition+"",
        "expertly hit", "with an "+ammunition+"",
        "hit", "with an expert "+ammunition+" shot",
  }));
  set_weapon_strength(12000);
}

int weapon_hit(object target) {
  object obj;
  int i;
  object *inv;
  status shotArrow;
  int bonus;

  inv = all_inventory(environment());

  obj = present("quiver", environment());
  for(i=1; (obj = present("quiver "+i, environment())); i++) {
    obj = present(ammunition, obj);
    if(obj) {
      switch(ammunition) {
        case "arrow" :
        tell_object(environment(), "You nock an arrow.\n");
        break;
        default :
        tell_object(environment(), "You load a "+ammunition+".\n");
        break;
      }

      bonus = ((int)obj->query_ammunition_bonus() + ARROW_DMG);
      environment(obj)->add_weight(-(int)obj->query_weight());
      shotArrow = 1;
      if(!environment()->query_npc())
        find_fate_of_last_arrow(obj, bonus);
      return bonus;
    }
  }

  if(!shotArrow && !environment()->query_npc()) {
    tell_object(environment(), "You have run out of "+ammunition+"s!\n");
    say(NAME+" fumbles around for some "+ammunition+"s, but can't find any!\n",
      environment());
    return -100000;  /* don't want to do ANY damage! */
  }
}

void find_fate_of_last_arrow(object obj, int bonus) {
  last_arrow = ({ obj, bonus, });
}

int query_dam(int damage, object attacker) {
  object *env, ob;
  string message;

  if(!attacker) return 1;
  if(environment()->query_npc()) return 1;
  if(damage < 1) return 1;
  if(!sizeof(last_arrow) || !last_arrow) return 1;
  if(!last_arrow[0]) return 1;
  env = all_inventory(environment(environment()));
  if(!damage) {
    if(!last_arrow[0]) return 1;
    /* you shoot someone else */
    if(!random(DEX)) {
      ob = env[random(sizeof(env))];
      if(ob == attacker) ob = environment();
      ob -> hit_player(random(damage));
      if(ob == environment()) {
        tell_object(environment(), "You shoot yourself in the foot!\n");
        say(NAME+" shoots "+environment()->query_objective()+"self "+
        "in the foot!\n");
      }
      tell_object(environment(), "You shoot "+ob->query_name()+
      " by accident!\n");
      say(NAME+" shoots "+ob->query_name()+" by accient!\n");

      if(last_arrow[1] > ARROW_DMG) {
        message = ""+ammunition+" explodes!";
        tell_object(environment(), "Your "+message+".\n");
        say(NAME+"'s "+message+".\n", environment());
        destruct(last_arrow[0]);
        return 1;
      }
      if(!random(CHANCE_TO_BREAK)) {
        message = ""+ammunition+" shatters!";
        tell_object(environment(), "Your "+message+"\n");
        say(NAME+"'s "+message+"\n", environment());
        destruct(last_arrow[0]);
        move_object(clone_object("objects/bits"), ob);
        return 1;
      }
      move_object(last_arrow[0], ob);
      return 1;
    }

    /* if you dont hit someone else, you must hit the ground hu?! */
    message = ""+ammunition+" hits the ground and ";
    if(last_arrow[1] > ARROW_DMG) {
      message += "explodes, leaving a scorch mark";
      destruct(last_arrow[0]);
    }
    else {
      if(!random(CHANCE_TO_BREAK)) {
        message += "shatters!";
        move_object(clone_object("objects/bits"),environment(environment()));
        destruct(last_arrow[0]);
      }
      else {
        message += "stays there";
        move_object(last_arrow[0], environment(environment()));
      }
    }
    tell_object(environment(), "Your "+message+"\n");
    say(NAME+"s "+message+".\n", environment());
    return 1;
  }


  /* "+ammunition+" did hit, but what happened?! */
  if(last_arrow[1] > ARROW_DMG) {
    message = ""+ammunition+" explodes on impact!";
    tell_object(environment(), "Your "+message+".\n");
    say(NAME+"s "+message+".\n", environment());
    destruct(last_arrow[0]);
    return 1;
  }
  if(!random(CHANCE_TO_BREAK)) {
    message = ""+ammunition+" breaks as it hits!";
    tell_object(environment(), "Your "+message+".\n");
    say(NAME+"'s "+message+".\n", environment());
    destruct(last_arrow[0]);
    move_object(clone_object("objects/bits"), attacker);
    return 1;
  }
  message = ""+ammunition+" sticks into "+attacker->query_name();
  tell_object(environment(), "Your "+message+".\n");
  say(NAME+"'s "+message+".\n", environment());
  move_object(last_arrow[0], attacker);
  return 1;
}



int right_weapon_class_bonus() {
  string tmp1, tmp2;
  int tmpBonus;
  string race;

  race = (string)environment()->query_race();
  if(query_wielded()) {
    if(sscanf(race, "%self%s", tmp1, tmp2) &&
      race != "dark elf") {
      tmpBonus += ELF_BONUS;
    }
  }
  tmpBonus += (int)environment()->query_bowyer() / BOWYER_MOD;
  tmpBonus += (int)environment()->query_weapon_proficiency(query_name())/MOD;
  return tmpBonus;
}

