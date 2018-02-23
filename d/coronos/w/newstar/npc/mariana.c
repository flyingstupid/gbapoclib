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
  set_name("Mariana");
  set_alias("bartender");
  set_short("Mariana, the lady bartender");
  set_long(
    "The woman standing behind the counter is of average height, buxom,\n"+ 
    "and full figured.  It is hard to tell her age because she looks to\n"+
    "be in her twenties but a single white lock marrs her lustrous raven\n"+
    "black hair.  Her dark lashed grey eyes are shrewd and calculating,\n"+ 
    "highlighted with kindness.  She wears a tight fitting red bodice,\n"+ 
    "an off white muslin chemise, rolled up to her elbows and a floor\n"+
    "length black skirt.  A dirty white rag is knotted around her slim\n"+
    "waist.  Her manner and humor are somewhat lewd, raucous laugh that\n"+
    "often echos the pub.  She has a large stubborn streak with a temper\n"+
    "quick to flair, but her large soft heart is what always prevails.\n");

  load_chat(2, ({
    "Mariana asks 'What's your pleasure?'\n",
    "Mariana smiles and says 'Welcome to Seline's Song.'\n",
    "Mariana grins slyly and gives you a slow wink.\n",
    "Mariana wipes her hands off on the rag tied around her waist.\n", 
    "Mariana reties her hair back with a leather thong.\n",
    "Mariana asks 'Can I get you anything?'\n", 
    "Mariana folds her arms across her chest and leans against the counter.\n",
    "Mariana waves her hand in a flourish and comments 'Best pub in town!'\n",
    "Mariana surveys the room in a calculating manner.\n",
    }));

  set_al(215);
  set_level(13);
  set_wc(17);
  set_ac(10);
  set_max_hp(260);
  set_hp(260);
  set_money(1200);
  set_gender(2);
  set_race("human");

}
 
