#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  if(arg) return;
 

  set_short("museum");
  set_long(
    "The museum is a vast room filled with many treasured artifacts\n"+
    "and relics.  This northwest corner is dedicated to the wildlife\n"+
    "that roams the realm.  A high, vaulted ceiling looms overhead,\n"+
    "dominated by a long skylight.  An immense dragon skeleton hangs\n"+
    "underneath the glass, overshadowing the room.  Smooth, marble\n"+
    "tiles covers the floor and the solid granite walls are bedecked\n"+
    "with different types of creatures.  A few full sized animals\n"+
    "stand along the walls with tall display cases in between them.\n");
  set_day_desc(
    "Sunlight streams through the skylight, casting ephemeral shadows\n"+
    "of the skeleton upon the reflecting tiles of the floor.\n");
  set_night_desc(
    "Stars twinkle from outside the skylight, nestled within the black\n"+  
    "sky.  The room is lit by lanterns evenly placed upon the walls.\n");
  set_items(({
    "museum",
      "The museum is a vast room filled with many treasured artifacts and\n"+
      "relics.  Its purpose is to educate all of the past and present.\n",
    "northwest corner#northwest",
      "The northwestern corner of the museum is dedicated to various\n"+
      "feral life forms of the past and present that roam this realm.\n",
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
      "covered with many different types of creatures known to this realm.\n"+
      "Various full sized stuffed animals stand along the walls.\n",
    "creatures#creature",
      "The heads and various limbs of many creatures hang upon these\n"+
      "walls.  They come from all niches of the realms and have been\n"+
      "placed here to help educate the towns folk of their existence.\n"+
      "Some of them are everyday creatures expected to been seen in a\n"+
      "nearby forest, field or mountain.  Others are feral creatures\n"+
      "which make up childern's nightmares and imaginings.\n", 
    "heads",
      "Many different creature heads hang upon the walls.\n",
    "limbs",
      "Various limbs protude from the these walls.  They can serve many\n"+
      "different purposes and are essential to the creatures make up.\n",
    "case#cases#display cases#display case",
      "Many tall display cases stand in between the creatures set upon\n"+
      "the floor.  They are filled with many insects, birds, reptiles\n"+ 
      "and small animals.\n",
    "birds",
      "All types and sizes of birds are perched and nestled within the\n"+
      "glass walls of the display cases.\n",
    "insects",
      "Many different types of insects have been mounted upon boards\n"+
      "with bodyparts outstretched and are protected within the case.\n",
    "small animals#rodents",
      "Mainly small rodents make up the small animals that fill the\n"+
      "display cases.\n",
    "reptiles",
      "Various types of feared reptiles lie motionless within the\n"+
      "display cases.  Though the majority are totally harmless,\n"+
      "they still seem to instill some kind of fear with people.\n",
    "animals",
      "Full bodied animals stand between the various display cases.\n"+
      "They are set in different poses in order the bring to life\n"+
      "their normal nature beyond these walls.\n",
    "souteast",
      "The southeastern corner of the museum is dedicated to various forms\n"+
      "of art work, such as sculptures, paintings and tapestries.\n",
    "east",
      "The northeastern corner of the museum is dedicated to artifacts\n"+
      "and relics of everyday life of the past, with common objects like\n"+
      "dress ware, dish ware and jewelery.\n", 
    "south",
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
    "The smell of taxidermy materials and dust lingers in the air.\n");
  set_listen(
    "All is fairly silent with the exception of footsteps echoing\n"+
    "out in the hallways of the Bureaucracy.\n");
  set_weather(2, 2, 0); 
  set_exits(({
      "/d/coronos/w/newstar/muse/muse2", "south",
      "/d/coronos/w/newstar/muse/muse5", "southeast",
      "/d/coronos/w/newstar/muse/muse4", "east",
      }));

  }
