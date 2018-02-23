#include <mudlib.h>
inherit "obj/shadows/shadow";

#define WEREBEAR_FORM "A large bear"
#define WC_BONUS      5
#define AC_BONUS     5

object who;
string whoName;

void shadow_werebear(string str) {
  who = this_player();
  whoName = (string)this_player()->query_name();
  if(who->query_werebear_object()) {
    destruct(this_object());
    return;
  }
  shadow_object(who);
}


status query_is_were() {
  object obj;
  return (obj=present("werebear", who)) ? obj->query_wereform() : 0;
}




string short(status wiz) {
  object ob;
  if(ob=present("werebear", who)) {
    if(ob->query_wereform()) return WEREBEAR_FORM;
  }
  return (string)who->short(wiz);
}

void long(status wiz) {
  object ob;
  if(ob = present("werebear", who)) {
    if(ob->query_wereform()) {
      write("You see before you a large bear. "+
            capitalize((string)who->query_pronoun()) +" looks a little "+
	    "like "+ (string)who->query_name() +".\n");
    }
  }

  who->long(wiz);
}

string query_plural() { return "large bears"; }
string query_name(status wiz) {
  object ob;
  if(ob=present("werebear", who)) {
    if(ob->query_wereform()) return "A bear";
  }
  return who->query_name(wiz);
}



int adj_hp(int amount) {
  object ob;
  int chance;
  if(amount < 0) { /* ie a hit has just occured */
    amount *= -1;
    chance = amount/(int)who->query_hp();
    if(chance*100 > random(100)) {
      if(ob=present("werebear", who))
        if(!query_is_were()) {
          ob->set_wereform(1);
          tell_object(who, "The anger builds up within you!\n"+
	      "You suddenly change form and become a werebear!\n");
          say(whoName+" cries out in anger and transforms into a bear!\n",
              who);
        }
    }
    return who -> adj_hp (-amount);
  }
  return who->adj_hp(amount);
}

status load_spell(mixed *arr) {
  if(query_is_were()) {
    write("You can't use your powers whilst in were-form!\n");
    return 1;
  }
  return who->load_spell(arr);
}




mixed *query_loaded_spell() {
  return (query_is_were()) ? 0 : (mixed *)who->query_loaded_spell();
}

int query_wc() {
  return (!(object)who->query_right_weapon() && query_is_were()) ?
    ((int)who->query_unarmed() + WC_BONUS) :
    (int)who->query_wc();
}

int query_ac() {
  return (!(object)who->query_ac() && query_is_were()) ?
  (AC_BONUS + (int)who->query_dexterity()/5 + (int)who->query_level()/10) :
  (int)who->query_ac();
}


status id(string str) {
  if(query_is_were()) return str == "bear";
  return (status)who->id(str);
}
object query_werebear_object() { return this_object(); }
