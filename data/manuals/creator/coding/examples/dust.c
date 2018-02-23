/* dust of dissapearance! */

#include <mudlib.h>
inherit SCROLL;

void reset(status arg) {
  if(arg) return;
  set_name("dust");
  set_alias("pinch");
  set_short("A pinch of dust");
  set_plural("pinches of dust");
  set_long(
    "The dust seems to be made from diamonds or some such thing as \n"+
    "it appears to refract some of the light.\n");
  set_info("This is dust of dissapearance.\n");
  add_spell("invisibility");
  set_casting_msg("You sprinkle the dust all over you...\n");
  set_max_charges(8);
  set_cast_level(8);
  set_charges(8);

}
