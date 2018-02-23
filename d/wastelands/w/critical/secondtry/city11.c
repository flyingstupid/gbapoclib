#include <mudlib.h>
inherit GUILD;
 
object staff;
 
void reset(status arg) {

  if(!guild_master) {
    guild_master = clone_object("inherit/monster");
    move_object(guild_master,this_object());
    guild_master->set_name("Erica");
    guild_master->set_short("Erica, The Waste Runner Legend");
    guild_master->set_long(
	"Erica is a legend amoung the Waste Runners, its said that she was one of\n"+
	"three to retreived the generator that this city is built around. If anyone\n"+
	"could ever get her to talk about her old days, the stories she could tell...\n");
    guild_master->set_gender(2);
    guild_master->set_race("human");
    guild_master->set_level(20);
    guild_master->add_class("pointman");
    guild_master->add_class("scout");
    guild_master->add_class("medic");
    guild_master->add_class("techman");
    guild_master->load_a_chat(25, ({
	"Erica says: They will never find your body.\n",
	"Erica says: You will not see the end of this day.\n",
	"Erica exclaims: Time you die!\n",
	"Erica says: I am going to end you.\n",
    }));

    guild_master->set_magic_resist(50);

    guild_master->load_chat(1, ({
	"Erica asks: Have you come here to train?\n",
	"Erica says: You look like you could use a workout.\n",
	"Erica says: I'm quite proud of our citizens.\n",
	"Erica says: Have you come to learn the art of waste running??\n",
	"Erica says: Not matter what you do, I can tell you how to do it.\n",
    }));


  }




  if(arg) return;
    set_short("Second Chance's Training Center");
 
    set_long(
	"The training center of Second Chance is filled with an assortment of strange\n"+
	"devices, along side weapons and armor, with a blend of first aid dummies.  \n"+
	"Everyone around town comes here at some point to learn useful skills to work\n"+
	"around town and even the Waste Runner's can be seen training for another grab.\n");

     

 
    set_exits(({   
	"/d/wastelands/w/critical/secondtry/city10", "south",
    }));
    set_weather(2, 0, 0);

    set_guild_name("No"); /* normal guild */
    set_classes(({
     "general",        ({
       "climb", "swim", "healing", "mining",
     }),
 
     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity",
       "combat",   "constitution", "charisma",
     }),
 
 
     "pointman",        ({
       "multi attack", "multi opponent", "two weapon",
       "unarmed",     "fighting", "protecting", "preparing",
     }),
 
        "scout",          ({
                          "stealth", "locks", "backstab",
                          "traps", "exploring", "surviving", "evading"
                    }),
 
        "medic",         ({
                      "mhealing", "enhancing", "preventing",
                    }),
 
        "techman", ({
                      "sensing", "destroying", "creating"
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
    tell_object(environment(staff),"Erica grabs her staff.\n");
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
    tell_object(ob,"Erica is busy defending herself.\n");
    tell_object(ob,"She is too busy to train anybody.\n");
}
 

