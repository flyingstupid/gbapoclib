#define TP this_player()

status url(string arg) {
  if(!arg) {
    TP->set_URL("");
    write("Your home page address has been removed.\n");
    return 1;
  }
  TP->set_URL(arg);
  write("You home page address has been set to "+arg+"\n");
  return 1;
}
