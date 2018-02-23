
/* PUB.c  Angel, Sept 1993
 * Converted for economy coinage at Feb 1994, Angel
 * This is the replacement for the local pub. This object is to
 * be inherited in the same way as the store.c file.
 * v2.0 Added listenning to rumours for added feeling to the pub April 98
 */
 
#include <mudlib.h>
inherit ROOM;
 
#define PLAYER_STAT (int)this_player()->query_charisma()
#define OWNER_STAT  15
#define L_OWNER     lower_case(OWNER)

#define NAME      0
#define SHORT     1
#define LONG      2
#define MSG       3
#define MSG_ROOM  4
#define HEAL      5

#define AL_SIZE   6 

#define RUMOURS   "/function/rumours"


string OWNER;
object player;
int overhead;
mixed *drink, *food, *sdrink;
status rumours_started;
 

status go();
void rumours(status noCallOut);
status has_drink(object ob); 
 
void reset(status arg) {
  if(OWNER && !present(L_OWNER)) this_object()->set_owner();
  if(arg) return;
  set_weather(1, 0, 0);
  drink = ({});
  food  = ({});
  sdrink= ({});
}
 

 
void init() {
  ::init();
  set_no_fight(1);
  set_no_summon(1);

  add_action("go",    "", 1  );
  add_action("sign",  "look" );
  add_action("sign",  "read" );
  add_action("sign",  "l");
  add_action("sign",  "exa");

  add_action("order", "order");
  add_action("order", "buy"  );

 add_action("listen", "listen");

  add_action("sell_bottle", "sell");

  if(!rumours_started) {
    rumours(0);
    rumours_started = 1;
  }
}
 
mixed *query_all_drinks() { return drink; }
/***********************************************************************/
/* alcoholic drink */
 
 
status query_drink(string str) {
  int i;
 
  if(!drink) drink = ({});
  for(i = 0; i < sizeof(drink); i++) {
    if(str == drink[i][NAME]) return i;
  }
  return -1;
}
 
 
void add_drink(string name, string short, string drink_msg, int heal) {
  mixed *tmp;
  if(query_drink(name) != -1) return;
  tmp = allocate(AL_SIZE);
  tmp[NAME]  = name;
  tmp[SHORT] = short;
  tmp[MSG]   = drink_msg;
  tmp[HEAL]  = heal;
  drink += ({ tmp, });
}
 
/************************************************************************/
/* soft drink */
 
int query_sdrink(string str) {
  int i;
 
  if(!sdrink) sdrink = ({});
  for(i = 0; i < sizeof(sdrink); i++) {
    if(str == sdrink[i][NAME]) return i;
  }
  return -1;
}
 
 
void add_sdrink(string name, string short, string drink_msg, int heal) {
  mixed *tmp;
  if(query_sdrink(name) != -1) return;
  tmp = allocate(AL_SIZE);
  tmp[NAME]  = name;
  tmp[SHORT] = short;
  tmp[MSG]   = drink_msg;
  tmp[HEAL]  = heal;
  sdrink += ({ tmp, });
}
 
 
/************************************************************************/
/* soft drink */
 
status query_food(string str) {
  int i;
 
  if(!food) food = ({});
  for(i = 0; i < sizeof(food); i++) {
    if(str == food[i][NAME]) return i;
  }
  return -1;
}
 
 
void add_food(string name, string short, string drink_msg, int heal) {
  mixed *tmp;
  if(query_food(name) != -1) return;
  tmp = allocate(AL_SIZE);
  tmp[NAME]  = name;
  tmp[SHORT] = short;
  tmp[MSG]   = drink_msg;
  tmp[HEAL]  = heal;
  food += ({ tmp, });
}
 
/*************************************************************************/
 
 
void display_drink() {
  string tmp, money_str;
  int cost, i;
 
  for(i = 0; i < sizeof(drink); i++) {
    tmp = (!i) ? "Alcohol: " : "         ";
    tmp += capitalize(drink[i][NAME]);
    tmp += "...............................................................";
    tmp = extract(tmp,0,50);
    cost = drink[i][HEAL]*4 + (drink[i][HEAL]*drink[i][HEAL])/10;
    if(!(money_str = (string)call_other(MONEY, "convert", cost))) {
      money_str = cost +"";
    }
    money_str = extract(money_str,0,8);
    write(tmp +" "+ money_str +" coins\n");
    tmp = 0;
  }
  if(!i) {
    write("Alcohol: None.\n");
  }
}
 
 
void display_sdrink() {
  string tmp, money_str;
  int cost, i;
 
  for(i = 0; i < sizeof(sdrink); i++) {
    tmp = (!i) ? "Drinks: " : "        ";
    tmp += capitalize(sdrink[i][NAME]);
    tmp += "...............................................................";
    tmp = extract(tmp,0,50);
    cost = sdrink[i][HEAL]*4 + (sdrink[i][HEAL]*sdrink[i][HEAL])/10;
    if(!(money_str = (string)call_other(MONEY, "convert", cost))) {
      money_str = cost +"";
    }
    money_str = extract(money_str,0,8);
    write(tmp +" "+ money_str +" coins\n");
    tmp = 0;
  }
  if(!i) {
    write("Drinks: None.\n");
  }
}
 
