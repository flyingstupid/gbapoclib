/* magic scroll */

#include <mudlib.h>
inherit WAND;

void reset(status arg) {
  if(arg) return;
  set_casting_msg("The magical words on the scroll begin to glow.\n");
  set_name("scroll");
  set_short("A scroll");
  set_long("A scroll. It contains ancient runes of magical power.\n");
  set_read("The runes are magical, you cannot read them.\n");
  set_weight(1);
  set_charges(100);
  set_domain_safe(1);
  set_info("@@query_classes_string:$this_object()$@@"+
           "@@query_level_string:$this_object()$@@"+
           "@@query_spell_triggers:$this_object()$@@");
}

status get() { return 1; }

void end_spell() {     /* called when end of spell */
  if(query_name() == "scroll")
    write("The light from the magical words fade.\n");

  write("The "+query_name()+" fades into oblivion...\n");
  destruct(this_object());
}

status load_spell(string str) {
  if(this_player()->test_dark()) return 1;
  return ::load_spell(str);
}

string query_object_type() { return "Scroll"; }

void init() {
  ::init();
}
