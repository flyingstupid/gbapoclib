/* Aurora - Chosen Prophet of the All-God
 */
#include <mudlib.h>
#define OBJ	"d/coronos/w/angel/city/obj"

status cure_wounds();
status cure_disease();
status dispel_magic();
int calc_money(int amount);

inherit MONSTER;
object symb;


void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("aurora");
  set_gender(2);
  set_magic_resist(75);
  set_wc(30);
  set_level(30);
  set_ac(30);
  set_short("High priestess Aurora Shadowborne, the Prophet of the All God");
  set_long(
     "With blue eyes and a young delicate face, there is an eternal   \n"+
     "peace within this young woman. Even though only in her youth     \n"+
     "she is the most powerful cleric, one chosen by the most powerful \n"+
     "of all gods - the All-God.\n");

  load_spells(30, ({ "cure serious wounds",
	"cure light wounds",
	"curse",
	"bless",
	"call lightning",
	"flamestrike",
	"holy strike",
	"cure critical wounds",
	"barkskin",
	"holy word",
	"starburst",
  }));


  load_chat(5, ({ "Aurora says: Welcome child.\n",
     "Aurora prays before the altar.\n",
     "Aurora prays earnestly.\n",
     "Aurora says: have you come to pray, my child?\n",
     "Aurora smiles happily.\n",
     "Aurora says: Worship with me, my child.\n"
  }));

  load_a_chat(8, ({ "Aurora says: My Lord will protect me.\n",
     "Aurora exclaims: Oh Lord, protect me.\n",
     "Aurora says: The All-God will strike you down.\n",
     "Aurora asks: Why do you attack me?\n"
  }));
  
  move_object(clone_object(OBJ+"/ring"), this_object());
  move_object(clone_object(OBJ+"/mace"), this_object());
  init_command("wield mace");
  init_command("wear ring");

  symb = clone_object(ARMOUR);
  symb -> set_type("amulet");
  symb -> set_name("symbol");
  symb -> set_ac(1);
  symb -> set_weight(1);
  symb -> set_value(300);
  symb -> set_short("A holy symbol");  
  symb -> set_alias("holy symbol");
  symb -> set_long(
     "This is a platinum holysymbol to the All-God. It gives off a \n"+
     "soft light and is perhaps magical in nature.\n");
  move_object(symb, this_object());
  init_command("wear symbol");

}
void init() {
  ::init();
  call_out("welcome", 1, this_player());
  add_action("pray", "pray");
}

hit_player() {
  object obj;
  obj = this_player();
  if(obj -> query_level() < 15) {
    this_object() -> stop_all_fight();
    this_player() -> stop_all_fight();
    say("Aurora says: I wouldn't do that if I were you "+ 
        obj->query_name() +"\n");
    return 0;
  }
}

void welcome(object obj) {
    if(this_player()->query_ghost()) {
      write("Aurora exclaims: I shall pray to the All-God to raise you!\n");
      obj->toggle_ghost();
      return;
    }
    say("Aurora says: Welcome, "+ this_player()->query_name() +". "+
        "Please worship with me.\n");
    return;
}

status pray() {
  if(!this_player()->query_ghost()) {
    write("Aurora says: I can offer you the following services.\n\n"+
          "Cure Light Wounds......100 coins \n"+
          "Cure Disease...........200 coins \n"+
          "Dispel Magic...........500 coins \n"+
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
      write("Aurora says: I hear you. But my powers can only be given "+
            "in my presence.\n");
    }
    return;
  }
  if(sscanf(str, "%syou%s\n", tmp1, tmp2) &&
    !sscanf(str, "%s:%s\n", tmp1, tmp2)) {
    if(this_player() == this_object()) return;
    tell_object(this_player(), query_name()+" shys away from you.\n");
    say(query_name()+" shys away from "+this_player()->query_name()+"\n",
	this_object());
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
  else if(sscanf(str, "%shullo%s", tmp1, tmp2)) {
    say("Aurora says: Hullo, my child.\n");
  }
}

status cure_wounds() {
  int mon;
  mon = 100;

  mon = calc_money(100);

  if(this_player()->query_money() < mon) {
    write("Aurora says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say("Aurora begins a silent prayer.\n");
  say("Aurora touches the wounds of "+ this_player()->query_name() +"\n"+
  this_player()->query_possessive() +" wounds are healed.\n", this_player());

  tell_object(this_player(), "Aurora touches your wounds.\n"+
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
    say("Aurora says: But you have no diseases, "
        + this_player()->query_name() +"\n");
    return 1;
  }
  say("Aurora begins a silent prayer.\n");
  say("Aurora lays her hands upon "+ this_player()->query_name()
     +" and\nheals "+ this_player()->query_possessive()
     +" diseases.\n", this_player());

  tell_object(this_player(), "Aurora lays her hands on you and "+
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
    say("Aurora says: But you don't have enough money for the donation.\n");
    return 1;
  }
  say("Aurora begins a silent prayer.\n");
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

int calc_money(int amount) {
  int bargain, my_stat;

  bargain = (int)this_player()->query_charisma();
  my_stat = 12;

  if(random(bargain) > random(my_stat)) 
    amount -= amount/4;
  else
    amount += amount/3;

  write(query_name()+" haggles with you over the price.\n");
  write(query_name()+" takes "+MONEY->convert(amount)+" coins for "+
  query_possessive()+" prayers.\n");
  return amount;
}
