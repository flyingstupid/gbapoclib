/* firesign.c -- Firesign the Longsword of F'rane */
/* Darkness */

#include <mudlib.h>
inherit MAGIC_WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("longsword");
  set_short("Firesign, elven longsword");
  set_alias("firesign");
  set_long(
    "This highly polished black longsword is an elegant elven weapon.  The\n"+
    "long, slender blade is engraved with ancient runes antiqued with red,\n"+
    "silver, and gold color.  The hilt is made of the same black metal as\n"+
    "the blade, and is covered with intricate silver designs.  A large ruby,\n"+
    "adorns the end of the hilt, adding a firey contrast to the black iron.\n"+
    "Perfectly balanced and razor sharp, this sword could be none other than\n"+
    "Firesign, longsword of F'rane the elven bladesinger.\n");

  set_length(48);
  set_type("slash");
  set_value(6000);
  set_sell_destruct(1);
  set_wc(15);               /* +2 sword */
  set_weight(5);
  set_smell("The sword smells of blood and polished metal.\n");
  set_protection("fire");
  set_protection("magic");
  set_enchanted(1);
  set_hit_func(this_object());

  set_attack_msg(({
    "grazed", "",
    "slashed", "fiercly",
    "skillfully sliced", "",
    "expertly hit", "",
    "masterfully excuted a maneuver with Firesign.\n", 
      "is stunned by the blow.",
    "tore", "apart with a deadly attack",
    "tore", "apart with a deadly attack",
    }));
}



status wield(string str) {         /* Firesign can not be wielded by Dark Elves. */
  ::wield(str);
  if(id(str)) {
    if(this_player()->query_race()=="dark elf") {
      tell_object(environment(), "The longsword glows a firey red!\n");
      environment()->hit_player(20 + random(20)); 
      drop();
    }
  return 1;
  }
}



int weapon_hit(object target) {                    
int CHANCE;
                                                   /* Abilities granted to only */
  if(environment()->query_race()=="elf" ||         /* the listed elfin races.   */
     environment()->query_race()=="high elf" ||
     environment()->query_race()=="half elf" || 
     environment()->query_race()=="wood elf" || 
     environment()->query_race()=="wild elf" ||
     environment()->query_race()=="grey elf"  )  {

    if(target->query_race()=="drow elf" ||
       target->query_race()=="dark elf"  ) {
       CHANCE = 1 + random(19);

      if(CHANCE<4) {     /* random emote */
        tell_object(environment(),
          "Firesign burns a firey red as it slashes through the Drow.\n");
        say(environment()->query_name() +
          "'s longsword burns a firey red as it slashes through the Drow.\n");
      }
      return 10;  /* +10 vs Drow Elves */
    }

    if(target->query_race()=="troll" ||
       target->query_race()=="giant" ||
       target->query_race()=="orc" ||
       target->query_race()=="kobold" ||
       target->query_race()=="imp" ||
       target->query_race()=="undead") {
       CHANCE = 1 + random(19);
 
      if(CHANCE<4) {  /* random emote */
        tell_object(environment(),
          "Firesign burns a firey red as it hits its mark.\n");
        say(environment()->query_name() +
          "'s longsword burns a firey red as it hits its mark.\n");
      }
      return 6;  /* +6 against listed races */
    }

  }
  return 0;
}



void init() {
  ::init();
  add_action("read1", "read");
}



status read1(string str) {
  string tmp1, tmp2;
 
  if(sscanf(str, "%srunes%s", tmp1, tmp2)) {
    if((string)this_player()->query_language("elf") &&
       (string)this_player()->query_class("mage")) {
      write(
        "The runes marking the sword are magical in nature.  They name the\n"+
        "weapon 'Firesign', and show that the sword is protected by many\n"+
        "magical forces which are passed on to its wielder.  Firesign also\n"+
        "acts aggressively towards certain elven enemies by burning as hot\n"+
        "as the forge in which it was made.\n");
      say(this_player()->query_name()+" inspects "+
          this_player()->query_possessive()+" longsword.\n",
          this_player());
    }

    else {
      write("The runes don't make any sense to you.\n");
      say(this_player()->query_name()+" inspects "+
          this_player()->query_possessive()+" longsword.\n",
          this_player());
    }

    return 1;
  }

  else {  return 0;  }  
}
