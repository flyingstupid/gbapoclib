/* muse/muse2.c */
/* Newstar 1997 */

#include <mudlib.h>
inherit ROOM;

object candy;
void reset (status arg){

  if(!candy) {
    candy = clone_object("/d/coronos/w/newstar/npc/candy");
    move_object(candy, this_object());
  }


  if(arg) return;

  set_short("museum");
  set_long(
    "The museum is a vast room filled with many treasured artifacts\n"+
    "and relics.  This southwest corner is dedicated to the warfare\n"+
    "of the past.  A high, vaulted ceiling looms overhead, dominated\n"+
    "by a long skylight.  An immense dragon skeleton hangs underneath\n"+
    "the glass, overshadowing the room.  Smooth, marble tiles cover the\n"+
    "floor and the solid granite walls are bedecked with implements of\n"+
    "war, different types of weapons and suits of armour are lined up\n"+
    "along it.  A small old catapult sits between two long display cases.\n");
  set_day_desc(
    "Sunlight streams through the skylight, casting ephemeral shadows\n"+
    "of the skeleton upon the reflecting tiles of the floor.\n");
  set_night_desc(
    "Stars twinkle from outside the skylight, nestled within the black\n"+  
    "sky.  The room is lit by lanterns evenly placed upon the walls.\n");
  set_items(({
    "museum",
      "The museum is a vast room filled with many treasured artifacts\n"+
      "and relics.  Its purpose is to educate all of past and present.\n",
    "southwest corner#southwest#corner",
      "The southwestern corner of the museum is dedicated to artifacts\n"+
      "of warfare from the past, such as weapons, implements and armour.\n",
    "ceiling",
      "The high, vaulted ceiling is made of solid granite, forming\n"+
      "arches, supported by thick wooden beams.  A long skylight runs\n"+
      "along the ceiling's length, letting in much light.  A large \n"+
      "dragon skeleton hangs from the ceiling.\n",
    "beams",
      "The thick wooden beams that support the high ceiling are\n"+
      "recessed into granite walls of the museum.\n",
    "skylight",
      "A long, glass skylight runs along the length of the high ceiling,\n"+
      "letting in a great amount of light.  A large dragon skeleton hangs\n"+
      "underneath the skylight, overshadowing the most of the room.\n",
    "dragon skeleton#skeleton#dragon",
      "An immense dragon skeleton hangs from the ceiling, underneath\n"+ 
      "the glass skylight.  The well preserved bones have been posed\n"+ 
      "to look as if just after take off, with its large wings only\n"+ 
      "partially outstretched.  It is doubtful that even this vast\n"+
      "room could support the massive wingspan of this creature.\n",
    "bones",
      "The bones of the dragon skeleton are solid and well preserved.\n",
    "wings",
      "The large wings of the dragon skeleton are only\n"+
      "partially outstretched, for the wingspan is truly\n"+
      "impressive and formidable.\n",  
    "floor",
      "The floor is made of smooth marble tiles that reflect any\n"+
      "light in the large room.\n",
    "walls#wall",
      "The solid granite walls are plain but elegant and contrast\n"+
      "with the wonders of the museum.  The walls of the southwestern\n"+
      "corner are covered with many different types of weapons and\n"+
      "implements of war.  Various suits of armours are lined up\n"+
      "along this corner of the museum.\n",
    "catapult",
      "An small, old catapult sits between the two display cases.\n"+
      "It looks to be more of a model, then actually used for real\n"+
      "siege.  It is made of sturdy wood, looking much like a\n"+ 
      "big ladle on wheels.\n", 
    "case#cases#display cases#display case",
      "Two long, glass display cases sit on either side of a small\n"+
      "catapult.  Both cases hold very different things still having\n"+
      "to do with war.\n",
    "first case#sword",
      "A fine, bejeweled sword is nestled on a bed of dark red velvet\n"+
      "in the first display case.  The long blade gleams in the light,\n"+
      "unmarred by the common scratches of battle.  The superb hilt is\n"+
      "inlayed with gold and silver, encrusted with rare gems.  This\n"+
      "sword once belonged to a king, used purely for show.\n",
    "second case#arrows#bolts",
      "The second case is filled with different types of arrows used\n"+
      "over the years.  Regular arrows, longbow arrows and crossbow\n"+
      "bolts of various sizes lie nestled upon the blue velvet.\n",
    "blue velvet",
      "A bed of blue velvet enhances the many arrows.\n",
    "red velvet",
      "A bed of red velvet nestles the fine swords, enhancing\n"+
      "its splendor.\n",
    "armour#suits#armours#suits of armour",
      "Various different types and sizes of armours are lined up\n"+
      "against the walls.  The each comes from a age of war, starting\n"+
      "out with the bare essentials for protection to full covering\n"+
      "of iron.\n",
    "weapons",
      "Various different types of weapons decorate the walls, from\n"+
      "spears to javelins, lances to pikes, swords to daggers, lochabers\n"+
      "to axes and maces to whips can be found.  The variety and cruelty\n"+
      "of their purposes can boggle the mind.\n",
    "spears#javelins#lances#pikes#swords#daggers#lochabers#axes#maces#whips",
      "A weapon used to maim and kill in battle.  Its looks make it clear\n"+
      "as to how it might be used, none of which pleasent.\n",
    "implements",
      "The implements that hang upon the walls are the restly odds and\n"+
      "ends that help wage a brutal war.  Various devices that many not\n"+
      "always be thought of when one thinks of warfare.\n",
    "east",
      "The southeastern corner of the museum is dedicated to various\n"+
      "forms of art work, such as sculptures, paintings and tapestries.\n",
    "northeast",
      "The northeastern corner of the museum is dedicated to artifacts\n"+
      "and relics of everyday life of the past, with common objects like\n"+
      "dress ware, dish ware and jewelery.\n", 
    "north",
      "The northwestern corner of the museum is dedicated to various\n"+
      "feral life forms of the past and present that roam this realm.\n",  
    }));
  set_night_items(({
    "lanterns#lantern",
       "Large, brass lanterns are evenly placed along the walls.\n"+
       "They fill the museum with a warm glow, enhancing many of\n"+
       "soft shadows.\n",
    }));
  set_smell(
    "The smell of old, oiled metal lies thick in the air.\n");
  set_listen(
    "All is fairly silent with the exception of footsteps echoing\n"+
    "out in the hallways of the Bureaucracy.\n");
  set_weather(2, 2, 0); 
  set_exits(({
      "/d/coronos/w/newstar/muse/muse3", "north",
      "/d/coronos/w/newstar/muse/muse4", "northeast",
      "/d/coronos/w/newstar/muse/muse5", "east",
      "/d/coronos/w/newstar/rooms/muse1", "south",
      }));
}
