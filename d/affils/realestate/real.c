/* Real Estate v1.2 (c) Angel 
 * Converted real estate info to mapping, using player_info January 1999
 */

#include <mudlib.h>
#include <linewrap.h>
#include <keeps.cfg>
inherit ROOM;

#define SAVE    	"ob_saves/affils"
#define OWNER   	"Shoal"

#define NAME            (string)this_player()->query_name()
#define CHARISMA        (int)this_player()->query_charisma()
#define MIN_LEVEL       30
#define MY_STAT         20
#define COST            100000



string *land, *tmpDesc;


void initialize_player_rooms();
void restore_me();
void save_me();


void reset(status arg) {
  object gnome, board;

  reset_doors(arg);

  if(!present("board")) {
    board = clone_object(BULLETIN);
    board -> set_save_file("ob_saves/boards/keeps");
    board -> set_long(
        "       The Land Council                \n"+
        "       ~~~~~~~~~~~~~~~~                \n"+
        "This board is for items on keeps and castles for players.\n");
    move_object(board, this_object());
  }

  if(!present("architect")) {
    move_object(clone_object("d/affils/realestate/arch"), this_object());
  }
  if(!present("shoal"))
    move_object(clone_object("d/affils/realestate/shoal"), this_object());
  if(arg) return;

  initialize_player_rooms();
  load_door(({
        "file", "d/coronos/w/darkness/b/hall/hall6",
        "direction", "oak door",
        "long", "A door of sturdy oak.\n",
  }));

  set_short("the realestate office");
  set_long(
"The obvious opulence of this room indicates that you have arrived\n"+
"in the Land Council Chambers, decorated by the Circle member, Sir\n"+
"George the gnome. The walls are decorated with plans and house   \n"+
"blue prints, as well as maps of the surrounding farming and      \n"+
"residential areas. On one wall is a fine plaque made from gold.  \n");


  set_items(({
"plans",
"The plans appear to be blue prints for various public works",

"blue prints",
"One of the blue prints appears to be Master George's own house plans",

"house plans",
"They look very elaborate. Only a skilled draftsmen could interpret it",

"maps", "The maps depict the city of Ille Coronos and the surrounding areas",
  }));

  set_night_desc(
"The room appears odly empty tonight; the only sign that this \n"+
"lavishly decorated office is ever in use is a small sign at  \n"+
"the front of the desk which stands in the middle of the room.\n");


  set_night_items(({
        "sign",
        "The sign is made from gold and reads: \n"+  
        "Ille Coronos Land Council: Office Closed",

        "desk",
"The desk is made from a dark oak, possibly a gift from the elvish \n"+
"people of Scianthian in the forest north of Ille Coronos. It looks\n"+
"very large and very heavy. The desk is bare tonight, except for a \n"+
"sign which sits on its top, and an oil lamp.",

        "lamp#oil lamp",
"The lamp is made from gold and steel, and appears to be empty of oil",
  }));





  set_day_desc(
"A fine old oak desk stands in the centre of this well appointed \n"+
"room, with a single oil lamp casting streams of soft filtered   \n"+
"light around it. The rest of the room is sparse, decorated only \n"+
"by yellowing parchments and ancient maps. \n");  


  set_day_items(({
"lamp#oil lamp",
"The oil lamp appears to be made from gold and steel, and casts \n"+
"soft yellow light over the desk.",

"oak desk#desk",
"The desk is made from a dark oak, possibly a gift from the elvish \n"+
"people of Scianthian in the forest north of Ille Coronos. It looks\n"+
"very large and very heavy. On the desk are stacks of papers and   \n"+
"writing quills and ink.",

"paper#papers",
"The papers are title deeds and papers of authority for various acts\n"+
"of land grants given by The Circle. All are stamped with the seal  \n"+
"of The Circle, the Land Council, and the Merchant's Guild",

"seal#stamp",
"The first depicts the symbol of The Circle; a golden circlet behind \n"+
"the symbol of the All-God; the next a pyramid of silver; and the last\n"+
"is a golden circlet in the background with hands shaking in the fore",

"hands",
"The hands look like they are shaking eachother in some kind of greeting",
"circlet",
"It is a simple circle of gold",
"symbol",
"The symbol of the All-God",
"pyramid#triangle",
"A triangle, pointing ever upward toward the heavens",

"writing quills#quills",
"The quills are made from dragon feathers, or so George, the cities \n"+
"head guildmaster and member of The Circle, would tell you",

"ink", "It looks fresh",
  }));


  set_weather(2, 1, 0);

  restore_me();
  if(!sizeof(land)) land = ({ });
}

