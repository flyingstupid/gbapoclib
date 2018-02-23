inherit "inherit/food";

reset (arg) {
  if (arg) return;
  set_alias("bit");
  set_name("food");
  set_short("bit of food");
  set_long("This old bit of food still looks edible.\n");
  set_weight(1);
  set_value(0);
  set_strength(1);
  set_eater_mess("You close your eyes, and cram the nasty bit of food into"+
     " your mouth.\n");
}
