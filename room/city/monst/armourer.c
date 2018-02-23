/* THE FORGE!  -   Angel, March 1994
 * This simple room makes armour and weapons of a standard type
 * for players. To make an item it takes time. This also removes
 * the variation of other Creators weapon shops, making them all
 * standard across the mud. 
 *
 * When you write down the price list for potions somewhere, please
 * make the price = 200 * the potion as a spell level
 *
 */
#include <mudlib.h>
inherit MONSTER;

#define OWNER            (string)this_object()->query_name()
#define CHARISMA         (int)this_player()->query_charisma()
#define VALUE_MOD        20
#define COST_MOD         300
#define EXTRA_MOD	 ((int)this_player()->query_level()/3)*2
#define DIFFICULTY       15   /* thorins difficulty to make armour/weapon */
#define ABILITY          20   /* thorins ability to make armour/weapon    */
#define TIME_OUT         10   /* time in lots of 30 seconds               */
#define CALLOUT_TIME     30

static object owner_ob;
object the_item;
static string owner_name, owner;
static status Forge, Brew, Enchant, Scribe;
static string customer;       /* The person the OWNER is working for */
static status working;        /* If the OWNER it is working          */
int counter;                  
status finished;

string job_name, type;

int ac, wc, weight, value, length; 
int tmp_value;
mixed *items;
string potion_name;
string *potion_array;
status fault;

void set_owner(string str);
status forge(string str);
status forge_item(); 
status make_potion();
status scribe(string tmp1, string tmp2);
status brew(string str);
status enchant(string tmp1, string tmp2);
status working();
void make_armour();

status set_forge(status arg)   { return Forge = arg;   }

status set_brew(status arg)    { return Brew = arg;    }
status set_enchant(status arg) { return Enchant = arg; }
status set_scribe(status arg)  { return Scribe = arg;  }


void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("thorin");
  set_short("Thorin the forger");
  set_forge(1);
}

void init() {
  if(!potion_array) potion_array = ({});
  ::init();
  add_action("forge", "make");
  add_action("brew", "brew");
  if((string)this_player()->query_name() == customer)
    call_out("check_finished_item", 1);
}

void catch_tell(string str) {
  string tmp1, tmp2, tmp3;

  if(Forge)
    if(sscanf(str, "%s says: make %s\n", tmp1, tmp2, tmp3)) {
      write(tmp2+".\n");
      write(tmp1+".\n");
     forge(tmp2);
    }
  if(Scribe)
    if(sscanf(str, "%s says: scribe %s\n", tmp1, tmp2)) 
      scribe(tmp1, tmp2);

  if(Enchant)

    if(sscanf(str, "%s says: enchant %s\n", tmp1, tmp2)) 
      enchant(tmp1, tmp2);

  if(Brew)
    if(sscanf(str, "%s says: brew %s\n", tmp1, tmp2)) 
      brew(tmp2);
}


status working() {
  if(customer) {
    write(OWNER+" says: I'm still busy, come back later.\n");
    return 1;
  }
  return 0;
}

