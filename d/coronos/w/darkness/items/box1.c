#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {
  if(arg) return;
  set_name("box");
  set_plural("boxes");
  set_short("A wooden box");
  set_long("This small wooden box is simple in design.  It has its five\n"+
           "sides nailed together, and then a hinged top can be closed\n"+
           "and opened easily.\n");
  set_max_weight(6);
  set_value(75);
  set_weight(2);
  set_closed(1);
}
