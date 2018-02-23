#include <mudlib.h>
#include <linewrap.h>
inherit MONSTER;


string *tmp_Races, tmp_Race;
string *places, Place;

void generate_items();
void reset(status arg) {
  ::reset(arg);
  generate_items();
  if(arg) return;

  set_name("citizen");
  set_short("A humble citizen");
  set_long("");
  set_gender(random(2) + 1);

  tmp_Races = ({
        "high elf", "halfling", "rock gnome",
        "forest gnome", "half elf", "grey elf",
        "hill dwarf", "mountain dwarf",
        "human", "human", "kender",
  });


  places = ({
        "market", "the university", "the courts",
        "the food stalls", "the stables",
        "the docks", "the ship yards",
        "the beach", query_possessive()+" mothers house",
        query_possessive()+" home",
        "the bank vaults", "see the Black Guard",
        "join the city watch",
  });

  Place    = places[random(sizeof(places)-1)];
  tmp_Race = tmp_Races[random(sizeof(tmp_Races)-1)];

  set_race(tmp_Race);
  add_money(100 + random(50));
  set_level(2 + random(5));
  set_alignment(50 + random(20));

  add_class("thief");
  add_class("fighter");

  if(!random(10)) {
    add_class("mage");
    load_spells(20, ({ "magic missile", "burning hands", }));
  }
  else if(!random(10)) {
    add_class("cleric");
    load_spells(20, ({ "bless", "curse", "cure wounds", }));
  }


  load_chat(10, ({
	"Citizen smiles contentedly.\n",
	"Citizen looks toward the clouds.\n",
	"Citizen strolls along.\n",
	"Citizen stops a moment to smell the air.\n",
	"Citizen takes a deep breath.\n",
	"Citizen says: It might rain today.\n",
	"Citizen smiles happily.\n",
	"Citizen says: Welcome to our fair city.\n",
	"Citizen says: I'm just on a walk.\n",
	"Citizen asks: Care to join me on my walk?\n",
	"Citizen asks: Would you like to join me for dinner?\n",
	"Citizen asks: Would you like to see my family?\n",
	"Citizen asks: Where are you from?\n",
	"Citizen asks: Where are you bound?\n",
	"Citizen asks: What is your name, fair traveller?\n",
	"Citizen asks: I wonder if the Circle is meeting today?\n",
	"Citizen asks: Have you seen the wonderful ships in the harbour?\n",
	"Citizen exclaims: My what a beautiful day it is today!\n",
  }));

  load_a_chat(10, ({
	"Citizen says: The Black Guard will hear of this.\n",
	"Citizen exclaims: The Black Guard will hunt you down!\n",
	"Citizen cries out for help.\n",
	"Citizen bursts into tears.\n",
	"Citizen exclaims: Help! Help! Help!\n",
	"Citizen exclaims: Help! I need some body!\n",
	"Citizen exclaims: Help! . . . not just anybody!\n",
	"Citizen exclaims: Help! . . . you know I need someone!\n",
	"Citizen exclaims: Help!\n",
	"Citizen says: Where is the law when you need one.\n",
  }));
}

void long(status wiz) {
    writelw(
"This is a simple citizen of the grand city of Ille Coronos, "+
"going about "+query_possessive()+" daily routine, walking to "+
Place+". "+capitalize(query_pronoun())+" looks as though "+
query_pronoun()+" is in no hurry, and would welcome a bright smile "+
"and some polite conversation.\n");
  ::long(wiz);
}

void generate_items() {
  object ob;
  int ii, jj;
  string *stuff, *desc, Name, Desc;

  if(present("clothing")) return;

  stuff = ({
"smock", "shirt", "gloves", "hat", "vest",
"pants", "boots", "shoes", "cloak", "robe",
  });

  desc = ({
	"simple", "humble looking", 
"clean", "dirty",
	"red", "green", "blue", "grey", "black",
	"festive", "colourful", "drab",
	"expensive", "extravagant",
  });

  Name = stuff[random(sizeof(stuff)-1)];
  Desc = desc[random(sizeof(stuff)-1)];

  ob = clone_object(CLOTHING);
  ob -> set_name(Name);

  switch(Name) {
    case "boots" : case "shoes" : case "pants" : case "gloves" :
      ob -> set_short("A pair of "+Name);
      break;
    default :
      ob -> set_short("A "+Name);
  }
  ob -> set_long(
    "This is "+Desc+" "+Name+" seems to have been made recently \n"+
    "within the workshops of the Yvette and Carren; a fine team of \n"+
    "tailors within the city of Ille Coronos.\n");
  ob -> set_value(10 + random(100));
  ob -> set_weight(1);
  ob -> set_alias("clothing");
  move_object(ob, this_object());
  init_command("wear "+Name);
}
