#include <mudlib.h>
inherit CLOTHING;

void reset(status arg) {
  if(arg) return;
  set_short("A small badge");
  set_long("The badge bears the symbol of the city Ille Coronos, and \n"+
	"designates its wearer as a deputy and legal bounty hunter.\n");
  set_weight(1);
  set_name("badge");
  set_alias("bounty license");
}

status query_auto_load() { return 1; }
status drop(status wiz)  { return 1; }
