 
#include <mudlib.h>
 
#define NAME        (string)this_player()->query_name()
#define MY_STAT     (int)this_player()->query_steal()
#define CLOSE_ENUF  3
 
string tmp1, tmp2;
object victim, obj, *env;
int mystat, yourstat, i, money;
 
void check_env(object ob);
status steal(string str, mixed alt_type) {

  money = 0;
 
  if(!str) {
    write("Steal from who?\n");
    return 1;
  }
  if(this_player()->query_attack()) {
    write("You cannot steal from someone while engaged in combat!\n");
    return 1;
  }
 
  if((status)environment(this_player())->query_no_fight() &&
    !this_player()->query_npc()) {
     write("You cannot steal here.\n");
     return 1;
  }
  if(!sscanf(str, "%s from %s", tmp1, tmp2)) {
    write("Steal what from who?\n");
    return 1;
  }
  
  env = all_inventory(environment(this_player()));
  victim = present(lower_case(tmp2), environment(this_player()));
  if(!victim) {
    write("That person is not here.\n");
    return 1;
  }
 
  if(victim->query_no_steal()) {
    write("You fail to steal from "+
         victim -> query_name() +"\n");
    return 1;
  }

  if(victim->query_security_level()) {
    notify_fail("You cannot steal from Creators!\n");
    return 0;
  }
  if(sscanf(tmp1, "%d coins", money) || sscanf(tmp1, "%d coin", money)) {
    if(money > 50) money = 50;
    if(victim -> query_money() < money) {
      write("You don't think "+ victim -> query_name() +" has that "+
      "many coins.\n");
      money = 0;
      return 1;
     }
   }
 
  if(!money) { 
    obj = present(lower_case(tmp1), victim);
    if(!obj) {
      write(victim -> query_name() +" has no "+ tmp1 +" on "+ 
      victim -> query_pronoun() +"\n");
      return 1;
    }
    if(!obj -> get() || obj -> query_auto_load() || obj -> drop()) {
      write("You cannot steal "+ obj->query_name() +" from "+
      victim -> query_name() +"!\n");
      return 1;
    }
  }
  if(money) {
    obj = clone_object("obj/money");
    obj -> set_money(money);
  }
 
  if(!alt_type)
    mystat = random(MY_STAT);
  else if (intp(alt_type))
    mystat = random(alt_type);
  else
    mystat = random((int)call_other(this_player(), "query", alt_type));
  yourstat = random((int)victim->query_intelligence());
 
  /* IF I WIN !! */
  if(mystat > yourstat) {   
    if(this_player()->query_attack() == 1){
       write("You cannot steal while engaged in combat!\n");
    }
    if(!this_player()->add_weight(obj->query_weight())) {
      write(obj -> query_name() +" is too heavy for you to carry!\n");
 
      return 1;
    }
 
    if(obj -> query_worn()) {
      write("You manage to remove the "+ obj -> query_name() +" that "+
      victim -> query_name() +" is wearing, without "+victim -> query_pronoun()
      +" noticing.\n");
      obj -> drop(1);  /* silently */
      return 1;
    }
 
    if(obj -> query_wielded()) {
      write("You manage to remove the "+ obj -> query_name() +" that "+
      victim -> query_name() +" is wielding without "+victim -> query_pronoun()
      +" noticing.\n");
      obj -> drop(1);  /* silently */
      return 1;
    }
 
    check_env(this_player());
    write("You steal "+ obj -> short() +" from "+ 
    victim -> query_name() +"'s pockets.\n");
    if(money) {
      this_player()->add_money(money);
      victim -> add_money(-money);
      money = 0;
      destruct(obj);
    }
    else {
      move_object(obj, this_player());    
      victim -> steal();
    }
    return 1;
  }
 
 
  /* a close attempt, but not quite */
  if(MY_STAT > 19 && ((yourstat - mystat) < CLOSE_ENUF)) {  
    if(!this_player()->add_weight(obj->query_weight())) {
      write(obj -> query_name() +" is too heavy. You cannot carry any more!\n");
 
    }
    if(obj -> query_worn()) {
      write("You manage to remove the "+ obj -> query_name() +" that "+
      victim -> query_name() +" is wearing.\n");
      obj -> drop(1);  /* silently */
    }
    if(obj -> query_wielded()) {
      write("You manage to remove the "+ obj -> query_name() +" that "+
      victim -> query_name() +" is wielding.\n");
      obj -> drop(1);  /* silently */
    }
    else {
      write("You manage to steal "+ obj -> short() +" from "+
      victim -> query_name() +"!!\n");
    }
    if(money) {
      this_player()->add_money(money);
      destruct(obj);
    }
    else {
      move_object(obj, this_player());
      victim -> steal();
      write("However, "+ victim -> query_name() +" catches you in the act!\n");
    }
  }
 
 
  /* here's where we fail totally !!! */
  else {
    write("You fail to steal "+ obj -> short() +" from "+ 
         victim -> query_name() +"\n");
  }
  check_env(this_player());
  if(money) destruct(obj);  /* gets rid of tmp money object cloned */
  if(victim -> query_npc()) {
    write(victim -> query_name() +" becomes enraged and begins to attack!\n");
    victim -> hit_player(0);
  }
  else {
    write(victim -> query_name() +" gets angry with you!\n");
    tell_object(victim, this_player()->query_name()+" attempted to steal "+
      " from you!\n");
  }
  return 1;
}
 
 
/* To see if anyone else notices this dastardly feat! */
void check_env(object player) {
  for(i=0; i<sizeof(env); i++) {
    if((env[i] != victim) && (env[i] != player)) {
      if(mystat < (env[i]->query_intelligence())) {
        tell_object(env[i], "You notice "+player -> query_name()+" stealing "+
        obj -> short() +" from "+ victim -> query_name() +"!!\n");
      }
    }
  }
}

