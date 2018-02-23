#include <mudlib.h>
inherit GUILD;
inherit MONSTER;
 
object staff;
 
void reset(status arg) {

  if(!guild_master) {
    guild_master = clone_object("inherit/monster");
    move_object(guild_master,this_object());
    guild_master->set_name("tesmond");
    guild_master->set_short("Captain Allyson, of the 12th garrison");
    guild_master->set_long(
	"Allyson joined the guard soon after Whitestarr and Shadowbane returned \n"+
	"to what is now Ille Coronos city. She has been a firm supporter of law \n"+
	"and discipline. She hopes one day to become a member of the black guard.\n");
    guild_master->set_gender(2);
    guild_master->set_race("human");
    guild_master->set_level(100);
    guild_master->add_class("fighter");
    guild_master->load_a_chat(25, ({
	"Allyson says: My guard will take care of you.\n",
	"Allyson says: You will not see the end of this day.\n",
	"Allyson exclaims: Guards! Guards! Guards!\n",
	"Allyson says: I shall slay you.\n",
    }));

    guild_master->set_magic_resist(50);

    guild_master->load_chat(10, ({
	"Allyson asks: Have you come here to train?\n",
	"Allyson asks: Have you come here to join the guard? You'll have to do some\n"+
	"	       trainning first, I think.\n",
	"Allyson says: You're a puny one. You'll need to put on some muscle.\n",
	"Allyson says: I'm quite proud of my men.\n",
	"Allyson says: Have you come here to learn the arts of warefare?\n",
	"Allyson says: If you're some kind of spellcaster you'll have to go elsewhere.\n",
    }));


  }




  

    set_guild_name("No"); /* normal guild */
    set_classes(({
     "general",        ({
       "climb", "swim",
     }),
 
     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity",
       "combat",   "constitution", "charisma",
     }),
 
 
     "fighter",        ({
       "multi attack", "multi opponent", "two weapon",
       "unarmed",     "armouring",      "weapon smith",
     }),
 
        "thief",          ({
                          "stealth", "locks", "steal", "backstab",
                          "appraisal", "traps",
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
       "the Simple Wanderer",
       "the Prominent Wanderer",
       "the Simple Rover",
       "the Prominent Rover",
       "the Famed Rover",
       "the Amateur Fighter",
       "the Skilled Fighter",
       "the Expert Fighter",
       "the Great Fighter",
       "the Famed Fighter",
       "the Amateur Warrior",
       "the Skilled Warrior",
       "the Expert Warrior",
       "the Great Warrior",
       "the Famed Warrior",
       "the Lesser Champion",
       "the Renowned Champion",
       "the Famed Champion",
       "the Amateur Swordsman",
       "the Lesser Swordsman",
       "the Prominent Swordsman",
       "the Great Swordsman",
       "the Master Swordsman",
       "the Renowned Swordsman",
       "the Famed Swordsman",
       "the Lesser Mercenary",
       "the Prominent Mercenary",
       "the Great Mercenary",
       "the Master Mercinary",
       "the Master Mercinacy"
     }),
 
     /* female titles */
     ({
       "the Utter Newbie",
       "the Simple Wandereress",
       "the Prominent Wandereress",
       "the Simple Rover",
       "the Prominent Rover",
       "the Famed Rover",
       "the Amateur Fighter",
       "the Skilled Fighter",
       "the Expert Fighter",
       "the Great Fighter",
       "the Famed Fighter",
       "the Amateur Warrior",
       "the Skilled Warrior",
       "the Expert Warrior",
       "the Great Warrior",
       "the Famed Warrior",
       "the Lesser Champion",
       "the Renowned Champion",
       "the Famed Champion",
       "the Amateur Swordswoman",
       "the Lesser Swordswoman",
       "the Prominent Swordswoman",
       "the Great Swordswoman",
       "the Master Swordswoman",
       "the Renowned Swordswoman",
       "the Famed Swordswoman",
       "the Lesser Mercenary",
       "the Prominent Mercenary",
       "the Great Mercenary",
       "the Master Mercinary"
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
 
 
void summon_staff() {
    if(!staff) return;
    tell_object(environment(staff),"Allyson summons his staff.\n");
    destruct(staff);
    reset(1);
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
    tell_object(ob,"Allyson is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}
 

