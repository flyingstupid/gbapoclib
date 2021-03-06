/* The University of Power
 * 
 * This lecture theatre supports training of wizards up to the level of 10.
 * This is therefore designed to give players a bit of magic use if they
 * so desire. 
 *
 * After level 10 they must seek the Isle of Sorcery and find a sponsor to
 * teach them magic after that stage.
 */
#include <mudlib.h>
inherit GUILD;

object staff;
void monster_died();
void reset(status arg) {

  if(!guild_master) {
    guild_master = clone_object(MONSTER);
    guild_master -> set_name("riannon");
    guild_master -> set_short("Magus Riannon, the wise");
    guild_master -> set_long(
     "Riannon is one of the tutors here at the university, hand picked \n"+
     "by Chancelor Damon himself. She is here, waiting for her students\n"+
     "so her lectures on basic conjuration, mathemagics, wild magic, and\n"+
     "the dangers of the unskilled mage can begin.\n");
    guild_master -> load_chat(5, ({ "Riannon looks over her notes.\n",
	"Riannon asks: Have you come here to learn or to ask questions?\n",
	"Riannon gathers together a few spell components.\n",
	"Riannon says: Be seated so the lecture can begin.\n",
	"Riannon asys: Stop talking and sit down.\n",
	"Riannon asks: Are you sure you want to learn magic?\n",
	"Riannon asys: If you want to learn magic you've come to the right "+
		"teacher.\n",
	"Riannon asks: Do you know anything about magic?\n",
	"Riannon prepares a spell.\n",
	"Riannon looks over her lecture material.\n",
    }));

    guild_master -> load_a_chat(5, ({ "Riannon says: How dare you!\n",
          "Riannon exclaims: You insolent fool!\n",
          "Riannon says: You shall be punished for this action.\n",
          "Riannon says: Begone, or my magic will slay you.\n",
          "Riannon exlaims: Leave the lecture theatre now!\n",
    }));
    guild_master -> set_gender(2);
    guild_master -> set_level(30);
    guild_master -> set_hp(3000);
    guild_master -> set_ac(30);
    guild_master -> add_class("mage");
    guild_master -> add_class("cleric");
    guild_master -> load_spells(15, ({ "cure serious wounds",
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
  if(!present("staff", guild_master)) {
    staff = clone_object(MAGIC_WEAPON);
    staff -> set_name("staff");
    staff -> set_wc(15); /* +3 staff */
    staff -> set_length(80);
    staff -> set_weight(6);
    staff -> set_value(4000); /* because of enchantments */
    staff -> set_type("crush");
    staff -> set_enchanted(1);
    staff -> set_short("An old gnarled staff");
    staff -> set_long(
               "This staff has seen many battles, evident by the number \n"+
               "of scorch marcks, and nicks along the length of the wood.\n");
    staff -> add_spell("fire ball");
    staff -> add_spell("detect magic");
    staff -> add_spell("lt");
    staff -> add_spell("dispel magic");
    staff -> set_class(({ "mage", }));
    staff -> set_max_charges(100);
    staff -> set_charges(100);
    staff -> set_cast_level(20);
    staff -> set_info(
               "Bigby's staff of the magi.\n"+
               "@@query_charges_string:$this_object()$@@"+
               "@@query_classes:$this_object()$@@"+
               "@@query_spell_triggers:$this_object()$@@");
    move_object(staff, guild_master);
    command("wield staff", guild_master);
    guild_master -> set_wc(35);
  }

  if(arg) return;
  set_short("the university's lecture theatre");
  set_long(
     "Tall shelves of dark ancient hardwood extend toward the     \n"+
     "lengthy shadows that mask the high comed ceiling above.     \n"+
     "Thousands of old tomes, books, scrolls and old parchments   \n"+
     "line the shelves; the tools that aid the wizard in his      \n"+
     "studies to achieve excelence in the arts of magic. Any      \n"+
     "wisened apprentice would find this library invaluable in    \n"+
     "his training in magic. A long oil lamp stands on a large    \n"+
     "bench at the front of the room, behind rows of old wooden   \n"+
     "seats and desks surrounding the bench like an ampitheatre.  \n");

  set_items(({
     "bench", "It looks like a work bench, but also has a podium.\n",
     "podium", "Who ever works here obvious gives lectures behind it",
     "seat#seats", 
	"The small wooden seats look rather painful to sit on for any \n"+
	"great length of time. They surround the lecture podium.\n",
     "desks#desk",
	"Students listenning to lecuters here use them to write upon",
     "shelf#shelves",
          "The shelves are made of a dark red wood, possibly even  \n"+
          "some sort of enchanted ceader, protecting their contents\n"+
          "from the passing of time, or possible tragedy",

     "tomes#old tomes",
          "Tomes of magical formula date back to the times of foundation\n"+
          "of this library; back when the Council of High Magic built "+
          "this tower",
     "oil lamp#lamp",
          "The lamp gives off enough light to study and read by",
     "desk#study desk",
          "A large desk, made of the same wood that the shelves were \n"+
          "carved from. The surface has been polished to a high sheen",
     "book#books",
          "Spidery runes of magic protect their spines not only from the \n"+
          "dangers of time and the elements, but from the prying eyes of \n"+
          "those who are not allowed to view their contents",
     "parchments#parchment",
          "Ancient parchments listing various methods of spell casting",
     "shadows#shadow",
          "It covers the ceiling in darkness",
     "darkness",
          "It is black",
     "ceiling#domed ceiling",
          "It is covered with long shadows",
  }));

  set_races(({
	"human", "half elf", "high elf", "grey elf", "gray elf", "gnome",
	"orc", "storm giant", "cloud giant", 
	"minotaur", "dark elf", "pixie", "nixie", }));

  set_exits(({
	"d/coronos/w/angel/city/univ/room1", "down",
  }));

  set_weather(2, 1, 0);
  set_guild_name("No"); /* normal guild */
  set_classes(({
      "general", ({ "climb", "swim",          }),
      "primary", ({ "intelligence", "wisdom", }),

/* not on your life !
     "fighter",        ({
       "multi attack", "multi opponent", "two weapon",
       "unarmed",     "armouring",      "weapon smith",
    }),
*/
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
    if(guild_master) {
     object attacker;
     if((attacker = (object)guild_master->query_primary_attack())) {
         if(present(attacker, this_object())) {
          call_out("no_guild_mess",1,this_player());
          return;
         }
     }
    }
    ::init();
    add_action("advance", "advance");
    add_action("advance", "train");
}

status advance(string str, status arg) {
  object ob;
  ob = this_object()->query_guild_master();
  if((int)this_player()->query_level() > 10) {
    write(ob->query_name()+" says: You had better seek the Masters\n"+
	"\tin the Tower of High Sorcery. I can't train you any more.\n");
    return 1;
  }
  ::advance(str, arg);
  return 1;
}



void no_guild_mess(object ob) {
    tell_object(ob,"Bigby is busy defending himself.\n");
    tell_object(ob,"He is too busy to teach anybody.\n");
}

void monster_died() {
  object corpse;

  corpse = present("corpse", this_object());
  tell_room(environment(), "Bigby begins to chant in an ancient language.\n"+
     "Bigby vanishes in a puff of smoke!\n"+
     "Bigby's staff falls to the ground.\n");
  if(corpse) destruct(corpse);
  return;
}

