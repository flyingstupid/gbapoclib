/***************************************************************************
 * Affiliations Room. v1.01. Angel of Heaven7, Oct, 1996.
 * 
 * An affiliation is like an old style guild, done to enhance the structure
 * of the class system, by giving each one the opportunity to be involved
 * with as many or as few 'social structure'-like 'old-style' guilds as
 * a player wishes.
 *
 * Such affiliations are hoped to be the Robes of Alignment, a KRYNN-style
 * guild of mages (grey, white, and evil wizards), based on alignment.
 *
 */
#include <mudlib.h>
#include <linewrap.h>

#define PATH		"ob_saves/affils/"
#define AFF		"obj/skills/affils"
#define NAME		(string)this_player()->query_name(1)

#define ADMIN           40
#define CREATOR         20

/**************************************************************************
 * Fn Specs 
 */

mapping affiliation_info;
string file;
string skills_file; /* the file name of the ob for players */
string affiliation_name, affiliation_file, affiliation_sponsor;
int donations;

void add_member(string str);
void add_leader(string str);

void remove_member(string str);
void remove_leader(string str);

status query_member(string str);
status query_leader(string str);
void save_me();
void restore_me();




/***************************************************************************
 * The Real Stuff
 */
inherit ROOM;
void reset(status arg) {
  if(arg) return;
  restore_me();
  if(!affiliation_info || !sizeof(affiliation_info))
    affiliation_info = ([
	"donations"     : 	donations,
	"founder"	:	"angel",
        "members"       :       ({ "angel", "kane", }),
         "leaders"       :       ({"angel", "octavian",}),
	"sponsor"       :	affiliation_sponsor
  ]);

}

mapping query_affiliation_data() { return affiliation_info; }


void restore_me() {
  string tmp1, tmp2;
  if(!sscanf(file_name(this_object()), "%sd/affils/rooms/%s", tmp1, file)) {
    write("Warning: Can't scan filename.\n");
    return;
  }
  if(!file) {
    write("Warning: Affiliation can not be restored!.\n");
    return;
  }
  restore_object(PATH+file);
}

void save_me() {
  string tmp;
  if(!sscanf(file_name(this_object()), "%sd/affils/rooms/%s", tmp, file))
    return;
  if(!file) {
    write("Warning: Affiliation can not be saved!\n");
    return;
  }
  save_object(PATH+file);
}


string query_founder() {
  return affiliation_info["founder"];
}

void set_affiliation_name(string str) {
  affiliation_name = str;
  save_me();
}

void set_affiliation_sponsor(string str) {
  affiliation_sponsor = str;
  save_me();
}


void set_affiliation_file(string str) {
  affiliation_file = str;
  save_me();
}


/* save file is the file of the object for players */
void set_skills_file(string str) {
  skills_file = str;
  save_me();
}

string query_affiliation_name()         { return affiliation_name;       }
string query_skills_file()              { return skills_file;            }
string query_affiliation_file() 	{ return affiliation_file;       }
string query_affiliation_sponsor()      { return affiliation_sponsor;    }


string *query_leaders() {
  return affiliation_info["leaders"];
}

status query_leader(string name) {
  string *tmp;
  tmp = affiliation_info["leaders"];
  return (member_array(name, tmp) != -1) ? 1 : 0;
}

status query_member(string name) {
  string *tmp;
  tmp = affiliation_info["members"];
  return (member_array(name, tmp) != -1) ? 1 : 0;
}


string *query_members() { return affiliation_info["members"]; }


void set_founder(string str) {
  affiliation_info["founder"] = str;
  save_me();
}

void add_leader(string str) { 
  string *tmp1, *tmp2;
  tmp1 = affiliation_info["leaders"];
  if(!query_leader(str)) {
    tmp1 += ({ str, });
    affiliation_info["leaders"] = tmp1;
  }
  save_me();
}

