#include <mudlib.h>
inherit GUILD;

object staff;

void reset(status arg) {
    if(!guild_master) {
     guild_master = clone_object(MONSTER);
     move_object(guild_master,this_object());
     guild_master->set_name("finnias");
     guild_master->set_short("Finnias the Sailor");
     guild_master->set_long(
	"Finnias is a heardy sailor who trainned himself to survive the \n"+
	"horrors of the sea. Perhaps if you ask him, he may teach you a \n"+
	"trick or two?\n");
     guild_master->set_gender(1);
     guild_master->set_race("human");
     guild_master->set_level(100);
     guild_master->add_class("fighter");
     guild_master->load_chat(20, ({
	"Finnias says: I am well versed in many general skills.\n",
	"Finnias says: Would you like to learn how to swim?\n",
	"Finnias says: I can teach you to swim if you would like.\n",
	"Finnias smiles happily.\n",
	"Finnias asks: Do you know how to swim?\n",
	"Finnias says: I can train you to swim.\n",
	"Finnias asks: Do you need trainning in swimming?\n",
    }));


     guild_master->load_a_chat(25,({ 
	"Finnias says: The sea never dealt me a blow like that.\n",
	"Finnias says: You are fouler than a seadragon.\n",
	"Finnias says: Be gone, foul land lubber.\n",
       }));
     guild_master->set_magic_resist(50);
     guild_master->set_spells(({
         "name",       "lightning hands",
         "level",      15,
         "damage",     40,
         "immune",     "lightning",
         "msg target", "You feel an electric shock as @@query_name:"+
         "$this_player()$@@ hits you.\n",
         "msg_room",    "@@query_name:$this_object()$@@ is thrown back by "+
         "an electric shock as @@query_name:"+
         "$this_player()$@@ hits "+
         "@@query_possessive:$this_object()$@@.\n",
         "msg caster",  "Your hands tingle when you hit "+
         "@@query_name:$this_object()$@@.\n",
       }));
    }
    if(arg) return;
   set_short("the Ille Coronos docks");
   set_long(
      "You are just south of a long stretch of stone that extends\n"+
      "outward from the beach, down to a set of large pylons. Here,\n"+
      "as the waves crash against the beach, and the sea gulls squawk\n"+
      "noisly, the great merchant ships bring their cargo to sell in\n"+
      "the markets of Ille Coronos.\n"
   );
   set_weather(1, 4, 6);
   set_smell("The air smells very salty.\n");
   set_listen("The waves crash against the beach close by.\n");
   set_exits(({
      "/d/coronos/w/angel/city/docks/dock1", "northeast",
	"d/coronos/w/chi/city/streets/dock3", "southwest",
   }));


    set_guild_name("Any"); /* allows people to learn SWIM here ONLY */
    set_classes(({
     "general",        ({
       "climb", "swim",
     }),

/*
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
    tell_object(environment(staff),"Finnias summons his staff.\n");
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
    tell_object(ob,"Finnias is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}

