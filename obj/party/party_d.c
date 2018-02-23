/* PARTY DAEMON v1.0 (c)Angel, March 1993.
 * This is the master file for the party system, which keeps
 * track of all the parties on the mud, their cumulative exp,
 * age, members, as well as the parties name and leader, the
 * latter of which is usually the first member of the members
 * array. The system also allows for a list of Highest and Best
 * parties, dependant upon exp gained per unit of time. This way
 * a little competition is encouraged between players. This list
 * is obtained by calling a function in this object which returns
 * a string which is the list. The party_list object calls this
 * function to display the list.
 *
 * v2.1 Sarak, March 1997
 *

 */
#include <mudlib.h>
#include <ansi.h>


#define PARTY_OB	"/obj/party/party_ob"
#define PARTY_FILE 	"/obj/party/party_d"
#define PARTY_SAVE	"ob_saves/party/party_save"
#define PARTY_BEST 	"/open/party/party_best"

#define SAVE        /* saves parties when quit */

mapping party_data;



string *query_all_members(string str);

void reset(status arg) {
  if(arg) return;

#ifdef SAVE
  restore_object(PARTY_SAVE);
#endif /* SAVE */

  if(!party_data || !sizeof(party_data)) {
    party_data = ([
      /* Order is as follows...                                        
       * party name : ([  party members : ({ memebers, }),
       *		  total  exp    : amount
       *		  total  exp    : amount
       *		  born: 
       *		  rate: 
       *		  founder : name,
       */
    ]);
  }
}

/**********************************************************
 * FN SPECS 
 */
string get_best_party();

/**********************************************************
 * FUNCTIONS 
 */
status query_party(string str) {
  if(!str) return 0;
  if(party_data[str]) return 1;
  return 0;
}


status add_party(mapping mapp, string str) {
  int i;
  mixed *arr;

  if(!sizeof(mapp)) return 0;
  if(!str) return 0;

  arr = m_indices(mapp);

  if(!query_party(str)) {
    party_data += mapp;
  }
#ifdef SAVE
  save_object(PARTY_SAVE);
#endif /* SAVE */
  return 1;
}



status remove_party(string str) {
  if(!query_party(str)) return 0;
  party_data = m_delete(party_data, str);
#ifdef SAVE
  save_object(PARTY_SAVE);
#endif /* SAVE */
  return 1;
}


mapping query_party_data() { return party_data; }

string *query_members(string str) {
  return query_all_members(str);
}


string *query_all_members(string party) {
  string *tmp;
  mapping mapp;

  if(mapp = party_data[party]) {
    tmp = mapp["members"];    
    return tmp;
  }
}


string query_leader(string party) {
  string tmp;
  mapping mapp;

  if(mapp = party_data[party]) {
    if(!tmp = mapp["leader"]) {
      tell_object(this_player(), "Your party has no leader!\n");
      remove_party(party);
    }
    else {
      return tmp;
    }
  }
}      
      


string query_founder(string party) {
  string tmp;
  mapping mapp;

  if(mapp = party_data[party]) {
    if(tmp = mapp["founder"]) {
      return tmp;
    }
    else {
      tell_object(this_player(), "Your party has no founder!\n");
      remove_party(party);
    }
  }
}


int query_age(string party) {
  int tmp;
  mapping mapp;
  if(mapp = party_data[party]) {
    if(tmp = mapp["age"]) 
      return tmp;
  }
}


int query_rate(string party) {
  int tmp;
  mapping mapp;
  if(mapp = party_data[party]) {
    if(tmp = mapp["rate"])
      return tmp;
  }
}


int query_total_exp(string party) {
  int tmp;
  mapping mapp;

  if(mapp = party_data[party]) {
    if(tmp = mapp["total exp"]) 
      return tmp;
  }
}


mixed *best_party() {
  mixed *party;
  mixed *party_names, party_info;
  string *temp;
  string tmp;
  mapping mapp;
  int i, rate;

  party = ({});

  party_names = m_indices(party_data);
  party_info  = m_values(party_data);


  for(i=0; i<sizeof(party_names); i++) {
    mapp = party_info[i];
    rate = mapp["rate"];
    party += ({
      ({ party_names[i], query_rate(party_names[i]), }),
    });
  }

  party = sort_array(party, "by_rate", this_object());

#ifdef SAVE
  save_object(PARTY_SAVE);
#endif /* SAVE */
  return party;
}

status by_rate(mixed *a, mixed *b) {
  return (a[1] < b[1]) ? 1 : 0;
}


string get_best_party() {
  mixed *party;
  string txt, tmp;
  string *temp_party;
  int i;

  party = best_party();

   txt = RED_B+BOLD+YELLOW_F+
        "_______________________________________________________________\n"+
        ">                 Best Parties on "+BLINK+MUD_NAME+OFF+
        RED_B+BOLD+YELLOW_F+"                     <\n"+
        "---------------------------------------------------------------\n"+
        OFF+BOLD+RED_B+YELLOW_F+
    " | Party Name              Members                    Rating | \n";

  for(i=0; i<sizeof(party); i++) {
    if(party[i][1] && sizeof(query_all_members(party[i][0]))) {
      tmp = " | "+party[i][0]+"                            ";
      tmp = extract(tmp,0,20);
      temp_party = query_all_members(party[i][0]);
      if(sizeof(temp_party))
        tmp = tmp +" "+capitalize(implode(temp_party, " "));
      tmp += "                                             ";
      tmp = extract(tmp,0,55);
      tmp += party[i][1]+"                                 ";
      tmp = extract(tmp,0,60);
      txt = txt + tmp +"| \n";
    }
  }


  txt += BOLD+YELLOW_F;
  txt += "_______________________________________________________________\n"+
         ">                                                             <\n"+
         "---------------------------------------------------------------\n";
  txt += OFF;

  return txt;

/*
  if(this_player()->valid_write(PARTY_BEST)) {
    rm(PARTY_BEST);
    write_file(PARTY_BEST, txt);
  }
*/
}



status get_party_object(string party, object player) {
  int i;
  object party_ob;

  if(!player) player = this_player();

  if(!party) return 0;

  if(member_array((string)player->query_name(1),
                  query_all_members(party)) == -1) return 0;

  if(present("party_object", player)) {
    party_ob = present("party_object", player);
    destruct(party_ob);
  }

  party_ob = clone_object(PARTY_OB);
  party_ob -> set_age(query_age(party));
  party_ob -> set_total_exp(query_total_exp(party));
  party_ob -> set_party(party);
  party_ob -> set_members(query_all_members(party));
  party_ob -> set_leader(query_leader(party));
  party_ob -> set_rate(query_rate(party));
  party_ob -> add_members((string)this_player()->query_name(1));
  move_object(party_ob, player);

  tell_object(player, "\nRestoring '"+party+"' party object...\n\n");
  return 1;
}
