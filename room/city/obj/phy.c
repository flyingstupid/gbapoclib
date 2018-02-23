/* Time Elemental Phylateracy, (c)Angel, March 1994.
 * v1.02 Angel, April 1994. 
 * This object is designed to be the sole transport between
 * not only remote parts of the mud, but also to domains of
 * variant themes. This should handle all of the destructing
 * of different objects of different themes between those
 * domains.
 */

#include <mudlib.h>
inherit ROOM;

static int counter;      /* How many gems I've just put here                 */
static int counter_d;    /* Element of the array that contains the domain    */
static int counter_m;    /* Counter for the message array                    */
static string place;     /* The domain room to visit                         */
static mixed *domains;   /* Array info of domain room, gem types             */
static string *gems;     /* Want to take the gems out we know what they were */

void trans_all_to_domain();
void messages();

void reset(status arg) {
  if(arg) return;
  gems = ({});  
  domains = ({
     ({ ({"room/void",}), ({"amethist",}),}),
     ({ ({"d/oplanes/astral/astral1",}), ({"ruby","diamond","saphire",}),}),
  });

  set_weather(5,1,0);
  custom_exits = "";
  set_items(({
     "dust",
          "There is a fair amount of dust and dirt on the pannel.\n"+
          "The dust on the runes, however, has been removed, as if\n"+
          "they have been regularly cleaned by tracing their patterns",
     "chair",
          "The chair is molded into the small chamber here inside the "+
          "the large elipsoid gem",
     "gems#gem",
          "The gems are in rows from the left to the right hand \n"+
          "side of the front of the inside of this small chamber.\n"+
          "In the centre of the pannel there are holes where you \n"+
          "assume three gems should go, but must be missing",
     "portal",
          "There is an openning in the side of the gem, large enough for \n"+
          "one person to fit inside. Perhaps you could enter the gem?",
     "hole#holes#pannel",
          "The holes in the pannel are big enough to place a regular sized "+
          "gem inside",
     "rune#runes",
          "The runes are no doubt runes of great power, containing the \n"+
          "life force of what ever creature is inside this large gem.  \n"+
          "There is a fair amount of dust and dirt on the pannel, but  \n"+
          "the runes themselves have been recently traced to remove it",
  }));
  set_listen("The rythmic sounds of the gem resemble a heart beating...\n");
  set_smell("There is a strange smell in the air here. Perhaps it is magic?\n");
  set_name("phylateracy");
  enable_commands();
}

/* The array of message1 and message 2 should be equal in their size */
void messages() {
  string *message1, *message2;
  string tmp;

  message1 = ({
    "The gems in the pannel glow..and then vanish!\n",
    "The whole phylateracy begins to emit a soft glow.\n",
    "The phylateracy glows more brightly...\n",
    "There is a tremendous flash of light...\n",
    "The suroundings outside the phylateracy appear to have changed.\n",
  });

  message2 = ({
        "The phylateracy begins to emit a soft glow.\n",
        "The phylateracy hums a low static hum...\n",
        "The phylateracy glows more brightly...\n",
        "There is a tremendous flash of light, and the phylateracy vanishes!\n",
        "The phylateracy appears again with a flash of light.\n",
  });

  tell_room(this_object(), message1[counter_m]);
  tell_room(environment(), message2[counter_m]);
  counter_m ++;
  if(counter_m >= sizeof(message1)) {
    trans_all_to_domain();
    remove_call_out("messages");
    return;
  }   
  call_out("messages", 2);
}

void long(status wiz) {
  if(present(this_player(), this_object())) {
    write(
     "Inside this small chamber is a molded chair sitting before an     \n"+
     "array of gems of varied colours, and runes of great power. Inside \n"+
     "the lights pulsate, as if the very chamber is alive with some     \n"+
     "driving force of energy. Perhaps you might be able to leave the gem?\n");
  }
  else {
    write(
    "The huge elipsoid gem is a strange deep blue in colour, and contains \n"+
    "several powerful runes of magic along its side. Perhaps you could    \n"+
    "enter the huge gem?\n");
  }
}

