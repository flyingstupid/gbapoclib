#include <mudlib.h>
inherit MAGIC_SCROLL;

void reset(status arg) {
  if(arg) return;
  set_name("tome");
  set_alias("book");
  set_short("The Tome of Summoning");
  set_long(
     "This ancient tome is designed to teach apprentices the\n"+
     "art of the school of magic of Conjuration Summoning.  \n");
  add_spell("monster summon 3");
  set_weight(5);
  set_charges(50);
  set_max_charges(50);
  set_cast_level(30);
  set_class(({ "cleric", "mage", }));
  set_info("One of the pages contains a scribed spell: Monster Summon 3\n"+
     "@@query_classes:$this_object()$"+
     "@@query_spell_triggers:$this_object()$"+
     "@@query_level_string:$this_object()$");
}

  
