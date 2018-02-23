#define AUTO_LOAD_FILE "/d/affils/ships/open/init_arg"

void start_ships();

void reset(status arg) {
  if(arg) return;
  start_ships();
}
void start_ships() {
  int i;
  string txt, tmp, *files;

  txt = read_file(AUTO_LOAD_FILE);
  if(!txt) return;
  files = explode(txt, "#");
  if(!sizeof(files)) return;
  for(i=0; i<sizeof(files); i++) {
    if(!files[i]) {
      sscanf(files[i], "%s\n", tmp);
    }
    else sscanf(files[i], "%s\n", tmp);

    if(!tmp || !strlen(tmp)) continue;
    write("Loading ship file: "+tmp+"\n");
    if(catch(call_other(tmp, "reset"))) {
      log_file("SHIPS_ERRORS", files[i]+" failed to load "+ctime(time())+"\n");
    }
  }
}
