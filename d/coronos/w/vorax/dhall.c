/* Dining Hall -- Bureaucracy */
/* Vorax -- Darkness */

#include <mudlib.h>
inherit ROOM;

void reset (status arg) {
  reset_doors(arg);
  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall8",
    "direction",        "wooden door",
    "long",             "This is a large wooden door.  It is made of thick oak\n"+
                        "boards held together with wrought iron bands.\n",
    "door id",          "north door",
    "key id",           "mayor's key",
    "lock id",          "iron lock",
    "lock description", "An iron lock\n",
    "lock difficulty",  16,
    "closed", 
  }));

    if(arg) return;

    set_short(
      "A large dining hall\n");
    set_long(
      "You have entered a spacious dining hall. A large cedar table\n"+
      "prominently rests in the center of the room.  Several smaller\n"+
      "tables and cabinets are aranged around the perimeter of the\n"+
      "hall.  Many velvet cushioned chairs surround the elegant table,\n"+
      "and a large, lavish chandelier hangs over the table's center.\n");
    set_weather(2, 1, 0);
    set_items
    (({
      "chandelier#chandeliers",
      "The chandelier is crafted from silver and various gems.\n",
      "art#artwork",
        "The many pieces of artwork come from all over the lands.\n",
      "cushions",
        "The blue velvet cushions are soft and comfy.\n",
      "tables#cabinets",
        "These tables and cabinets are storage for silverware and eatery.\n"+
        "They can also be used as serving tables.\n",
      "dining hall#hall",
        "The dining hall is very large, and able to cater to many people.",
      "oak table#table",
        "The dining table is very shiny, allowing you to see your reflection"+
        "on the polished surface.\n",
      "chairs",
        "The chairs, like everything else in the room, are made of oak"+
        "with plush velvet cushions.\n",
      "walls",
        "The granite walls are decorated with various pieces of art.",
    }));
    set_smell(
      "Smells of all kinds of food linger in the air.\n");
    set_listen(
      "Footsteps can be heard just outside as people walk by.\n");

  if(!present("maid")){
    move_object(clone_object(
    "/d/coronos/w/newstar/npc/maid"),
    this_object());
  }
}
