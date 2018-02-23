inherit "inherit/weapon";

int charges;

reset (arg) {
  if (arg) return;
  set_name("staff");
  set_type("crush");
  set_short("Staff of Escher");
  set_long("This is a long, twisted oaken staff, with rubies enbedded\n"+
     "in it at one end. A dark red line runs the length of it.\n");
  set_wc(12);
  set_length(72);
  set_weight(4);
  set_value(2000);
  charges = 10 + random(10);
  set_sell_destruct(1);
}

init() {
  ::init();
  add_action("strike", "strike");
}

strike(str) {
  if(!str) {
     write("Strike whom?\n");
     return 1;
  }
  if(str = this_player()->query_name()) {
     if(charges > 0) {
       write("You strike yourself in the head, and feel better.\n");
       say(this_player()->query_name()+" strikes themself in the head"+
          ", and seems to enjoy it.\n", this_player());
       this_player()->adj_hp(1000);
       charges = charges - 1;
       return 1;
     }
     else {
       write("You strike yourself in the head, but nothing happens.\n");
       say(this_player()->query_name()+" strikes themself in the head"+
          ", and winces slightly.\n", this_player());
       return 1;
     }
   }
  if(!present(find_living(str), environment(this_player()))) {
     write("Strike whom?\n");
     return 1;
  }
  else {
     write("You strike "+capitalize(str)+", and they seem to enjoy it.\n");
     tell_object(find_living(str), this_player()->query_name()+" strikes"+
       " you in the head, and you feel better.\n");
     say(this_player()->query_name()+" strikes "+capitalize(str)+" in the"+
       " head, and they seem to enjoy it.\n", this_player());
     find_living(str)->adj_hp(1000);
     charges = charges - 1;
     return 1;
  }
}