void remove_leader(string str) {
  string *tmp1, *tmp2;
  int i;
  if(!str) return;
  if(!query_leader(str)) return;
  tmp1 = affiliation_info["leaders"];
  if((i = member_array(str, tmp1)) != -1) { 
    tmp2 = tmp1[0..i-1] + tmp1[i+1..sizeof(tmp1)-1];
    affiliation_info["leaders"] = tmp2;
  }
  save_me();
}

void remove_member(string str) {
  string *tmp1, *tmp2;
  int i;
  if(!str) return;
  if(!query_member(str)) return;
  tmp1 = affiliation_info["members"];
  if((i = member_array(str, tmp1)) != -1) {
    tmp2 = tmp1[0..i-1] + tmp1[i+1..sizeof(tmp1)-1];
    affiliation_info["members"] = tmp2;
  }
  save_me();
}

void add_member(string str) {
  string *tmp1, *tmp2;
  tmp1 = affiliation_info["members"];
  if(!query_member(str)) {
    tmp1 += ({ str, });
    affiliation_info["members"] = tmp1;
  }
  save_me();
}


/**************************************************************************
 * Player Actions 
 */

void init() {
  object ob1, ob2;
  ::init();
  ob1 = this_player();

  if((string)this_player()->query_affiliation(affiliation_file))
  if(!present(this_object()->query_affiliation_name(), ob1)) {
    if(!skills_file)
      ob2 = clone_object(AFF);
    else
      ob2 = clone_object(skills_file);
    move_object(ob2, ob1);
    if(!ob2) {
      write("Warning: No ob2!\n");
      return;
    }
    ob2 -> set_affiliation_name(this_object()->query_affiliation_name());
    ob2 -> set_affiliation_file(this_object()->query_affiliation_file());
    ob2 -> set_affiliation_sponsor(this_object()->query_affiliation_sponsor());

    write("Affiliation object not found. Adding new object...\n");
  }


  add_action("aff_show",   "leaders");
  add_action("aff_show",   "members");
  add_action("aff_donate", "donate");

  add_action("aff_admit", "admit");
  add_action("aff_banish", "banish");
}

status aff_donate(string str) {
  int amount, tmp;

  tmp = affiliation_info["donations"];
  if(!sscanf(str, "%d", amount)) {
    write("Donate how much to "+this_object()->query_affiliaiton_name()+"?\n");
    return 1;
  }
  if((int)this_player()->query_money() < amount) {
    write("You don't have that much to donate.\n");
    return 1;
  }

  write("You donate "+MONEY->convert(amount)+" coins.\n");
  this_player()->add_money(-amount);
  tmp += amount;
  affiliation_info["donations"] = tmp;
  save_me();
  return 1;
}


status aff_show() {
  string verb;
  string tmp;

  verb = query_verb();
  if(verb == "leaders") {
    write("The leaders of the "+this_object()->query_affiliation_name()+
	" are:\n\n");
    tmp = implode(affiliation_info["leaders"], " ");
    writelw(tmp +"\n");
    return 1;
  }
  else if(verb == "members") {
    write("The members of the "+this_object()->query_affiliation_name()+
	" are:\n\n");
    tmp = implode(affiliation_info["members"], " ");
    writelw(tmp +"\n");
    return 1;
  }
  return 0;
}

