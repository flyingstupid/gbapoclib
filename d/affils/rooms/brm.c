#include <mudlib.h>
inherit AFFILIATION;
inherit GUILD;

object robe;
void quest1();
void quest2();
void reset(status arg) {
  guild::reset(arg);
  affils::reset(arg);

  if(!guild_master) {
    guild_master = clone_object(MONSTER);
    guild_master -> set_name("sol");
    guild_master -> set_short("Archmagus Sol, of the Nine");
    guild_master -> set_long(
"Sol might look innocent, but his magic and temper tantrums \n"+
"are deadly. It is said he is a genius when it comes to magic,\n"+
"for he knows more than many of his predecessors. Then again, \n"+
"it is said he killed them to get to the position on the     \n"+
"Council of the Nine"+
     "Sol is a Black Robe Mage.\n");

    guild_master -> load_chat(5, ({ 
	"Sol studies an ancient tome.\n",
        "Sol looks around the room as if he has misplaced something.\n",
        "Sol asks: Have you seen my...? ..never mind.\n",
        "Sol looks puzzled.\n",
        "Sol scratches his head.\n",
	"Sol exclaims: I'll tell my mummy on you!\n",
          "Sol asks: Have you come to study here, apprentice?\n",
          "Sol peruses a few scrolls of magic.\n",
          "Sol ponders the complexities of a magical formula.\n",
          "Sol practices a complex magical spell.\n",
    }));

    guild_master -> load_a_chat(5, ({ "Sol says: How dare you!\n",
          "Sol exclaims: You insolent fool!\n",
          "Sol says: You shall be punihed for this action.\n",
          "Sol says: Begone, or my magic will slay you.\n",
    }));
    guild_master -> set_gender(1);
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
    robe = clone_object("d/coronos/w/angel/city/obj/grobe");
    move_object(robe, guild_master);
    guild_master->init_command("wear robe");
  }


  reset_doors(arg);
  if(arg) return;

  load_door(({
	"file", "d/sorcery/w/angel/ehall1",
	"direction", "north door",
	"long",
	"A large smoky black door",
  }));


  set_short("the chambers of the black robed mages");
  set_long(
"Battle plans from many wars, both past and present hang on the \n"+
"walls of this fine office. There is definitely the cry of war  \n"+
"in this room. Suits of armour, glistening in the candle light  \n"+
"from the single black ornate candle that sits on the wide desk,\n"+
"filled with papers and plans. This is where hopeful students   \n"+
"from all over Magia come to learn from the master of the Black  \n"+
"Robes, and join the robes of alignment.\n");

  set_items(({
"papers#paper#plan#plans",
"They outline new spells and new tactics in which to employ them",

"desk", 
"A large desk of some dark black metal",

"armour#suits of armour#suits",
"Nine carefully cared for suits of full plate armour stand at \n"+
"attention at regular intervals around the room. You almost   \n"+
"expect them to come to life at any moment now!",

"candle",
"A black incense candle. The scent from it is quite delicate, \n"+
"and in quite contrast to the rest of the room. It bears the   \n"+
"initials SW in a circle of magic at its base",

"plans#battle plans",
"You catch a glimpse of one of the plans for the Ebony War.\n"+
"It makes some mention of drow bases around the tips of    \n"+
"what is now known as Ille Coronos",
  }));

  set_weather(5, 1, 0);
  set_affiliation_name("Black Robe Mage");
  set_affiliation_file("brm");
  set_skills_file("/obj/skills/affils/brm");
  set_exits(({
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
  quest1();
}

void quest1() {
  call_out("quest2", 1);
}

void quest2() {
  object ob;
  if((string)this_player()->query_current_quest() == "sol's toy") {
    if(!(ob = present("sol's toy", this_player()))) {
      write("Sol says: I see the council of Ille Coronos sent you to find my \n"+
            "          missing property. All I can tell you is that I left it\n"+
            "somewhere on Main Street. It's red and has orange and yellow stripes.\n"+
            "\nSol sighs.\n\n"+
            "Sol says: I am sure relations between the Nine here, and Ille Coronos \n"+
            "would certainly improve if you found it and returned it here.\n");
    }
    else {
      write("Sol exclaims: You found my toy!\n\n"+
            "Sol snatches away the spinning top.\n\n"+
            "Congradulations! You have completed your quest!\n");
      this_player()->finish_quest("sol's toy");
      destruct(ob);
    }
    return;
  }
}
