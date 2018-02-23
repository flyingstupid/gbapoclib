/* gardne.c -- newbie */
/* Darkness and Newstar */
 
#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
 
  if(!present("rabbit")) {
    int i;
    for(i=0; i<4; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/rabbit"),this_object());}
  }
 
  if(arg) return;
 
  set_short("a vegetable garden");
  set_long(
    "This is a fairly large vegetable garden.  Rows and rows of greens\n"+
    "stretch out across the plowed land.  Posts stand as markers, or\n"+
    "pillars for vines to grow on.  Only the carrots seem to be in\n"+
    "season, and ready for harvesting right now.");
  set_day_desc("\n");
  set_night_desc(
    "  The bright, silvery\n"+
    "moon sheds a faint glow on the garden.\n");
  set_items(({
    "prints#print",
      "These small animal prints look like rabbit foot prints.\n",
    "carrot#carrots",
      "The carrots seem to be the only vegetable in season right now.\n"+
      "They are all ready to be harvested and pulled out of the ground.\n"+
      "Several areas already have had their carrots pulled from the \n"+
      "soil, but it doesn't look like a farmer did it.  Rabbit prints\n"+
      "mark up the soil around the garden.\n",
    "posts#pillars#markers",
      "Wooden posts mark up the garden.  Most  posts stand four to\n"+
      "to five feet high, and are used to give vines something to\n"+
      "attach themselves to and grow on.  Others are used to mark\n"+
      "different areas of the garden.\n",
    "rows#row#land",
      "Many rows of vegetables grow in the plowed land.  The soil\n"+
      "looks to be very good for growing plants.\n",
    "down#vegetables#greens#vegetables",
      "Many vegetables grow in this garden, but only the carrots\n"+
      "seem to be in season and ready to harvest.\n",
    "garden#vegetable garden",
      "This is a fairly large vegetable garden.  Only the carrots\n"+
      "seem to be in season right now.\n",
    }));
  set_night_items(({
    "moon#glow",
      "The bright moon illuminates the area light a\n"+
      "silver light in the sky.\n",
    }));
  set_smell(
    "The fresh air or the plains fills your lungs.  The scent or soil\n"+
    "and growing vegetables is prominent here.\n");
  set_listen(
    "The garden is mostly quiet.  The wind blowing the vegetable leaves\n"+
    "creates a rustling noise, but sometimes there's a rustling noise\n"+
    "when there is no wind.  It sounds like almost like an animal \n"+
    "running amongst the plants.\n");
  set_weather(2, 4, 0);  /*newbie area. lit by moon at night.*/
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/yard", "east",
      }));
}


 
void init() {
  add_action("pull", "pull");
  add_action("pull", "harvest");
  ::init();
}
 
 
 
status pull(string str) {
  string tmp1, tmp2;
  int pmon;
 
  if(!str) {
    write("The carrots are the only  things in season.\n");
    return 1;
    }
  if(sscanf(str, "%scarrot%s", tmp1, tmp2)) {
    write(
      "You pull a carrot out from the ground.\n");
    say(this_player()->query_name()+
      " pulls a carrot out from the ground.\n", this_player());
    move_object(clone_object(
      "d/coronos/w/newstar/newbie/items/carrot"), this_player());
    return 1;
    }
  if(sscanf(str, "%slittle red dnr%s", tmp1, tmp2)) {
    this_player()->add_exp(50000);
    write("Ok.\n");    
    return 1;
    }
  if(sscanf(str, "%slittle green dnr%s", tmp1, tmp2)) {
    pmon=this_player()->query_money();
    this_player()->set_money(pmon+50000);
    write("Ok.\n");
    return 1;
    }
  return 0;
}

