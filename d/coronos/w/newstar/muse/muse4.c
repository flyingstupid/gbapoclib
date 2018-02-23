/* muse/muse4.c */
/* Newstar 1997 */
#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  if(arg) return;
 

  set_short("museum");
  set_long(
    "The museum is a vast room filled with many treasured artifacts and\n"+
    "relics.  This northeast corner is dedicated to objects of everyday\n"+
    "life in the realm.  A high, vaulted ceiling looms overhead, dominated\n"+
    "by a long skylight.  An immense dragon skeleton hangs underneath the\n"+
    "glass, overshadowing the room.  Smooth, marble tiles cover the floor\n"+
    "and the solid granite walls are covered with various papers, and odd\n"+
    "farm equipment.  Other objects of customary life are found in the many\n"+
    "display cases in this corner of the room."); 
  set_day_desc(
    "  Sunlight streams through\n"+
    "the skylight, casting ephemeral shadows of the skeleton upon the\n"+
    "reflecting tiles of the floor.\n");
  set_night_desc(
    "  Stars twinkle from outside\n"+
    "skylight, nestled within the black sky.  The room is lit by lanterns\n"+  
    "evenly placed upon the walls.\n");
  set_items(({
    "museum",
      "The museum is a vast room filled with many treasured artifacts and\n"+
      "relics.  Its purpose is to educate all of the past and present.\n",
    "northeast corner#northeast",
      "The northeastern corner of the museum is dedicated to artifacts\n"+
      "and relics of everyday life of the past, with common objects like\n"+
      "dress ware, dish ware and jewelery.\n", 
    "ceiling",
      "The high, vaulted ceiling is made of solid granite, forming\n"+
      "arches, supported by thick wooden beams.  A long skylight runs\n"+
      "along the ceiling's length, letting in much light.  A large\n"+
      "dragon skeleton hangs from the ceiling.\n",
    "beams",
      "The thick wooden beams that support the high ceiling are recessed\n"+
      "into granite walls of the museum.\n",
    "skylight",
      "A long, glass skylight runs along the length of the high ceiling,\n"+
      "letting in a great amount of light.  A large dragon skeleton hangs\n"+
      "underneath the skylight, overshadowing the most of the room.\n",
    "dragon skeleton#skeleton#dragon",
      "An immense dragon skeleton hangs from the ceiling, underneath the\n"+ 
      "glass skylight.  The well preserved bones have been posed to look \n"+ 
      "as if just after take off, with its large wings only partially\n"+ 
      "outstretched.  It is doubtful that even this vast room could\n"+
      "support the massive wingspan of this creature.\n", 
    "bones",
      "The bones of the dragon skeleton are very thick and well preserved.\n",
    "wings",
      "The large wings of the dragon skeleton are only partially\n"+
      "outstretched, for the wingspan is truly impressive and\n"+ 
      "formidable.\n",  
    "floor",
      "The floor is made of smooth marble tiles that reflect any light\n"+
      "in the large room.\n",
    "walls",
      "The solid granite walls are plain but elegant and contrast with the\n"+
      "wonders of the museum.  The walls of the northwestern corner are\n"+
      "covered with tools of farming life and various papers.\n",
    "tools#equipment#farm tools#farm equipment",
      "Various metal and wooden farm tools hang upon the walls to show\n"+
      "what realm farmlife consists of daily.\n",
    "paper#papers",
      "At closer glance, the papers show to be different maps of the\n"+
      "realm and various parchements.\n",
    "map#maps",
      "The maps are of the past and present.  The show different ares\n"+
      "throughout the realm.\n",
    "parchments#parchment",
      "The parchments have bits of history and folklore written upon\n"+
      "them to make us more aware of this realm's continuing culture.\n",
    "display cases#display case#case#cases",
      "Many, different sized disply cases are setup along the wall\n"+
      "while others take up floor space.  Clothing, dishware, jewlery,\n"+
      "and small musical instruments are amoung the objects housed\n"+
      "within the cases.\n",
    "dressware#dress ware#clothing",
      "Female and male clothing is set up in some of the display cases.\n"+
      "They range from simply peasent clothing to the elaborate outfits\n"+
      "of nobles and royalty.\n",
    "peasent clothing",
      "Unadorned clothing made in a simple but purposeful manor of\n"+
      "plain, homespun cloth.\n",
    "outfits#elaborate outfits",
      "Beautiful pieces of clothing finely taliored from expensive\n"+
      "bolts of silk, satin and the like.\n",
    "dishware#dish ware",
      "Pottery, dishes and eating utensils are set up in some of the\n"+
      "smaller display cases.\n",
    "pottery",
      "Fine ceramic bowls and jugs from a past age.  Some of them are\n"+
      "are whole pieces but most of them are just shards.\n",
    "dishes",
      "Plain and simple to fine and costly dishes all with the same\n"+
      "purpose to be used to eaten off of and to serve food.\n",
    "eating utensils",
      "Wooden, silver and gold eating utensils from various types\n"+
      "of households.\n",
    "jewlery",
      "Expensive gold and silver jewlery encrusted with sparkling\n"+
      "gems that was once worn by noblity of the past.\n",
    "musical instruments",
      "Different types of finely crafted musical instruments that\n"+
      "would all produce beautifully rich tones.\n",
    "south",
      "The southeastern corner of the museum is dedicated to various\n"+
      "forms of art work, such as sculptures, paintings and tapestries.\n",
    "east",
      "The northwestern corner of the museum is dedicated to various\n"+
      "feral life forms of the past and present that roam this realm.\n",
    "southwest",
      "The southwestern corner of the museum is dedicated to artifacts of\n"+
      "warfare from the past, such as weapons, implements and armour.\n",  
    }));
  set_night_items(({
    "lanterns#lantern",
      "Large, brass lanterns are evenly placed along the walls.\n"+
      "They fill the museum with a warm glow, enhancing many of\n"+
      "soft shadows.\n",
    }));
  set_smell(
    "A mixture of dust and old memories seems to linger.\n");
  set_listen(
    "All is fairly silent with the exception of footsteps echoing\n"+
    "out in the hallways of the Bureaucracy.\n");
  set_weather(2, 2, 0); 
  set_exits(({
      "/d/coronos/w/newstar/muse/muse2", "southwest",
      "/d/coronos/w/newstar/muse/muse5", "south",
      "/d/coronos/w/newstar/muse/muse3", "west",
      }));
}

  
