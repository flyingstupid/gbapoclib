/* scryer object */

inherit "inherit/timer";

object old_room, master, eye_controller;

void reset(status arg) {
  if(arg) return;
  set_living_name("wizard eye");
  enable_commands();
}

status query_npc() { return 1; }

status id(string str) {
  return str == "spell"
      || str == "wizard eye";
}


void eye(object who) {
  if(!who) {
    destruct(this_object());
    return;
  }
  master = who;
}


void time_out() {
  if(master) {
    tell_object(master,"The wizard eye dispels.\n");
  }
  if(eye_controller) destruct(eye_controller);
  ::time_out();
}


void dispel_magic() { time_out(); }


void new_room(string str) {
  object ob;

  if(!str) return;
  if(!(master || eye_controller)) {
    time_out();
    return;
  }
  if(!old_room) move_object(this_object(), environment());
  command(str, this_object());
  if(!old_room || environment(old_room) != environment() 
  || str == "l" || str == "look") {
    write(
"#################################################################\n"+
"Wizard Eye->\n");
    environment()->long(0);
    this_player()->show_inventory(environment());
    write("\n"+
"#################################################################\n");
    old_room = environment();
    return;
  }  
  if(sscanf(str,"look at %s",str)) {
    if(!environment()->look_at(str)) {
      if(ob = present(str, environment())) {
        write(
"#################################################################\n"+
"Wizard Eye->\n");
        ob->long(0);
        write(
"\n#################################################################\n");

      }
      else {
        write(
"#################################################################\n"+
"Wizard Eye->There is no "+ str +" here.\n\n"+
"#################################################################\n");
      }
    }
    return;
  }
  write("###Wizard Eye->You refocus the eye.\n\n###\n");
}


void catch_tell(string str) {
  if(!(master || eye_controller)) {
    time_out();
    return;
  }
  if(environment(master) != environment()) {
    tell_object(master,
"#################################################################\n"+
"Wizard Eye->\n"+ str +"\n"+
"#################################################################\n");
  }
}




status cast_spell(object caster,object target,object prev,int level) {
  object ob;
  string who;

  if((ob = present("eye", caster))) {
    if(ob->query_wizard_eye()) {
      ob = (object)ob->query_wizard_eye();
      write("You extend the time of your wizard eye spell.\n");
      ob->adj_time(level * 60);
      destruct(this_object());
      return 1;
    }
    else {
      destruct(ob);
    }
  }
  eye_controller = clone_object("skills/obj/eye");
  eye_controller->set_wizard_eye(this_object());
  move_object(eye_controller, caster);
  master = caster;
  adj_time(level * 60);
  write("Your 'minds eye' focuses upon this area. You can move it\n"+
        "with 'eye <direction>'.\n");
  say(caster->query_name() +" continues to concentrate.\n");
  return 1;
}

