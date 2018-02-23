#include <mudlib.h>
inherit CONTAINER;
 
void reset(status arg) {
  if(arg) return;
  set_name("mailbox");
  set_alias("door");
  set_short("A mailbox");
  set_long(
    "This is a small mailbox made of wood.  It is attatched\n"+
    "to a short wooden beam.  The wooden door has a sign on\n"+
    "it.  The sign reads,'::Newman::'\n");
  set_max_weight(4);
  set_weight(10000);
  set_closed(1);
}
