void init_arg() {
  call_out("initialiseBard", 2);
}

void initialiseBard() {
  if(environment()) 
  if(present("guild_object 2", environment())) {
    destruct(this_object());
    return;
  }
  clone_object("obj/shadows/bard")->shadow_bard(environment());
}

status query_auto_load() { return 1; }
status drop() { return 1; }

void extra_long() {
  write(environment()->query_name() +" is a bard.\n");
}

status id(string str) {
  return str == "bard" || str == "guild_object"; 
}

