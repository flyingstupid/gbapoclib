#include <mudlib.h>
#include <linewrap.h>
 
#define TP this_player()
 
status score(string who) {
  string tmp;
  string money_str;
  string *weap;
  int *skills, ii;
  object ob;
  string title, *affiliations, guild_string, *languages_known;
  int money, savings, stuffed, intoxicated, soaked, whimpy, level_drained;
  mapping weapon_prof;
 
  if(who) {
    if(TP->query_security_level() < 10) {
      notify_fail("Only creators can access other player's score!\n");
    }
    ob = find_player(who);
    if(!ob) {
      notify_fail("Cannot find player: "+who+".\n");
      return 0;
    }
  } 
  else {
    ob = TP;
  }
 
 
  title           = ob->query_title();
  affiliations    = ob->query_affiliations();
  guild_string    = ob->query_guild_string();
  money           = ob->query_money();
  savings         = ob->query_savings();
  stuffed         = ob->query_stuffed();
  intoxicated     = ob->query_intoxication();
  soaked          = ob->query_soaked();
  whimpy          = ob->query_wimpy();
  level_drained   = ob->query_level_drained();
  languages_known = ob->query_languages_known();
  weapon_prof     = ob->query_weapon_prof();
 
  if(who) who = capitalize(who);
 
  if(!ob->query_special_title()) ob->set_special_title("");
 
  if(ob->query_ghost()) {
    notify_fail(((ob == TP) ? "You are" : who+" is")+
	" in an immaterial state with no scores.\n");
    return 0;
  }
 
  if(!TP->query_security_level()) {
    write("\n"+((ob == TP) ? "You are" : who+" is")+": "+
      ob->short(0)+".  Alignment: "+ob->query_al_title()+".\n");
  } 
  else {
    write("\n"+((ob == TP) ? "You are" : who+" is")+": "+
      ob->short(0)+"\n");
  }
 
 tmp = ((ob == TP) ? "You have" : who+" has")+
      " skills in general, "+implode(ob->query_classes(), ", ") +".\n";
  writelw(tmp);

  if(guild_string && lower_case(guild_string) != "no")
    write(((ob == TP) ? "You belong" : who+" belongs")+
    " to "+capitalize(guild_string) +"\n");
 
  tmp = "Exp to spend: "+ ob->query_exp() 
	  +"                         ";
  tmp = extract(tmp,0,35);
  tmp += "Total experience points: "+ ob->query_total_exp() 
	   +"                        ";
  tmp =  extract(tmp,0,70);
  write(tmp+"\n");
 
  tmp = "Player Level: "+ ob->query_level() 
	  +"                         ";
  tmp = extract(tmp,0,35);
  tmp += "Hit Points: "+ ob->query_hp() +"("+ ob->query_max_hp() +")"+
         "                         ";
  tmp = extract(tmp,0,70);
  write(tmp+"\n\n");
  
  tmp = "-------------------------------------------------------------------------";
  write(tmp+"\n\n");

  ob->query_primary_stats();
  write("\n");
 if(!whimpy)
    write(((ob == TP) ? "You are" : who+" is")+
    " feeling very brave!\n");
  else {
    write(((ob == TP) ? "You are" : who+" is")+
    " ready to run at "+ whimpy +" hit points - ");
    write(((whimpy*100)/ob->query_max_hp()) +"%\n");
  }

  tmp = "-------------------------------------------------------------------------";
  write(tmp+"\n\n");
 
    money_str = "no";
    if(money) {
      if(!(money_str = (string)call_other(MONEY, "convert", money))) {
        money_str = money +"";
      }
    }

    tmp = ((ob == TP) ? "You are" : who+" is")+" carrying "+
      money_str +" coins, and have ";
    money_str = "no";
    if(savings) {
      if(!(money_str = (string)call_other(MONEY, "convert", savings))) {
        money_str = savings +"";
      }
    }
    tmp += money_str +" coins in the bank.";
 
  writelw(tmp+"\n");
 
/* This can be splitt into two sections. Otherwise things will become
   extremely confusing! */
 
  if(ob == TP) {
    tmp = (intoxicated && stuffed && soaked)
    ? "You are intoxicated, have a full stomach, "+
      "and are certainly not thirsty.\n"
    : (intoxicated && stuffed)
    ? "You are intoxicated, and have a full stomach.\n"
    : (intoxicated && soaked)
    ? "You are intoxicated, and are not thirsty.\n"
    : (intoxicated)
    ? "You are intoxicated.\n"
     : (stuffed && soaked)
    ? "You have a full stomach, and are certainly not thirsty.\n"
    : (stuffed)
    ? "You have a full stomach.\n"
    : (soaked)
    ? "You are certainly not thirsty.\n"
    : "You have not eaten, or drank anything lately.\n";
  } 
  else {
    tmp = (intoxicated && stuffed && soaked)
    ? who+" is intoxicated, has a full stomach, "+
      "and is certainly not thirsty.\n"
    : (intoxicated && stuffed)
    ? who+" is intoxicated, and has a full stomach.\n"
    : (intoxicated && soaked)
    ? who+" is intoxicated, and is not thirsty.\n"
    : (intoxicated)
    ? who+" is intoxicated.\n"
    : (stuffed && soaked)
    ? who+" has a full stomach, and is certainly not thirsty.\n"
    : (stuffed)
    ? who+" has a full stomach.\n"
    : (soaked)
    ? who+" is certainly not thirsty.\n"
    : who+" has not eaten, or drank anything lately.\n";
  }
  write(tmp);
 

  ob->show_age(0);

  tmp = "Birth: "+ob->query_birth_date();
  writelw(tmp+"\n"); 

  if(sizeof(affiliations) > 0) {
    tmp = ((ob == TP) ? "You belong" : who+" belongs")+
      " to the following player affiliations: ";
    tmp += implode(affiliations, ", ");
    writelw(tmp+"\n");
  }


  tmp = "-------------------------------------------------------------------------";
  write(tmp+"\n");
 
  if(level_drained) {
     write("\n"+((ob == TP) ? "You have" : who+" has") +
       " been level drained "+ level_drained +" times.\n");
  }
  if(!pointerp(languages_known)) languages_known = ({});
  if(sizeof(languages_known)) {
    tmp = "Languages known: ";
    tmp += implode(languages_known, ", ");
    writelw(tmp+"\n");
  }
 
  if(sizeof(weapon_prof)) {
    weap   = m_indices(weapon_prof);
    skills = m_values(weapon_prof);
    tmp = "Weapon Proficiencies: ";
    for(ii=0; ii<sizeof(skills); ii++) {
      tmp += capitalize(weap[ii])+": "+skills[ii]+", ";
    }
    tmp += "\n";
    writelw(tmp);
  }
 
  tmp = "Type 'ss' for short score.                                         ";
  tmp = extract(tmp,0,30);
  tmp += "Type 'skills <class>' for list of skills.                         ";
  tmp = extract(tmp,0,70);
  writelw(tmp+"\n");
  return 1;
}


