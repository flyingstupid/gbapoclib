#include <mudlib.h>
#include <ansi.h>
#include <levels.h>

#define TP this_player()
#define IDLE_TIME 5

string who() {
  object *who, pager;
  int i, num_wiz;
  string verb, mud;
  string pn;
  string str, new_str;
  string sh, tmp;


  str = " Welcome to the Wastelands ";
  tmp = "";
  for (i = 0 ; i < (75 - strlen(str)) / 2 ; i = i + 2)
    tmp += "-=";
  str = BLUE_F+tmp+CYAN_F+BOLD+str+OFF+BLUE_F+tmp+tmp;
  str = ansi_extract(str,0,75);
  if(!ANSI_ON) str = TP->filter_ansi(str);
  new_str = str +"\n";

  who = filter(users(),"filter_users",TP);
  who = sort_array(who, "by_sec_level", TP);

  /* who list */

  for(i = 0; i < sizeof(who); i++) {
#ifdef SHOW_LEVEL
    if(!who[i]->query_security_level())
    str = "[ "+ (string)who[i]->query_level() +" ]";
#else
    if(!who[i]->query_security_level())
      str = "[PLAYER]";
#endif /* SHOW_LEVEL */
#ifdef QC
    else if(member_array((string)who[i] -> query_name(1),QC) != -1)
      str = "[ QC ]";
#endif /* QC */
    else if((int)who[i] -> query_security_level() >= SEC10)
      str = "[FOUNDER]";
    else if((int)who[i] -> query_security_level() >= SEC9)
      str = "[ADMIN]";
    else if((int)who[i] -> query_security_level() >= SEC8)
      str = "[ARCH]";
    else if((int)who[i] -> query_security_level() >= SEC7)
      str = "[QC]";
    else if((int)who[i] -> query_security_level() >= SEC6)
      str = "[LORD]";
    else if((int)who[i] -> query_security_level() >= SEC5)
      str = "[ELDER]";
    else if((int)who[i] -> query_security_level() >= SEC4)
      str = "[SENIOR]";
    else if((int)who[i] -> query_security_level() >= SEC3)
      str = "[CREATOR]";
    else if((int)who[i] -> query_security_level() >= SEC2)
      str = "[APPREN]";
    else
      str = "[ASPIR]";
    str += ".................";
    str = ansi_extract(str,0,10);
    if(who[i]->query_invis()) {
      str = "#"+ str;
    }

    tmp = "";
    if(who[i]->query_security_level()) {
      if(who[i]->short()) tmp += (string)who[i]->short();
      else
       tmp += (string)who[i]->query_name();
    }
    else {
      tmp += " "+(string)who[i]->query_name() +" ";
      if(!who[i]->query_disguise_on())
        tmp += (string)who[i]->query_lastname()+" ";
      if(who[i]->query_security_level())
        tmp += who[i]->query_al_title()+" ";
      else
        tmp += " ";
    }
    sscanf(tmp, " %s", tmp);
    str += " "+tmp;

/* don't show party info
#ifdef PARTY_DAEMON
    if(present("party_object", who[i])) {
      if((string)present("party_object",who[i])->query_leader()
        == (string)who[i]->query_name(1))
        str += " (Leader: ";
      else
        str += " (Member: ";
      str += ((string)who[i]->query_party())+")";
    }
#endif * PARTY_DAEMON *
*/

    if(query_idle(who[i]) > 60 * IDLE_TIME) {
      str += "                                                         ";
      str = ansi_extract(str,0,65);
      str+= OFF+RED_F+BOLD+" { Idle }"+OFF;
    } else str = ansi_extract(str,0,75);
    if(!TP->ansi_on())
      str = TP->filter_ansi(str);
    else
      str = str+OFF;
    new_str += str +"\n";
  }
   /* Bottom line */

  who = filter(who,"filter_wizards",TP);
  num_wiz = sizeof(who);
  if(!i) {
    str = " There are no players ";
  }
  if(i == 1) {
    str = " You are all alone ";
  }
  else {
    if(i - num_wiz == 1) {
      str = " There is 1 player ";
    }
    else {
      str = " There are "+ (i-num_wiz) +" players ";
    }
    if(num_wiz == 1)
      str += "and 1 Game Master ";
    else
      str += "and "+ num_wiz +" Game Masters ";
  }
  tmp = "";
  for (i = 0 ; i < (75 - strlen(str)) / 2 ; i = i + 2)
    tmp += "-=";
  str = BLUE_F+tmp+CYAN_F+BOLD+str+OFF+BLUE_F+tmp+tmp;
  str = ansi_extract(str,0,75);
  if(!ANSI_ON) str = TP->filter_ansi(str);
  new_str += str +"\n";
#ifdef PAGER
  pager = clone_object(PAGER);
  move_object(pager, TP);
  pager->page(new_str);
#else
  write(new_str);
#endif  /* PAGER */
  return new_str;
}
