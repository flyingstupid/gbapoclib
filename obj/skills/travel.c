/* teleport object */

string *destinations;

void reset(status arg) {
  if(arg) return;
  destinations = ({});
}

string *query_destinations() {
  return destinations;
}

mixed *query_auto_load() {
  string file;
  int i;

  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);
  return ({ file, destinations, });
}

void init_arg(string *dest) { destinations = dest; }


void init() {
  add_action("dest", "destination");
}


status dest(string str) {
  int i;
  status remove;

  if(!str) {
    write("Destinations: ");
    if(!sizeof(destinations)) 
      write("none.\n\n");
    else {
      for(i = 0; i < sizeof(destinations); i += 2) {
        if(i) write("\n              ");
        write(destinations[i]);
/*
          write(", ");
*/
      }
      write(" \n\n");
    }
    write("Type 'destination <location>'  to memorise location.\n"+
          "     'destination -<location>' to remove memorised location.\n");
    return 1;
  }
  if(sscanf(str,"-%s",str)) remove = 1;
  i = member_array(str,destinations);
  if(remove) {
    if(i == -1) {
      write("Unknown destination \""+ str +"\".\n");
    }
    else {
      destinations = destinations[0..(i-1)]
                   + destinations[(i+2)..(sizeof(destinations)-1)];
      write("Destination \""+ str +"\" has been forgotten.\n");
    }
    return 1;
  }
  if(sizeof(destinations) > 19) {
    write("You can only memorise "+ (sizeof(destinations)/2) 
         +" destinations.\nUse 'destination -<keyword>' to remove.\n");
    return 1;
  }
  if(environment(this_player())->query_no_teleport() 
  || environment(this_player())->query_no_summon()) {
    write("This area contains a magical instability that will not allow "+
          "you to teleport to here.\n");
    return 1;
  }
  if(i == -1) {
    destinations += ({ str, (string)this_player()->query_current_room(), });
  }
  else {
    destinations[i+1] = (string)this_player()->query_current_room();
  }
  write("Location memorised as \""+ str +"\".\n");
  return 1;
}
  
status id(string str) { return str == "teleport"; }

status drop(status quit) {
  return 1;
}

