/* This letter is a note to Grandpa Newman.  It is Unique just for storie's sake.
   It hints that the armour is something special in this area.
*/

#include <mudlib.h>
inherit TREASURE;
 
 void reset (status arg){
  if(arg) return;
 
  set_weight(1);
  set_value(0);
  set_name("old letter");
  set_alias("letter");
  set_short("an old letter");
  set_long(
    "This is a very old letter written on parchment.  The parchment is\n"+
    "very yellowed and crumbly.  The ink is a little faded, but you can\n"+
    "still make out a soldier's crest stamped at the top of the letter.\n"+
    "Some of the writing is legible here and there, but it is mostly\n"+
    "illegable.\n");
  set_sell_destruct(1);
}

void init() {
  ::init();
  add_action("reader", "read");
}

status reader(string str) {
  string tmp1, tmp2;
  if(!str) {
    write("What are you trying to read?\n");
    return 1;
  }
  if(sscanf(str, "%sletter%s", tmp1, tmp2)) { 
    write(
     "You handle the crumbly parchment carefully as you try to read the  \n"+
     "fading letter.  The top half of the page is legible, but it begins \n"+
     "to fade and blur towards the bottom.                             \n\n"+ 
     "#################################################################  \n"+
     "#                                                  . ... .  ... #  \n"+  
     "# Lieutenant Newman,                                            #  \n"+
     "#                                                               #  \n"+
     "#    After years of your loyal services and dedication to your  #  \n"+
     "# regiment, we present to you an honorable discharge due to your#  \n"+
     "# leg injuries recieved during .. . .  .    ..     ...          #  \n"+
     "# ...              .        ...          .       ...      ..    #  \n"+
     "#    .     ..          .          ...     ..     . . ..     ... #  \n"+
     "#  .    ..      .          .    ..       ...     .. hereby also #  \n"+
     "# present you with your newely gilded Lieutenant's armour as a  #  \n"+
     "# token of our esteemed appreciation for your heroism .. .   .  #  \n"+
     "# . .   .   ...    .    .     .      ...       .    ..      .   #  \n"+
     "#  .  .     .    ..   .    .   .  .   ..                        #  \n"+
     "#                                                               #  \n"+
     "#                                           ..  . . .           #  \n"+
     "#                                              . ... ..         #  \n"+
     "#                                              ... ... .        #  \n"+  
     "#################################################################  \n");     

    return 1;
  } 
  return 0;
}