void display_food() {
  string tmp, money_str;
  int cost, i;
 
  for(i = 0; i < sizeof(food); i++) {
    tmp = (!i) ? "Food: " : "      ";
    tmp += capitalize(food[i][NAME]);
    tmp += "...............................................................";
    tmp = extract(tmp,0,50);
    cost = food[i][HEAL]*4 + (food[i][HEAL]*food[i][HEAL])/10;
    if(!(money_str = (string)call_other(MONEY, "convert", cost))) {
      money_str = cost +"";
    }
    money_str = extract(money_str,0,8);
    write(tmp +" "+ money_str +" coins\n");
    tmp = 0;
  }
  if(!i) {
    write("Food: None.\n");
  }
}
 

 
status sign(string str) {
  if(str == "at menu" || str == "menu") {
    write("-- Welcome to "+ short(0) +"!! --\n");
 
    if(drink && sizeof(drink)) {
      display_drink();
    }
    if(sdrink && sizeof(sdrink)) {
      if(drink && sizeof(drink)) write("\n");
      display_sdrink();
    }
    if(food && sizeof(food)) {
      if((drink && sizeof(drink)) || (sdrink && sizeof(sdrink))) {
        write("\n");
      }
      display_food();
    }
    return 1;
  }
  return 0;
}
 
 
status order(string str) {
  int i;
  object beer;
  string name, short_desc, mess, type;
  string tmp1, tmp2;
  int value, cost, strength, heal;
 
  if(!present(L_OWNER)) {
    write("No one appears to be here to serve you right now.\n");
    return 1;
  }
 
  if(!str) {
    write(OWNER +" says: What did you want to order?\n");
    return 1;
  }
 

  if(query_drink(str) != -1) {
   i = query_drink(str);
    name       = drink[i][NAME];
    short_desc = drink[i][SHORT];
    mess       = drink[i][MSG];
    heal       = drink[i][HEAL];
    value      = heal * 4 + (heal * heal) /10;
    strength   = heal;
    type       = "beer";
  }
 
   if(query_sdrink(str) != -1) {
     i = query_sdrink(str);
    name       = sdrink[i][NAME];
    short_desc = sdrink[i][SHORT];
    mess       = sdrink[i][MSG];
    heal       = sdrink[i][HEAL];
    value      = heal * 4 + (heal * heal) /10;
    strength   = heal;
    type       = "soft_drink";
  }
 
  if(query_food(str) != -1) {
    i = query_food(str);
    name       = food[i][NAME];
    short_desc = food[i][SHORT];
    mess       = food[i][MSG];
    heal       = food[i][HEAL];
    value      = heal * 4 + (heal * heal) /10;
    strength   = heal;
    type       = "food";
  }
 
  if(!name) {
    write(OWNER +"says: What did you want to order?\n");
    return 1;
  }
 
  if(random(PLAYER_STAT) > random(OWNER_STAT))
    value -= random(value/3);
  else
    value += random(value/4);
  write(OWNER +" haggles with you over the price of "+ name +"...\n");
 
  if(this_player()->query_money() < value) {
    write(OWNER +" says: Hey! You haven't got "+
    (string)call_other(MONEY, "convert", value) +" coins!\n");
    return 1;
  }
 
  if(type == "beer") {
    beer = clone_object(DRINK);
    beer -> set_pub_drink(1);
    beer -> set_alco_drink(1);
    beer -> set_consumer_msg(mess +"\n");
    beer -> set_room_msg("@@query_name:$this_player()$@@ drinks a "+name+"\n");
  }
  else
    if(type == "soft_drink") {
      beer = clone_object(DRINK);
      beer -> set_consume_msg(mess +"\n");
      beer -> set_room_msg("@@query_name:$this_player()$@@ drinks a "+name+"\n");
      beer -> set_pub_drink(1);
      beer -> set_soft_drink(1);
  }
  else
    if(type == "food") {
      beer = clone_object(FOOD);
      beer -> set_consume_msg(mess +"\n");
      beer -> set_room_msg("@@query_name:$this_player()$@@ eats a "+name+"\n");
  }
 
  if(!this_player()->add_weight(beer->query_weight())) {
     write(OWNER +" says: You can't carry more!\n"+
             OWNER +" says: You'd better put on a bit more muscle.\n");
     destruct(beer);
     return 1;
  }
 
  beer -> set_value(value/4);
  beer -> set_name(name);
  beer -> set_strength(strength);
  beer -> set_short(short_desc);
  beer -> set_long(short_desc +"\n");
  if(sscanf(short_desc, "%s bowl %s", tmp1, tmp2))
    beer -> set_empty_container("bowl");
  if(sscanf(short_desc, "%s mug %s", tmp1, tmp2))
    beer -> set_empty_comtainer("mug");
  if(sscanf(short_desc, "%s plate %s", tmp1, tmp2))
    beer -> set_empty_container("plate");
 

  move_object(beer, this_player());
  this_player()->add_money(-value);
  write(OWNER +" takes "+(string)call_other(MONEY, "convert", value)+
	"coins for a "+ name +"\n");
  say(this_player()->query_name() +" orders a "+ name +".\n");
  return 1;
}
 
