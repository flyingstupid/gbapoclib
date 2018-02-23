#include <mudlib.h>
/* THIS room isn't done yet..needs to be fixed -Russ */
/* Its done now....have fun -Monger =) */
string ring;
inherit ROOM;

  static status open;
  void reset(status arg) {
  open = 0;
  if(arg) return;

  set_short("a bedroom in a small house");
  set_long("\
This is a small, peaceful bedroom. Softly lapping water can be heard\n\
through an open window, and the smell of the ocean lingers in. Large,\n\
colorful sea murals cover the walls, and shells lay here and there\n\
about the room. A comfortable looking feather bed sits in one corner,\n\
covered in turqouise silk. Silk robes and dresses hang from a clothing\n\
rack in one corner, and a bookcase filled with old books stands in\n\
another. An antique writing desk is the only other furniture in this\n\
room. A walnut door leads back to the living room.\n");
  set_search_array(({
"room", "A small jeweled box sits on the desk. It looks like it could be opened.",
"desk", "A small jeweled box sits on the desk, maybe you could open it?",
"box", "Try to open it.",
}));
  set_weather(2, 2, 0);
  set_items(({
"window",
"The window stands slighty ajar.\n",
"murals#walls",
"Colorful murals of the sea have been painted onto the walls.\n",
"shells",
"Pale pastel shells lie around the room at different places.\n",
"bed#silk#linens",
"The feather bed is covered in turqouise linens.\n",
"robes#dresses#rack#clothing rack",
"Beautiful dresses and robes of silk hang on this wooden rack.\n",
"bookcase#books",
"The books in the boockcase are rather dusty.\n",
"desk#writing desk",
"There is a small jeweled box on the desk, it looks like it can\n\
be opened.\n",
"box#jeweled box",
"The box is covered in jewels, and looks like it can be opened.\n",
}));
  set_exits(({
"/d/coronos/w/russkie/rooms/h1", "east",
}));
}
  void init() {
  add_action("open", "open");
  ::init();
}
open(string str){
  string tmp1, tmp2;
 if(str!="box"){
  write("Open what?\n");
  return 1;
  }
 if(open == 1){
  write("The box is already open!\n");
  write("The box is empty.\n");
  return 1;
 }
  if(ring == 1){
   write("You open the box and it's empty!\n");
    return 1;
    }
  write("You open the box and a sparkling ring falls out!\n");
  move_object(clone_object("/d/coronos/w/russkie/obj/ring"),this_player());
  open = 1;
  ring = 1;
 call_out("redo",1800);
  say(this_player()->query_name() +"opens a jeweled box.\n");
  return 1;
}
redo(){
  tell_room(this_object(),"The box glows briefly and closes.\n");
 open = 0;
 ring = 0;
 return 1;
 }
