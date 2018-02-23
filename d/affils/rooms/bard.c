#include <mudlib.h>
inherit GUILD;
#define GUILD_OB	"obj/skills/classes/bard"
object staff;

void reset(status arg) {


  if(!guild_master) {
     guild_master = clone_object(MONSTER);
     move_object(guild_master,this_object());
     guild_master -> set_name("jacques");
     guild_master -> set_short("Jacques, the Master Bard");
     guild_master -> set_long(
	"Jacques has been a lecturer here within the university for some  \n"+
	"years now, passing on the knowledge he has gained over the years\n"+
	"wandering the Middle Realms of Magia in search of knowledge.    \n"+
	"Perhaps if he thought you worthy, he might take you under his wing\n"+
	"and teach you also.\n");

     guild_master -> set_gender(1);
     guild_master -> set_race("human");
     guild_master -> set_level(50);
     guild_master -> add_class("cleric");
     guild_master -> add_class("fighter");
     guild_master -> add_class("bard");

     guild_master->load_chat(4,({ 
	"Jacques says: The way to knowledge is through yourself.\n",
	"Jacques ponders the complexities of the universe.\n",
	"Jacques says: Have you come here to learn?\n",
	"Jacques studies the history of Ille Coronos.\n",
	"Jacques asks: Did you know that Ille Coronos was built on the ruins\n"+
	"\tof the city WhiteStarr?\n",
	"Jacques asks: Did you know that WhiteStarr was a famous Lore Master\n"+
	"\twho worshipped Antaaries?\n",
	"Jacques asks: Did you know that Ille Coronos means 'the Circle'?\n",
     }));

     guild_master->load_a_chat(10, ({
	"Jacques says: That's not a good idea.\n",
	"Jacques says: I wouldn't recommend doing that.\n",
	"Jacques says: Don't do that.\n",
     }));

     guild_master->set_magic_resist(50);
  }

  if(arg) return;
  set_short("the University of Power");
  set_exits(({
         "d/coronos/w/angel/city/univ/library1", "south",
  }));

  set_long(
	"A tall archway marks the way into this large amphitheatre.  \n"+
	"Long rows of benches span the width of the room before the  \n"+
	"small wooden podium at the front. A large chalk board stands\n"+
	"quietly before it, several shelves of large books at either \n"+
	"side. \n");

  set_items(({
	"archway", "The archway is lined with various runes.\n",
	"runes",   "The runes appear magical in nature.\n",

	"rows#benches",
	"The benches appear very uncomfortable, but should seat about "+
	"two hundred people.\n",

	"chalk board#board",
	"The chalk board appears to have some writing on it, but it's\n"+
	"terribly difficult to read from all the way at the back of the room\n",

	"writing#words",
	"As you squint, trying to focus on the board, you believe the words\n"+
	"are about history, quite possibly of the city Ille Coronos.\n",

	"podium",
	"It seems like an excellent vantage point to conduct lectures.\n",

	"shelf#shelves",
	"The shelves appear quite old, and are almost falling to pieces.\n",
	"book#books",
	"The books appear just as old as the shelves",
  }));
  set_weather(2, 1, 0);
  set_guild_name("the scholarly bards");
  set_races(({ "all", }));
  
  set_classes(({
     "general",        ({
       "climb", "swim",
     }),

     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity", 
       "combat",   "constitution", "charisma",
     }),


     "bard",        ({
       "song", "steal", "linguistics", 
       "two weapon", "appraisal", "history", 
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
        "the Simple Rhymer",
        "the Lyrist",
        "the Sonnateer",
        "the Skald",
        "the Simple Racaraide",
        "the Skilled Racaraide",
        "the Simple Joungleur",
        "the Skilled Joungleur",
        "the Famed Joungleur",
        "the Simple Troubador",
        "the Skilled Troubador",          
        "the Famed Troubador",          
        "the Simple Minstrel",          
        "the Skilled Minstrel",          
        "the Famed Minstrel",          
        "the Simple Muse",         
        "the Skilled Muse",     
        "the Famed Muse",      
        "the Simple Lorist",
        "the Skilled Lorist",
        "the Famed Lorist",
        "the Master Lorist",    
        "the Lecturer",    
        "the Master Lecturer",  
        "the Academic",
        "the Master Academic",  
        "the Master Scholar",   
        "the Bard",  
        "the Master Bard",   
      }),

      /* female titles */
      ({
        "the Utter Newbie",
        "the Simple Rhymer",
        "the Lyrist",
        "the Sonnateer",
        "the Skald",
        "the Simple Racaraide",
        "the Skilled Racaraide",
        "the Simple Joungleur",
        "the Skilled Joungleur",
        "the Famed Joungleur",
        "the Simple Troubador",
        "the Skilled Troubador",          
        "the Famed Troubador",          
        "the Simple Minstrel",          
        "the Skilled Minstrel",          
        "the Famed Minstrel",          
        "the Simple Muse",         
        "the Skilled Muse",     
        "the Famed Muse",      
        "the Simple Lorist",
        "the Skilled Lorist",
        "the Famed Lorist",
        "the Master Lorist",    
        "the Lecturer",    
        "the Master Lecturer",  
        "the Academic",
        "the Master Academic",  
        "the Master Scholar",   
        "the Bard",  
        "the Master Bard",   
      }),
  }));
  /*** get a new pretitle one in four levels after 30 ***/
  set_pretitles(({
      ({}), /* no neuter pretitles */

      /* male pretitles */
      ({
        "Lord",
      }), 

      /* female pretitles */
      ({
        "Lady",
      }),
  })) ;

}



void init() {
  if((string)this_player()->query_guild_string() ==
     (string)this_object()->query_guild_name()) {
     if(!present("guild_object", this_player()))
       move_object(clone_object(GUILD_OB),this_player());
  }
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
    tell_object(ob,"Jacques is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}

status leave(string str) {
  object obj;

  if(str != "bard") {
    write("Jacques says: Leave what?\n");
    return 1;
  }
  if(!this_player()->query_class("bard")) {
    write("Jacques says: Only bard can leave his profession here.\n");
    return 1;
  }
  if(query_guild_name() != (string)this_player()->query_guild_string()) {
    write("Jacques says: Only "+query_guild_name()+" can do that here.\n");
    return 1;
  }

  obj = present("guild_object", this_player());
  if(obj) destruct(obj);
  obj = this_player()->query_bard_aura_object();
  if(obj) destruct(obj);
  this_player()->save_me(1);
  ::leave(str);
  return 1;
}



