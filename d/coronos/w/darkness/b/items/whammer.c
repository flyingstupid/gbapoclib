#include <mudlib.h>

inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("warhammer");
  set_alias("hammer");
  set_short("Brock's Warhammer");
  set_long(
    "A large dwarven warhammer expertly crafted deep within the city of Stokh.\n"+
    "The head is a solid cylindrical piece of steel with a hint of blue colour\n"+
    "to it.  The steel handle is wrapped with leather for a better grip.  The\n"+
    "dwarven symbols across the head mark the superior quality of this weapon.\n");
  set_length(28);
  set_type("crush");
  set_value(3000);
  set_wc(16);  /* +6 warhammer */
  set_weight(7);
  set_sell_destruct(1);

  set_attack_msg(({
    "missed", "",
    "crushed", "brutaly",
    "crippled", "severly",
    "devastated", "painfully",
    "slammed", "with a crushing blow to the head",
    "slammed", "with a crushing blow to the head",
    "knocked the wind out of", "with a well placed hit to the chest",
    }));
}


status wield(string str) {
  ::wield(str);
  if(id(str)) {
    if(this_player()->query_strength() < 18) {
      tell_object(environment(), 
        "The warhammer is too heavy for you to wield effectively.\n"+
        "You strain to keep it in your hands until it fnally drops\n"+
        "to the ground.\n");
      drop();
    }
  return 1;
  }
}
