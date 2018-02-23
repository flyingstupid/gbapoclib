/* A monster that goes home when he finishes work
 *
 * It should be noted that I had to use a call_out rather than a heart beat
 * as heart_beats temporarily hault when there are not players
 * around with that monster.
 */

#include <mudlib.h>
#define TELL(X) tell_room(environment(this_object()), X)
#define WEATHER "/obj/weather"
#define HOUR (int)WEATHER->query_hour()
#define PM   (status)WEATHER->query_pm()
#define AM   (status)WEATHER->query_am()


inherit MONSTER;


void go_home();
void go_work();
void do_home_commands();
void do_work_commands();
void set_shop_chats();
void set_at_home_chats();
void set_going_home_chats();
void set_going_to_work_chats();
void walking();

string *home_directions;
string *work_directions;

int direction_counter;

status goHome, goWork, atHome, atWork;
status startedWalking;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  home_directions = ({
	"open west door",
	"w", "sw", "nw", "nw", "nw", "w", "w", "w", "w", "w", "w",
	"w", "w", "w", "w", "n", "e",
  });

  work_directions = ({
	"w", "s", "e", "e", "e", "e", 
	"e", "e", "e", "e", "e", "e", "se", "se", "se", "ne", "e", 
"open east door",  
  });


  set_name("galdon");
  set_alias("Galdon");
  set_short("Galdon, the shopkeeper");
  set_long("He looks quite mischevious.\n");


  
  set_race("human");
  set_gender(1);
  set_level(18);
  set_shop_chats();


/* set_heart_ob(this_object());
 */
  set_magic_resist(1000);
  is_npc = 1;
}

void long(status wiz) {
  if(atWork) 
    write("Galdon has always run this shop. He is known for his greedines,\n"+
          "and will rip-off anybody given given the opportunity.\n");

  if(atHome)
    write("Galdon runs the local general store in Ille Coronos.\n"+
          "Right now, however, he seems to be enjoying some rest after work.\n");

  if(goWork)
    write("Galdon runs the local general store in Ille Coronos.\n"+
          "Right now he seems to be on his way to work.\n");

  if(goHome)
    write("Galdon runs the local general store in Ille Coronos.\n"+
	  "Right now he seems to be on his way home after a long day.\n");

  ::long(wiz);
}

void set_shop_chats() {
  this_object()->load_chat(10, ({
"Galdon asks: Would you like to buy something?\n",
"Galdon exclaims: I have the best collection of wares in all of Ille Coronos!\n",
"Galdon glances at your purse string.\n",
"Galdon asks: Would you like to buy something?\n",
  }));
  atWork = 1;
}

void set_going_home_chats() {
  this_object()->load_chat(10, ({
"Galdon says: It's good to be going home.\n",
"Galdon says: It's been a long day.\n",
"Galdon says: I wonder what I will have for dinner tonight.\n",
"Galdon smiles happily.\n",
  }));
}

void set_at_home_chats() {
  this_object()->load_chat(10, ({
"Galdon says: It is good to be home.\n",
"Galdon says: I wonder what is for dinner.\n",
"Galdon asks: Do I know you?\n",
"Galdon asks: Have I seen you at my shop recently?\n",
  }));
}


void set_going_to_work_chats() {
  this_object()->load_chat(10, ({
"Galdon mumbles something about work.\n",
"Galdon says: A shop keeper's work is never done.\n",
"Galdon says: Drop by my shop from time to time.\n",
"Galdon asks: Have you been to my shop lately?\n",
  }));
}



void monster_heart_beat() {
  if(!startedWalking) {
    startedWalking = 1;
    walking();
  }
}

void walking() {
  string time;
  string tmp1, tmp2;
  int hour, minute;


  if(goHome) {
    do_home_commands();
    call_out("walking", 1);
    return;
  }

  if(goWork) {
    do_work_commands();
    call_out("walking", 1);
    return;
  }

  time = environment()->query_time();
  if(atWork && (HOUR > 5 && PM)) {
      tell_room(environment(this_object()), 
      "Galdon says: Looks like it is time to go home.\n"+
	    "Galdon packs up the general store and heads for home.\n");
      set_going_home_chats();
      go_home();
      call_out("walking", 1);
      return;
  }
  else if(atHome && (HOUR > 5 && AM)) {
       tell_room(environment(this_object()),
       "Galdon says: Looks like it is time to go to work.\n"+
           "Galdon packs up his things and heads for his general store.\n");
      set_going_to_work_chats();
      go_work();
      call_out("walking", 1);
      return;
  }
  call_out("walking", 1);
}



void go_home() {
  atWork = 0;
  goHome = 1;
  direction_counter = 0;
}

void go_work() {
  atHome = 0;
  goWork = 1;
  direction_counter = 0;
}

void do_home_commands() {
  if(random(5)) return;
  if(direction_counter > sizeof(home_directions)-1) {
    atHome = 1;
    goHome = 0;
    TELL("Galdon puts his thing down, and sits back in his reclining chair.\n");
    set_at_home_chats();
    return;
  }
  command(home_directions[direction_counter], this_object());
  direction_counter++;
}

void do_work_commands() {
  if(random(5)) return;
  if(direction_counter > sizeof(work_directions)-1) {
    atWork = 1;
    TELL("Galdon puts his things on the counter and sets up shop for the day.\n");
    goWork = 0;
    set_shop_chats();
    return;
  }
  command(work_directions[direction_counter], this_object());
  direction_counter++;
}

  	