void extra_long(status wiz) {
  string tmp1, tmp2;

  sscanf(lower_case((string)environment()->short()),"%sa%s",tmp1,tmp2);
  sscanf(lower_case((string)environment()->short()), "%sthe%s",tmp1,tmp2);
  if(!tmp2) tmp2 = lower_case((string)environment()->short());
  
  write(
     "In the centre of the \n"+
      "\b"+tmp2+" is a smooth elipsoid\n"+
     "gem of incredible dimensions. Along each side is a portal, large \n"+
     "enough for a single person to fit inside the bulk of the gem.   \n");
}

void init() {
  ::init();
  add_action("read_it",     "read"   );
  add_action("put_gem",     "put"    );
  add_action("put_gem",     "place"  );
  add_action("get_gem",     "get"    );
  add_action("get_gem",     "take"   );

  add_action("trace_runes", "trace"  );
  add_action("enter",       "enter"  );
  add_action("leave",       "leave"  );
  add_action("look_here",   "look"   );
  add_action("look_here",   "exa"    );
  add_action("look_here",   "examine");
  add_action("look_here",   "l"      );
}

status read_it(string str) {

  if(str == "runes" && present(this_player(), this_object())) {
    if(this_player()->query_class("mage")) {
      write(
"The runes seem to be similar to those found in the writings of a \n"+
"time-reaver spell, but amoung them are also runes of teleportation.\n"+
"Other runes about the interior and exterior of the gem indicate some\n"+
"sort of life trapping spell has been cast upon it. Perhaps you are  \n"+
"actually inside some sort of soul-object or phylateracy?\n");

      say((string)this_player()->query_name()+" reads the runes around "+
      "the gem.\n");
      return 1;
    }

    else if(this_player()->query_class("cleric")) {
      write(
"The runes on the pannel about them gems are unfamiliar to you, but those \n"+
"around the sides and interior are reminiscent of a life trapping spell of\n"+
"some sort. Perhaps you are actually inside some sort of soul-object or   \n"+
"perhaps a large phylateracy?\n");

      say((string)this_player()->query_name()+" reads the runes around the "+
      "inside of the gem.\n");
      return 1;
    }

    else {
      write("The runes don't make any sense to you at all.\n");
      say((string)this_player()->query_name()+" looks confused as "+
      this_player()->query_pronoun()+" reads the runes in the gem.\n");
      return 1;
    }
  }
  return 0;
}



status look_here(string str) {
  string tmp1, tmp2;
  string *words;

  words = ({ "gems", "pannel", "holes", "hole", });

  if(!str) return 0;
  sscanf(str, "at %s", tmp1);

  if((member_array(tmp1, words) != -1 || 
      member_array(str, words) != -1) && counter) {

    if(counter == 1)
     write("There is 1 gem already placed in the first of the three holes.\n");

    else
     write("There are "+counter+" gems already placed in the holes.\n"+
           "You think that perhaps a "+domains[counter_d][1][counter]+
           " might go in the next hole.\n");
    return 1;
  }

  if(str == "runes" && !present(this_player(),this_object())) {
    write("The runes appear to be magical. You would have to \n"+
          "enter the gem in order to read them more easily   \n");
    return 1;
  }

  if(str == "portal" && !present(this_player(),this_object())) {
    write("The portal is an openning in the side of the gem, large \n"+
          "for a single person to fit through, and enter the gem.  \n");
    return 1;
  }
  return 0;
}


/***************************************************************************
 * Incase the player puts in the wrong gem, then he is able to get them all
 * out and start again. Or, if he is just experimenting, then he is able to
 * remove the gems when he has finished.
 */
status get(string what) { return 0; }  /* can't get this ! */

