#include <mudlib.h>
inherit ROOM;

static object elemental, apprentice;
void reset(status arg) {

  if(!present("elemental")) {
    elemental = clone_object(MONSTER);
    elemental -> set_name("fire elemental");
    elemental -> set_alias("elemental");
    elemental -> set_race("elemental");
    elemental -> set_short("A huge fire elemental");
    elemental -> set_long(
     "A large column of flame with almost human-like features, this \n"+
     "powerful being has been summoned by powersful magics. He does \n"+
     "not appear pleased to be here.\n");
    elemental -> set_gender(1);
    elemental -> set_level(15);
    elemental -> add_spell_immunity("fire");
    elemental -> add_class("fighter");
    elemental -> add_class("mage");
    elemental -> load_spells(40, ({ "fire ball", "bbb", }));
    elemental -> load_chat(10, ({ "Elemental says: Free me mortal.\n",
          "Elemental moves around the circle of protection.\n",
          "Elemental glares at you menacingly.\n",
          "Elemental makes the room seem very warm.\n",
    }));
    elemental -> load_a_chat(10, ({ "Elemental says: I will burn you.\n",
          "Elemental says: I will burn you to a crisp.\n",
          "Elemental says: You will soon be ash under my feet.\n",
          "Elemental says: I will boil your blood.\n",
    }));
    elemental -> set_wc(20);
    elemental -> set_ac(12);
    elemental -> add_money(200 + random(100));
    elemental -> set_dead_ob(this_object());
    move_object(elemental, this_object());
  }

  if(!present("apprentice")) {
    apprentice = clone_object(MONSTER);
    apprentice -> set_name("apprentice");
    apprentice -> set_race("half elf");
    apprentice -> set_gender(2);
    apprentice -> set_short("An apprentice");
    apprentice -> set_level(10);
    apprentice -> set_long(
          "This little apprentice is fearful and frightened! The look \n"+
          "on her face is one of dread. \n");
    apprentice -> load_chat(20,({ "Apprentice asks: Please help me?\n",
          "Apprentice exclaims: Please help me!\n",
          "Apprentice says: I've summoned this elemental by mistake.\n",
          "Apprentice says: Do you know what to do?\n",
          "Apprentice says: Can you make the elemental go away?\n",
          "Apprentice says: Please make the elemental go away.\n",
    }));
    apprentice -> add_class("mage");
    apprentice -> load_spells(15,({
          "burning hands", "web", "monster summon 1", "rope trick",
          "chill touch", "stone skin", "fire shield",
    }));
    apprentice -> set_heart_ob(this_object());
    move_object(apprentice,this_object());
    move_object(clone_object("room/city/obj/s_book"),apprentice);
  }

  if(arg) return;
  set_short("the basement of the council of high magic");
  set_long(
     "A large circle of white marble lined with white candles sits in \n"+
     "the middle of the room. The walls are scortched and marked with \n"+
     "blood. Apparently something terrible has happened here. A cold  \n"+
     "iron staircase winds its way upward into the darkness.\n");

  set_items(({
     "stairs#staircase",
          "A stairwell of cold black iron, descending downward",
     "walls#wall",
          "The walls are of a cold grey stone, possibly made by magical \n"+
          "magical means. They are covered with spots of blood and burn \n"+
          "marks from some intense fire or explosion",
     "candle#candle",
          "They surround the circle in the center of the room",
     "circle#marble",
          "A marble circle has been placed in the centre of the room.\n"+
          "Your knowledge of magic tells you it is a circle of protection",
     "stone",
          "No dwarf chiselled this stone",
  }));
  set_listen("You hear the crackling of fire...somewhere close by.\n");
  set_smell("The air here smells of burnt flesh.\n");
  set_exits(({
     "room/city/mage/bfloor1", "up",
	"room/city/mage/dungeon/stcase", "down",
     "room/city/mage/bfloor3", "east",
  }));
  set_weather(2,1,0);    
}

void monster_died() {
  object corpse;
  corpse = present("corpse", this_object());
  tell_room(this_object(), "Elemental explodes....then vanishes...\n");
  if(corpse) destruct(corpse);
}

void monster_heart_beat() {
  if(present("rope", this_object())) {
    if(apprentice)
      command("climb rope", apprentice);
  }
}
