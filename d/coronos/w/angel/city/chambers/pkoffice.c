/* PK OFFICE
 *
 * This object simply adds and removes player killers
 *
 * v2.01 Angel, July 1996
 * v1.01 Angel, Nov 1994
 */
#include <mudlib.h>
#include <linewrap.h>
#include <living.cfg>

#define CHA		(int)this_player()->query_charisma()
#define MY_CHA		20
#define DEFAULT_COST	500
#define LICENSE		"objects/pk"
#define SAVE_VILLANS    "ob_saves/pk"   /* do we save the villians on reboot? */
#define BOUNTY  1000            /* 1 gold is default bounty */

#define CURZON	"d/coronos/w/angel/city/monst/curzon"
#define NAME    (string)this_player()->query_name()


/*****************************************************************************
 * Fn Prototypes
 */

void save_me();
void add_villian(string name, string victim, string crime);

mapping villians;
static string tmp_name;

inherit ROOM;
void reset(status arg) {
  if(!present("curzon")) {
    move_object(clone_object(CURZON), this_object());
  }

  reset_doors(arg);

  if(arg) return;



#ifdef SAVE_VILLANS
  restore_object(SAVE_VILLANS);
#endif

  if(!villians || !sizeof(villians)) villians = ([ ]);


  load_door(({
    "destination",      "d/coronos/w/darkness/b/hall/hall6",
    "direction",        "west door",
    "long",             "This is a wooden door made of oak.\n",
    "door id",          "west door",
  }));

  load_door(({
	"file", "d/coronos/w/angel/city/chambers/gaol",
	"direction", "cell door",
	"long",
	"A large iron gaol door with a little peep hole at the top.\n",
  }));
remove_door("east door");
remove_door("black door");
// Nasty hack by Aziz. Could someone tell me *where* this east door is made?

  load_door(({
	"direction", "black door",
	"file", "d/affils/rooms/dirk",
	"description", "A fine door with a poster of the Dirk's captain pinned to it.\n",
  }));
  set_short("the Office of the Black Guard");
  set_long(
	"A large desk dominates the confines of this relatively small \n"+
	"office. Behind it is a large flag, bearing a golden circle   \n"+
	"with a crucifix in the centre. On the wall there is a sign.  \n"+
	"There is a dark iron door to the east that marks the hallway \n"+
	"of the prison cells.\n");
  set_weather(2, 2, 0);
  set_exits(({
  }));


  set_items(({
	"sign", "Perhaps you should read it?",
	"flag", "The flag of Ille Coronos",
  }));

}



status query_villian(string name) {
  if(villians[name]) return 1;
  return 0;
}

int query_bounty(string name) {
  mixed *tmp;
  tmp = villians[name];
  return tmp[0];  /* first element is bouty value */
}



status query_victim(string killer, string victim) {
  mixed *tmp;

  if(!villians[killer]) return 0;
  tmp = villians[killer];
  tmp = tmp[1]; /* array of victim names */
  return (member_array(victim, tmp) == -1) ? 0 : 1;
}

mixed *query_victims(string name) {
  mixed *tmp;
  if(!villians[name]) return 0;
  tmp = villians[name];
  return tmp[1];
}

mixed *query_all_victims(string name) {
  return query_victims(name);
}

void remove_villian(string name) {
  villians = m_delete(villians, name);
  save_me();
}

void add_villian(string name, string victim, string crime) {
  mixed *tmp, temp;
  int amount;

  if(!victim) victim = "the innocent";
  if(!crime)  crime  = "terrible crimes!";

  if(!query_villian(name))
    villians += ([ name : ({ BOUNTY, ({ victim, }), ({ crime, }), }), ]);
  else {
    if(query_victim(name, victim)) {
      tmp    = villians[name];  /* returns array value   */
      tmp    = tmp[1];          /* the victims of 'name' */
      tmp   += ({ victim, });
      temp   = villians[name];
      temp   = temp[2];
      temp  += crime;
      amount = query_bounty(name);
      villians[name] = ({ amount, tmp, temp, });
    }
  }
  save_me();
}

void change_bounty(string name, int amount) {
  mixed *tmp, temp, old;
  int old_bounty;

  if(!query_villian(name)) return;
  tmp  = villians[name];
  tmp  = tmp[1];        /* all victims */
  temp = villians[name];
  temp = temp[2];
  old = villians[name];
  old_bounty = old[0];
  villians[name] = ({ (old_bounty + amount), tmp, temp, });
  save_me();
}


mapping query_all_data() { return villians; }
void save_me() { save_object(SAVE_VILLANS); }

void init() {
  ::init();
  add_action("pk_remove", "remove");
  add_action("pk_add", "add");
  add_action("pk_give", "give");
  add_action("pk_buy", "buy");
  add_action("pk_sign", "read");
  add_action("pk_change", "increase");
}

