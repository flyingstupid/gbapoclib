#include <mudlib.h>
inherit WEAPON;

reset (arg) {
  if (arg) return;
  set_name("club");
  set_type("crush");
  set_short("A small stick");
  set_long("It looks like part of a dead tree branch.\n"+
           "If it were regular size, it could pass off as a club.\n");
  set_wc(6);
  set_length(20);
  set_weight(2);
  set_value(1);
  set_alias("stick");
}
