/*Skipping Stone.  Darkness. 12/96 =P */
#include <mudlib.h>
#define DEX   (int)this_player()->query_dexterity()
#define PONDQ  (string)this_player()->query_current_room()
#define POND1 "d/coronos/w/newstar/newbie/rooms/pond1"
#define POND2 "d/coronos/w/newstar/newbie/rooms/pond2"

inherit TREASURE;

void reset(status arg) {
  if(arg) return;

  set_name("stone");
  set_short("a stone");
  set_long(
    "This is a smooth, oval stone.  It has been smoothed over time.\n"+
    "It looks like it would make a perfect skipping stone.\n");
  set_weight(1);
  set_value(0);
  set_sell_destruct(1);
}

void init() {
  add_action("skipper", "skip");
  ::init(); 
}

status skipper(string str) {
  int SCORE, DIFF, THROW;
  string tmp1, tmp2;

  if(!str) {
    write("Do you wish to skip the stone?\n");
    return 1;
    }


  else if(sscanf(str, "%sstone%s", tmp1, tmp2)) { 
    
    if(PONDQ==POND1 || PONDQ==POND2) {
      if(DEX > 4)  SCORE=2;  /*assign a SCORE*/
      if(DEX > 9)  SCORE=3;
      if(DEX > 14) SCORE=4;
      if(DEX > 19) SCORE=5;    
      if(DEX < 5) SCORE=1;
  
      DIFF=random(8);     /*assign DIFFICULTY*/
      THROW=DIFF+SCORE;   /*Calculate the  THROW score*/ 

      /*Skip the stone*/                
      if(THROW<5) {
        write("You try to skip the stone, but it just sinks right\n"+
              "into the water.  PLOP!\n");
        say(this_player()->query_name()+" attempts to skip a stone across"+
            "the pond, but fails.\n"+"It just sinks into the water. PLOP!\n",
            this_player());
        destruct(this_object());
        return 1; }

       if(THROW==5) {
       write("You skip the stone once!\n"+
              "SKIP! PLOP!\n");
        say(this_player()->query_name()+" skips a stone across the pond!\n"+
            "SKIP! PLOP!\n");
        destruct(this_object());
        return 1; }

      if(THROW==6) {
        write("You skip the stone twice!\n"+
              "SKIP! SKIP! PLOP!\n");
        say(this_player()->query_name()+" skips a stone across the pond!\n"+
            "SKIP! SKIP! PLOP!\n");
        destruct(this_object());
        return 1; }

      if(THROW==7) {
        write("You skip the stone three times!\n"+
              "SKIP! SKIP! SKIP! PLOP!\n");
        say(this_player()->query_name()+" skips a stone across the pond!\n"+
            "SKIP! SKIP! SKIP! PLOP!\n");
        destruct(this_object());
        return 1; }

      if(THROW==8) {
        write("You skip the stone four times!\n"+
              "SKIP! SKIP! SKIP! SKIP! PLOP!\n");
        say(this_player()->query_name()+" skips a stone across the pond!\n"+
            "SKIP! SKIP! SKIP! SKIP! PLOP!\n");
        destruct(this_object());
        return 1; }

      if(THROW==9) {
        write("You skip the stone five times!\n"+
              "SKIP! SKIP! SKIP! SKIP! SKIP! PLOP!\n");
        say(this_player()->query_name()+" skips a stone across the pond!\n"+
            "SKIP! SKIP! SKIP! SKIP! SKIP! PLOP!\n");
        destruct(this_object());
        return 1; }
 
      if(THROW>9) {  /*A Special Skip across the pond. Move Object.*/
        write("You skip the stone across the whole pond!\n"+
              "SKIP! SKIP! SKIP! SKIP! SKIP! SKIP!\n"+
              "It lands amongst the stones on the other side.\n");
        say(this_player()->query_name()+ 
            " skips a stone across the entire pond!\n"+
            "SKIP! SKIP! SKIP! SKIP! SKIP! SKIP!\n"+
            "It lands amongst the stones on the other side.\n");

        if(PONDQ==POND1) {
          move_object(this_object(), "d/coronos/w/newstar/newbie/rooms/pond2");
          tell_room("/d/coronos/w/newstar/newbie/rooms/pond2", 
            "A stone skips across the pond and lands at your feet.\n");
          return 1; }

        if(PONDQ==POND2) {
          move_object(this_object(), "d/coronos/w/newstar/newbie/rooms/pond1");
          tell_room("/d/coronos/w/newstar/newbie/rooms/pond1.c",
            "A stone skips across the pond and lands at your feet.\n");
          return 1; }

      } /*throw>9*/
    return 0; 
    }  /*querry correct rooms*/

    else {
      write("You can't skip the stone here!\n");
      return 1; 
      }
    
  return 0;
  }  /* "skip stone" */
 return 0; 
} /*end status skipper*/
