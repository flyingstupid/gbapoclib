/* basis for a summoned monster */

inherit "inherit/monster";
inherit "inherit/timer";

object master;

object query_master()     { return master; }
void set_master(object m) { master = m; }

string short(status wiz) {
  return (master ? (string)master->query_name() +"'s " : "") 
       + ::short(wiz);
}


void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("summoned creature");
  set_plural("summoned creatures");
}


void heart_beat() {
  object attack;

  ::heart_beat();
  if(!master) {
    time_out();
    return;
  }
  attack = (object)master->query_primary_attack();
  if(attack == this_object()) {
    time_out();
    return;
  }
  if(attack) {
    if(attack != query_primary_attack()) {
      add_secondary_attacker(attack);
      set_primary_attack(attack);      
    }
    if((object)attack->query_primary_attack() == this_object()) {
      attack->add_secondary_attacker(master);
      attack->set_primary_attack(master);
    }
  }
  if(!attack) {
    if(attack = query_primary_attack()) {
      tell_room(environment(),query_name() +" stops fighting.\n");
      stop_fight(attack);
      attack->stop_fight(this_object());
    }
    set_heart_beat(1);
  }
}


status cast_spell(object caster,object target,object prev,int level) {
  master = caster;
  adj_time(level * 30);
  set_heart_beat(1);
  move_object(this_object(), environment(caster));
  if(this_object()->id("summoned"))
    tell_room(environment(),"The "+ query_name() +" arrives in a flurry.\n");
  else if(this_object()->id("animated"))
    tell_room(environment(),"The "+ query_name() +" starts to move!\n");
  else if(this_object()->id("conjured")) 
    tell_room(environment(),"The "+ query_name() +
              " appears in a flash of light.\n");
  else
    tell_room(environment(),query_name() +" arrives\n");

  return 1;
}


void time_out() {
  if(this_object()->id("summoned"))
    tell_room(environment(),query_name() +" flees...\n");
  else if(this_object()->id("animated"))
    tell_room(environment(),query_name() +" crumbles to dust!\n");
  else if(this_object()->id("conjured")) 
    tell_room(environment(),query_name() +" disappears...\n");
  else
    tell_room(environment(),query_name() +" fades away...\n");
  
  ::time_out();
}


status dispel_magic() {  time_out(); }


status monster_died() {
  object corpse;

  remove_call_out("time_out");
  if((corpse = present("corpse", environment()))) destruct(corpse);
  tell_room(environment(),"The corpse disappears.\n");
}    

