/* barn1.c -- newbie 
 * Darkness and Newstar 
 *
 * Convered into a horsemanship guild room - Angel Dec 1998 
 */

#include <mudlib.h>

#define CHA             (int)this_player()->query_charisma() + \
                        (int)this_player()->query_appraisal()

#define MY_STAT         20

inherit GUILD;

void reset (status arg){

    if(!guild_master) {
      guild_master = clone_object(MONSTER);
      move_object(guild_master,this_object());
      guild_master -> set_name("alex");
      guild_master ->   set_short("Alex, the farm hand");
      guild_master ->   set_long(
	"Alex has been hired from Ille Coronos to tend to the stables. \n"+
	"While he appears a little young, he is excellent at tending to\n"+
	"the needs of the horses and other animals here. He has also been\n"+
	"known to train people in the art of riding, from time to time.\n");

    guild_master -> set_race("human");
    guild_master -> load_chat(5, ({
	"Alex asks: Did you come to learn to ride?\n",
	"Alex says: I ride horses quite well.\n",
	"Alex sweeps the floor.\n",
	"Alex smiles happily.\n",
	"Alex asks: Can you ride a horse?\n",
    }));

    guild_master ->   set_magic_resist(200); 
    guild_master ->   set_level(12); 
  }

  if(!present("barrel")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/barrel"),this_object());
  }

  if(!present("stallion")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/stallion"),this_object());
  }

  if(!present("mare")) {
    int i;
    for(i=0; i<2; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/mare"),this_object());}
  }

  if(!present("pony")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/pony"), this_object());
  }

  if(arg) return;

  set_short("inside a barn");

  set_long(
    "This is a fairly simple barn.  It has a single, large room with\n"+
    "various seperations for animals, feed, and other equipment.  A\n"+
    "ladder leads to a small loft where excess hay is kept.  There\n"+
    "is a window, level with the loft, that is used to haul up the hay.\n"+
    "A small barrel, in which lanterns are usually stored, stands at\n"+
    "the foot of the ladder.  The heavy barn doors are partially open,\n"+
    "swinging back and forth in the wind.\n");  

  set_items(({
    "barn#room",
      "The barn is large but simple.  It is well\n"+
      "kept and in good condition.\n",
    "seperations#seperation#fences#fence#partitions",
      "Several areas are partitioned with wooden fences to seperate\n"+
      "animals, such as horses, pigs and goats.  A few other partitions\n"+
      "hold hay, bags of chicken feed, and other such items.\n",
    "animals#animal",
      "Many different animals can be kept in this barn.\n",
    "hay",
      "The hay is fresh and clean for the animals to eat.\n"+
      "There is a large pile of hay below the loft.\n",
    "pile",
      "The pile of hay is quite tall.  It looks soft and comfortable.\n",
    "chicken feed#feed",
      "The chicken feed is fresh and nutritious for the chickens.\n",
    "ladder",
      "The ladder is sturdy, but its rungs look well worn from much\n"+
      "use. Don't fall if you try and climb it.  You might hurt yourself.\n",
    "loft#up",
      "Up above, is a small loft used for storing excess hay.  It can't\n"+
      "really be inspected from ground level, but you notice a ladder\n"+
      "leading up to the loft.\n",
    "window",
      "This is more of a set of double doors set high into the wall of the\n"+
      "barn.  It is mainly used to haul bushels of hay into barn, directly\n"+
      "up to the loft.\n",
    "doors#door",
      "These barn doors are about ten feet high, and look very heavy.\n"+
      "The sway slightly back and forth in the wind.\n",
    "wind",
      "You can't see the wind, but it does kick up dust and debris off\n"+
      "the floor.  It also howls through the large, open barn.\n",
    "dust#debris",
      "It's just your everyday dust, dirt, loose hay, etc.\n",
    "walls#cracks#wall#crack#board#boards",
      "The old barn walls are made of long wooden boards nailed together.\n"+
      "Over the years, the boards have warped and bent, creating small\n"+
      "cracks where the boards used to meet.\n",
    }));
  set_extra_objects(({
    "hay#some hay", "d/coronos/w/newstar/newbie/items/hay", }));

  set_smell(
    "You sniff the air.\n"
    "Many different smells fill the air in the barn. The most prominent\n"+
    "is the smell of animals and their feed.  It is also quite musty in \n"+
    "the humid barn.\n");

  set_listen(
    "You hear the wind beating against the outter walls of the barn.\n"+
    "The howling of the wind whistles as it enters through cracks in\n"+
    "the walls.\n");

  set_weather(1, 2, 0);
  set_climb(2);
  set_fall_dam(4);

  set_exits(({
      "d/coronos/w/newstar/newbie/rooms/field1.c", "out",
  }));

  set_guild_name("Any");

/* Set the things that can be trained here */

    set_classes(({
     "general",        ({
	"riding landbased",
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
       "the Master Mercinary",
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
       "Colonel"
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
  ::init();

  if(guild_master) {
    object attacker;

    if((attacker = (object)guild_master->query_primary_attack())) {
       if(present(attacker, this_object())) {
         call_out("no_guild_mess",1,this_player());
         return;
       }
    }
  }
}

void no_guild_mess(object ob) {
    tell_object(ob,"Alex is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}


