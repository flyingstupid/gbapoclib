mixed *horse_info;

status describe_horse_long();
status horse_describe_long();

status name(string str) {
  horse_info = ({});
  if(!str) {
    notify_fail("Name what?\n");
    return 0;
  }
  write("What is the name of your steed? > ");
  input_to("name2");
  return 1;
}

status name2(string str) {
  if(!str[0]) {
    notify_fail("Ok.\n");
    return 0;
  }
  horse_info = ({ capitalize(str), });  
  write("What is the description of your horse? \n");
  horse_describe_long();
  return 1;
}

status horse_describe_long() {
  string str;
  clone_object("obj/editor")->edit("describe_long", str);
}

void describe_long(string arg) {
  horse_info += ({ arg, });
  write("Your steeds' name is: "+horse_info[0]+"\n"+
        "Your steeds' description is: \n"+horse_info[1]+"\n");
  this_player()->set_horse_info(horse_info);
  "/bin/skills/classes/paladin/call"->call("steed", 1);
}

/* when the editor does a quit and No save it calls editor_quit(), */
void editor_quit(string arg) {
  switch(arg) {
    case "describe_long":
      write("Your steed's descriptions have not been changed.\n");
    break;
  }
}

