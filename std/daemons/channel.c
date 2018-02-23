/**************************************************************************
 * Channel Daemon for the Heaven 7 Mudlib.                                *
 *                                                                        *
 * OBJECT DESCRIPTION                                                     *
 * ******************                                                     *
 * This handles all of the channel messaging.                             *
 *                                                                        *
 * OBJECT HISTORY                                                         *
 * **************                                                         *
 * ????.??.?? - Originially written by Angel.                             *
 * 1997.11.?? - v1.1 revised by Sarak on Castinian.                       *
 * 1998.08.10 - Incorporated from the Castinian mudlib.                   *
 *                                                                        *
 **************************************************************************/

#include <mudlib.h>
#include <ansi.h>
#include <linewrap.h>
#include <msg_str.h>
#include <ansi_filter.h>

#define SAVE_FILE "/data/ob_saves/channel_history"
#define TP this_player()

varargs status valid_channel(string str);

mapping history;

void reset(status arg) {
  if(arg) return;
  restore_object(SAVE_FILE);
}

status chat_channel(string channel,
                    string message,
                    status silently,
                    status no_echo) {
  int i;
  object *user;
  string tail, head, c_name, c_marker;
  string tmp1, tmp2, msg, *tmp3, *tmp4;

  if(!history) history = ([]);
  user = users();
  if(!channel) channel = "OOC";
  if(!message || !strlen(message)) message = "mumbles";

  if(message == TP->query_name()+": who") {
    write(" Players on the "+capitalize(channel)+" channel\n");
    write("-----------------------------------------------\n");
    for(i=0; i<sizeof(user); i++) {
      if((status)user[i]->query_channel(channel))
        if((int)user[i]->query_level() > 0)
          if(!(user[i]->query_invis() && (user[i]->query_security_level() >
            TP->query_security_level())))
              write(user[i]->short()+"\n");
    }
    write("-----------------------------------------------\n");
    return 1;
  }
  if(message == TP->query_name()+": -h") {
    write("History of "+capitalize(channel)+" channel.\n");
    for(i = 0; i < sizeof(history[channel]) ; i++)
      write(history[channel][i]);
    return 1;
  }

  for(i=0; i<sizeof(user); i++) {
    if(no_echo && user[i] == TP) continue;
    if(!environment(user[i])) continue;
    if(user[i]->query_channel(channel))
      if(!user[i]->query_edit())
        if(!silently) {
          if(user[i]->ansi_on()) {
            c_name = user[i]->query_color_attribute("channel_name");
            c_marker = user[i]->query_color_attribute("channel_marker");
            head = c_marker+"["+OFF+c_name+capitalize(channel)+OFF+
              c_marker+"]"+OFF+" ";
          } else {
            head = "["+capitalize(channel)+"] ";
          }
          tail = msg_str(message, 75, strlen(filter_ansi(head)));
          tell_object(user[i], head+tail+"\n");
        }
        else
          tell_object(user[i], lw(message+"\n"));
  }

  tmp3 = history[channel];
  if(!tmp3) tmp3 = ({ });
  if(sizeof(tmp3) >= 10)
    tmp3 = tmp3[sizeof(tmp3)-9..sizeof(tmp3)-1];
  tmp3 += ({ "["+channel+"] "+message+"\n", });
  history -= ([ channel ]);
  history += ([ channel : tmp3, ]);
  save_object(SAVE_FILE);
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
  if((int)TP->query_security_level())
    channels += ({ "wiz", "lpc", });

  channels += (string *)TP->query_classes();
  channels += (string *)TP->query_languages_known();
  channels += (string *)TP->query_affiliations();

  i = member_array("common", channels);
  channels = channels[0..i-1] + channels[i+1..sizeof(channels)-1];

/*
  channels += (string *)TP->query_channels();
*/
  if(!str) return channels;
  if((int)TP->query_security_level()) return 1;


  return (member_array(str, channels) != -1) ? 1 : 0;
}
