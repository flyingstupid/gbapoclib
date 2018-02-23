#include <mudlib.h>
#include <ansi.h>
#include <linewrap.h>
#include <msg_str.h>

status tell(string str) {
  string player, msg;
  string sMessage;
  string tp_ansi, ob_ansi;
  string sSoul, sParams, *spSoulStrings;
  object ob;
  string ansi_tp, ansi_ob, tail;

#ifdef RPG
  if(!(status)this_player()->query_security_level() &&
     !(status)environment(this_player())->query_ooc_room()) {
    notify_fail("Error: Command 'tell' can only be used 'Out of Character'\n");
    return 0;
  }

#endif /* RPG */

  if(!str || sscanf(str, "%s %s", player, msg) != 2) {
    notify_fail("Usage: tell <player> <message>\n");
    return 0;
  }

  player = lower_case(player);
  if(!ob = find_player(player)) {
    notify_fail("There is no one here by that name.\n");
    return 0;
  }

  if(ob->query_invis()) {
    if(this_player()->query_security_level() < ob->query_security_level()) {
      notify_fail("There is no one here by that name.\n");
      return 0;
    }
  }

#ifdef RPG
  if(!(status)this_player()->query_security_level()) {
    if(!ob->query_security_level() && !environment(ob)->query_ooc_room()) {
      notify_fail("Error: "+capitalize(player)+" is currently in play.\n");
      return 0;
    }
  }
#endif /* RPG */

  if((status)ob->query_edit()) {
    notify_fail("Error: "+capitalize(player)+" is in edit mode. "+
    "Please use Intermud Mail if important.\n");
    return 0;
  }

  if(!ob->query_channel("ooc")) {
    notify_fail("Error: "+capitalize(player)+" is not listening to the "+
     "\ncommon channel '[OOC]' and can not be reached.\n");
    return 0;
  }

  if(ob == this_player()) {
    notify_fail("You know what they say about talking to yourself don't you?\n");
    return 0;
  }

  tp_ansi = this_player()->query_color_attribute("tell");
  ob_ansi = ob->query_color_attribute("tell");
  msg = this_player()->filter_ansi(msg);
  if(sscanf(msg, ":%s", msg) == 1) {
    msg = this_player()->query_name()+" "+msg;
    ansi_tp = tp_ansi+"<"+capitalize(player)+">"+OFF+" ";
    ansi_ob = ob_ansi+"[*]"+OFF+" ";
    tail = msg;
  }
  else if(sscanf(msg, ";%s", sSoul) == 1) {
    sParams = "";

    sscanf(sSoul, "%s %s", sSoul, sParams);

    sParams = player+" "+sParams;
    spSoulStrings = SOUL_D -> do_soul(sSoul, sParams, 2);

    if(!spSoulStrings) return 0;
    if(spSoulStrings[1] && strlen(spSoulStrings[1]))
      sMessage = spSoulStrings[1];
    else if(spSoulStrings[2] && strlen(spSoulStrings[2]))
        sMessage = spSoulStrings[2];
    else
      return 0;
    ansi_tp = tp_ansi+"<"+capitalize(player)+">"+OFF+" ";
    ansi_ob = ob_ansi+"[*]"+OFF+" ";
    tail = sMessage;
  } else {
    ansi_tp = tp_ansi+"You tell "+capitalize(player)+","+OFF+" ";
    ansi_ob = ob_ansi+this_player()->query_name()+" tells you,"+OFF+" ";
    tail = "\""+msg+"\"";
  }
  if(!this_player()->ansi_on())
    ansi_tp = this_player()->filter_ansi(ansi_tp);
  if(!ob->ansi_on())
    ansi_ob = ob->filter_ansi(ansi_ob);
  msg = msg_str(tail, 75, strlen(this_player()->filter_ansi(ansi_tp))+1);
  write(ansi_tp+msg+"\n");
  msg = msg_str(tail, 75, strlen(ob->filter_ansi(ansi_ob))+1);
  tell_object(ob, ansi_ob+msg+"\n");
  return 1;
}

