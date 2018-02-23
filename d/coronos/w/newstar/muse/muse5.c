/* muse/muse5.c */
/* Newstar 1997 */
#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  if(arg) return;
 

  set_short("museum");
  set_long(
    "The museum is a vast room filled with many treasured artifacts\n"+
    "and relics.  This southeast corner is dedicated to the magnificent\n"+
    "works of art from past and present movements.  A high, vaulted\n"+
    "ceiling looms overhead, dominated by a long skylight.  An immense\n"+
    "dragon skeleton hangs underneath the glass, overshadowing the room.\n"+
    "Smooth, marble tiles cover the floor and the solid granite walls are\n"+
    "decorated with fine tapestries and paintings.  The floor space is\n"+
    "filled with diverse scupltures various medias.");
  set_day_desc(
    "  Sunlight streams\n"+
    "through the skylight, casting ephemeral shadows of the skeleton\n"+
    "the reflecting tiles of the floor.\n");
  set_night_desc(
    "  Star twinkle from\n"+
    "outside the skylight, nestled within the black sky.  The room is\n"+  
    "by lanterns evenly placed upon the walls.\n");
  set_items(({
    "museum",
      "The museum is a vast room filled with many treasured artifacts and\n"+
      "relics.  Its purpose is to educate all of the past and present.\n",
    "souteast",
      "The southeastern corner of the museum is dedicated to various forms\n"+
      "of art work, such as sculptures, paintings and tapestries.\n",
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
      "The solid granite walls are plain but elegant and contrast with\n"+
      "the wonders of the museum.  The walls of the southeastern corner\n"+
      "are decorated fine tapestries and beautiful pieces of artwork,\n"+
      "from paintings to drawings and sketchs to portraits.\n",
    "tapestries#tapestry",
      "The fine tapestries are beautifully woven wall hangings that\n"+
      "depict many different scenes of the mythical past.  Each tells\n"+
      "its own intricate tale displayed with splendid detail.\n",
    "paintings#painting",
      "Paintings of all sizes hang upon the walls depicting sundry\n"+
      "scenes of life.  The medias differ as muchs as the scenes,\n"+
      "from rich oils, vibrant acrylics and soft watercolours.\n",
    "drawings",
      "Beautiful drawings also hang upon the walls rivaling the\n"+
      "paintings in artistic value.  Charcol, pastel and simple\n"+
      "pencil are the most common to be seen.\n",
    "sketches",
      "Various different types of sketchs can also been spotted\n"+
      "amoung the more finished artworks.  They show the truer\n"+
      "sides of the artists in their simply beauty.\n",
    "portraits#portrait",
      "Stately portraits of seemingly important people hang upon\n"+
      "the walls with the other pieces of artwork.  One wonders\n"+
      "exactly how well the likenesses of these various people\n"+
      "was caught.\n",
    "scupltures#scuplture",
      "Life-like scupltures of smooth marble, soft soapstone, carved\n"+
      "wood and molded metal are scattered about the floor in this\n"+
      "corner of the museum.  From the largest to the smallest, the\n"+
      "intricate detial and special care with which they were all\n"+
      "made is truely amazing.\n", 
    "northwest",
      "The northwestern corner of the museum is dedicated to various\n"+
      "feral life forms of the past and present that roam this realm.\n",
    "north",
      "The northeastern corner of the museum is dedicated to artifacts\n"+
      "and relics of everyday life of the past, with common objects like\n"+
      "dress ware, dish ware and jewelery.\n", 
    "west",
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
    "The sophisticated scent of art gently wafts your nostrils.\n");
  set_listen(
    "All is fairly silent with the exception of footsteps echoing\n"+
    "out in the hallways of the Bureaucracy.\n");
  set_weather(2, 2, 0); 
  set_exits(({
      "/d/coronos/w/newstar/muse/muse2", "west",
      "/d/coronos/w/newstar/muse/muse3", "northwest",
      "/d/coronos/w/newstar/muse/muse4", "north",
      }));
}

