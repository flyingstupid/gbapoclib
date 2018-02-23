#include <mudlib.h>

inherit MONSTER;
void make_nuts();
void reset(status arg) {
  ::reset(arg);

  if(arg && !present("nuts"))
    make_nuts();

  else {
    set_name("possum");
    set_alias("possum");
    set_short("A cute little ring tailed possum");
    set_long("A little grey possum. Although it looks cute and timid \n"+
             "it will probably right to keep its home, here in the rafters\n"+
             "here above the rotunda.\n");
    set_gender(random(2) + 1);
    set_race("possum");
    set_level(1);
    set_hp(50);
    set_ac(3);
    set_wc(5);
    load_chat(10,({ "Possum chatters away.\n",
     "Possum runs around in the rafters.\n",
     "Possum chatters happily.\n",
     "Possum chatters hungrily.\n",
     "Possum chatters noisily.\n",
     "Possum searches for more nuts.\n",
     "Possum bounces around.\n",
    }));

    load_a_chat(10,({ "Possum yelps in pain.\n",
     "Possum cries out for help!\n",
     "Possum snarls ferociously.\n",
     "Possum tries to run away, but fails!\n",
    }));
    set_heart_ob(this_object());
    make_nuts();
  }
}

void monster_heart_beat() {
  if(present("nuts") && !random(10)) 
    command("eat nuts",this_object());  /* he eats them!! */
}

void make_nuts() {
  object obj;
  int i;
  for(i=0; i<random(4)+1; i++) {
    obj = clone_object(FOOD);
    obj -> set_name("nuts");
    obj -> set_short("Some nuts");
    obj -> set_long(
               "A handful of tasty gum nuts.\n");
    obj -> set_value(5);
    obj -> set_weight(1);
    obj -> set_room_msg(
          "@@query_name:$this_player()$@@ hungrily munches on some "+
          "@@query_name:$this_object()$@@.\n");
    obj -> set_consumer_msg("The nuts taste so yummy! It's no wonder "+
          "possums love them so much!\n");
    obj -> set_strength(5);
    move_object(obj, this_object());
  }
}

