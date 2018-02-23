#include <mudlib.h>
inherit WEAPON;

#include <rnd_name.h>
#include <ansi.h>




string command_word;
int ac_bonus, wc_bonus;

void reset(status arg) {
  if(arg) return;
  set_name("broadsword");
  set_alias("sword");
  set_type("slash");
  set_length(42);
  set_wc(16); /* can be up to +4! */
  set_weight(4);
  set_value(5000);
  set_hit_func(this_object());
  set_enchanted(1);
  set_short("A broadsword");

  set_long(
	"This is a fine weapon indeed, with a blade of mithril steel \n"+
	"and a guard of white gold inlaid with small saphires. On the\n"+
	"blade itself are various runes of protection and defence, as\n"+
	"well as of attack.\n"
  );

  command_word = make_name("defender");
  set_info("A defender broadsword\n"+
	"This magical weapon grants the wielder both magical prowess\n"+
	"in the weapon, but also a magical defence bonus. To alter the\n"+
	"balance of this protection, simply use the command "+
	command_word+".\n");
}


int weapon_hit() {
  if(ac_bonus > wc_bonus) {
    if(!random(5))
    tell_room(environment(), 
	BOLD+GREEN_F+
	"Your broadsword emits a barrier of protection"+OFF+".\n");
  }
  else if(ac_bonus < wc_bonus) {
    if(!random(5))
      tell_room(environment(),
	BOLD+GREEN_F+
	"Your broadsword glows more brightly as you attack."+OFF+"\n");
  }
  else {
    tell_room(environment(),
	BOLD+GREEN_F+
	"Your sword feels powerful in yours hands.\n");
  }
  return wc_bonus; /* maximum of +4 */
}



void init() {
  ::init();
  add_action("change_bonus", command_word);
}

status change_bonus(string str) {
  string tmp1, tmp2;
  int amount;

  if(!str) {
    notify_fail("To alter the defence or attack capability use either:\n"+
	command_word+" attack <amount> 	or \n"+
	command_word+" defence <amount>\n");

    return 0;
  }

  /* take away from ac and put on wc */
  if(sscanf(str, "attack %d", amount)) {
    if(amount > 4) {
      write(
	"You can only assign a maximum of four points to your attack.\n");
      return 1;
    }
    if(amount < 0) {
      write("You can only assign positive numbers to your attack bonus.\n");
      return 1;
    }
    ac_bonus -= amount;
    wc_bonus += amount;
    write("You feel your broadsword power up with energy.\n");
    return 1;
  }
  
  else if(sscanf(str, "defence %d", amount)) {
    if(amount > 4) {
      write(
	"You can only assign a maximum of four points to your attack.\n");
      return 1;
    }
    if(amount < 0) {
      write("You can only assign positive numbers to your attack bonus.\n");
      return 1;
    }
    ac_bonus += amount;
    wc_bonus -= amount;
    write("You feel your broadsword power up with energy.\n");
    return 1;
  }

  write("To alter the defence or attack capability use either:\n"+
	command_word+" attack <amount> 	or \n"+
	command_word+" defence <amount>\n");
  return 1;
}

int armour_class_bonus() { return ac_bonus; }

status id(string str) { return ::id(str) || str == "external"; }
