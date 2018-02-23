/* rooms/muse1.c */
/* Newstar 1997 */
#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  if(arg) return;

 reset_doors(arg); 
  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall8",
    "direction",        "museum door",
    "long",             "This is a thick, wooden door made of solid oak.\n"+
                        "A relief of the insignia of Ille Coronos has\n"+
                        "been carved into the top half.\n",
    "door id",          "south door",
    "key id",           "mayor's key",
    "lock id",          "iron lock",
    "lock description", "An iron lock\n",
    "lock difficulty",  16,
    "closed",
  }));

  set_short("an entrance hall");
  set_long(
    "The entrance way to the museum is a short hallway with a high ceiling\n"+
    "and solid granite walls.  A single, small, silver chandelier hangs low\n"+
    "from above, reflecting its light off the smooth, marble floor tiles.  An \n"+
    "ornate wooden reception desk sits off to the left with a red upholstered\n"+
    "chair behind it and is flanked by two large flags.  The vast museum lies\n"+
    "just a few feet ahead to the north and the main hall is to the south. \n");
  set_items(({
    "entrance#entrance way#hall",
      "The entrance to the museum is a short hallway, not as wide as the\n"+
      "main hall, with solid granite walls and smooth marble tiled floors.\n",
    "museum#north",
      "The museum is a large room filled with many old relics of the past.\n"+
      "Its purpose is to educate of ages gone by.\n",
    "desk",
      "A large, wooden reception desk made of maple, simply built but intricately\n"+ 
      "carved in high fashion.  It has been varished into a dark shine with a few\n"+ 
      "scratches marring the polished surface that come from everyday wear.\n",  
    "scratch#scratches",
      "Just a few simple scratches that come with age and everyday wear.\n",
    "ceiling",
      "The high ceiling is made of granite and is supported by wooden beams.\n"+
      "A single silver chandelier hang down low from a thick metal chain.\n",
    "beams",
      "The thick woodem beams that support the high ceiling are recessed\n"+
      "into granite walls of the hallway.\n",
    "chandelier",
      "A single, small, silver chandelier hangs from the high ceiling.\n"+
      "It is very ornate and well crafted, giving off a warm glow.\n",
    "floor",
      "The floor is made of smooth marble tiles and reflects the light\n"+
      "of the chandelier.\n",
    "walls",
      "The solid granite walls are plain but elegant and contrast with the\n"+
      "wonders of the museum.\n",
    "flags",
      "Two large stately flags stand on either side of the wooden desk with\n"+
      "long golden tassels hanging from each.   The one on the left is the\n"+
      "former flag of Ille Coronos and the one on the right is the newer flag\n"+
      "flag of Ille Coronos.\n",
   "chair",
      "A dark red upholstered chair sits behind the wooden reception desk.\n"+
      "It is large and comfortable looking, with a padded back and seat.\n"+
      "The arms and legs are ornate, resembling lion's paws.\n",   
    }));
  set_smell(
    "The scent of burning chandelier oil is the only smell\n"+
    "that permiates the air here.\n");
  set_listen(
    "Footsteps echoe throughout the halls of the Bureaucracy.\n");
  set_weather(2, 2, 0); 
  set_exits(({
      "/d/coronos/w/newstar/muse/muse2", "north",
      }));

 if(!present("tully")) { 
    int i;
    for(i=0; i<1; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/npc/tully"),this_object());} }
}

