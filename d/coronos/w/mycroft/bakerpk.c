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

#define JOE FRIDAY "d/coronos/w/mycroft/joefriday.c"
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
if(!present("JOE FRIDAY")) {
move_object(clone_object(JOE FRIDAY), this_object());
  }

  reset_doors(arg);

  if(arg) return;



#ifdef SAVE_VILLANS
  restore_object(SAVE_VILLANS);
#endif

  if(!villians || !sizeof(villians)) villians = ([ ]);

  load_door(({
	"direction", "north door",
	"file", "d/coronos/w/angel/city/chambers/dirk",
"description","A solid steel door.\n",
  }));
set_short("The Offices of the Ministry of Justice");
  set_long(
"A small, neatly kept office. There is little more than a desk, a few\n"+
"chairs, and some filing cabinets.  A group of sketch artist mug shots\n"+
"cover the wall in back of you.  There is a sign to your right.\n");
  set_weather(2, 2, 0);
  set_exits(({
"//d/coronos/w/mycroft/annex1.c","north",
  }));


  set_items(({
	"sign", "Perhaps you should read it?",
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
write("Joe Friday says: Do you want something?\n");
    return 1;
  }
  if(present("bounty license", this_player())) {
write("Joe Friday says: Have you been smoking the Weed or something? You have a license!.\n");
    return 1;
  }
  if(query_villian(this_player()->query_name(1))) {
write("Joe Friday says: I can't give a license to a sociopath like yourself!\n");
    return 1;
  }
write("Joe Friday finds the current price for a bounty hunting license.\n");
  cost = DEFAULT_COST;
  if(CHA < MY_CHA)
    cost -= cost /4;
  else
    cost += cost/3;

    write("Curzon says: That will cost you "+MONEY->convert(cost)+" coins.\n");
  if(!flag && cost > (int)this_player()->query_money(cost)) {
write("Joe Friday says: You don't have that kind of bread!\n");
    return 1;
  }
  if(!flag)
    this_player()->add_money(-cost);
  ob = clone_object(LICENSE);
  move_object(ob, this_player());
  if(!flag)
write("Joe Friday says: As much as I hate vigilantes, I\n"+
"don't have the resources to do this job alone.  So good\n"+
"hunting down this criminal, bounty hunter.\n");
  return 1;
}

status pk_change(string str) {
  string tmp1, tmp2;
  if(!sscanf(str, "%sbounty on %s", tmp1, tmp2)) {
write("Joe Friday says: You want to up the reward on who?\n");
    return 1;
  }
  tmp2 = lower_case(tmp2);
  if(!query_villian(tmp2)) {
write("Joe Friday says: No such criminal on our hotlist!\n");
    return 1;
  }
  tmp_name = tmp2;

write("Joe Friday says: You want to up the bounty by how much?\n");
        " Write amount > ");
  input_to("pk_change2");
  return 1;
}

status pk_change2(string str) {
  int amount;
  string type;

  if(!str || str == "") {
write("Joe Friday says: Ok, mac, but up the ante on the scum just makes\n"+
"life safer here in our beloved city.\n");
    return 1;
  }
  if(sscanf(str, "%d %s",amount, type)) { 
    if(type == "platinum") amount *= PLATINUM;
    else if(type == "gold") amount *= GOLD;
    else if(type == "silver") amount *= SILVER;

    if(amount > (int)this_player()->query_money()) {
write("Joe Friday says: You don't have the dough, mister!\n");
      return 1;
    }
write("It's good to see some people still care about Justice like I do!\n");
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
write("Joe Friday says: What criminal do you want to remove from the list?\n");
    return 1;
  }
    if(!query_villian(str)) {
write("Joe Friday says: But he's a good man, I tell you!\n");
    return 1;
  }
  remove_villian(str);
write("Joe Friday says: Ok then , he's offthe hook.\n");
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

if(!present("joe friday)){

    write("There's no one present in the guard's office right now...\n");
    return 1;
  }
  if(!(ob=present("head", this_player()))) {
write("Joe Friday says: You don't have a head for me, Chester!\n");
    return 1;
  }
  name = (string)ob->query_alias_name();
  if(!name) {
write("Joe Friday says: What are you trying to do, bribe me?\n");
    return 1;
  }

  if(!query_villian(name)) {
write("Joe Friday says: But "+name" is straight, I tell you!\n");
    return 1;
  }

write("You give "+ob->short()+" to Detective Friday.\n");
say(NAME+" gives "ob->short()+" to Detective Friday.\n", this_player());

  amount = query_bounty(name);
write("Detective Friday says: Take the reward money and get out!\n"+
"Joe Friday gives you "+(string)MONEY->convert(amount)+"\n");

  this_player()->add_money(amount);

  destruct(ob);
  this_player()->recalc_carry();
  remove_villian(name);
  save_me();
  return 1;
}
