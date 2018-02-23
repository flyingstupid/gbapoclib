#include <mudlib.h>
#include <levels.h>
#include <ansi.h>

status people(string arg) {
  string total, name, level, age, IP, loc;
  string domain_str, temp, HEAD, BORDER;
  int idle, a, i;
  object *who, pager;

  HEAD = this_player()->query_color_attribute("headings");
  BORDER = this_player()->query_color_attribute("borders");

  if(!this_player()->query_security_level()) return 1;
  total = BORDER+"----------------------------------------------------------------"+
    "------------\n";

  total += "-- "+OFF+HEAD+"Name            Level  Age  Idle  IP Address       "+
    "Location            "+OFF+BORDER+"--\n";
  total += "----------------------------------------------------------------"+
    "------------"+OFF+"\n";


  who = filter(users(),"filter_users",this_player());  

  if(arg == "1")
    who = sort_array(who, "by_name", this_player());
  else if(arg == "2")
    who = sort_array(who, "by_level", this_player());
  else if(arg == "3")
    who = sort_array(who, "by_age", this_player());
  else if(arg == "4")
    who = sort_array(who, "by_environment", this_player());
  else if(arg == "5")
    who = sort_array(who, "by_ip_number", this_player());
  else 
    who = sort_array(who, "by_sec_level", this_player());

  for(i = 0; i < sizeof(who); i++) {
    name = capitalize((string)who[i]->query_real_name());
    name += (who[i]->query_invis())
      ? " I"
      : "";
    name += (who[i]->query_edit())
      ? " E"
      : "";
    name += (who[i]->query_busy())
      ? " B"
      : "";
    name += (who[i]->query_disguise_on())
      ? " D"
      : "";

    switch((int)who[i]->query_security_level()/10) {
      case 1:
        level = ASP_COL+"Aspiran";
        break;
      case 2:
        level = APPRENTICE_COL+"Apprent";
        break;
      case 3:
        level = CREATOR_COL+"Creator";
        break;
      case 4:
        level = SENIOR_COL+"Senior";
        break;
      case 5:
        level = ELDER_COL+"Elder";
        break;
      case 6:
        level = LORD_COL+"Lord";
        break;
      case 7:
        level = QC_COL+"QC";
        break;
      case 8:
        level = ARCH_COL+"Arch";
        break;
      case 9:
        level = ADMIN_COL+"Admin";
        break;
      case 10:
        level = ADMIN_COL+"Founder";
        break;
      default:
        level = PLAYER_COL+sprintf("%d", who[i]->query_level());
        break;
    }
    temp = this_player()->filter_ansi(level);
    a = 7 - strlen(temp);
    for(idle = 0; idle < a; idle++)
      level = " "+level;
    level += OFF;
    a = (int)who[i]->query_age();
    if(a/302400) {
      age = (a/302400) + " W";
    }
    else if(a/43200) {  
      age = (a/43200) +" D";
    }  
    else if(a/1800) {  
      age = (a/1800) +" h"; 
    }  
    else if(a/30) {  
      age = (a/30) +" m";
    }  
    else 
      age = (a*2) + " s";

    idle = query_idle(who[i])/60;
    IP = query_ip_number(who[i]);
    if(environment(who[i])->identify())
      loc = (string)environment(who[i])->identify();
    else
      loc = file_name(environment(who[i]));  

    if(sscanf(loc, extract(WIZARD_DIR +"%s",1), temp))
      loc = "~" + temp;  
    else if (sscanf(loc, extract(DOMAIN_DIR+"%s/w/%s",1),domain_str,temp))
      loc = domain_str +","+ temp;
    temp = sprintf("%-15s  %s  %4s  %3d  %-15s  %-s", name, level, 
      age, idle, IP, loc);
    temp = ansi_extract(temp, 0, 75);
    total += temp+"\n";
  }  

  total += BORDER+"---------------------------------------------"+
    "-------------------------------"+OFF+"\n";
  if(!ANSI_ON) total = this_player()->filter_ansi(total);
  pager = clone_object(PAGER);
  move_object(pager, this_player());
  pager->page(total);
  return 1;  
} 
