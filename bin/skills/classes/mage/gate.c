/** gate spell **/

object exit_gate;
string creator;

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */

status gate(mixed targ, mixed alt_type, string class) {
  int dam, i;
  string file;

  if(!alt_type) alt_type = "conjuration";
  if(!class) class = "mage";

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  this_player()->load_spell(({
  "target",            environment(this_player()),
  "name",              "Gate",
  "sphere",            alt_type, 
  "cost",              30,
  "level",             30,
  "class", class,
  "cast time",         2,
  "spell object",      file,
  "casting msg",      "You push tremendous energies to weaken the fabric of "+
                      "space.\n",
  "casting msg room", NAME +" starts playing with some interdimensional "+
                      "energies.\n",
  "passive",
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int dmg) {
  int i;
  string file;

  if(environment(caster)->query_no_summon()
  || environment(caster)->query_no_teleport()) {
    write("The magical instability of the area prevents the portal forming.\n");
    destruct(this_object());
    return 1;
  }


  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  exit_gate = clone_object(file);
  exit_gate->set_exit_gate(this_object());
  move_object(exit_gate, caster);
  creator = (string)caster->query_name();
  exit_gate->set_creator_name(creator);
  write("You have anchored one portal exit to this area.\n"+
        "Go to proposed next portal exit area, and type 'anchor' to "+
        "create the portal.\n");
}

void set_exit_gate(object ob)   { exit_gate = ob; }
void set_creator_name(string n) { creator = n;    }

object query_exit_gate()        { return exit_gate; }
string query_creator_name()     { return creator;   }


void init() {
  add_action("portal", "portal");
  add_action("anchor", "anchor");
}

status portal(string str) {
  object ob;

  if(!query_exit_gate()) {
    write("The portal disipates.\n");
    destruct(this_object());
    return 1;
  }
  if(living(environment()) || living(environment(query_exit_gate()))) {
    return 0;
  }

/* okay this is so that typing portal is the same as typing 'portal 1'
   you could take out the if(str) block now, I'll do it later - Sarak */

  if(!str) str = "1";
  if(str) {
//  if(ob = present("portal "+ str, environment(this_player()))) {
    if(ob = present("gate "+ str, environment(this_player()))) {
      if(ob != this_object()) return 0;
    }
    else {
      notify_fail("There is no portal "+ str +" here.\n");
      return 0;
    }
  }  
  this_player()->move_player("portal",environment(exit_gate), 0);
  return 1;
}

status anchor() {
  if(!living(environment())) return 0;
  if(environment(this_player())->query_no_summon()
  || environment(this_player())->query_no_teleport()) {
    write("The magical instability of the area prevents the portal forming.\n"+
          "You should try another anchor point.\n");
    return 1;
  }
  move_object(this_object(), environment(this_player()));
  tell_room(environment(), "A portal forms in front of you.\n");
  return 1;
}


status id(string str) {
  return str == "spell"
      || str == "gate"
      || str == "portal";
}

void extra_long() {
  if(!query_exit_gate()) {
    call_out("dispel_magic",1);
    return;
  }
  if(living(environment()) || living(environment(query_exit_gate()))) {
    return;
  }
  write("You see a swirling portal.\n");
}

void long() {
  if(!query_exit_gate()) return;
  if(living(environment()) || living(environment(query_exit_gate()))) {
    return;
  }
  write("The swirling portal is a gate created by "+ creator +" to some "+
        "unknown dimension.\n");
}

void dispel_magic() {
  tell_room(environment(),"The portal closes.\n");
  if(exit_gate) destruct(exit_gate);
  destruct(this_object());
}

status query_domain_safe() { return 1; }