status aff_admit(string str) {
  string tmp1, tmp2;
  object ob;
  object oB;

  if(!str) {
    notify_fail("Admit <who> as <member|leader>\n");
    return 0;
  }

  str = lower_case(str);
  if(sscanf(str, "%s as leader%s", tmp1, tmp2)) {
    str = tmp1;
    if(!ob=present(str, this_object())) {
      notify_fail(capitalize(str)+" is not here.\n");
      return 0;
    }
    if(!query_leader(NAME) && !this_player()->secure(ADMIN)) {
      notify_fail("Only another leader, or a Creator of security "+ADMIN+" can admit "+
      "a leader to the affiliation.\n");
      return 0;
    }
    if(!query_member(str)) {
      notify_fail(capitalize(str)+" is not even a member yet!\n");
      return 0;
    }
    if(query_leader(str)) {
      notify_fail(capitalize(str)+" is already a leader in the bureaucracy.\n");
      return 0;
    }

    ob->add_affiliation(this_object()->query_affiliation_file());

    write("You admit "+capitalize(str)+" into the bureaucracy.\n");
    tell_object(ob, "You are now a part of the bureaucracy.\n");

    if(!ob->query_channel(file))
      ob->toggle_channel(file);
    CHANNEL_D -> chat_channel(file, 
	(string)ob->query_name()+" is now a leader of "+
	"the "+this_object()->query_affiliation_name()+"\n");

    add_member(ob->query_name(1));
    add_leader(ob->query_name(1));
    return 1;
  }

  if(sscanf(str, "%s as member%s", tmp1, tmp2)) {
    str = lower_case(tmp1);
    if(!ob=present(str, this_object())) {
      notify_fail(capitalize(str)+" is not here.\n");
      return 0;
    }
    if(!query_leader(NAME) && !this_player()->secure(CREATOR)) {
      notify_fail("Only another leader, or Creator, can admit new members.\n");
      return 0;
    }
    if(query_member(str)) {
      notify_fail(capitalize(str)+" is already a member!\n");
      return 0;
    }
    
    write("You admit "+ob->query_name()+" into the "+
	(string)this_object()->query_affiliation_name()+".\n");
    tell_object(ob, NAME+" inducts you into the "+
	(string)this_object()->query_affiliation_name()+".\n");

    ob->add_affiliation(this_object()->query_affiliation_file());
    add_member(ob->query_name(1));

    ob->add_affiliation(this_object()->query_affiliation_file());

    ob -> toggle_channel(file);
    CHANNEL_D -> chat_channel(file,
        (string)ob->query_name()+" is now a member of "+
        "the "+this_object()->query_affiliation_name()+"\n");

    if(!skills_file)
      oB = clone_object(AFF);
    else
      oB = clone_object(skills_file);
    move_object(oB, ob);
    oB->set_affiliation_file(this_object()->query_affiliation_file());
    oB->set_affiliation_name(this_object()->query_affiliation_name());
    oB->set_affiliation_sponsor(this_object()->query_affiliation_sponsor());

    oB->add_affiliation(this_object()->query_affiliation_file());

    if(function_exists("admit_fn", this_object()))
      this_object()->admit_fn(ob);

    return 1;
  }
}

status aff_banish(string str) {
  object ob;
  object oB;

  if(!str) {
    notify_fail("Banish <who>?\n");
    return 0;
  }

  str = lower_case(str);

  if(!ob=find_player(str)) {
    notify_fail("You can only banish a player who is logged in.\n");
    return 0;
  }

  if(!query_leader(NAME) && !this_player()->secure(ADMIN)) {
    notify_fail("Only another leader, or a Creator of security "+ADMIN+" can banish "+
    "a member\n");
    return 0;
  }

  if(!query_member(str)) {
    notify_fail(capitalize(str)+" is not even a member!\n");
    return 0;
  }


  if(query_leader(str)) {
    if((int)this_player()->query_level() < (int)ob->query_level()) {
      notify_fail("You can only banish a member of lower level than yourself.\n");
      return 0;
    }
  }


  write("You banish "+capitalize(str)+" from "+
	this_object()->query_affiliation_name()+" affiliation.\n");

  tell_object(ob, "You have been banished from the "+ 
	this_object()->query_affiliation_name()+"\n");


  CHANNEL_D -> chat_channel(file, 
      (string)ob->query_name()+" has been banished from "+
      "the "+this_object()->query_affiliation_name()+"\n");

  remove_member(ob->query_name(1));

  if(query_leader(str)) 
    remove_leader(ob->query_name(1));

  ob -> remove_affiliation(this_object()->query_affiliation_file());

  if(oB = present(this_object()->query_affiliation_name(), ob))
    destruct(oB);

  return 1;
}