status get_gem(string str) {
  string what, where;
  object obj;
  int i;

  sscanf(str, "%s from %s", what, where);
  if(where != "hole") {
    notify_fail("Get what from where?\n");
    return 0;
  }

  if((str == "gem" || str == "gems" || member_array(str, gems) != -1) &&
     !present(this_player(),this_object()))  return 0;

  if(!sizeof(gems)) {
    notify_fail("There are no gems in the holes!\n");
    return 0;
  }
  write("You manage to pry the gems from their holes.\n");
  say((string)this_player()->query_name()+" prys the gems from their "+
      "holes.\n",this_player());
  for(i=0; i<sizeof(gems); i++) {
    obj = clone_object("inherit/treasure");
    obj -> set_name(gems[i]);
    obj -> set_alias(gems[i]);
    obj -> set_short("A "+gems[i]);
    obj -> set_long("The "+gems[i]+" seems to have lost its shine.\n");
    obj -> set_value(10 + random(20));
    if(!this_player()->add_weight()) {
      write("You can't seem to carry the "+gems[i]+".\n"+
            "It falls from your hands to the ground.\n");
      move_object(obj, environment(this_player()));
    }
    else {
      write("You take the "+gems[i]+" from the hole in the pannel.\n");
      move_object(obj, this_player());
      say((string)this_player()->query_name()+" gets a "+gems[i]+" from "+
      "the front pannel.\n",this_player());
    }
  }
  gems = ({});
  counter_d = 0;
  counter = 0;
  return 1;
}


/****************************************************************************
 * This enables the player to adventure for gems, insert them to activate
 * (or bribe) the phylateracy to taking him somewhere. The destination
 * matches the array of gems in the *domains array. The domains array must
 * each be unique with its #1 element so there is no confusion with the
 * destination the player wishes to go. Note that the phylateracy is still
 * unique to magic, while not being obviously modern of scientific. Players
 * are encouraged to venture into the library to find out why/how this thing
 * works.
 */

status put_gem(string str) {
  string what, where;
  string temp;
  status flag;
  object obj;
  int i;
  if(counter >= 3) {
    notify_fail("There are no more holes to place the gems in.\n"+
                "Your attention turns to the runes beside them.\n");
    return 0;
  }
  sscanf(str, "%s in %s", what, where);
  if(where != "hole") {
    notify_fail("Put where in where?\n");
    return 0;
  }
  if(!what) return 0;
  obj = present(what, this_player());
  if(!obj) {
    notify_fail("But you don't have a "+what+"!\n");
    return 0;
  }


  write("You try to put the gem in the hole in the pannel.\n");
  say((string)this_player()->query_name()+" tries to put a gem in "+
          "the pannel.\n", this_player());

/* Match str with first element of each array to find domain sequence */
  if(!counter) {
    for(i=0; i<sizeof(domains); i++) {
      if((string)obj->query_name() == domains[i][1][counter]) {
        flag = 1;
        counter_d = i;  /* the element which contains the current domain */
        place = domains[counter_d][0][0];
        counter ++;
      }
    }
  } 
  else {
    if((string)obj->query_name() == domains[counter_d][1][counter]) {
      flag = 1;
      counter ++;
    }
  }

  if(flag) {
    gems += ({ (string)obj->query_name(), });
    temp = implode(gems, ",");

    write("The gem seems to fit perfectly, and becomes wedged inside"+
          " the hole.\n");
    if(counter < sizeof(domains[counter_d][1]))
      write("It looks like a "+domains[counter_d][1][counter]+" might "+
            "fit in the next hole.\n");
    else
      write("All the holes are now full. Your attention turns to the runes.\n");
    destruct(obj);
    flag = 0;
    return 1;
  }
  else {
    write("The gem does not seem to fit into the hole.\n"+
          "It looks like a "+domains[counter_d][1][counter]+" might "+
          "fit in the hole.\n");
    say((string)this_player()->query_name()+"'s gem does not seem to fit "+
         "into the pannel.\n",this_player());
    return 1;
  }
  return 0;
}


/* Take us to the domain, now that all the gems have been put inside */
status trace_runes(string str) {
  int i;
  string place;

  if(str != "runes" && str != "patterns") {
    notify_fail("Trace what?\n");
    return 0;
  }
  write("You trace the runes on the pannel.\n");
  say((string)this_player()->query_name()+" traces the runes on "+
  "the pannel.\n",this_player());

  if(counter < sizeof(domains[counter_d][1])) {
    notify_fail("Nothing happens. Perhaps you require more gems?