status forge(string str) {

  int i;
  if(!Forge) return 0;
  if(working()) return 1;
  if(!str) {
    write(OWNER+" says: What did you want me to make?\n");
    return 1;
  }


  items = ({
	"helm", "armour", "boots", "amulet", "cloak",
	"slash", "cleave", "pierce", "crush",
        "gloves", /* Added by Sarak on September 7, 1995 due to bug */
  });  /* temp array to stpo them stuffing up the array match */
  if(member_array(str, items) != -1) {
    write("Thorin asks: What kind of "+str+" was that?\n");
    return 1;
  }


  items = ({ 
          /* NAME             WC         TYPE          WT      VALUE  LENGTH */
          "sickle",            9,       "slash",       4,        400,      24,
          "dagger",            8,       "slash",       4,        275,      15,
          "dirk",              8,       "slash",       4,        400,      12,
          "knife",             6,       "slash",       4,        90,       12,
          "scimitar",         10,       "slash",       5,        520,      36,
          "broadsword",       12,       "slash",       5,        1100,     42, 
          "falchion",         12,       "slash",       5,        1100,     42,
          "khopesh",          11,       "slash",       5,        770,      42,
          "longsword",        13,       "slash",       6,        1500,     42,
          "shortsword",       10,       "slash",       5,        520,      24,
          "rapier",           12,       "pierce",      5,        1100,     48,
          "sabre",            10,       "slash",       5,        520,      45,
          "cutlass",          11,       "slash",       5,        770,      36,
          "halberd",          13,       "pierce",      6,        1500,     60, 
          "pike",             12,       "pierce",      5,        1100,     60, 
          "lance",            10,       "pierce",      5,        520,      150,
          "ranseur",          11,       "pierce",      5,        770,      96,
          "spear",            10,       "pierce",      5,        520,      70,
          "trident",          10,       "pierce",      5,        520,      50,
          "club",              9,       "crush",       4,        400,      36,
          "flail",            10,       "crush",       5,        520,      48,
          "horsemansfail",    10,       "crush",       5,        520,      48,
          "footmansflail",    10,       "crush",       5,        520,      48,
          "hammer",           11,       "crush",       5,        770,      24,
          "warhammer",        11,       "crush",       5,        770,      30,
          "staff",            12,       "crush",       5,        1100,     80,
          "rod",              12,       "crush",       5,        1100,     80,
          "mace",             12,       "crush",       5,        1100,     36,
          "horsemansmace",    12,       "crush",       5,        1100,     36,
          "footmansmace",     12,       "crush",       5,        1100,     36,
          "battleaxe",        12,       "cleave",      5,        1100,     48, 
          "handaxe",           8,       "cleave",      4,        275,      24,
          "axe",              10,       "cleave",      5,        520,      30,
          "twohandedsword",   14,       "cleave",      7,        1600,     72,
          "bastardsword",     13,       "cleave",      6,        1500,     54,
          "morning  star",     9,       "cleave",      4,        400,      24,
          "morningstar",       9,       "cleave",      4,        400,      24,
          "claymore",         14,       "cleave",      7,        1600,     72
  });
  if(member_array(lower_case(str), items) > -1) {
    i = member_array(lower_case(str), items);
    job_name   = items[i];
    wc         = items[i + 1];
    type       = items[i + 2];
    weight     = items[i + 3];
    value      = items[i + 4];
    length     = items[i + 5];
    the_item = clone_object(WEAPON);
  }


  else {
    items = ({ "chainmail",   3,        "armour",      5,        800,
               "platemail",   4,        "armour",      6,        1600,
               "fieldplate",  4,        "armour",      5,        2500,
               "fullplate",   4,        "armour",      5,        2500,
               "shield",      1,        "shield",      3,        200,
               "boots",       1,        "boots",       2,        200,
               "gauntlets",   1,        "gloves",      1,        300,
               "helm",        1,        "helm",        1,        300,
               "helmet",      1,        "helm",        1,        300
    });
    if(member_array(lower_case(str), items) > -1) {
      i = member_array(lower_case(str), items); 
      job_name   = items[i];
      ac     = items[i + 1];
      type   = items[i + 2];
      weight = items[i + 3];
      value  = items[i + 4];

      the_item = clone_object(ARMOUR);
    }
    else {
      write(OWNER+" says: I can't make a "+str+".\n");
      return 1;
    }
  }

  tmp_value = value;
  if(random(VALUE_MOD) > random(CHARISMA))
    tmp_value += random(value/4);
  else
    tmp_value -= random(value/3);
  tmp_value *= 6;
  /* same as in the shop... players PAY for the convenience! */
  /* -Angel. Aug 95 */
  write(OWNER+" haggles with you over the price of the "+job_name+".\n");
  if(this_player()->query_money() < tmp_value) {

    write(OWNER+" says: But you don't have "+
      call_other(MONEY, "convert", tmp_value)+" coins!\n");
    return 1;
  }
 
  write(OWNER+" takes "+call_other(MONEY, "convert", tmp_value)+
        " coins from you for the "+job_name+"\n");
  this_player()->add_money(-tmp_value);

  tell_room(environment(), OWNER+" says: It'll take a while to make it.\n"+
                           OWNER+" says: Come back later.\n");

  customer = (string)this_player()->query_name();
  finished = 0;  /* just started */
  forge_item();
  return 1;
}



