/* DEATH SCENE MAKER v1.00  Angel, November 1994
 * The original death mark was not flexible enough to allow for multiple death 
 * scenes, or shorter ones without difficulty. This object is cloned to the
 * player, is auto loading, and reads files according to the players
 * alignment. The object can also be configured to include races as well.
 */

#define DELAY		3 /* HB too fast, so use call_out 8( */
#define PATH             "/room/death/open/"
#define DEFAULT          "death.txt"
#define DEATH_ROOM       "/room/death/death_room"
#define LG_CHURCH	"/d/affils/rooms/all-god"
#define LN_CHURCH	"/d/affils/rooms/antaaries"
#define NG_CHURCH	"/d/affils/rooms/antaaries"
#define TN_CHURCH	"/d/affils/rooms/taalandrix"
#define NE_CHURCH        CHURCH
#define CN_CHURCH	"/d/affils/rooms/taalandrix"
#define CE_CHURCH        CHURCH


#include <mudlib.h>

status start_death;
int timer;
string *death_messages, return_room;

void get_death();
void death_scene();
void start_death_again();
void reincarnate_death();
void start_death();

void init() {
  add_action("comm_death", "", 1);
  if(!timer) get_death();
}

void get_death() {
  string txt, file;
  string alignment_string;

  if(environment())
    alignment_string = (string)environment()->query_al_title();
  file = PATH;

  switch(alignment_string) {
    case "(Lawful Good)":
      file += "lg.txt";
      return_room = LG_CHURCH;
    break;

    case "(Lawful Neutral)":
      file += "a1.txt";
      return_room = LN_CHURCH;
    break;

    case "(Neutral Good)":
      file += "ng.txt";
      return_room = NG_CHURCH;
    break;

    case "(True Neutral)":
      file += "tn.txt";
      return_room = TN_CHURCH;
    break;

    case "(Chaotic Neutral)":
      file += "cn.txt";
      return_room = CN_CHURCH;
    break;

    case "(Neutral Evil)":
      file += "ne.txt";
      return_room = NE_CHURCH;
    break;
    default: /* (Chaotic Evil */
      file += "ce.txt";
      return_room = CE_CHURCH;
    break;
  }

  if(!file_size(file)) 
    file = PATH + DEFAULT;

  txt = read_bytes(file, 0, file_size(file));
  if(!txt) {
    write("Error: Can not read 'Death File'.\n");
    environment()->move_player("X#"+CHURCH);
    destruct(this_object());
    return;
  }
  if(!environment()->query_ghost()) {
    tell_object(environment(), "Angel exclaims: Hang on... you're not dead!\n");
    environment()->move_player("X#"+CHURCH);
    destruct(this_object());
    return;
  }

  death_messages = explode(txt, "#");

  say("You see a dark shape gathering some mist above the corpse of "+
      capitalize((string)environment()->query_name(1))+"...\n",
      environment());
  move_object(environment(), DEATH_ROOM);

  start_death();
}

void start_death() {
  death_scene();
}

void death_scene() {
  if(!environment()->query_ghost()) {
    remove_call_out("death_scene");
    destruct(this_object());
    return;
  }
  tell_object(environment(), death_messages[timer]);
  timer++;
  if(timer >= sizeof(death_messages)) {
/*
    if(return_room == CN_CHURCH) 
      reincarnate_death();
*/
    environment()->move_player("X#"+return_room);
    remove_call_out("death_scene");
    destruct(this_object());
    return;
  }
  call_out("death_scene", DELAY);
}

void reincarnate_death() {
  string *race;
  race = ({ 
     "wood elf", "half elf", "high elf", "grey elf", "dark elf",
     "mountain dwarf", "hill dwarf", 
     "minotaur", "orc", "half giant",
     "halfling", "kender", "sprite",
     "deep gnome", "forest gnome", "rock gnome",
     "pixie", "nixie", "kobold", "goblin", 
     "human",
  });
  environment()->set_race(race[random(sizeof(race))]);
  tell_object(environment(), "\nYou feel your soul change into a new body.\n\n");
  environment()->toggle_ghost();
}

status comm_death(string str) {
  string verb;
  verb = query_verb();

  if(verb == "quit" || verb == "Quit") {
    tell_object(environment(), "You cannot escape death that easily...\n");
    remove_call_out("death_scene");
    return 0;
  }
  if(this_player()->query_security_level()) {
    tell_object(environment(),
               "Your powers of immortality allow you to act!!\n");
    return 0;
  }
  tell_object(environment(),
               "You fail to do anything in your immaterial state.\n");
  return 1;
}

mixed query_auto_load() {  return "/room/death/death_mark:"+ timer;  }
 
void init_arg(int arg) {
  sscanf(arg,"%d",timer);
  call_out("start_death_again", 1);
}

void start_death_again() {
  tell_object(environment(),
    "\n\nYou can't escape death that easily...!\n\n"+
    "You feel your soul being pulled to another place...\n\n\n");
  get_death();
}

status get(string item) { return 1; }
status drop(string item) { return 1; }
