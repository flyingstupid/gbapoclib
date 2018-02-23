#include <mudlib.h>
inherit ROOM;

object monster, wand;
void reset(status arg) {

  if(!find_living("otiluke")) {
    monster = clone_object(MONSTER);
    monster -> set_name("otiluke");
    monster -> set_wander(50, 360);
    monster -> set_heart_ob(this_object());
    monster -> set_race("human");
    monster -> add_class("mage");
    monster -> set_gender(1);
    monster -> set_short("Magus Otiluke");
    monster -> set_al(10);
    monster -> set_long(
     "Young, short and puny, Otiluke has overcompensated for his    \n"+
     "drawbacks by being overly aggressive and abrasive. Unlike the \n"+
     "older more contemplative members of the Council, Otiluke      \n"+
     "believes in the use of offensive fire power.\n");
    monster -> set_level(25);
    monster -> set_ac(28);
    monster -> set_wc(30);
    monster -> load_chat(6, ({ "Otiluke says: What?\n",
     "Otiluke glares at you.\n",
     "Otiluke says: 'ere...get lost you.\n",
     "Otiluke pounds his fist into his palm menacingly.\n",
    }));
    monster -> load_a_chat(10,({ "Otiluke says: I'll get you for this.\n",
     "Otiluke exclaims: I'll rip you to shreds!\n",
     "Otiluke exclaims: No one does this to me and gets away with it!\n",
     "Otiluke says: Get lost!\n",
    }));

    monster -> add_spell_immunity("fire");
    monster -> add_spell_immunity("lightning");
    monster -> set_magic_resist(25);
    monster -> load_spells(30, ({ "fire ball", "fire shield", 
          "lightning bolt", "chain lightning",
          "monster summon 2", 
          "cone of cold", "ice storm", "  monster summon 3",
    }));
    move_object(monster,this_object());
  }

  if(!present("wand", find_living("otiluke"))) {
    wand = clone_object(WAND);
    wand -> set_cast_level(20);
    wand -> set_class(({ "mage", "cleric", }));
    wand -> set_name("wand");
    wand -> set_short("A long white wand");
    wand -> set_long(
          "Covering the length of the wand are silvery runes of magic \n"+
          "which define the wands powers, enchanted inside this shaft \n"+
          "of white steel.\n");
    wand -> query_info("A Wand of Frost.  ");
    wand -> add_spell("ice storm");
    wand -> set_max_charges(50);
    wand -> set_charges(50);
     wand -> set_cast_level(30);
    move_object(wand, find_living("otiluke"));
  }


  if(arg) return;
  set_short("the tower of high magic");
  set_long(
     "This is a large spacious room; the great hall of the council of   \n"+
     "high magic. All around you are paintings of great and famous      \n"+
     "wizards, who have devoted their lives to the study of magic, and  \n"+
     "the furthering of the power of wizards in the community of Tempus.\n"+
     "An iron stair case winds its way upward into the darkness of the  \n"+
     "tower above, and down into the basement below.\n");
  set_items(({
     "painting#paintings",
          "There is one of Bigby, Modenkainen, Tenser, and others",
     "stairs#staircase",
          "A stairwell of cold black iron, descending downward",
  }));
  set_weather(2,4,0);
  set_exits(({
     "room/city/mage/tower3", "up",
     "room/city/mage/bfloor1", "down",
     "room/city/mage/gfloor2", "north",
  }));
}

void monster_heart_beat() {
  string tmp1, tmp2;
  if(!sscanf(file_name(environment(find_living("otiluke"))), "%smage%s",
    tmp1, tmp2)) { 
    tell_room(environment(find_living("otiluke")),
      "Otiluke begins to chant in an ancient language...\n"+
      "Otiluke teleports away!\n\n");
    move_object(find_living("otiluke"), this_object());
  }
}

