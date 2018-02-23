/***********************************************************
 * THE CHANNEL DAEMON
 * v1.0 Angel Aug '96
 * ..pretty simple, hu?!
 * Other work is done inside player.c ..but its not much 
 */

#include <ansi.h>
#include <linewrap.h>


#define CHANNEL_HISTORY "/open/channels/"
status chat_channel(string channel,
                    string message,
                    status silently,
                    status no_echo) {
  int i;
  object *user;
  string tmp1, tmp2, msg, *tmp3, *tmp4;


  user = users();
  if(!channel) channel = "OOC";
  if(!message || !strlen(message)) message = "mumbles";

  msg = lw(BLACK_B+BOLD+WHITE_F+"["+capitalize(channel)+"]"
    +OFF+" "+message+"\n");
  tmp3 = explode(msg, "\n");
  msg = "";
  for(i = 1 ; i < sizeof(tmp3) ; i++)
    if(strlen(tmp3[i]) > 0) msg += tmp3[i]+" "; 
  msg = lw(msg);
  tmp3 = ({ tmp3[0], });
  if(strlen(msg)) tmp3 += explode(msg, "\n");
  msg = implode(tmp3, "\n")+"\n";
  for(i=0; i<sizeof(user); i++) {
    if(no_echo && user[i] == this_player()) continue;
    if(!environment(user[i])) continue;
    if(user[i]->query_channel(channel))
      if(!user[i]->query_edit())
        if(!silently) {
          if(user[i]->ansi_on())
            tell_object(user[i], msg); 
          else
            tell_object(user[i], user[i]->filter_ansi(msg));
        }
        else
          tell_object(user[i], lw(message+"\n"));
  }
#ifdef CHANNEL_HISTORY
  if((string)previous_object()->query_object_type() == "Party") return 1;
  if(!sscanf(channel, "%s %s", tmp1, tmp2))
    write_file(CHANNEL_HISTORY+channel+".txt", 
  	"["+channel+"] "+message+"\n");
  if(file_size(CHANNEL_HISTORY+channel+".txt") > 1000) rm(CHANNEL_HISTORY+channel+".txt");
#endif /* CHANNEL_HISTORY */
  return 1;
}


varargs valid_channel(string str) {
  string *channels;
  int i;

  if(str == "common") return 0;
  if(str == "ooc") str = "OOC";
  /* players channels */
  channels = ({
    "OOC", 
  });

  /* wizardly levels */
  if((int)this_player()->query_security_level())
    channels += ({ "wiz", "lpc", });

  channels += (string *)this_player()->query_classes();
  channels += (string *)this_player()->query_languages_known();
  channels += (string *)this_player()->query_affiliations();

  i = member_array("common", channels);
  channels = channels[0..i-1] + channels[i+1..sizeof(channels)-1];

/*
  channels += (string *)this_player()->query_channels();
*/
  if(!str) return channels;
  if((int)this_player()->query_security_level()) return 1;


  return (member_array(str, channels) != -1) ? 1 : 0;
}
