/* mother.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
  
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("Mrs Newman");
  set_alias("mother");
  set_short("Mrs Newman");
  set_long(
    "This is Mrs Newman, the mother of this family.  She is a pretty, young\n"+
    "woman, small and slim.  She has big, beautiful, blue eyes, that sparkle\n"+
    "when she smile and long, dark blond hair that she keeps tied at the\n"+
    "nape of her neck.  She has a kind heart and a friendly nature, always\n"+
    "ready to help.  She works hard to keep this house in order.\n");
  load_chat(5, ({
    "Mrs Newman cheerfully hums a little tune.\n",
    "Mrs Newman flashes you a sparkling smile.\n",
    "Mrs Newman tucks a lock of hair behind her ear.\n",
    "Mrs Newman sighs happily and goes about her work.\n",
    "Mrs Newman smooths out the wrinkles in her dress.\n",
    }));
 
  load_a_chat(40, ({
    "Mrs Newman cries out for help.\n",
    "Mrs Newman shakes her finger, scolding sharply.\n",
    "Mrs Newman flails her arms about and shrieks with fear.\n",
    "Mrs Newman yells 'Leave me be!  I have done nothing!'\n",
    "Mrs Newman struggles with all her might to get away.\n",
    }));
 
  set_attack_msg(({
    "missed", "barely",
    "poked", "sharply in the ribs",
    "pinched","on the arm",
    "grabbed", "by the ear, painfully twisting it",
    "slapped", "across the face",
    "whacked", "across the head",
    "kicked", "hard in the shins",
    }));
 
  set_al(275);
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_hp(50 + random(5));
  set_gender(2);
  set_money(45 +random(20));
  set_race("human");
 
 
if (!present("apron")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/apron"),
    this_object());
    command("wear apron");
  }
}
