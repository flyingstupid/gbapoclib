#include <mudlib.h>
#define NAME (string)this_player()->query_name()

inherit ROOM;
status magpie();
void monster_died();

void reset(status arg) {
  if(arg) return;

  set_short("the city garden");
  set_long(
     "The cobblestone pathway winds its way through the bushland \n"+
     "garden past some spider orchids growing on the bark of a  \n"+
     "few mountain ash trees. Some black and white birds perch  \n"+
     "high on a branch above you, watching your movements.\n");

  set_day_desc(
     "The sunlight beams down on you from on high, peeking through the \n"+
     "white fluffy clouds.\n");
  set_night_desc(
     "The moon stares down at you as dark sinister clouds pass by.\n");

  set_listen("Mapgies caw noisily.\n");
  set_smell("There is the strong smell of eucalyptus here.\n");

  set_items(({
     "branches#branch#above",
          "There seems to be a nest in one of the branches",
     "nest",
          "This must be what the magpies are protecting. Surely \n"+
          "they would attack anyone who attempted to take it",
     "bird#birds",
          "The birds are australian magpies. Beware, for   \n"+
          "they may swoop down and attack you at any moment",
     "path#cobblestone path#cobblestones#cobblestone",
          "A well travelled cobblestone path",
     "tree#gum tree#ghost-gum#gum",
          "This tree's trunk is a light grey, almost white colour. Atop \n"+
          "the tree is some movement amid the leaves",
     "ash#mountain ash",
          "A tall grey eucalypt; one of the largest "+
          "types of trees in the world",
     "orchid#spider orchid",
          "A long black-orange flower sways in the breeze that blows \n"+
          "through the leaves of the trees. The orchid seems to be   \n"+
          "growing on the trees themselves",
  }));
  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of an echidna",
  }));

  set_night_items(({
     "moon",
          "You can see the man in the moon. He \n"+
          "appears to be grinning an evil grin at you",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));
  set_exits(({
	"d/coronos/w/angel/city/gardens/garden1", "northwest",
	"d/coronos/w/angel/city/gardens/garden8", "south",
	"d/coronos/w/angel/city/gardens/garden9", "southeast",
	"d/coronos/w/angel/city/gardens/garden3",  "west",
  }));
  set_weather(1,4,0);
}

void init() {
  ::init();
  if(!random(10) && !present("magpie")) call_out("magpie", 1);
}

void magpie() {
  object obj;

  say("A mapgie swoops down from the tree top and attacks "+NAME+".\n",
     this_player());
  tell_object(this_player(), 
     "A magpie swoops down from the tree tops and attacks you.\n");
  obj = clone_object(MONSTER);
  obj -> set_name("magpie");
  obj -> set_race("bird");
  obj -> set_short("An angry magpie");
  obj -> set_long(
          "The mapgie is a black and white bird, as large as a crow, \n"+
          "with a sharp black beak and a mean attitude. It is here   \n"+
          "protecting its young from passers by.\n");
  obj -> load_a_chat(10,({ "Magpie caws loudly.\n",
           "Magpie swoops around.\n",
           "Magpie dives toward you.\n",
           "Mapgie hisses at you.\n",
           "Mapgie caws angrily.\n",
           "Magpie flaps it wings.\n",
         }));
  obj -> set_level(2);
  obj -> set_ac(3);
  obj -> set_wc(6);
  obj -> set_hp(60);
  obj -> set_gender(2);
  obj -> set_attack_msg(({
          "buffets",          "softly, with her wings",
          "pecks",            "lightly, with her beak",
          "pecks",            "with her beak",
          "rakes",            "with her claws",
          "buffets",          "menacingly with her wings",
          "smashes",          "with her beak",
          "crunches",         "with her beak",
  }));
  obj -> set_dead_ob(this_object());
  move_object(obj, this_object());
  obj -> add_secondary_attacker(this_player());
}

void monster_died() {
  object egg;

  tell_room(this_object(),
     "As the magpie dies, her egg falls from the nest above...\n");

  egg = clone_object(FOOD);
  egg -> set_name("egg");
  egg -> set_short("A magpie egg");
  egg -> set_long(
          "The egg is white with spotts and speckles.\n"+
          "I wouldn't eat it if I were you.\n");
  egg -> set_room_msg(
          "@@query_name:$this_player()$@@ eates the mapgies egg.\n"+
          "@@query_name:$this_player()$@@ turns a sickly shade of green.\n");
  egg -> set_consumer_msg(
          "I warned you...you start to feel very ill.\n"+
          "That'll teach you for eating live magpie young.\n"); /* eewww! */
  egg -> set_strength(2);
  move_object(egg, this_object());
}
