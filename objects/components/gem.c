 
#include <mudlib.h>
inherit TREASURE;

 
void reset (status arg){
  string *arr, ruby;

  arr = ({
	"saphire", "ruby", "emerald", 
  });
  ruby = arr[random(sizeof(arr))];

    if(arg) return;
 
    set_weight(1);
    set_value(10);
    set_name("Gem");
    set_alias("gem");
    set_short("a gem");
    set_long("It looks like a small "+ruby+".\n");
    set_extra_info("It doesn't look very valuable.");
}
