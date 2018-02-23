#include <mudlib.h>
inherit ROOM;

static object monster, apprentice, wand;
static int i;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "file", "room/city/garden/garden2",
     "direction", "north door",
     "long",
        "A large pair of double iron doors, made from a strange black wood.\n",
     "key id", "city key",
  }));
  if(!present("apprentice")) {
    for(i=0; i<4; i++) {
      apprentice = clone_object(MONSTER);
      apprentice -> set_name("apprentice");
      apprentice -> set_al(200);
      apprentice -> set_level(10);
      apprentice -> set_short("A young apprentice");
      apprentice -> set_gender(random(2) + 1);
      apprentice -> set_race("human");
      apprentice -> set_long(  
           "This young apprentice is trying to learn the complexities \n"+
           "of magic and so has journeyed here to learn from the masters.\n");
      apprentice -> set_wc(14);
      apprentice -> set_ac(9);
      apprentice -> add_money(200 + random(300));
      apprentice -> load_chat(10,({ "Apprentice says: Hullo there.\n",
          "Apprentice asks: Can you help me?\n",
          "Apprentice asks: I am trying to learn some magic here.\n",
          "Apprentice tries to learn a complex magical formula.\n",
          "Apprentice says: I just don't think I can learn this one.\n",
      }));
      apprentice -> load_a_chat(10,({ "Apprentice screams for help!\n",
          "Apprentice exclaims: Mordenkainen will not like this!\n",
          "Apprentice exclaims: Stop it, please!\n",
          "Apprentice bursts into tears.\n",
          "Apprentice sobs sadly.\n",
      }));
      apprentice -> load_spells(40,({ "burning hands",
          "monster summon 1", "shadow door", }));
      apprentice -> set_magic_resist(10);
      move_object(apprentice,this_object());
    }
  }

  if(!find_living("rary")) {
    monster = clone_object(MONSTER);
    monster -> set_name("rary");
    monster -> set_alias("archmage");
    monster -> set_wander(50, 1120);
    monster -> set_heart_ob(this_object());
    monster -> set_race("human");
    monster -> add_class("mage");
    monster -> add_class("cleric");
    monster -> set_gender(1);
    monster -> set_short("Archmage Rary");
    monster -> set_al(500);
    monster -> set_long(
     "One of the ancient mages of the council, Rary is the traditional \n"+
     "archmage, carefully studying tomes almost as old as he is. Rary  \n"+
     "is a dithering old wizard, probably currently searching for his  \n"+
     "spectacles.\n");
    monster -> set_level(45);
    monster -> set_ac(38);
    monster -> set_wc(30);
    monster -> load_chat(10,({ "Rary looks around the room.\n",
     "Rary asks: Have you seen my glasses?\n",
     "Rary says: I seem to have misplaced my spectacles.\n",
     "Rary says: What did you say?\n",
     "Rary says: Sorry, I'm a little hard of hearing.\n",
     "Rary wanders around the room.\n",
     "Rary scratches his head.\n",
     "Rary ponders the situation.\n",
     "Rary thinks carefully.\n",
     "Rary asks: Will you help me find my glasses?\n",
    }));
    monster -> load_a_chat(10,({ "Rary says: Have respect for your elders.\n",
     "Rary says: Be kind to your elders.\n",
     "Rary says: Leave my alone, you big bully.\n",
     "Rary asks: Have you no pitty for the elderly?\n",
     "Rary exclaims: Mordenkaine will hear about this!\n",
     "Rary bursts into tears.\n",
    }));
    monster -> add_spell_immunity("death");
    monster -> add_spell_immunity("poison");
    monster -> add_spell_immunity("cold");
    monster -> add_spell_immunity("fire");
    monster -> add_spell_immunity("lightning");
    monster -> set_magic_resist(55);
    monster -> load_spells(30, ({ "fire ball", "fire shield", 
          "lightning bolt", "chain lightning", "curse", "bless",
          "monster summon 2", "burning hands", "stone skin",
          "cone of cold", "ice storm", "  monster summon 3",
          "disintegrate", "pwk", "pws", "comet", "death spell",
          "energy drain", "chill touch", "heal", "cure light wounds",
          "hold person", "hold monster", "phantom armour",
    }));
    monster -> set_dead_ob(this_object());
    move_object(monster,this_object());
  }

  if(arg) return;
  set_short("the tower of high magic");
  set_long(
     "The grand hall of the Council of Magic is a great sight to \n"+
     "behold. Tall pillars of blue-write marble stretch to the   \n"+
     "high vaulted ceiling above, painted with ornate frescoes.  \n");
  set_items(({
     "columns#column#pillar#pillars#marble",
          "Marble columns which stretch toward the ceiling",
     "frescoe#frescoes",
          "The frescoes depict the titanic struggle of mankind against \n"+
          "the terrors and evil of the dark-ones. Both seem locked in a tie",
     "ceiling#vaulted ceiling",
          "The ceiling is far above you",
  }));

  set_weather(2,4,0);
  set_exits(({
     "room/city/mage/gfloor1", "south",
  }));
}

void monster_died() {
  object corpse;
  tell_room(environment(find_living("rary")),
     "Rary exclaims: Lucky I have that contingency spell!\n"+
     "Rary vanishes in a puff of smoke!\n\n");
  corpse = present("corpse", environment(find_living("rary")));
  if(corpse) destruct(corpse);
}
  
void monster_heart_beat() {
  string tmp1, tmp2;

  if(!sscanf(file_name(environment(find_living("rary"))), "%smage%s",
    tmp1, tmp2)) {
    tell_room(environment(find_living("rary")),
      "Rary begins chanting in an ancient language...\n"+
      "Rary teleports away!\n\n");
    move_object(find_living("rary"), this_object());
  }
}

