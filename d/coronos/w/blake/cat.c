inherit "inherit/monster";

void reset(status arg) {
  ::reset(arg);

  if (arg) return;
  set_name("cat");
  set_race("cat");
  set_short("a cat");
  set_long(
    "A small grey cat with white tiny paws. It has large yellow eyes and \n"+
    "a pink nose. The tail is darker then the rest of the fur, almost \n"+
    "black. Your presence doesn't seem to bother the cat at all.\n");
  set_level(3);
  set_alignment(50);
  set_hp(55 + random(15));    
  set_ac(5);
  set_gender(random(2) + 1);
  set_wc(7);
  set_aggressive(0);
  set_wander(25,80);
  load_chat(10, ({ "Cat licks its nose.\n",
     "Cat rub against you.\n",
     "Cat looks up at you.\n",
     "Cat sits down and licks its fur.\n",
     "Cat spots a bird in the distance.\n" 
  }));

  load_a_chat(13, ({ "Cat bites at you.\n",
     "Cat cries out in pain.\n",
     "Cat fails to run away.\n",
  }));
 
  set_attack_msg(({
     "bit",         "deep at the throat",
     "bit",         "on the arm",
     "nibbled",     "onn the leg"
    "chomped",     "on the ankle",     "nibbled",     "on the toe",     "nibbled",     "with it's teeth",     "grazed",      "with its claws"  }));  set_dead_ob(this_object());}monster_died() {  move_object(clone_object("objects/disease"),this_object());}
