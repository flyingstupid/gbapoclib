#include <mudlib.h>
inherit WAND;

void reset(status arg) {
  if(arg) return;
  set_name("wand");
  set_short("Wand");
  set_long("The wand is scribed with ancient runes of magical power.\n");
  set_read("The runes are magical, you cannot read them.\n");
  set_weight(1);
  set_value(300);
  set_charges(100);
  set_info("@@query_charges_string:$this_object()$@@"+
           "@@query_classes_string:$this_object()$@@"+
           "@@query_level_string:$this_object()$@@"+
           "@@query_spell_triggers:$this_object()$@@");
}

status get() { return 1; }