void restore_me() { restore_object(SAVE+"/lands"); }
void save_me()    { save_object(SAVE+"/lands");    }


void remove_land(string str) {
  int i;

  if(!land || !sizeof(land)) land = ({ });
  if((i = member_array(str, land)) != -1) {
    land = land[0..i-1]
                 + land[i+1..sizeof(land)-1];
  }
} 

void initialize_player_rooms() {
  int i;
  string txt, tmp, *files;

  txt = read_file(AUTO_LOAD_FILE);
  if(!txt) return;
  files = explode(txt, "#");
  if(!sizeof(files)) return;
  for(i=0; i<sizeof(files); i++) {
    if(!files[i]) {
      sscanf(files[i], "%s\n", tmp);
    }
    else sscanf(files[i], "%s\n", tmp);

    if(!tmp || !strlen(tmp)) continue;
    write("Loading player file: "+tmp+"\n");
    if(catch(call_other(tmp, "reset"))) {
      log_file("KEEP_ERRORS", files[i]+" failed to load "+ctime(time())+"\n");
    }
  }
} 


string *query_land() { return land; }
string *query_tmpDesc() { return tmpDesc; }



void init() {
  ::init();

  add_action("land_add",     "add");
  add_action("land_buy",     "buy");
  add_action("land_sell",    "sell");
  add_action("look_at",      "look");
  add_action("look_at",      "examine");
  add_action("look_at",      "exa");
}





status land_add(string arg) {
  string tmp; 
  if(!this_player()->query_security_level())
    return 0;

  if(!present("shoal"))
    write("Shoal is not here, so you do the paper work yourself.\n");

  if(!arg) {
    notify_fail(OWNER+" asks: Add what land to the list?\n");
    return 0;
  }

  arg = (string)WIZARD->make_path(arg);

  if(file_size(arg+".c") < 1) {
    notify_fail(OWNER +" says: "+arg+" is not a valid file.\n");
    return 0;
  }

  if(member_array(arg, land) != -1) {
    notify_fail(OWNER+" says: I'm sorry, but that land has already been "+
        "added.\n");     
    return 0;
  }
  write(OWNER+" says: Adding "+arg+" to the list of land.\n");
  land += ({ arg, });
  save_me();
  return 1;
}


status look_at(string str) {
  int i, j;
  string tmp;

  if(str == "plaque") {
    write(
        "                 Ille Coronos Land Council                     \n"+
        "                 ~~~~~~~~~~~~~~~~~~~~~~~~~                     \n"+
        " Valid Commands:       buy <land>......Purchase some land      \n"+
        "                       sell land ......Sell a title to some land\n"+
        "                       examine land....Look at the list of land\n"+
        "                       examine <land>..Look at a specific land \n");
    if(this_player()->query_security_level())
      write(
        "                       add <file>......Add land to the list \n");
    return 1;
  }


  if(!present("shoal")) {
    notify_fail(OWNER+" is not here to show you the land he has for sale.\n");
    return 0;
  }

  if(str == "land") {
    if(sizeof(land) < 1) {
      write(OWNER+" says: I don't have any land to sell you today.\n");
      return 1;
    }
    tmp = "";
    write(OWNER+" says: I have the following land for sale.\n");
    for(i=0; i<sizeof(land); i++) {
      tmp = (string)call_other(land[i], "short")+".......................";
      tmp = extract(tmp, 0, 50);
      if(!(j = (int)land[i]->query_land_value()))
        j = COST;
      tmp += (string)MONEY->convert(j)+" coins";
      write(tmp+"\n");
    }
    return 1;
  }

  for(i=0; i<sizeof(land); i++) {
    if((string)call_other(land[i], "short") == str) {
      write("You look more closely at the land on the wall.\n");
      call_other(land[i], "long");
      return 1;
    }
  }

  return ::look_at(str);
}


int land_properties() {
  mapping keepsMap;
  int i;
  keepsMap = (mapping)this_player()->query_player_info("keeps");
  return (i=(sizeof(keepsMap))) ? i : 0;
}


