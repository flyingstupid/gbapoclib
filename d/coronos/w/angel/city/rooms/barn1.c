#include <mudlib.h>

#define CHA             (int)this_player()->query_charisma() + \
			(int)this_player()->query_appraisal()

#define MY_STAT         20



inherit GUILD;

static int max_dogs;

void reset(status arg) {
    if(!guild_master) {
     guild_master = clone_object(MONSTER);
     move_object(guild_master,this_object());

     guild_master -> set_name("gregory");
     guild_master ->   set_short("Gregory, the dog trainer");
     guild_master ->   set_long(
        "Gregory is a member of the city guard who trains dogs to aid \n"+
        "them in various tasks. He has always believed a good dog is  \n"+
        "better than 5 good guards.\n");

     guild_master ->   set_race("human");
     guild_master ->   load_chat(5, ({ "Gregory asks: Do you wish to purchase a fine dog?\n",
        "Gregory goes about his duties, cleaning kennels.\n",
     }));
     guild_master ->   set_magic_resist(200); /* dont want him going anywhere! */
     guild_master ->   set_level(12);

    }

    max_dogs = 5;
    if(arg) return;

  
    set_short("the dog breader's training house");
    set_long(
	"The smell of dogs in this section of the city guard's quarters is strong\n"+
	"and quite over powering. Several kennels line the west wall, and dogs   \n"+
	"stick their heads out, growling at you. ");

    set_weather(2, 1, 0);

    set_exits(({
	"d/coronos/w/vorax/west7", "northeast",
    }));

    set_items(({
        "kennel#kennels",
        "The kennels are quite well looked after, and are very clean.\n",

        "wall#west wall",
        "The west wall contains several kennels where the dogs that \n"+
        "Gregory trains are kept safe and well cared for",
    }));

 
 
    set_guild_name("Any"); /* allows people to learn SWIM here ONLY */

/* Set the things that can be trained here */

    set_classes(({
     "general",        ({
       "climb", "swim", "animal handling",
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

void long(status wiz) {
  ::long(wiz);
  write("Only "+max_dogs+" kennels are full.\n");
}

void init() {
  string message;

  ::init();

  message =  "            [ Gregory, Dog breeder and trainer ]                    \n\n"+
	     " Training in animal handling for citizens of Ille Coronos available.\n"+
             " Trained War Dogs also for sale. War Dogs are well trained, but can \n"+
             " only be handled well by an experienced animal handler.             \n\n"+
             "War dogs will only remain with you while you're logged in.\n\n"+
             " Cost for war dog: 1 platinum coin \n\n"+
	     "    Commands                            Comments                    \n"+
         
             "  buy dog ......................... Purchase a war dog \n"+
	     "  raise|advance animal handling .... Advances animal handling skill \n"+
	     "  cost animal handling ............. (Not)|Possible to raise skill  \n";


  add_action("buy_me", "buy");

  sign = present("sign", this_object());
  if(sign) 
    destruct(sign);


  sign = clone_object(SIGN);
  move_object(sign, this_object());

  sign -> set_message(message);


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
    tell_object(ob,"Finnias is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}


status buy_me() {
  int cost;
  object ob;

  cost = 5000;
  if(!present("gregory")) {
    write("There doesn't appear to be anyone here to serve you.\n");
    return 1;
  }

  if(max_dogs < 1) {
    write("Gregory says: I've run out of trained dogs for you to buy.\n");
    return 1;
  }

  if(!this_player()->query_animal_handling()) {
    write("Gregory says: I wouldn't even think of giving over one of my \n"+
          "dogs to someone as untrained as you are.\n");
    return 1;
  }



  max_dogs --;

  write("You haggle with Gregory over the price of a war dog.\n");
  if(random(CHA) < random(MY_STAT))
    cost -= cost/4;
  else
    cost += cost/3;
  if((int)this_player()->query_money() < cost) {
    write("Gregory says: You don't have "+MONEY->convert(cost)+"!\n");
    return 1;
  }

  this_player()->add_money(-cost);
   ob = clone_object("d/coronos/w/angel/city/rooms/dog");
  ob->set_owner(this_player()->query_name(1));
  move_object(ob, environment(this_player()));

  write("Gregory takes "+MONEY->convert(cost)+" from you.\n");
  write("Gregory goes into a kennel and takes out a war dog for you.\n");
    write("Gregory says: Take good care of her, "+
    this_player()->query_name()+".\n");

  return 1;
}


