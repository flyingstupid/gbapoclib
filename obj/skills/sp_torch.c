inherit "objects/torch";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_short("a stick");
  set_name("stick");
  set_plural("sticks");
  set_alt_name("torch");
  set_fuel(6000);
  set_max_fuel(6000);
  set_light_intensity(2);
  set_value(40);
}


void long(status wiz) {
  if(query_time_left() != -1)
    write("This is a piece of timber that burns with an enhanced magical\n"+
          "flame. The flame looks much brighter, and seems to burn much\n"+
          "longer then a normal flame.\n");
  else
    write("This stick looks slightly charred on the end.\n");
}

void time_out() {
  tell_room(environment(), "The "+query_name()+" winks out and crumbles...\n");
  ::time_out();
}

void dispel_magic() {  time_out(); }