status land_buy(string str) {
  object ob;
  int i, cost;
  string tmp;
  mapping keepsMap;

  if(!present("shoal")) {
    notify_fail(OWNER+" is not here to sell any land to you.\n");
    return 0;
  }

  if(!str) {
    notify_fail(OWNER+" says: What land do you want to purchase?\n");
    return 0;
  }


  if((int)this_player()->query_level() < MIN_LEVEL + land_properties()) {
    notify_fail(OWNER+" asks: Why should I sell land to a nobody like you?\n");
    return 0;
  }
  write("You bargain with "+OWNER+" over the price of some land.\n");
  say(NAME+" bargains with "+OWNER+" over the price of some land.\n", 
	this_player());


  for(i=0; i<sizeof(land); i++) {

    if(str == (string)call_other(land[i], "short")) {
      if(!cost = ((int)call_other(land[i], "query_land_value")))
        cost = COST;
     if(random(CHARISMA) > random(MY_STAT))
       cost -= cost/4;
     else
        cost += cost/3;

      if(cost > (int)this_player()->query_money()) {
        write(OWNER+" exclaims: You seem to have a cash flow problem!\n");
        return 1;
      }
      writelw("You purchase "+str+" for "+MONEY->convert(cost)+" coins.\n");
      this_player()->add_money(-cost);
      ob = clone_object("d/affils/realestate/title");  

      keepsMap = (mapping)this_player()->query_player_info("keeps");
      if(!keepsMap) keepsMap = ([ ]);

      keepsMap += ([ land[i] : ([
					"value" : cost,
				]),
		  ]);

      this_player()->add_player_info("keeps", keepsMap);
      remove_land(land[i]);
      save_me();
      return 1;
    }
  }
  write(OWNER+" exclaims: I don't have any land that looks like that!\n");
  return 1;
}



status land_sell(mixed arg) {
  int i, cost;
  string *files;
  int j, k;
  string tmp;
  object ob;
  object obj;
  mapping keepsMap, tmpMap;
  string *keys;
  mixed *values;



  if(!present("shoal")) {  
    notify_fail(OWNER+" is not here to buy any land from you.\n");
    return 0;
  }

  if(!(keepsMap = ((mapping)this_player()->query_player_info("keeps")))) {
    notify_fail(OWNER+" exclaims: You don't have any land to sell me!\n");
    return 0;
  }

  if(!sizeof(keepsMap)) {
    notify_fail(OWNER+" exclaims: You don't have any land to sell me!\n");
    return 0;
  }


  keys   = m_indices(keepsMap);
  values = m_values(keepsMap);
  
  /* if we have more than one island */
  if(sizeof(keys) > 1 && !arg) {
    write("You have several items of real estate you can sell.\n");
    for(i=0; i<sizeof(keys); i++) {
      call_other(keys[i], "???");
      ob = find_object("/"+ keys[i]);
      write("["+ (i+1) +"]\t"+ call_other(ob, "query_short") +"\n");
    }
    write("Which item of land do you wish to sell? (#1 - #"+ sizeof(keys) +") ");
    input_to("land_sell");
    return 1;
  }

  
  if(arg) arg = to_int(arg);
  if(arg > 0) arg --;

  tmpMap = values[arg]; 
  cost = tmpMap["value"];

  if(!cost) cost = COST;
  cost /= 4;

  if(random(CHARISMA) > random(MY_STAT))
    cost += cost/4;
  else
    cost -= cost/3;

  tmp = keys[arg]; /* a filename */
  call_other(tmp, "???");
  obj = find_object("/"+ tmp);

  write(OWNER+" exclaims: I'll give you "+MONEY->convert(cost)+" for "+
	obj->short() +"!\nYou hand over the title deeds to your property.\n");
  

  this_player()->add_money(cost);
  this_player()->save_me(1);


  land += ({ tmp, });

  if(ob = present("Doorway", obj)) {
    writelw("You can hear developers moving in on "+
    (string)obj->short()+" already!\n");

    obj->reset(0); /* give it a good reset to remove the door object! */

    sscanf(file_name(ob), "%sdoorway%d", tmp, i);
    files = get_dir(PLAYER_DIR + lower_case(NAME) +"/");

    for(j=0; j<sizeof(files); j++) {
      if(sscanf(files[i], "%s"+i+".c", tmp)) {
        if(file_size(PLAYER_DIR + lower_case(NAME) +"/"+ files[j]) > 0)
          rm(PLAYER_DIR + lower_case(NAME) +"/"+ files[j]);
      }
    }
  }

  if(member(keepsMap, keys[arg]))
    keepsMap -= ([ keys[arg] ]);

  /* replace their player_info with the new information */
  this_player()->add_player_info("keeps", keepsMap);
  return 1;
}


