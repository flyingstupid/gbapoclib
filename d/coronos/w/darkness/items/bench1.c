#include <mudlib.h>
 
inherit "inherit/chair";
 
 
reset(string arg)  {
  if (arg) 
    return;
 
  ::reset();
 
  set_name("bench");
  set_short(0);
  set_long(
    "This is a bench built into the gazebo.  It is made of darkened\n"
    "oak boards.\n"
    );
  set_weight(10000);
  set_max_sitters(12);
}
