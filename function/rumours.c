/* Rumours Maker v1.01 Angel April 1998
 * This little piece of code is designed to compliment the pub. 
 * When a player listens he receives a rumour designed to 
 * enhance game play, give him hints to various things happening
 * around the mud, or even just give hints to (mini)quests.
 */

#include <mudlib.h>

#define TP		this_player()
#define NAME	(string)TP->query_name()
#define TELL(X);	tell_room(environment(TP), "X");
#define FILE	"/data/rumours/rumours.txt"

string get_rumour() {
  string txt, file;
  string *rumours;

  file = FILE;

  txt = read_bytes(file, 0, file_size(file));

  if(!txt) return 0;

  rumours = explode(txt, "#");
  return rumours[random(sizeof(rumours)-1)];
}



