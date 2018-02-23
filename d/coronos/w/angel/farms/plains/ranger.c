#include <mudlib.h>
inherit GUILD;
#define GUILD_OB	"obj/skills/classes/ranger"
object staff;

void reset(status arg) {
  if(!guild_master) {
     guild_master = clone_object(MONSTER);
     move_object(guild_master,this_object());
     guild_master->set_name("mirrin");
     guild_master->set_short("Mirrin, the Ranger");
     guild_master->set_long(
	"Mirrin, or Jack to his friends, is a middle aged      \n"+
	"man whose eyes reflect the wisdom of learning and     \n"+
	"experience. Jack's knowledge of the land is famous    \n"+
	"throughout the lands of Ille Coronos, and the northern\n"+
	"lands of Magia. Jack has been known to pass on his    \n"+
	"knowledge from time to time.\n");

     guild_master->set_gender(1);
     guild_master->set_race("human");
     guild_master->set_level(50);
     guild_master->add_class("ranger");
     guild_master->add_class("fighter");

     guild_master->load_chat(4,({ 
	"Mirrin asks: Have you seen Spotty Dog?\n",
	"Mirrin surveys the land with satisfaction.\n",
	"Mirrin says: This is fine farming land.\n",
	"Mirrin investigates some nearby tracks.\n",
	"Mirrin says: Be careful, my friend. Drow are close by.\n",
     }));

     guild_master->load_a_chat(20, ({
	"Mirrin says: Spotty Dog won't be pleased with this.\n",
	"Mirrin dodges your blow skillfully.\n",
	"Mirrin sidesteps your attack.\n",
     }));


     guild_master->set_magic_resist(50);
  }

  if(arg) return;
  set_short("the elfin forest");
  set_exits(({
	"d/affils/rooms/antaaries", "north",
	"d/coronos/w/angel/scanthian/new2", "south",
  }));
  set_long(
  "The forest here is lush and green, and reminds you of a far off land \n"+
  "where peace and tranquility abound. There is a small clearing here \n"+
  "which looks as though it has been recently used.\n");

  set_weather(2, 0, 0);
  set_guild_name("the rangers of the forest"); /* normal guild */
  set_races(({ "hill dwarf", "human", "halfling", "forest gnome",
    "grey elf", "half elf", "wood elf", "high elf", "dark elf",
    "gray elf", "wild elf", /* just in case *wink* */
  }));
  
  set_classes(({
     "general",        ({
       "climb", "swim",
     }),

     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity", 
       "combat",   "constitution", "charisma",
     }),


     "ranger",        ({
       "multi attack", "multi opponent", "two weapon",
       "bowyer",
	"nature sphere", "conjuration", "charm", "tracking",
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
	"the Lesser Runner",
	"the Amateur Runner",
	"the Prominent Runner",
	"the Amateur Strider",
	"the Prominent Strider",
	"the Renowned Strider",
	"the Amateur Scout",
	"the Prominent Scout",
	"the Renowned Scout",
	"the Amateur Courser",
	"the Prominent Courser",
	"the Renowned Courser",
	"the Amateur Tracker",
	"the Prominent Tracker",
	"the Renowned Tracker",
	"the Amateur Guide",
	"the Prominent Guide",
	"the Renowned Guide",
	"the Amateur Pathfinder",
	"the Prominent Pathfinder",
	"the Renowned Pathfinder",
	"the Amateur Woodsman",
	"the Prominent Woodsman",
	"the Renowned Woodsman",
	"the Amateur Ranger",
	"the Prominent Ranger",
	"the Renowned Ranger",
	"the Keeper of the Forest",
	"the Guardian of the Forest",
     }),

     /* female titles */
     ({
"the Lesser Runner",
"the Amateur Runner",
"the Prominent Runner",
"the Amateur Strider",
"the Prominent Strider",
"the Renowned Strider",
"the Amateur Scout",
"the Prominent Scout",
"the Renowned Scout",
"the Amateur Courser",
"the Prominent Courser",
"the Renowned Courser",
"the Amateur Tracker",
"the Prominent Tracker",
"the Renowned Tracker",
"the Amateur Guide",
"the Prominent Guide",
"the Renowned Guide",
"the Amateur Pathfinder",
"the Prominent Pathfinder",
"the Renowned Pathfinder",
"the Amateur Woodswoman",
"the Prominent Woodswoman",
"the Renowned Woodswoman",
"the Amateur Ranger",
"the Prominent Ranger",
"the Renowned Ranger",
"the Keeper of the Forest",
"the Guardian of the Forest",

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
     }),
  }));
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
    tell_object(ob,"Mirrin is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}

status leave(string str) {
  object obj;

  if(str != "ranger") {
    write("Mirrin says: Leave what?\n");
    return 1;
  }
  if(!this_player()->query_class("ranger")) {
    write("Mirrin says: Only ranger can leave his profession here.\n");
    return 1;
  }
  if(query_guild_name() != (string)this_player()->query_guild_string()) {
    write("Mirrin says: Only "+query_guild_name()+" can do that here.\n");
    return 1;
  }

  obj = present("guild_object", this_player());
  if(obj) destruct(obj);
  obj = this_player()->query_ranger_aura_object();
  if(obj) destruct(obj);
  this_player()->save_me(1);
  ::leave(str);
  return 1;
}



