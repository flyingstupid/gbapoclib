#include <mudlib.h>
#define OBJ "/d/coronos/w/angel/city/obj/"
#include <linewrap.h>

inherit MONSTER;

string *robes, Robe;
string *studies, Study;
string *races, Race;

void generate_items();
void reset(status arg) {

  robes = ({
	"White Robe",
	"Grey Robe",
	"Black Robe",
  });

  studies = ({
	"the mysteries of the multiverse",
	"the complexities of alchemy",
	"tomes of evocation",
	"tomes of alteration",
	"the darkness of necromancy",
	"safeties of abjuration",
	"new spells in the charm school",
	"architecture",
	"wild magic",
	"the physical laws of magic",
	"the tomes of the ancients",
	"ancient history",
	"engineering", 
	"new spells",
	"butterflies",
	"insects",
  });

  races = ({
"rock gnome", "forest gnome", 
"half elf", "grey elf", "high elf", "dark elf",
"human", "human",
"minotaur", "orc", "lizardman",
  });
	
  Race = races[random(sizeof(races)-1)];
  Robe = robes[random(sizeof(robes)-1)];
  Study = studies[random(sizeof(studies)-1)];

  ::reset(arg);
  if(arg) return;
  generate_items();

  set_name("apprentice");
  set_alias("mage");
  set_short("An apprentice "+Robe+" mage");
  set_long("");

  set_race(Race);
  set_gender(random(2) + 1);
  set_level(5 + random(10));

  add_class("mage");
  load_spells(20 + random(50), ({
	"magic missile", "fire shield", "acid arrow", "acid rain",
	"hold person", "hold monster", "fire ball", "energy drain",
	"cone of cold", "chill touch", "lightning bolt",
	"rope trick", "bbb", "burning hands",
	"monster summon 1", "monster summon 2", "monster summon 3",
	"vampiric touch", "scare", "sbf", "mks", "ice storm",
  }));

  load_chat(10, ({
	"Apprentice says: Hello there.\n",
	"Apprentice says: Renegades are a danger to magic.\n",	"Apprentice asks: Who are you?\n",
	"Apprentice asks: Are you another apprentice?\n",
	"Apprentice asks: Youre not a renegade are you?\n",
	"Apprentice asks: Have you seen the Master?\n",
	"Apprentice asks: What magic do you study?\n",
	"Apprentice asks: Are you versed in the magical arts?\n",
	"Apprentice says: I'm studying "+Study+".\n",
	"Apprentice smiles happily.\n",
	"Apprentice studies diligently.\n",
	"Apprentice ponders over "+query_possessive()+" studies.\n",
  }));

  load_a_chat(5, ({
	"Apprentice exclaims: Leave me alone!\n",
	"Apprentice exclaims: You will not get away with this!\n",
	"Apprentice exclaims: I will not surrender to you!\n",
	"Apprentice exclaims: My magic will slay you!\n",
	"Apprentice exclaims: Dont do that!\n",
  }));


}

void long(status wiz) {
  writelw(
    "A studious apprentice of the complex and arcane arts of maigic, "+
    "this young apprentice is studying "+Study+", which keeps "+
    query_objective()+" busy day in and day out. \n");

  write("Apprentice is a "+Robe+" mage\n");
  ::long(wiz);
}

void generate_items() {
  object ob;
  string str;
 
  sscanf(Robe, "%s Robe", str);
  str = lower_case(str);

  if(!present("robe")) {
    if(random(20)) {
      ob = clone_object(CLOTHING);
      ob -> set_value(100);
    }
    else {
      ob = clone_object(ARMOUR);
      ob -> set_value(300);
      ob -> set_ac(1);
      ob -> set_info("These robes confer a magical protection to "+
	"the wielder as if he was wearing true armour.\n");
    }

    ob -> set_name("robe");
    ob -> set_short("A "+str+" robe");
    ob -> set_long(
	"A classic "+str+" robe worn by mages and wizards.\n"+
	"It looks quite simple and very comfortable.\n");
    ob -> set_weight(1);
    move_object(ob, this_object());
    init_command("wear robe"); 
  }
  
  if(!random(10)) {
    ob = clone_object(OBJ+"dagger");
    move_object(ob, this_object());
    init_command("wield dagger");
  }

}

object scroll; 

void init() {
  ::init();
  if(!scroll) {
    scroll = clone_object(OBJ+"m_scroll");
    move_object(scroll, this_object());
  }
}
