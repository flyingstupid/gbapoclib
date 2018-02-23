#include <mudlib.h>
#include <linewrap.h>
#include <keeps.cfg>

#define NAME		this_player()->query_name(1)


#define COST		10000

#define CHR		(int)this_player()->query_charisma()
#define CHANCE		20


status hired;
string owner;


inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("architect");
  set_level(15);
  set_short("A dwarven architect");
  set_long(
	"Perhaps he will design and make a house for you?\n");
  set_gender(1);
  set_race("mountain dwarf");
  set_alias("dwarf");

  set_heart_ob(this_object());

}

void long(status wiz) {
  ::long(wiz);
  if(hired && owner) 
    write(query_name()+" has been hired by "+owner+".\n");
}

void monster_heart_beat() {
  if(owner) {
    if(!find_player(lower_case(owner))) {
      tell_room(environment(),
	query_name()+" shrugs his shoulders and leaves.\n");
      hired = 0;
      owner = 0;
      move_object(this_object(), find_object(query_create_room()));
    }
  }
}
      

void init() {
  ::init();
  add_action("hire",  "hire");
  add_action("build", "build");
  add_action("fire", "fire");
}


status fire() {
  tell_room(environment(), query_name()+" smiles and waves goodbye.\n");
  if(owner != this_player()->query_name()) {
    write(query_name()+" says: You haven't hired me, so you can't fire me.\n");
    return 1;
  }

  owner = 0; hired = 0;
  move_object(this_object(), find_object(query_create_room()));
  return 1;
}

status hire() {
  int cost;

  if(hired) {
    notify_fail(query_name()+" says: Sorry, I am already being hired.\n");
    return 0;
  }

  if(!present("RealEstate", this_player())) {
    notify_fail(query_name()+" exclaims: I'll only build something if you own "+
	"some land!\n");
    return 0;
  }
  write(query_name()+" bargains with you over the price of hiring him.\n");

  cost = COST;

  if(random(CHR) > random(CHANCE))
    cost -= cost/4;
  else
    cost += cost/3;

  hired = 1;
  if(cost > (int)this_player()->query_money()) {
    notify_fail(query_name()+" says: You seem to have a cash flow problem.\n");
    return 0;
  }

  this_player()->add_money(-cost);
  this_player()->add_followers(this_object());
  writelw(query_name()+" takes "+MONEY->convert(cost)+" coins from you "+
	"for the cost of hiring him.\n");

  owner = NAME;
  owner = capitalize(owner);
  return 1;
}


status build(string str) {
  string tmp1, tmp2;
  string txt;
  object ob;
  int i, j, k;

  if(!str) {
    notify_fail(query_name()+" asks: build you what?\n");
    return 0;
  }


  if(owner != capitalize(NAME)) {
    notify_fail(query_name()+" asks: Why should I build you anything?\n");
    return 0;
  }

  if(!ob = present("RealEstate", this_player())) {
    notify_fail(query_name()+" says: Where's you deed to the land?\n");
    return 0;
  }

  if(present("Doorway", environment())) {
    notify_fail(query_name()+" says: This land has already been developed.\n");
    return 0;
  }

  if((string)ob->query_file() !=
     "/"+ (string)this_player()->query_current_room()) {
    notify_fail(query_name()+" says: You have to own the land before I can "+
	"build on it.\n");
    return 0;
  }


  if("/"+ (string)this_player()->query_current_room() !=
     present("parchment", this_player())->query_file()) {
    notify_fail(query_name()+" says: I can't build here. You don't own the land.\n");
    return 0;
  }

  if(sscanf(str, "%shouse%s", tmp1, tmp2)) {   

    MASTER->master_create_player_files(NAME);
    for(i=0; i<20; i++) {
      if(file_size(PLAYER_DIR + NAME +"/home"+i+".c")  < 1)
      break;
   }

    txt = "#include <mudlib.h>\n"+
          "#define NAME \""+ capitalize(NAME) +"\"\n"+
          "inherit ROOM;\n\n\n";

    write_file(PLAYER_DIR + NAME +"/home"+i+".c", txt);

    txt = read_file(HOME);
    write_file(PLAYER_DIR + NAME + "/home"+i+".c", txt);

    txt = "#include <mudlib.h>\n"+
	  "#define ENV \""+ file_name(environment(this_player())) +"\"\n"+
	  "#define NAME \""+ capitalize(NAME) +"\"\n";

    write_file(PLAYER_DIR + NAME +"/doorway"+ i +".c", txt);
    txt = read_file(DOORWAY);
    write_file(PLAYER_DIR + NAME +"/doorway"+ i +".c", txt);

    call_other(PLAYER_DIR + NAME +"/home"+i, "reset");
    call_other(PLAYER_DIR + NAME + "/doorway"+ i, "reset");

    write_file(AUTO_LOAD_FILE, "#"+ PLAYER_DIR + NAME +"/doorway"+ i +".c\n");
    write(query_name()+" says: Well, that should take care of it!\n");
    return 1;
  }
  
  notify_fail(query_name()+" says: I only build houses.\n");
  return 0;
}

  
