#include <mudlib.h>
#define PATH    "d/coronos/w/angel/ud/l1"

inherit ROOM;                         
 reset(arg){
         ::reset(arg);


         set_short("A dangerous cliff");
         set_long(
       "As you enter, you notice that you are standing atop a large canyon "+
       "which looks very steep, and dangerous. When you look up you see "+
       "the clouds. You wonder what this vine could be for. There is a sign "+
       "posted here.\n");
         set_weather(3,4,3);
	 set_exits(({
        PATH+"/begin", "south",
        PATH+"/cliff2", "north",
        }));
          set_items(({"canyon#rock#rock formation", "A massive canyon stands here, "+    
 "it was carved by a mighty river.\n",
                      "ground#room#floor", "All the you notice in this area is the canyon.\n",
                      "sky#vine", "A huge vine reaches up to the sky.\n",
"town", "This canyon lies on the outside of town.\n",
"cloud#clouds", "They are fluffy clouds.\n",
                      "sign", "A large sign, maybe you should read it.\n",


 }));
set_smell("You smell the air as it wisps throuhg the canyon.\n");
set_listen("You hear a breeze coming out of the canyon.\n");

}
void init(){
   ::init();
   add_action("climb","climb");
add_action("read_sign","read");
}
int climb(string str){
     if(str=="vine"){
 write("You gaze up at the massive vine and realize you may be able to climb\n "+
"it. You pull all your strength together and hurl your body up the vine.\n "+
"When you pass the cloud cover, you notive a town, up in the sky.\n");
  this_player()->move_player(
      "silent#/d/statiu/w/leanai/cloud/1.c");
   return 1;
   }
   write("Climb what?\n");
   return 1;
}
status read_sign(string arg)
{
  if(!arg || arg != "sign")
    return 0;
 write("+---------------------+\n");
 write("|  DANGEROUS CLIFF    |\n");
 write("+---------------------+\n");
  return 1;
}      



