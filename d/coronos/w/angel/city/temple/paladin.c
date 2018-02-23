/* This is the example guild for the mudlib. This room goes into the church
 * complex somewhere. Add the exits to and from the appropriate rooms.
 * Angel, November 1994
 */


#include <mudlib.h>
#include <linewrap.h>

#define W_PER_LEVEL 7  /* number of levels to get a new weapon of choice */
#define GUILD_OB	"obj/skills/classes/paladin"

inherit GUILD;

string *valid_weapons_of_choice;

status train_specialisation(string str);
status choose_weapon_of_choice(string str);

void reset(status arg) {
    if(!guild_master) {
     guild_master = clone_object(MONSTER);
     move_object(guild_master,this_object());
     guild_master->set_name("kaile");
     guild_master->set_alignment(1000);
     guild_master->set_short("Sir Kaile the True");
     guild_master->set_long(
          "Kaile is pure of heart and noble of mind. He is one of \n"+
          "the most honoured, and most powerful of all holy knights  \n"+
          "who serve the All-God. \n");
     guild_master->set_gender(1);
     guild_master->set_race("human");
     guild_master->set_level(10000);
     guild_master->add_class("fighter");
     guild_master->add_class("paladin");
     guild_master->add_class("cleric");
     guild_master->load_a_chat(25,({ 
       "Kaile says: My heart is true, you shall not stop me.\n",
       "Kaile parries your blows.\n",
       "Kaile says: The All-God will protect me.\n",
       "Kaile exclaims: Such a casual disregard for life!\n",
     }));
     guild_master->set_magic_resist(50);
    }

    if(arg) return;
    set_short("the paladin's training room");
    set_long(
        "About the walls hang swords and shields and banners of many   \n"+
        "holy crusades. This place is where the holy knights who serve \n"+
        "in the church of the All-God come to train in their arts,     \n"+
        "trade stories of glory and honour, and polish their armour    \n"+
        "and weapons, or train their squires. By the large archway is  \n"+
        "a sign of silver.\n");

    set_races(({ "human", "gray elf", "grey elf", "half elf", "high elf", }));
    set_items(({
     "banners#banner",
     "These banners bear the coat of arms, icons and designs of the\n"+
     "holy knights, the paladin, who have served in holy crusades",

     "walls#wall",
     "The walls are made of stone, giving you a sense of antiquity",

     "swords",
     "The gleaming blades seem ancient, yet still sharp enough to kill "+
     "the unwary man",

     "shields#shield",
     "There was once a pattern worked into the surface, \n"+
     "but it has been worn down through years of use",

     "devices#device","These are unfamiliar, but seem deadly nonetheless",
     "doorway","The doorway is large, but easily defendable",
     "place","This is the training room",
    }));

    set_weather(2, 1, 0);
    set_guild_name("Paladins of the All-God");
    set_exits(({
		"d/affils/rooms/all-god", "east",
    }));
    set_classes(({
     "general",        ({
       "climb", "swim",
     }),

     "primary",        ({
       "strength", "intelligence", "wisdom", "dexterity", 
       "combat",   "constitution", "charisma",
     }),


     "paladin",        ({
       "multi attack", 
       "multi opponent",
       "armouring",
       "weapon smith",

       "sword spec", 
       "shield spec",
       "lance spec",
       "crushing spec", 

       "healing sphere", 
       "combat sphere",
       "protection sphere",               
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
     30,      50,      75,      100,     175,     250,
     400,     600,     900,     1200,    2000,    3000,
     4500,    6500,    10000,   15000,   20000,   30000,
     50000,   75000,   100000,  125000,  150000,  175000,
     200000,  225000,  250000,  275000,  300000,  325000,
    }));

    set_titles(({ 
     ({}), /* no neuter characters now but possible */


     /* male titles */ 
     ({
          "the Novice Horseman",
          "the Simple Lancer",
          "the Prominent Armiger",
          "the Famed Armiger",
          "the Simple Esquire",
          "the Skilled Esquire",
          "the Prominent Esquire",
          "the Gallant",
          "the Noble Warder",
          "the Holy Warder",
          "the Saintly Warder",
          "the Guardian",
          "the Noble Guardian",
          "the Holy Guardian",
          "the Saintly Guardian",
          "the Chevalier",
          "the Noble Chevalier",
          "the Holy Chevalier",
          "the Saintly Chevalier",
          "the Noble Justicar",
          "the Holy Justicar",
          "the Saintly Justicar",
          "the Noble Knight",
          "the Holy Knight",
          "the Saintly Knight",
          "the Guardian of the Faith",
          "the Keeper of the Faith",
          "the Protector of the Faith",
          "the Defender of the Faith",
          "the Paladin",
          "the Noble Paladin",
          "the Holy Paladin",
          "the Saintly Paladin",
          "the Chosen Paladin of the All-God",
     }),

     /* female titles */
     ({
          "the Novice Horsewoman",
          "the Simple Lancer",
          "the Prominent Armiger",
          "the Famed Armiger",
          "the Simple Esquire",
          "the Skilled Esquire",
          "the Prominent Esquire",
          "the Gallant",
          "the Noble Warder",
          "the Holy Warder",
          "the Saintly Warder",
          "the Guardian",
          "the Noble Guardian",
          "the Holy Guardian",
          "the Saintly Guardian",
          "the Chevalier",
          "the Noble Chevalier",
          "the Holy Chevalier",
          "the Saintly Chevalier",
          "the Noble Justicar",
          "the Holy Justicar",
          "the Saintly Justicar",
          "the Noble Knight",
          "the Holy Knight",
          "the Saintly Knight",
          "the Guardian of the Faith",
          "the Keeper of the Faith",
          "the Protector of the Faith",
          "the Defender of the Faith",
          "the Paladin",
          "the Noble Paladin",
          "the Holy Paladin",
          "the Saintly Paladin",
          "the Chosen Paladin of the All-God",
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
     }),
   }));

   valid_weapons_of_choice = ({
     "longsword",     "shortsword",    "lance", "scimitar", 
     "broadsword",    "bastardsword",  
     "footmansflail", "horsemansflail", 
     "footmansmace",  "horsemansmace",
     "militarypick",   
   });
}


void init() {
  object attacker;
  if(guild_master) {
    if((int)this_player()->query_level() < 2) {
      call_out("newbie_message", 2);
    }
    if((attacker = (object)guild_master->query_primary_attack())) {
      if(present(attacker, this_object())) {
        call_out("no_guild_mess",1,this_player());
        return;
      }
    }
  }
  if((string)this_player()->query_guild_string() ==
     "Paladins of the All-God") {
     if(!present("paladin", this_player()))
       move_object(clone_object(GUILD_OB),this_player());
  }
  ::init();
  add_action("train_specialisation", "train");
}

void no_guild_mess(object ob) {
    tell_object(ob,"Kaile is busy defending himself.\n");
    tell_object(ob,"He is too busy to train anybody.\n");
}

void newbie_message() {
  if(present(this_player())) {
    writelw("Kail says: I do not think you are ready for the committment "+
            "you need to become a holy knight. Come back when you are.\n");
  }
}



status train_specialisation(string str) {
  if((string)this_player()->query_guild_string() != "Paladins of the All-God"){
    notify_fail("Kaile says: Sorry, you can't train here.\n");
    return 0;
  }

  if(!this_player()->query_weapon_proficiency("lance")) {
    write("Kaile exclaims: You have no need for your training in your   \n"+
          "                   other weapons. I will train you in the "+
          " lance!\n");
    if(!present("lance", this_player())) {
      write("Kaile exclaims: You don't have that weapon!\n"+
            "                   How can I train you in that!!\n");
      return 1;
    }

    this_player()->set_weapon_prof();
    this_player()->add_weapon_spec("lance");
    this_player()->set_alignment(1000);   /* to set thier alignment */
    ::train_weapon("lance");
    return 1;
  }

  if(!str) {
    write("Kaile asks: What weapon do you wish to train with?\n");
    return 1;
  }

  if(sizeof((string *)this_player()->query_weapon_spec()) -1 <
    ((int)this_player()->query_level() / W_PER_LEVEL)) {
    write("Kaile says: You must choose another weapon of choice.\n"+
          "               Your current weapons of choice are...    \n"+
          "\t"+
          implode((string *)this_player()->query_weapon_spec(),
            "   ")+"\n"+
          "               You may choose from these weapons...     \n"+
          "\t"+
          implode(valid_weapons_of_choice, "   ")+"                \n");
    write("Which weapon do you choose? > ");
    input_to("choose_weapon_of_choice");
    return 1;
  }
  ::train_weapon(str);
  return 1;
}

status choose_weapon_of_choice(string str) {
  if(!str) {
    write("Kaile says: Come back when you have made up your mind.\n");
    return 1;
  }

  if(member_array(str, valid_weapons_of_choice) == -1) {
    write("Kaile says: That is not a knightly weapon to choose.\n"+
          "               You must choose one of these weapons... \n"+
          implode(valid_weapons_of_choice, "  ")+"                \n");
    write("Answer > ");
    input_to("choose_weapon_of_choice");
    return 1;
  }
  if(!present(str, this_player())) {
    write("Kaile says: You don't even have that weapon!\n"+
          "               How can I train you in that!!\n");
    return 1;
  }

  this_player()->add_weapon_spec(str);
  write("Kaile begins to train you in the ways of the "+str+".\n"+
        "Adding weapon of choice...\n");
  ::train_weapon(str);
  return 1;
}

status leave(string str) {
  object obj;

  if(str != "paladin") {
    write("Kaile says: Leave what?\n");
    return 1;
  }
  if(!this_player()->query_class("paladin")) {
    write("Kaile says: Only paladin can leave the guild here.\n");
    return 1;
  }
  if(query_guild_name() != (string)this_player()->query_guild_string()) {
    write("Kaile says: Only "+query_guild_name()+" can do that here.\n");
    return 1;
  }

  obj = present("guild_object", this_player());
  if(obj) destruct(obj);
  obj = this_player()->query_paladin_aura_object();
  if(obj) destruct(obj);
  this_player()->save_me(1);
  ::leave(str);
  return 1;
}

