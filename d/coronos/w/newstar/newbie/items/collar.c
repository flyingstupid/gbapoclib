#include <mudlib.h>
inherit CLOTHING;
 
reset(arg) {
  if(arg) return;
  set_name("dog collar");
  set_alias("collar");
  set_short("a dog collar");
  set_long(
    "This is a simple dog collar made of leather.\n");
  set_weight(1);
  set_value(20);
  set_sell_destruct(1);
}
