/* back stab */
/* This is a SPECIAL backstab file. It is for use by NPCs ONLY! */

/* for some strange reason, players can bypass the heart beat of setting
 * their attackers, and hence get multiple backstabs IF they use DO
 * commands and other MACROs supplied by clients. The following use of
 * a flag and a call_out is NOT recommended as a permanent solution,
 * but rather a temporary one.
 * - Angel, Aug '96.
 */

static status done_backstab;

#include <mudlib.h>
#include <living.cfg>
#define NAME      (string)this_player()->query_name()

status backs(string str) {
  object obj, primary, weapon;
  string type;
  int your_dex;
  int dam;
  int my_backstab;


  if(!this_player()->query_npc()) return 0;
  if(!str) {
    notify_fail("backstab who?\n");
    return 0;
  }

  obj = present(lower_case(str), environment(this_player()));
  if(!obj) {
    notify_fail(capitalize(str)+" isn't here to backstab!\n");
    return 0;
  }
  if(!living(obj)) {
    write("Well, it doesn't move. It hardly knows you are here.\n");
    return 1;
  }
/*
 * This was a temporary fix. Put it back in if the code below starts to fail.
  if(done_backstab) {
    write("Not so fast, "+this_player()->query_name()+"!\n");
    return 1;
  }
*/

  if((primary = (object)this_player()->query_primary_attack())) {
    if(present(primary, environment(this_player()))) {
      write("You can't backstab someone while fighting!\n");
      return 1;
    }
  }

  if(!this_player()->query_stealth_on()) {
    write("You must sneak up on your victim before you can backstab them!\n");
    return 1;
  }

  if(weapon = this_player()->query_right_weapon()) {
    if((string)weapon->query_type() == "missile") {
      write("You can't backstab someone with a missile weapon!\n");
      return 1;
    }
  }

  if((status)environment(this_player())->query_no_fight()) {
    notify_fail("You can't start a fight here!\n");
    return 0;
  }

  if((status)obj->query_sec_att_name(lower_case(NAME))) { 
    notify_fail(obj->query_name()+" seems to recognises you!\n");
    this_player()->set_primary_attack(obj);
    obj -> set_primary_attack(this_player());
    this_player()->attack();
    return 0;
  }

  if(!this_player()->add_secondary_attacker(obj)) {
    write("The law prevents you from attacking "+obj->query_name()+"\n");
    say(NAME+" attempts to backstab "+obj->query_name()+".\n", obj);
    tell_object(obj, NAME+" tries to backstab you!!\n");
    return 1;
  }

  if(!obj->add_secondary_attacker(this_player())) {
    write("The law prevents you from attacking "+obj->query_name()+"\n");
    say(NAME+" attempts to backstab "+obj->query_name()+".\n", obj);
    tell_object(obj, NAME+" tries to backstab you!!\n");
    return 1;
  }
  your_dex = (int)obj->query_intelligence();
  /* for surprising them...must beat their intelligence */
  my_backstab = (int)this_player()->query_backstab();

  if(random(your_dex) <= random(my_backstab)){
    write("You sneak up on "+ obj->short() +"...\n");
    write("You surprise "+ obj->short() +"!!\n");
    say(NAME +" sneaks up on "+ obj->short() +"...\n", obj);
    say(NAME +" surprises "+ obj->short() +"!!\n", obj);
    tell_object(obj, NAME+" sneaks up on you, and surprises you!\n");

    dam = random(my_backstab) + (int)this_player()->query_wc();
    dam = dam * ((int)this_player()->query_backstab()/5 + 1);

    weapon = (object)this_player()->query_right_weapon();
    if(weapon) type = (string)weapon->query_type();

    this_player()->attack_msg(dam,type,obj,"right");

    if(random(100) <= 1){
      write("You PLUNGE your weapon into "+ obj->short() +"'s back!\n");
      write("Your weapon RIPS through "+ obj->short() +"'s VITAL organs!\n");
      say("You see "+ NAME + "'s weapon protrude " + obj->short() +"'s CHEST!\n");
      say(NAME +" KILLED "+ obj->short() +" with a sneak attack!!\n");
      if(!obj->id("PLAYER")) {
        obj->death();
        return 1;
      }
    }
  }

  else {
    write("You sneak up on "+ obj -> short() +"...\n");
    write(obj->short() +" sees you coming, and dodges the attack!\n");
    tell_object(obj,"You see "+ this_player()->query_name()
                    +" sneaking up on you.\n");
    say("You see "+ this_player()->query_name()
        +" sneaking up on "+ obj->query_name() +".\n", obj);
  }

  this_player()->add_secondary_attacker(obj); /* get ready to attack */

  done_backstab = 1;


  if(!obj) return 1; /* just in case! */
  this_player()->set_primary_attack(obj);     /* make sure focus of attack */
  obj -> set_primary_attack(this_player());   /* make sure focus of attack */
  this_player()->attack();                    /* attack */
  if(obj) obj -> hit_player(dam);
  /* obj -> do_damage(dam); ..it keeps bugging out 8( */
  return 1;
}

