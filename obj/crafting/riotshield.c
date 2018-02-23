inherit "inherit/armour";

reset(arg) {
  if(arg) return;
  set_name("shield");
  set_type("Shield");
  set_short("riot shield");
  set_long("A police issued riot shield.\n");
  set_info("Nothing special jumps out at you.");
  set_ac(2);
  set_weight(3);
  set_value(400);
  set_armour_material("Metal");
}