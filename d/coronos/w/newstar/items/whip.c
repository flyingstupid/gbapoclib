/*Newstar*/
#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("whip");
  set_short("a leather whip");
  set_alias("  ");
  set_long(
    "This is a well crafted, leather whip made in Sillin for their fine horsemasters.\n"+
    "It is made from thick cowhide, wound together with a fringed tip.  The handle is\n"+
    "long and wrapped in black suede, making it easier to grip.  The end of the handle\n"+
    "is silver, engraved with the crest of Sillin, marking its fine craftsmanship.  It\n"+
    "is common to find this whip used by great horsebreeders.\n");
  set_value(1100);
  set_sell_destruct(1);
  set_length(50);  /* A whip is longer, but can be wield w/ another weapon */
  set_type("whip");
  set_wc(12); 
  set_weight(5);
  set_attack_msg(({
    "snapped the air next to", "with a loud crack",
    "slashed", "severely",
    "gave", "a deep, painful gash",
    "maimed", "brutally",
    "tore through", "deeply", 
    "struck", "with great precision", 
    "struck", "with great precision",
  }));
}
