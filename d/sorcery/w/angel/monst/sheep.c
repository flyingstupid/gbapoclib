#include <mudlib.h>
#define CHANCE	10
#define DEX	(int)this_player()->query_dexterity()

inherit MONSTER;

status got_fleece, bad_cut;
object fleece;

void reset(status arg) {
  got_fleece = 0;
  bad_cut = 0;
  ::reset(arg);
  if(arg) return;
  set_name("sheep");
  set_plural("sheep");
  set_race("sheep");
  set_gender(1);
  set_short("A sheep");
  set_long(
	"A little woolly sheep. While he looks very experienced at \n"+
	"climbing the mountains here, he does look a bit lost.\n");
  set_level(1);

  load_chat(5, ({
	"Sheep says: Baaa.\n",
	"Sheep asks: Baaa?\n",
	"Sheep exclaims: Baaa!\n",
	"Sheep looks lost.\n",
	"Sheep munches on some grass.\n",
	"Sheep munches on your boot.\n",
	"Sheep tries to chew your boot.\n",
	"Sheep sniffs your purse string.\n",
	"Sheep looks at you blankly.\n",
  }));
  set_attack_msg(({
	"missed", "",
	"butted", "lightly",
	"bit", "lightly",
	"butted", "with a hard strike!",
	"bit", "visciously",
	"butted", "with a stunning blow!",
	"butted", "nearly unconscious!",
  }));
}

void long(status wiz) {
  if(got_fleece) {
    if(bad_cut)
      write("The sheep looks badly cut, as if a novice attempted "+
             "to shear him.\n");
    else
      write("A bald sheep. He looks cold and very nude without his fleece.\n");
  }
  else
    ::long(wiz);
}



void catch_tell(string str) {
  string tmp1, tmp2, tmp3;
  ::catch_tell(str);
  if(sscanf(str, "%syou%s\n", tmp1, tmp2, tmp2) &&
    !sscanf(str, "%s:%syou%s\n", tmp1, tmp2, tmp3)) {
    if(!query_attack())
    write("The sheep feels very fluffy and soft.\n");
  }
}

void init() {
  ::init();
  add_action("shear_me", "sheer");
  add_action("shear_me", "shear");
}

status shear_me(string str) {
  string tmp1, tmp2;
  object ob, oB;

  if(query_attack()) return 0;
  if(!str) {
    write("Sheep looks at you quizically.\n");
    return 1;
  }

  if(!ob=present("knife", this_player()) &&
     !ob=present("dagger", this_player())) {
     write("You need a knife to shear the sheep.\n");
    return 1;
  }

  if(!oB = present(str, environment(this_player()))) {
    write("That's not here.\n");
    return 1;
  }

  if(!sscanf(str, "%ssheep%s", tmp1, tmp2)) {
    write("You can only shear the sheep!\n");
    return 1;
  }

  if(oB != this_object()) return 0;

  if(got_fleece) {
    write("This sheep has already been shorn.\n");
    return 1;
  }

  if(random(CHANCE) > random(DEX)) {
    write("You shear the sheep, but don't do very well.\n");
    add_secondary_attacker(this_player());
    bad_cut = 1;
    got_fleece = 1;
    return 1;
  }
  else {
    write("You shear the sheep, and do remarkably well!\n");
    fleece = clone_object("d/sorcery/w/angel/obj/fleece");
    if(!this_player()->add_weight(1)) {
      write("The fleece falls to the ground.\n");
      move_object(fleece, environment());
    }
    else {
      write("You take the fleece.\n");
      move_object(fleece, this_player());
    }

    got_fleece = 1;
    return 1;
  }
  return 1;
}
