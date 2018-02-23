#include <mudlib.h>
inherit MONSTER;
object hammer; 

void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("brock");
  set_short("Brock, of Stokh.");
  set_long(
    "This Dwarf looks quite old and wise, but he still has the flame of\n"+
    "a youthfull warior in his eyes.  His bright blue eyes and graying\n"+
    "hair match the dull grays and blues of his clothes.  His dark beard\n"+
    "is long and well groomed.  He holds himself as someone with much \n"+
    "authority.\n");
    
  load_chat(2, ( {
    "Brock grins smuggly at you.\n",
    "Brock grooms his beard as he sinks into thought.\n",
    "Brock wrinkles his nose then sneezes.\n",
    "Brock closes his eyes and relaxes a bit.\n",
    "Brock stretches his arms and yawns.\n",
    }));
  load_a_chat(25, ( {
    "Brock growls loudly!\n",
    "Brock looks very mad.\n",
    "Brock: How dare you attack me here!\n",
    "Brock: You fool!\n",
    "Brock: HaHa!  You weakling!\n",
    }));
  load_l_chat(2,"dwarf", ({ 
    "Hello there.\n",
    "Good day to you.\n",
    }));
 
  set_al(100);
  set_level(36);
  set_gender(1);
  set_race("dwarf");
  add_class("fighter");
  set_max_hp(2500);
  set_hp(2500);
  set_wc(30);
  set_ac(17);
  set_intelligence(30); 
  set_money(2700+random(300));

  if(!hammer) {
    hammer = clone_object("d/coronos/w/darkness/b/items/whammer.c");
    move_object(hammer, this_object());  
    command("wield hammer");
  }
}
