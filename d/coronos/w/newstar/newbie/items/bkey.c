#include <mudlib.h>
inherit TREASURE;
 
void reset (status arg){
  if(arg) return;
  
  set_weight(1);
  set_value(10);
  set_sell_destruct(1);
  set_name("old bronze key");
  set_alias("key");
  set_short("an old bronze key");
  set_long("This is a small key made of bronze.  It has a\n"+
           "soldier's crest engraved on it.\n");
}
