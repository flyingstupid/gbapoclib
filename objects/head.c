#include <mudlib.h>
inherit TREASURE;
void reset(status arg) {
  if(arg) return;
  set_name("arrow head");
  set_alias("head");
  set_value(1);
  set_weight(1);
  set_short("An arrow head");
  set_long("It appears to have been taken from the shaft of "+
           "a missile weapon.\n");
}
