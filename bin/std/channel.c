#include <mudlib.h>

#define TP this_player()

status channel(string str) {
  string *arr, tmp;
  arr = (string *)CHANNEL_D->valid_channel(0);
  tmp = implode(arr, ", ");
  if(!str) {
    write("Usage: channel <valid channel>.\n");
    write("Valid channels are: "+tmp+"\n");
    return 1;
  }
  if(str == "ooc") str = "OOC";
  if(TP->query_channel(str)) {
    write("Turning "+str+" off.\n");
    if(!TP->query_invis())
      TP->chat_channel(str, ":leaves this channel.\n");
    TP->remove_channel(str);
    return 1;
  }


  if(!(status)CHANNEL_D->valid_channel(str)) {
    write("That is not a valid channel.\n");
    write("Valid channels are: "+tmp+".\n");
    return 1;
  }

  write("You start to listen to the "+str+" channel.\n");
  TP->add_channel(str);
  if(!TP->query_invis())
    TP->chat_channel(str, ":joins the channel.\n");
  return 1;
}
