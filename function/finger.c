/* finger.c
 * Implemented for SoT by Mumbles
 * 931026
 */

/* updated dec 93 */
/*updated jan 94 = Spouse added */

#include <player.cfg>
#include <process.h>


string title, al_title, pretitle, name;
string    spouse, called_from_ip, email, guild_string, extra_info;
int last_login_time;
string race, realname;
int gender, age, level, security_level, guild_level;
status is_invis;
int new; /* new mail*/
string URL;

string tmp1, tmp2;

string get_finger_str(string str, status intermud) {
  object ob;
  string tmp;
  string finger;

  if(str && sscanf(str,"%s %s",str,tmp) != 2) {
    str = lower_case(str);
    ob = find_player(str);
    if(ob) ob->save_me(1);
    if(!restore_object(SAVE_WIZARD+str)) {
      if(!restore_object(SAVE_PLAYER+str)) {
        if(!restore_object(SAVE_FIRST+str)) {
          if(!restore_object(SAVE_NO_BANISH+str)) {
            return "No player with that name exists.\n";
          }
        }
      }
    }

    if(!email) email = "none";

    finger =  pretitle +((!pretitle || pretitle == "") ? "": " ");
    finger += capitalize(name) +((title) ? " "+ title : "");
    finger += ((al_title) ? " "+al_title : "") +"\n";
    finger += "Game Status: "+
            (security_level < 10 ? "Player" :
             security_level < 20 ? "Aspirant Creator" :
             security_level < 30 ? "Apprentice Creator" :
             security_level < 40 ? "Creator":
             security_level < 50 ? "Senior Creator":
             security_level < 60 ? "Elder Creator":
             security_level < 70 ? "Lord":
             (member_array(name, QC) != -1) ? "Quality Control (QC)" :
             security_level < 80 ? "Quality Control":
             security_level < 90 ? "Arch" :
             security_level < 100 ? "Administrator" : 
             "Founder") +" of level "+
            (security_level < 10 ? level: security_level) +"\n";
    finger += "Gender: "+
		(gender == 1 ? "Male" :
		 gender == 2 ? "Female" :
		 gender <  1 ? "None" :
                 "Unknown") +"\n";

    finger += "Subclass: "+ ((lower_case(guild_string) == "no" || !guild_string) 
                          ? "none" 

                          : guild_string   ) +"\n";
    finger += "Race: "+race+"\n";
    if (spouse == 0) {
    finger += "Spouse : none\n";
    }
    else {
    finger += "Spouse: "+capitalize(spouse)+"\n";
    }
    finger += "Last Login: "+ctime(last_login_time)+" ";
    if(this_player()->query_security_level())
      finger += "from "+called_from_ip+" ";
    finger += "\n\t(Current Mud-Time: "+ctime(time())+") ";
    if(ob) {
      if(intermud 
      || (security_level <= this_player()->query_security_level() && is_invis)
      || !is_invis) {
        if(environment(ob) && file_name(environment(ob))[0..5] != "secure") {
          if(interactive(ob))
            finger += " (still online)";
          else
            finger += " (linkdead)";
        }
      }
    }
    finger += "\n";
    if(realname) {
      if(!sscanf(realname, "%s!%s", tmp1, tmp2) ||
         this_player()->query_security_level()) 
        finger += "Name in Real Life: "+ realname +"\n";
    }

    
    if(!sscanf(email, "%s!%s", tmp1, tmp2) ||
      this_player()->query_security_level())
      finger += "E-mail Address: "+ email +"\n";
	if( new = "/obj/mail_rdr"->new_mail(str))
      finger += capitalize(str) +" has "+
	( new > 0 ? "received New" : "unread" ) + " mail.\n";
  if(security_level) {
    extra_info = process_msg(extra_info);
  }
  finger += "Home Page URL: ";
  if(URL)
    finger += URL;
  finger += "\n";
  finger += ((extra_info == "") ? "No Plan." : "Plan:\n"+ extra_info) +"\n";
    return finger;
  }
  return "finger <who>\n";
}


void finger(string str) {
  write(get_finger_str(str,0));
}
