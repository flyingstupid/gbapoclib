#include <mudlib.h>
inherit AFFILIATION;
inherit GUILD;

object robe;
void reset(status arg) {
  guild::reset(arg);
  affils::reset(arg);

  if(!guild_master) {
    guild_master = clone_object(MONSTER);
    guild_master -> set_name("ariel");
    guild_master -> set_short("Archmage Ariel, of the Nine");
    guild_master -> set_long(
     "Reclusive, Ariel seldom adventures anymore, unless it is absolutely \n"+
     "necessary. Instead, she conforms to the traditional role of a wizard,\n"+
     "pale and studious. Although smart and wise, Ariel is less of a leader\n"+
     "of men and more a spectator. She is always willing to let others do  \n"+
     "her task for her. She now spends her time tutoring and training new  \n"+
     "apprentices within the Tower of High Sorcery.\n"+
     "Ariel is a White Robe Mage.\n");

    guild_master -> load_chat(5, ({ 
	"Ariel studies an ancient tome.\n",
          "Ariel asks: Have you come to study here, apprentice?\n",
          "Ariel peruses a few scrolls of magic.\n",
          "Ariel ponders the complexities of a magical formula.\n",
          "Ariel practices a complex magical spell.\n",
    }));

    guild_master -> load_a_chat(5, ({ "Ariel says: How dare you!\n",
          "Ariel exclaims: You insolent fool!\n",
          "Ariel says: You shall be punished for this action.\n",
          "Ariel says: Begone, or my magic will slay you.\n",
          "Ariel exlaims: Leave the library now!\n",
    }));
    guild_master -> set_gender(2);
    guild_master -> set_level(30);
    guild_master -> set_hp(3000);
    guild_master -> set_ac(30);
    guild_master -> add_class("mage");
    guild_master -> add_class("cleric");
    guild_master -> load_spells(15, ({ 
	"cure serious wounds",
          "energy drain", "meteor swarm", "comet", "burning hands",
          "chill touch", "vampiric touch", "disintegrate",
          "fire shield", "stone skin", "bless", "curse",
          "lightning bolt", "fireball", "death spell",
    }));
    guild_master -> add_spell_immunity("cold");
    guild_master -> add_spell_immunity("fire");
    guild_master -> add_spell_immunity("lightning");
    guild_master -> set_magic_resist(50);
    guild_master -> set_race("human");
    guild_master -> add_money(100 + random(1000));
    guild_master -> set_dead_ob(this_object());
    move_object(guild_master,this_object());
  }

  if(!present("robe", guild_master)) {
    robe = clone_object("d/coronos/w/angel/city/obj/wrobe");
    move_object(robe, guild_master);
    guild_master->init_command("wear robe");
  }


/*
  load_door(({
    "file", "d/affils/rooms/wrm",
    "direction", "south door",
    "long", "A fine door of sturdy oak.\n",
  }));
*/

  load_door(({
        "file", "d/sorcery/w/angel/hall2",
        "direction", "west door",
        "long",
        "A fine door of sturdy oak.\n",
  }));



  if(arg) return;


  set_short("the chambers of the white robed mages");
  set_long(
	"A single tapestry of elvish design is draped over the wall \n"+
	"to the south. Infront of it is a simple desk of white stone\n"+
	"and a soft comfortable chair, while on your right stands a \n"+
	"tall shelf bearing many books of different shapes and sizes.\n");

  set_items(({
	"tapestry#wall",
	"The tapestry on the wall depicts the great battle between the \n"+
	"One Whose Name is Spoken in Whispers and the three Guardians "+
	"of Magic.\n",

	"desk",
	"The desk is fashioned from a single piece of marble, and bears\n"+
	"several elvish runes along its side. In the centre of the line\n"+
	"of runes is the wizard mark of elvish mage and former head of \n"+
"the Nine, Ekimthanis Llore.\n",

"runes#rune", "They are of a magical nature",
"shelf",
"The shelf is nearly 12 feet tall, and contain hundreds of books",
"book#books",
"They are on simple magic for teaching new students",
  }));

  set_weather(5, 1, 0);
  set_affiliation_name("White Robe Mage");
  set_affiliation_file("wrm");
  set_skills_file("/obj/skills/affils/wrm");
  set_exits(({
	"d/sorcery/w/angel/hall2", "west",
  }));

  set_guild_name("No"); /* normal guild */
  set_classes(({
      "primary", ({ "intelligence", "wisdom", }),

      "mage",    ({
          "illusion", "charm", "conjuration", "abjuration",
          "necromancy", "evocation", "divination", "alteration",
      }),
  }));

  set_exp(({
      0,       1014,    1522,    2283,    3425,    5138,
      7707,    11561,   17341,   26012,   39018,   58527,
      87791,   131687,  197530,  296296,  444444,  666666,
      1000000, 1500000, 2000000, 2500000, 3000000, 3500000,
      4000000, 4500000, 5000000, 5500000, 6000000, 6500000,
  }));

  set_skill_exp(({
      30,      50,     75,      100,     175,     250,
      400,     600,    900,     1200,    2000,    3000,
      4500,    6500,   10000,   15000,   20000,   30000,
      50000,   75000,  100000,  125000,  150000,  175000,
      200000,  225000, 250000,  275000,  300000,  325000,
  }));

set_titles(({
      ({}), /* no neuter characters now but possible */


      /* male titles */
      ({
        "the Utter Newbie",
        "the Apprentice",
        "the Initiate",
        "the Student of Magic",
        "the Apprentice of Magic",
        "the Apprentice Magician",
        "the Magician",
        "the Apprentice Sorcerer",
        "the Sorcerer",
        "the Wizard",
        "the Wizard of the 1st Circle",
        "the Wizard of the 2nd Circle",
        "the Wizard of the 3rd Circle",
        "the Wizard of the 4th Circle",
"the Wizard of the 4th Circle",
        "the Wizard of the 5th Circle",
        "the Wizard of the 6th Circle",
        "the Wizard of the 7th Circle",
        "the Wizard of the 8th Circle",
        "the Wizard of the 9th Circle",
        "the Mage",
        "the High Mage",
        "the High Mage of the 1st Circle",
        "the High Mage of the 2nd Circle",
        "the High Mage of the 3rd Circle",
        "the High Mage of the 4th Circle",
        "the High Mage of the 5th Circle",
        "the High Mage of the 6th Circle",
        "the High Mage of the 7th Circle",
        "the High Mage of the 8th Circle",
        "the High Mage of the 9th Circle",
      }),

      /* female titles */
      ({
        "the Utter Newbie",
"the Apprentice",
        "the Initiate",
        "the Student of Magic",
        "the Apprentice of Magic",
        "the Apprentice Magician",
        "the Magician",
        "the Apprentice Sorcerer",
        "the Sorcerer",
        "the Wizard",
        "the Wizard of the 1st Circle",
        "the Wizard of the 2nd Circle",
        "the Wizard of the 3rd Circle",
        "the Wizard of the 4th Circle",
        "the Wizard of the 5th Circle",
        "the Wizard of the 6th Circle",
        "the Wizard of the 7th Circle",
        "the Wizard of the 8th Circle",
        "the Wizard of the 9th Circle",
        "the Mage",
        "the High Mage",
        "the High Mage of the 1st Circle",
"the High Mage of the 1st Circle",
        "the High Mage of the 2nd Circle",
        "the High Mage of the 3rd Circle",
        "the High Mage of the 4th Circle",
        "the High Mage of the 5th Circle",
        "the High Mage of the 6th Circle",
        "the High Mage of the 7th Circle",
        "the High Mage of the 8th Circle",
        "the High Mage of the 9th Circle",
      }),
  }));
  /*** get a new pretitle one in four levels after 30 ***/
  set_pretitles(({
      ({}), /* no neuter pretitles */

      /* male pretitles */
      ({
        "Magus",
        "Magus",
        "Magus",
        "High Magus",
        "High Magus",
        "High Magus",
        "Archmage",
        "Archmage",
        "Archmage",
      }),

      /* female pretitles */
      ({
        "Magus",
        "Magus",
        "Magus",
        "High Magus",
        "High Magus",
        "High Magus",
        "Archmage",
        "Archmage",
        "Archmage",
      }),
  })) ;
}

void init() {
  affils::init();
  guild::init();
}
