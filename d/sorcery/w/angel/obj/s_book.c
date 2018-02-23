#include <mudlib.h>
inherit MAGIC_SCROLL;

void reset(status arg) {
  if(arg) return;
  set_name("tome");
  set_alias("book");
  set_short("The Tome of Summoning");
  set_long(
	"This ancient tome contains much on the workings of the \n"+
	"school of necromancy; the study of the dead.\n");
  add_spell("death spell");
  set_weight(5);
  set_charges(50);
  set_max_charges(50);
  set_cast_level(30);
  set_class(({ "cleric", "mage", }));
  set_info("One of the pages contains a scribed spell: Death Spell\n"+
     "@@query_classes:$this_object()$"+
     "@@query_spell_triggers:$this_object()$"+
     "@@query_level_string:$this_object()$");
}

  
