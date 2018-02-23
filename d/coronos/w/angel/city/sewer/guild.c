#define PATH	"d/coronos/w/angel/city/sewer/"

/* thieves guild */

#include <mudlib.h>
inherit GUILD;

void reset(status arg) {
  object dagger, leather, staff;

if(!present("board")) {
  object board;
  board = clone_object(BULLETIN_BOARD);
  board -> set_save_file("ob_saves/boards/thief");
  move_object(board,this_object());
}
  if(!guild_master) {
    guild_master = clone_object("inherit/monster");
    guild_master->set_name("sarak");
    guild_master->set_short("Sarak the Grand Master Thief");
    guild_master->set_long(
     "Sarak is tall, lean and muscley. His narrow shifty eyes  \n"+
     "watch you carefully as you wander about the room. He is the  \n"+
     "head trainer here in the den. The only thing worse than his \n"+
     "gaze is the pain of his dagger.\n");
    guild_master->set_race("human");
    guild_master->set_level(15);
    guild_master->set_hp(1000);
    guild_master->set_al(-100);
    guild_master->set_chance(10);
    guild_master->set_spells(({
      "target msg", "@@query_name:$this_player()$@@'s poisoned dagger "+
                    "cuts you deeply...",
      "room msg",   "@@query_name:$this_player()$@@'s poisoned dagger "+
                    "cuts @@query_name:$this_object()$@@ deeply...",
      "immune",     "poison",
      "damage",     100,
    }));
    guild_master->add_spell_immune("poison");
    guild_master->load_a_chat(12, ({ "Sarak says: You will die!\n" }));
    guild_master->load_chat(5, ({ "Sarak says: Have you come to train?\n" }));
    guild_master->set_ac(12);
    guild_master->set_wc(20);
    move_object(guild_master, this_object());
  }
  if(!present("dagger", guild_master)) {
    dagger  = clone_object("inherit/weapon");
    dagger -> set_name("dagger");
    dagger -> set_short("A jeweled dagger");
    dagger -> set_long("This dagger is long and thin, with many jewels \n"+
                       "encrusted into its golden hilt.\n");
    dagger -> set_length(16);
    dagger -> set_type("slash");
    dagger -> set_wc(10);       /* +2 dagger!! */
    dagger -> set_enchanted(1);
    dagger -> set_weight(3);
    dagger -> set_value(800);
    move_object(dagger, guild_master);
    guild_master->init_command("wield dagger");
  }
  if(!present("leather", guild_master)) {
    leather = clone_object("inherit/armour");
    leather -> set_name("leather");
    leather -> set_ac(2);
    leather -> set_weight(3);
    leather -> set_value(400);
    leather -> set_armour_material("leather");
    leather -> set_short("Black leather armour");
    leather -> set_long(
          "A suit of black leather armour, made from the hide of \n"+
          "some sort of great cat, most likely a panther. The    \n"+
          "hide is soft and smooth, yet strong and flexible.     \n");
    leather -> set_type("armour");
    move_object(leather, guild_master);
    guild_master -> init_command("wear leather");
  }
  if(arg) return;
  set_short("The Den of Thieves");
  set_long(
     "Scattered about the large wooden crates are small dummies \n"+
     "with small bells sewn into the fabric of their long rich  \n"+
     "clothing. Long ropes of differing ticknesses that hang    \n"+
     "from the ceiling knotted for climbling. Doors with large  \n"+
     "brass nobs, traps and trip wires attached to them stand   \n"+
     "in frames about the room. This is obviously some training \n"+
     "room for those with the gift of nimble fingers - the den  \n"+
     "of the cities thieves. Attached to one crate is a large   \n"+
     "piece of paper of some sort.\n");

  set_items(({
     "crate#crates", "Several crates of assorted items lie scattered \n"+
                     "about the room, loaded with assorted illegal   \n"+
                     "items for the express purpose of pleasing the  \n"+
                     "grand master thief who trains young thieves here",

     "door#doors",   "Doors that thieves test their lock and trap "+
                     "skills on",

     "rope#ropes",   "Several knotted ropes hang from the ceiling to  \n"+
                     "young thieves in their climbing skills",

     "traps#trip wires#wire#nobs#brass nobs#nob",
                     "These are all rigged into the traps on the doors \n"+
                     "to aid young thieves in their training",
  }));
  set_weather(2, 1, 0);
  set_exits(({ PATH+"tunnel9", "north", }));
  set_guild_name("No"); /* normal guild */
  set_classes(({
   "general",        ({
                       "climb", "swim",
                     }),

   "primary",        ({
                       "dexterity", "charisma",
/* can't raise these here....
                       "strength", "combat", "constitution",
                       "intelligence", "wisdom",
 */
                     }),

   "thief",          ({
                       "stealth", "locks", "steal", "backstab",
                        "appraisal", "disguise", "traps",
                     }),

/* these are alternatives....

   "fighter",        ({
                       "multi attack", "multi opponent", "two weapon",
                       "unarmed",     "armouring",      "weapon smith",
                     }),

   "cleric",         ({
                       "healing sphere", "necromancy sphere", "combat sphere",
                       "stellar sphere", "protection sphere", "nature sphere",
                       "divination sphere",
                     }),

   "mage",           ({
                       "illusion", "charm", "conjuration", "abjuration",
                       "necromancy", "evocation", "divination", "alteration",
                     }),
 */
  }));
  set_exp(({
                  0,    1014,    1522,    2283,    3425,    5138,
               7707,   11561,   17341,   26012,   39018,   58527,
              87791,  131687,  197530,  296296,  444444,  666666,
            1000000, 1500000, 2000000, 2500000, 3000000, 3500000,
            4000000, 4500000, 5000000, 5500000, 6000000, 6500000,
  }));
  set_skill_exp(({
                 30,      50,      75,     100,     175,     250,
                400,     600,     900,    1200,    2000,    3000,
               4500,    6500,   10000,   15000,   20000,   30000,
              50000,   75000,  100000,  125000,  150000,  175000,
             200000,  225000,  250000,  275000,  300000,  325000,
  }));
  set_titles(({ 
               ({}), /* no neuter characters now but possible */


 /* male titles */
           ({
          "the Utter Newbie",
          "the Apprentice Rogue",
          "the Aspiring Rogue",
          "the Apprentice Footpad",
          "the Aspiring Footpad",
          "the Master Footpad",
          "the Apprentice Locksmith",
          "the Aspiring Locksmith",
          "the Master Locksmith",
          "the Apprentice Cutpurse",
          "the Aspiring Cutpurse",
          "the Master Cutpurse",
          "the Apprentice Robber",
          "the Aspiring Robber",
          "the Master Robber",
          "the Apprentice Burglar",
          "the Aspiring Burglar",
          "the Master Burlgar",
          "the Apprentice Filcher",
          "the Aspiring Filcher",
          "the Master Filcher",
          "the Apprentice Sharper",
          "the Aspiring Sharper",
          "the Master Sharper",
          "the Apprentice Magsman",
          "the Aspiring Magsman",
          "the Master Magsman",
          "the Aspiring Thief",
          "the Master Thief",
          "the Master Thief",
           }),

          /* female titles */
           ({
          "the Utter Newbie",
          "the Apprentice Rogue",
          "the Aspiring Rogue",
          "the Apprentice Footpad",
          "the Aspiring Footpad",
          "the Master Footpad",
          "the Apprentice Locksmith",
          "the Aspiring Locksmith",
          "the Master Locksmith",
          "the Apprentice Cutpurse",
          "the Aspiring Cutpurse",
          "the Master Cutpurse",
          "the Apprentice Robber",
          "the Aspiring Robber",
          "the Master Robber",
          "the Apprentice Burglar",
          "the Aspiring Burglar",
          "the Master Burlgar",
          "the Apprentice Filcher",
          "the Aspiring Filcher",
          "the Master Filcher",
          "the Apprentice Sharper",
          "the Aspiring Sharper",
          "the Master Sharper",
          "the Apprentice Magsman",
          "the Aspiring Magsman",
          "the Master Magsman",
          "the Aspiring Thief",
          "the Master Thief",
	  "the Master Thief",
           }),
  }));

  /*** get a new pretitle one in four levels after 30 ***/
  set_pretitles(({
                  ({}), /* no neuter pretitles */

                   /* male pretitles */
                  ({
                        "Captain",
                          "Major",
                        "Colonel",
                        "General",
                       "Marshall",
                "Knight Marshall",
                            "Sir",
                           "Lord",
                        "Baronet",
                          "Baron",
                       "Viscount",
                          "Count",
                        "Marquis",   
                           "Duke",
                     "Grand Duke",
                       "Archduke",
                         "Prince",
                   "Crown Prince",
                           "King",
                        "Emperor",
                       "Overlord",
             }),

                 /* female pretitles */
             ({
                        "Captain",
                          "Major",
                        "Colonel",
                        "General",
                       "Marshall",
                "Knight Marshall",
                         "Madame",
                           "Lady",
                        "Baronet",
                       "Baroness",
                    "Viscountess",
                       "Countess",
                       "Marquise",   
                        "Duchess",
                  "Grand Duchess",
                    "Archduchess",
                       "Princess",
                 "Crown Princess",
                          "Queen",
                        "Empress",
                       "Overlady",
            }),
  }));
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
}


void no_guild_mess(object ob) {
  if(!ob) return;
  tell_object(ob, guild_master->query_name() +" is busy defending "+
                  guild_master->query_possessive() +"self.\n");
  tell_object(ob,capitalize((string)guild_master->query_possessive()) +
                 " is too busy to train anybody.\n");
}


