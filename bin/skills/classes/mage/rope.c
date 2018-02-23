/* ROPE TRICK */

inherit "inherit/timer";

status rope_up;
string room;

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status rope(string targ, mixed alt_type, string class) {
  int time, i;
  string file;

  if(targ != "trick") {
    notify_fail("rope trick?\n");
    return 0;
  }
  if(!alt_type) alt_type = "alteration";
  if(!class) class = "mage";
  time = (objectp(alt_type))
      ? (int)alt_type->query_cast_level() 
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            this_player(),
  "name",              "Rope Trick",
  "sphere",            alt_type, 
  "cost",              4,
  "damage",            time,
  "level",             2, /* 5 dim. space - 8 */
  "class", class,
  "cast time",         3,
  "spell object",      file,
  "casting msg",      ({
                     "You take the rope and stand it in the air...\n",
                     "An interdimensional space is created at its top.\n",
                      }),
  "casting msg room", ({
                      NAME +" takes a length of rope and stands it on "+
                        "its end...\n",
                      "The rope hangs in mid air!\n", 
                      }),
  "passive",
  "component",        "rope#cord",
/* other spell options... 
  "area",
  "immune",            0,
  "msg target",       0,
  "msg room",         0,
  "msg caster",       0,
 */
  }));
  return 1;
}

/************************************************************************/
/* call when this object is cloned to target */


status cast_spell(object caster, object target, object previous, int time) {
  object trick;

  trick = present("ropetrick", environment(target));
  if(trick) {
   tell_object(target,"It rips into an existing interdimensional "+
                      "space!!\nIt disrupts your spell.\n");
   trick->dispel_magic();
   destruct(this_object());
   return 1;
  }
  room = (string)this_player()->query_current_room();
  move_object(this_object(), environment(this_player()));
  tell_object(target,"You climb the rope.\n");
  move_object(this_player(), this_object());
  tell_room(environment(),target->query_name()+" climbs the rope.\n");
  adj_time(120 * time);
  return 1; /* do not do damage */
}

status id(string str) {
  return str == "spell"
      || str == "rope"
      || str == "ropetrick";
}


void extra_long() {
  if(!rope_up) {
    write("There is a rope here, suspended in mid-air.\n");
  }
}

string short(status wiz) {
  if(environment(this_player()) == this_object()) {
    return "A dimensional hole in space";
  }
  if(wiz) return file_name(this_object());
}

void long() {
  if(environment(this_player()) == this_object()) {
    write("You look down through a dimensional hole to see......\n");
    call_other(room,"long");
    extra_long();
    if(!rope_up) write("Perhaps you can raise the rope.\n");
  }
  write("A rope which hangs in mid air. Perhaps you can climb it?\n");
}

void time_out() {
  int i;
  object *inv;

  if(environment()) {
    inv = all_inventory();
    for(i = 0; i < sizeof(inv); i++) {
      if(!inv[i]) continue;
      tell_room(environment(),inv[i]->query_name()+" falls out of the sky.\n");
      move_object(inv[i], environment());
      if(living(inv[i])) {
        command("look",inv[i]);
        tell_object(inv[i],"The interdimensional space collapses!\n");
      }
    } 
  }
  ::time_out();
}

void dispel_magic() { time_out(); }

void init() {
  if(environment(this_player()) == this_object()) {
    add_action("down","down");
    add_action("raise","raise");
    add_action("lower","lower");
  }
  if(environment(this_player()) == environment()) {
    add_action("climb","climb");
  }
}


status lower(string str) {
  if(str == "rope") {
    if(rope_up) {
      write("You lower the rope.\n");
      say(this_player()->query_name()+" lowers the rope.\n");
      rope_up = 0;
    }
    else {
      write("It is already down.\n");
   }
   return 1;
 }
 notify_fail("lower what?\n");
 return 0;
}


status raise(string str) {
  if(str == "rope") {
    if(!rope_up) {
      write("You raise the rope.\n");
      say(this_player()->query_name()+" raises the rope.\n");
      rope_up = 1;
    }
    else {
      write("It is already down.\n");
   }
   return 1;
 }
 notify_fail("raise what?\n");
 return 0;
}
   
status down() {
  if(rope_up) {
    write("You have to lower the rope first.\n");
  }
  else {
    this_player()->move_player("climbs down the rope#"+room,0,1);
  }
  return 1;
}

status climb(string str) {
  if(rope_up) return 0;
  if(str == "rope") {
    this_player()->move_player("climbs up the rope#"+
    file_name(this_object()));
    return 1;
  }
  notify_fail("climb what?\n");
  return 0;
}


