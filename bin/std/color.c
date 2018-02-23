/**************************************************************************
 * Color Command for the Heaven 7 Mudlib.                                 *
 *                                                                        *
 * OBJECT DESCRIPTION                                                     *
 * ******************                                                     *
 * This command allows the player to customise the colors that are        *
 * displayed for various aspects of the mud.                              *
 *                                                                        *
 * OBJECT HISTORY                                                         *
 * **************                                                         *
 * 1998.08.10 - Incorporated from the Castinian mudlib.                   *
 * 1998.08.12 - Added the "say" and "tell" functionality (Sarak).         *
 *                                                                        *
 **************************************************************************/


#include <mudlib.h>
#include <ansi.h>
#include <linewrap.h>
#include <list_array.h>

#define FORE ([ "black" : BLACK_F, "red" : RED_F, "green" : GREEN_F, \
                "yellow" : YELLOW_F, "blue" : BLUE_F, "magenta" : MAGENTA_F, \
                "cyan" : CYAN_F, "white" : WHITE_F, \
             ])

#define BACK ([ "black" : BLACK_B, "red" : RED_B, "green" : GREEN_B, \
                "yellow" : YELLOW_B, "blue" : BLUE_B, "magenta" : MAGENTA_B, \
                "cyan" : CYAN_B, "white" : WHITE_B, \
             ])

#define TP this_player()

#define VALID_ANSI ({ \
  "channel_marker", "channel_name", "say", "tell", \
  "headings", "borders", \
})
  //"room_exit", "room_day_desc", "room_night_desc", \
  //"emote", "social", "borders", "headings", "titles", \

status color(string arg) {
  string *arr, fore;
  int i, j;

  if(!arg) {
    write("Your attributes are currently set as follows :-\n\n");
    arr = ({ });
    for(i = 0 ; i < sizeof(VALID_ANSI) ; i++) {
      arr += ({ TP->query_color_attribute(VALID_ANSI[i]) + 
        VALID_ANSI[i] + OFF, });
    }
    fore = list_array(arr);
    if(!TP->ansi_on()) fore = filter_ansi(fore);
    write(fore);
    return 1;
  }
  arr = explode(arg, " ");
  if(member_array(arr[0], VALID_ANSI) == -1) {
    notify_fail("Usage: color <attribute> "+
      "[<foreground color>] [<background color>] [bold]\n             "+
      "[blink]\n");
    return 0;
  }
  if(sizeof(arr) > 1 && arr[1] == "OFF") {
    write("Your "+arr[0]+" attribute has been reset.\n");
    TP->set_color_attribute(arr[0], OFF);
    return 1;
  }
  fore = "";
  i = 1;
  j = sizeof(arr);
  if(i < j && FORE[arr[i]]) {
    fore = FORE[arr[i]];
    i++;
  } else {
    notify_fail("Usage: color <attribute> "+
      "[<foreground color>] [<background color>] [bold]\n             "+
      "[blink]\n");
     return 0;
  }
  if(i < j && BACK[arr[i]]) {
    fore += BACK[arr[i]];
    i++;
  }
  if(i < j && arr[i] == "bold") {
    fore += BOLD;
    i++;
  }
  if(i < j && arr[i] == "blink")
    fore += BLINK;
  write(arr[0]+" set to "+fore+"this."+OFF+"\n");
  TP->set_color_attribute(arr[0], fore);
  return 1;
}
