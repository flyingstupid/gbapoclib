void reset(status arg) {
  if(arg) return;
  set_light(1);
}


string short() { return "room"; }


void long() {
  write("An Empty Room\n");
}

