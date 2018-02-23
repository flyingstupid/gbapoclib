inherit "inherit/weapon";

reset(arg) {
    if(arg) return;

  set_name("scimitar");
  set_short("A scimitar");
  set_long("This scimitar has certainly been well used, but it's\n"+
           "still a rather usable weapon. \n");
  set_length(36);
  set_type("slash");
  set_sell_destruct(1);
  set_value(400);
  set_wc(9);
  set_weight(4);
  set_smell("It has a faint smell of rust.\n");
}