void check_finished_item() {
  object obj;

  if(present(job_name, this_object())) {
    obj = present(job_name, this_object());
    tell_room(environment(), OWNER+" says: Hullo "+this_player()->query_name()+
               ", I've finished your");
    if(wc) tell_room(environment(), " weapon.\n");
    else if(ac) tell_room(environment(), " armour.\n");
    else
      tell_room(environment(), " item.\n");
    
    move_object(obj, this_player());
    customer = 0;
    job_name = 0;
    finished = 0;
    return;

  }
  if(finished) {
    tell_room(environment(), OWNER+" says: I'm sorry "+customer+", but "+
     "someone stole your "+job_name+" from me.\n\t\tPerhaps I can make "+
     "another one for you?\n");
    finished = 0;  /* can make another one now */
    return;
  }
  tell_room(environment(), OWNER+" exclaims: I haven't finished the "+job_name+
     " yet! Come back later!\n");
}

status brew(string str) {
  int i;
  string tmp1, tmp2;
  object obj;

  if(!Brew) return 0;

  if(customer) {
    write(OWNER+" says: Sorry, I'm busy, come back later.\n");
    return 1;
  }

  obj = clone_object(MAGIC_POTION);
  if(!obj -> set_spell(str)) {
    write(OWNER+" says: I don't know how to brew that potion.\n");
    return 1;
  }
  if(member_array(str, potion_array) == -1) {
    write(OWNER+" says: I don't know how to make that potion.\n");
    return 1;
  }
  value = (int)obj->query_cast_level() * COST_MOD;
  if(random(VALUE_MOD) > random(CHARISMA))
    value -= random(
value/4);
  else

    value += random(value/3);
  write(OWNER+" haggles with you over the price of the potion.\n");
  if((int)this_player()->query_money() < value) {
    write(OWNER+" says: You don't have "+
    call_other(MONEY, "convert", value)+" coins for the "+job_name+".\n");
    return 1;
  }

  this_player()->add_money(-value);
  write(OWNER+" takes "+call_other(MONEY, "convert", value)+
     " coins from you for the potion.\n");

  job_name = "potion";
  potion_name = str;
  customer = (string)this_player()->query_name();
  the_item = obj;
  tell_room(environment(), OWNER+" begins to brew a "+potion_name+" potion.\n");
  make_potion();
  return 1;
}

status make_potion() {
  object obj;
  counter++;
  obj = the_item;
  if(counter >= TIME_OUT) {
    if(random(DIFFICULTY) > random(ABILITY))
      fault = 1;

    obj -> set_name("potion");
    obj -> set_short("A potion");
    obj -> set_long("A potion in a steel vial.\n");
    obj -> set_info("A potion of "+job_name+".\n");
    obj -> set_weight(1);
    move_object(obj, this_object());
    tell_room(environment(), OWNER+" finishes the potion.\n");

    finished = 1;
    remove_call_out("make_potion");
    return 1;
  }
  tell_room(environment(), OWNER+" continues to brew a potion.\n");
  call_out("make_potion", CALLOUT_TIME);
  return 1;
}

status forge_item() {
  object obj;

  counter++;
  obj = the_item;
  if(counter >= TIME_OUT) {
    if(random(DIFFICULTY) > random(ABILITY))
      fault = 1;
    obj -> set_name(job_name);
    obj -> set_short("A steel "+job_name);
    obj -> set_long("A finely designed "+job_name+", forged in\n"+
          "the traditional dwarvish fashion.\n");
    if(wc) {
      obj -> set_wc(wc);
      obj -> set_length(length);
    }
    else
      obj -> set_ac(ac);

    obj -> set_weight(weight);
    obj -> set_type(type);
    obj -> set_value(value);    
      
    move_object(obj, this_object());

    tell_room(environment(), OWNER+" finishes the "+job_name+".\n");

    finished = 1;
    counter = 0;
    remove_call_out("forge_item");
    if(!find_player(lower_case(customer))) {
      tell_room(environment(), OWNER+" wonders where "+capitalize(customer)+
        " has got to.\n"+OWNER+" throws the "+obj->short()+" away.\n");
      destruct(obj);
    }

    return 1;
  }
  tell_room(environment(), OWNER+" continues to forge a "+job_name+".\n");
  call_out("forge_item", CALLOUT_TIME);
  return 1;
}
