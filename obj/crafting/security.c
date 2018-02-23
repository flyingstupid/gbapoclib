inherit "inherit/armour";

reset(arg) {
  if(arg) return;
  set_name("armour");
  set_type("Armour");
  set_short("security armour");
  set_long("A set of police issued security armour.\n");
  set_info("Nothing special jumps out at you.");
  set_ac(3);
  set_weight(4);
  set_value(1200);
  set_armour_material("Leather");
}