#include <mudlib.h>
inherit "objects/bow.c";
 
reset(arg) {
  if(arg) return;
 
  set_short("an ivory bow");
  set_alias("bow");
  set_long(
    "The Ivory Bow is made from pure ivory.  Intricately carved and sculpted,\n"+
    "the elfish bow is a deadly weapon.  Very elegant in design, this bow makes\n"+
    "a fine addition to any archer's collection.\n");  
  set_info(
    "This bow requires "+ammunition+"s in a quiver.\n");
  set_value(2000); 
  set_weapon_strength(12000); 
  set_weight(5); 
  set_hit_func(this_object());
  set_wc(0);
  set_ammunition("arrow");
  set_length(10000);
  set_type("missile");
  set_sell_destruct(1);
  set_attack_msg(({
    "hit", "with an expert arrow shot.",
    "pierced", "very deeply with an arrow.",
    "fired an arrow at", "with perfect accuracy.",
    "sent a deadly arrow tearing through", ".",
    "aimed well with the bow...\n"+
    "The arrow hit", "with devastating results.",
    "aimed well with the bow...\n"+
    "The arrow hit", "with devastating results.",
    "sent a deadly arrow tearing through", ".",
  }));
}
