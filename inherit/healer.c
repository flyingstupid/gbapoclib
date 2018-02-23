/* A generic healer */
#include <mudlib.h>

#define OWNER	(string)this_object()->query_name()
#define GOD     (string)this_object()->query_god()

void delay_catch(string str);

string set_god(string str);
status cure_wounds();
status cure_disease();
status dispel_magic();
status neutralize_poison();
status restoration();

int calc_money(int amount);

string god;

inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("alethian");
  set_short("Alethian, the healer");
  set_god("Antaaries");
  set_long(
	"Alexian is a healer, and priest of Antaaries. In return for \n"+
	"a suitable donation to the church she can heal you of your ills.\n");
  set_race("high elf");
  set_gender(2);
}


void init() {
  ::init();
  call_out("welcome", 1, this_player());
  add_action("pray", "pray");
  add_action("pray", "worship");
}

hit_player() {
  object obj;
  obj = this_player();
  if(obj -> query_level() < 15) {
    this_object() -> stop_all_fight();
    this_player() -> stop_all_fight();
    say(OWNER+" says: I wouldn't do that if I were you "+ 
        obj->query_name() +"\n");
    return 0;
  }
}


void welcome(object obj) {
  if(this_player()->query_ghost()) {
    write(OWNER+" exclaims: I shall pray to the "+GOD+" to raise you!\n");
    obj->toggle_ghost();
    return;
  }

  say("Aurora says: Welcome, "+ this_player()->query_name() +". "+
          "Please worship with me.\n");
}



status pray(string str) {
  string tmp1, tmp2;
  if(str) {
    delay_catch(str);
    return 1;
  }

  if(!this_player()->query_ghost()) {
    write(OWNER+" says: I can offer you the following services.\n\n"+
          "Cure Light Wounds......100 coins \n"+
          "Cure Disease...........200 coins \n"+
          "Dispel Magic...........500 coins \n"+
          "Neutralize Poison.....1000 coins \n"+
          "Restoration.........10 000 coins \n"+
          "Aurora says: Tell me which service you wish, "+
           this_player()->query_name() +"?\n");
    return 1;
  }
  this_player()->toggle_ghost();
  return 1;
}


void catch_tell(string str) {
  call_out("delay_catch",1,str);
}

void delay_catch(string str) {
  string tmp1, tmp2;
  
  if(this_object()->query_attack()) return;
  if(environment(this_player()) != environment()) {
    if(sscanf(str, "%stell%s", tmp1, tmp2)) {
      write(OWNER+" says: I hear you. But my powers can only be given "+
            "in my presence.\n");
    }
    return;
  }

  if(sscanf(str, "%scure light wounds%s", tmp1, tmp2)) {
    cure_wounds();
  }
  else if(sscanf(str, "%scure disease%s", tmp1, tmp2)) {
    cure_disease();
  }
  else if(sscanf(str, "%sdispel magic%s", tmp1, tmp2)) {
    dispel_magic();
  }
  else if(sscanf(str, "%sneutralize poison%s", tmp1, tmp2)) {
    neutralize_poison();
  }
  else if(sscanf(str, "%srestoration%s", tmp1, tmp2)) {
    restoration();
  }
  else if(sscanf(str, "%shello%s", tmp1, tmp2)) {
    say(OWNER+" says: Hello, my child.\n");
  }
}

status cure_wounds() {
  int mon;
  mon = 100;

  mon = calc_money(100);

  if(this_player()->query_money() < mon) {
    write(OWNER+" says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say(OWNER+" begins a silent prayer.\n");
  say(OWNER+" touches the wounds of "+ this_player()->query_name() +"\n"+
  this_player()->query_possessive() +" wounds are healed.\n", this_player());

  tell_object(this_player(), OWNER+" touches your wounds.\n"+
                             "You are healed.\n");
  this_player()->add_money(-mon);
  this_player()->adj_hp(2 * (random(4) + 1));
  return 1;
}

status cure_disease() {
  object disease;
  int mon;
  mon = calc_money(200);

  if(this_player()->query_money() < mon) {
    say("Aurora says: But you don't have enough money for the donation.\n");
    return 1;
  }
  if(present("Disease", this_player()));
    disease = present("Disease", this_player());
  if(!disease) {
    say(OWNER+" says: But you have no diseases, "
        + this_player()->query_name() +"\n");
    return 1;
  }
  say(OWNER+" begins a silent prayer.\n");
  say(OWNER+" lays her hands upon "+ this_player()->query_name()
     +" and\nheals "+ this_player()->query_possessive()
     +" diseases.\n", this_player());

  tell_object(this_player(), OWNER+" lays her hands on you and "+
    "cures your diseases.\n");
  this_player()->add_money(-mon);
  destruct(disease);
  return 1;
}



status dispel_magic() {
  int i, j;
  int mon;
  object *obj;

  mon = calc_money(500);
  obj = all_inventory(this_player());

  if(this_player()->query_money() < 500) {
    say(OWNER+" says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say(OWNER+" begins a silent prayer.\n");
  for(i=0; i<sizeof(obj); i++) {
    if(obj[i] -> dispel_magic()) {
      if(obj[i] -> short())
        say(obj[i] -> short() +" is dispelled.\n");
      else
        say("Something is dispelled.\n");
      j++;
    }
  }
  if(!j) {
    say("Nothing happens.\n");
  }
  this_player()->add_money(-mon);
  return 1;
}


status neutralize_poison() {
  object poison;
  object target;
  int mon;

  target = this_player();
  poison = present("Poison", target);
  mon    = calc_money(1000);

  if(this_player()->query_money() < mon) {
    write(OWNER+" says: But you don't have enough money for the donation.\n");
    return 1;
  }

  say(OWNER+" begins a silent prayer.\n");

  if(poison) {
     tell_object(target,"You feel the poison leave your body.\n");
      write(OWNER+" neutralizes the poison in "+ target->query_name() 
           +"'s system.\n"); 
      say(OWNER+" neutralizes the poison in "+
          target->query_name()+".\n",target);
    destruct(poison);
    target->set_constitution((int)target->query_constitution());
  }
  else {
      write(OWNER+" says: You are not poisoned.\n");  
  }
  this_player()->add_money(-mon);
  return 1;
}

status restoration() {
  object target;
  int mon;

  target = this_player();
  mon    = calc_money(10000);

  if(this_player()->query_money() < mon) {
    write(OWNER+" says: But you don't have enough money for the donation.\n");
    return 1;
  }

  say(OWNER+" begins a silent prayer.\n");

  if(!target->query_level_drained()) {
      write(OWNER+" says: You have not level drained.\n");
      return 1;
  }
  else {
    tell_object(target,"You have been restored a level.\n");
    say(OWNER+" has restored a level to "+
        target->query_name() +".\n");
    target->restore_level();
  }
  this_player()->add_money(-mon);
  return 1;
}

int calc_money(int amount) {
  int bargain, my_stat;

  bargain = (int)this_player()->query_charisma();
  my_stat = 12;

  if(random(bargain) > random(my_stat)) 
    amount -= amount/4;
  else
    amount += amount/3;

  write(query_name()+" haggles with you over a suitable donation.\n");
  write(query_name()+" takes "+MONEY->convert(amount)+" coins for "+
  query_possessive()+" prayers.\n");
  return amount;
}

string set_god(string str) { return (god) ? god = str : god = "Antaaries"; }
string query_god()         { return god; }