status go() {
  string current_verb, exit_room;
  int index;
  string *exits_here;
 
  current_verb = query_verb();
  exits_here = (string *)this_object()->query_exits();

  if(member_array(current_verb, exits_here) != -1) {
    if(has_drink(this_player())) {
      tell_object(this_player(), OWNER +" says: You're not allowed "+
        "to leave here with drinks!\n");
      return 1;
    }
  }
  return 0;
}
 
status has_drink(object obj) {
     int i;
     status drink;
     object *ob;
 
     ob = all_inventory(obj);
     for(i=0; i<sizeof(ob); i++) {
         if(ob[i] -> id("pub drink") || ob[i] -> query_pub_drink())
             drink = 1;
        if(ob[i] -> can_put_and_get()) {
             if (has_drink(ob[i]))
                  drink = 1;
        }
     }
     return drink;
}
 
string set_owner(string owner_name) {
  object owner;
 
  if(!owner_name || !stringp(owner_name)){
    if(OWNER)
      owner_name = OWNER;
    else
      owner_name = "shamus";
  }
  OWNER = capitalize(owner_name);
  owner = clone_object("inherit/monster");
  owner -> set_name(L_OWNER);
  owner -> set_race("human");
  owner -> set_short(OWNER+", the bartender");
  owner -> set_long(OWNER+" has always run this pub.\n");
  owner -> set_al(30);
  owner -> set_gender(1);
  owner -> set_level(15);
  owner -> set_wc(20);
  owner -> set_ac(18);
  owner -> set_hp(7050);
  owner -> load_chat(1,({

             OWNER+" says: Would you like something to drink?\n",
             OWNER+" says: Do you have any bottles to sell?\n",
 }));
  owner -> load_a_chat(25,({
             OWNER+" says: You'll never steal my beer!\n",
             OWNER+" gives you a wack over the head with a bottle.\n", }));
 
  owner -> add_money(1200 + random(800));

  move_object(owner, this_object());
}
 
query_prop(string str) {
  if(str == "nulmagic") return str;
  return;
}
 
status sell_bottle(string arg) {
   object bottle;
   int coinage;
   bottle = present("bottle", this_player());
   if(arg != "bottle") {
     write(OWNER+" asks: sell what?\n");
     return 1;
   }
   if(arg == "bottle" && !bottle) {
      write(OWNER+" says: Hey! You don't have a bottle!.\n");
      return 1;
   }
   if(arg == "bottle" && bottle) {
     coinage = (int)bottle->query_value();
     coinage /= 4;
     write(OWNER+" says: Thanks for helping out the city.\n");
     if(random(PLAYER_STAT) > random(OWNER_STAT))
       coinage += random(coinage/4);
     else
       coinage -= random(value/3);
     write(OWNER+" hands you "+
     (string)call_other(MONEY, "convert", coinage)+
     "for the bottle\n");
     say(this_player()->query_name()+" sells the empty bottle to "+OWNER+".\n");
     this_player()->add_money(coinage);
     destruct(bottle);
     return 1;
    }
}

status listen(string str) {
  if((string)this_object()->query_listen() != "You hear nothing special.\n")
    return 1;
  rumours(1);
  return 1;
}  

void rumours(status noCallOut) {
  string txt;

  txt = RUMOURS->get_rumour();
  if(!txt) txt = "\n";

  tell_room(this_object(), txt);
  if(!noCallOut) call_out("rumours", 300);
  return;
}

void add_rumours(string str) {
}
