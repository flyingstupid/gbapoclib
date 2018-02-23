
/* Player Keeps Generator
 * v1.01 Angel, July 1997 (c)
 *
 * Authors notes:
 * Quite simply this daemon is designed to allow players the
 * ability to custom design their keeps by use of a 'room
 * generator'-type item. In game terms it is hoped that NPCs
 * will be hired by the players to come into their homes and
 * do the alterations to their specifications.
 *
 * To allow players the right to design what ever they like,
 * however, is not the purpose of this piece of code. It is
 * desiged to allow players some freedom to custom design their
 * homes under the supervision of a Creator. He should then
 * watch the development of keeps within these directories
 * and make alterations as needed. 
 *
 * It is also hoped that this supervisor will aid players in the
 * development of their homes, and make some alterations
 * himself that would otherwise be impossible and too complex
 * for a basic 'room generator' to accomplish.
 *
 */

#include <mudlib.h>
#include "defs.h"


string filetoAlter;

inherit ROOM;

void reset(status arg) {
  if(arg) return;
  set_alias("gen");
}


void init() {
  ::init();
  add_action("keeps_items", "items");
  add_action("keeps_exits", "exits");
  add_action("keeps_long",  "long");
  add_action("keeps_short", "short");

  add_action("keeps_StartNewRoom", "New");
  add_action("keeps_save",         "Save");
  add_action("keeps_restore",      "Restore");
  add_action("keeps_WriteRoom", "Write");

}

status keeps_save() {
  write("Saving alterations to room.\n");
  save_object(SAVE_FILE+NAME);
  return 1;
}
 
status keeps_restore() {
  write("Restoring alterations to current room...\n");
  restore_object(SAVE_FILE+NAME);
  write("Done.\n");
  return 1;
}


status keeps_StartNewRoom() {
  string file;
  string *fileArr;
  string tmp1, tmp2;
  int i, j, k;
 
  file = file_name(environment(environment()));
  if(!sscanf(file, "%s/%s.c", tmp1, file)==2) {
    write("Invalid room file: File is a clone.\n");
    return 1;
  }
 
  /* save the room you're in, into the /ob_saves dir */
  write("Loading parameters of "+file+"\n");
  call_other(file, "save_file", SAVE_FILE);
  filetoAlter = file;
 
  /* strip off all the file parts, and leave the last bit */
  fileArr = explode(file, "/");
  file = fileArr[sizeof(fileArr)-1];
 
  /* get the saved file and put stored bits in this ob */
  write("Storing file parameters.\n");
  restore_object(SAVE_FILE+file);
 
  /* save the info under our name for future easy access */
  write("Restoring file parameters to current object.\n");
  save_object(SAVE_FILE+NAME);
  write("File ready to accept new data.\n");
  return 1;
}

static string item_long;
static string item_name;

void add_item_long(string str) { 
  add_item(item_name, str);
  write("Adding item:"+ item_name+"\n"+
	"Adding item long: "+ str +"\n");
  keeps_save();
  keeps_restore();
}


status keeps_items() {
  write("An item is a noun in the room that other players can \n"+
	"look at in the room description. It can be a single  \n"+
	"word, or a number of words separated by a #. 	      \n"+
	"E.g. chair#chairs#sofa#easy chair\n\n"+
	"What is the name of the item? > ");
  
  input_to("keeps_items2");
  return 1;
}

status keeps_items2(string str) {
  if(!strlen(str)) {
    write("Exiting add an item.\n");
    return 1;
  }

  item_name = str;
  write("The name of the item is: "+str+".\n"+
	"Is this correct? [y/n] ");
  input_to("keeps_items3");
  return 1;
}

status keeps_items3(string str) {
  object ob;

  if(str == "n" || !strlen(str)) {
    write("Exiting add an item.\n");
    return 1;
  }
  write("Adding item: "+item_name+"\n");
  write("Write the description for the item:\n");
  ob = clone_object(EDITOR);
  ob -> edit("add_item_long", item_long);
  return 1;
}

  
  
status keeps_WriteRoom() {
  string txt;
  string tmp;

  txt =  HEADER;
  if(!short_desc) short_desc = NAME+"'s room";
  txt += "  set_short("+ short_desc     +"); \n"+
  txt += "  set_long(\""+ long_desc +"\"); \n"+
  tmp = (string)call_other(C_ITEMS, "convert_items", items);

  txt += tmp +"\n";
  txt += FOOTER;
  rm("/players/angel/file.c");
  write_file("/players/angel/file.c", txt);
  return 1;
}

string query_object_type() { return "RoomGenerator"; }
string query_name()        { return "RoomGenerator"; }
string query_info()        { return query_name()+": version "+ VER +"\n"; }

get() { return 1; }