status pk_buy(string str) {
  status flag;
  object ob;
  int cost;
  if(!str) {
    write("Curzon says: Did you want to buy something?\n");
    return 1;
  }
  if(present("bounty license", this_player())) {
    write("Curzon says: You've already got a license. So go away.\n");
    return 1;
  }
  if(query_villian(this_player()->query_name(1))) {
    write("Curzon says: I'm not giving a license to a criminal like you!\n");
    return 1;
  }
  write("Curzon bargains with you over the price of a bounty hunters license\n");
  cost = DEFAULT_COST;
  if(CHA < MY_CHA)
    cost -= cost /4;
  else
    cost += cost/3;

  if(flag = (status)this_player()->query_affiliation("black-guard"))
    write("Curzon says: Licenses for you are free.\n");
  else
    write("Curzon says: That will cost you "+MONEY->convert(cost)+" coins.\n");
  if(!flag && cost > (int)this_player()->query_money(cost)) {
    write("Curzon says: You don't have that much money.\n");
    return 1;
  }
  if(!flag)
    this_player()->add_money(-cost);
  ob = clone_object(LICENSE);
  move_object(ob, this_player());
  if(!flag)
    write("Curzon appoints you an official deputy.\n"+
        "Curzon says: Good luck, bounty hunter.\n");
  else
    write("Curzon exclaims: Good luck. Hail the Black Guard!\n");
  return 1;
}

status pk_change(string str) {
  string tmp1, tmp2;
  if(!sscanf(str, "%sbounty on %s", tmp1, tmp2)) {
    write("Curzon says: Increase the bounty on who?\n");
    return 1;
  }
  tmp2 = lower_case(tmp2);
  if(!query_villian(tmp2)) {
    write("Curzon says: But I've not heard of such a criminal.\n");
    return 1;
  }
  tmp_name = tmp2;

  write("Curzon says: How much would you like to increase the bounty by? \n"+
        " Write amount > ");
  input_to("pk_change2");
  return 1;
}

status pk_change2(string str) {
  int amount;
  string type;

  if(!str || str == "") {
    write("Curzon says: Very well. But increasing a bounty ensures that \n"+
          "             someone will want to catch him.\n");
    return 1;
  }
  if(sscanf(str, "%d %s",amount, type)) { 
    if(type == "platinum") amount *= PLATINUM;
    else if(type == "gold") amount *= GOLD;
    else if(type == "silver") amount *= SILVER;

    if(amount > (int)this_player()->query_money()) {
      write("Curzon says: You don't have that much money.\n");
      return 1;
    }
    write("Curzon says: Gods be praised for your charitable donation.\n");
    change_bounty(tmp_name, amount);
    tmp_name = 0;
    this_player()->add_money(-amount);
    return 1;
  }
}


status pk_sign(string str) {
  mixed *keys, *values;
  string tmp;
  int i;
  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str != "sign") {
    notify_fail("Read the sign?\n");
    return 0;
  }
  keys = m_indices(villians);
  values = m_values(villians);

  write(" Cities Most Wanted List.\n"+
        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  tmp = ""; /* initialise string */
  for(i=0; i<sizeof(keys); i++) {
    tmp += "A reward of "+MONEY->convert(values[i][0])+" is offered for ";
    tmp += "the head of "+capitalize(keys[i])+", for ";
    tmp += implode(values[i][2], ", ");
    tmp += "\n";
    writelw(tmp);
    tmp = "";
  }
  write("\n\nOther valid commands here are as follows:\n"+
  " buy license.................. Buy a bounty hunters license.\n"+
  " increase bounty on <name>.... Add money to the criminals reward.\n");
  if(this_player()->query_affiliation("black-guard")) {
    write("\n");
    write("The following commands are available to the Black Guard.\n");
    write(" add <criminal>............. Adds someone's name to the list.\n");
    write(" remove <criminal>.......... Remove someone's name.\n");
  }
  return 1;
}

status pk_remove(string str) {
  if(!str) {
    write("Curzon says: Whose name do you want to remove from the list?\n");
    return 1;
  }
    if(!query_villian(str)) {
    write("Curzon says: But "+str+" is not a criminal.\n");
    return 1;
  }
  remove_villian(str);
  write("Curzon says: Very well then, "+capitalize(str)+" has been "+
  "admonished of his crime.\n");
  return 1;
}


status pk_add(string str) {
  if(!query_villian(str)) {
    write("You add "+str+"'s name to the list of criminals.\n");
   add_villian(lower_case(str), 0, 0);
    return 1;
  }
  return 0;
}

status pk_give(string str) {
  object ob;
  int amount;
  string tmp1, tmp2;
  string name;

  if(!present("curzon")) {
    write("There's no one present in the guard's office right now...\n");
    return 1;
  }
  if(!(ob=present("head", this_player()))) {
    write("Curzon exclaims: You don't have a head to give me!\n");
    return 1;
  }
  name = (string)ob->query_alias_name();
  if(!name) {
    write("Curzon asks: Why are you giving THAT to me?\n");
    return 1;
  }

  if(!query_villian(name)) {
    write("Curzon says: But "+name+" is not a criminal.\n");
    return 1;
  }

  write("You give "+ob->short()+" to Curzon.\n");
  say(NAME+" gives "+ob->short()+" to Curzon.\n", this_player());

  amount = query_bounty(name);
  write("Curzon says: Here is the reward money.\n"+
        "Curzon gives you "+(string)MONEY->convert(amount)+".\n");

  this_player()->add_money(amount);

  destruct(ob);
  this_player()->recalc_carry();
  remove_villian(name);
  save_me();
  return 1;
}
