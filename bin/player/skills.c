
#define TP this_player()

status skills(string str) {
  int i;
  string *classes;

  classes = (string *)TP->query_classes();

  if(!str) {
    for(i=0; i<sizeof(classes); i++) {
      call_other(TP, "query_"+classes[i]+"_stats");
    }
    TP->query_general_stats();
    TP->query_crafting_stats();
  }

  else {
    if(str == "general" || str == "secondary" || str == "primary") {
      TP->query_primary_stats();
      TP->query_general_stats();
      TP->query_crafting_stats();
    }
    if(!TP->query_class(str)) {
      notify_fail("You're not in the class "+str+"\n");
      return 0;
    }
    call_other(TP, "query_"+str+"_stats");
  }

  write("\nType 'help "+str+"' for further information.\n");
  return 1;
}

