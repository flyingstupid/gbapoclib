#include <mudlib.h>
inherit MONSTER;
 
void init() {
  call_out("chat",1);
  ::init();
}
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("Tully");
  set_alias("caretaker");
  set_short("Tully, the museum caretaker");
  set_long(
    "Tully is an elderly man that has been the caretaker of this museum for\n"+
    "many years.  He is a quiet scholarly man, well versed in the many relics\n"+
    "of the museum, though he can come off as being somewhat eccentric.  Thick,\n"+
    "dark rimmed glasses frame his small, squinty eyes that have endured many\n"+
    "long hours of reading.  His thinning white hair is a wild unkempt mop atop\n"+
    "his head and his rosy cheeks glow with excitment of endless knowledge.\n");
  load_chat(5, ({
    "Tully shoves his glasses back up his nose with his index finger.\n",
    "Tully runs his fingers through his unruly white hair.\n",
    "Tully hrms to himself thoughtfully.\n",
    "Tully mutters to himself in soft tones.\n",
    "Tully looks upward and scratches his head.\n",
    }));
 
  load_a_chat(40, ({
    "Tully looks shocked and confused that someone would attack him.\n",
    "Tully runs in circles around the room.\n",
    "Tully whimpers and scrambles to get away.\n",
    "Tully tries to look threatening without much success.\n",
    "Tully shouts 'This is very unbecoming behaviour!'\n", 
    }));

set_attack_msg(({
    "missed", "barely",
    "jabbed", "sharply in the ribs",
    "smacked","on the arm",
    "hit", "on the head",
    "kicked" "painfully in the leg",
    "kicked", "hard in the behind",
    "punched", "in the stomach, knocking the wind out",
    }));
 
  set_al(210);
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(95);
  set_max_hp(95);
  set_gender(1);
  set_money(200 +random(50));
  set_race("human");

}
