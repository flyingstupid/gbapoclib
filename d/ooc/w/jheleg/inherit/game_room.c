/* 
  Gaming Room v1.1 - Jheleg of Heaven7

  This inheritable will allow a gaming room to be set up where
  multiple games can be accessed.  It also allows for a 
  centralized configuration interface.  This will no doubtedly
  change as I get feedback.
*/

#include <mudlib.h>
inherit ROOM;

#define GAME_LIST "d/ooc/w/jheleg/bhouse/game_list"
string *games, new_title, new_infofile, new_filename, new_author;

string *query_games_array() { return games; }

void reset(status arg)
{ 
   ::reset(arg); 
   if (!arg)
   {
      games = ({});
      restore_object(GAME_LIST);
      set_day_items(({
            "sign",
         "It is a carved wooden sign.  Perhaps you should read it?\n",
      }));
      set_night_items(({
            "sign",
         "It is a carved wooden sign.  Perhaps you should read it?\n",
      }));
   }
}

void init()
{
   ::init();
   add_action(     "read_fun", "read");
   add_action("listgames_fun", "list");
   add_action(     "info_fun", "info");
   add_action(     "play_fun", "play");
   add_action("challenge_fun", "challenge");

   if(this_player()->query_security_level())
   {
      add_action(   "add_game_fun", "add");
      add_action("remove_game_fun", "remove");
   }
}

status read_fun(string str)
{
   if(!str || str != "sign") return 0;
   if(this_player()->query_security_level())
   {
      write(
"8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8\n"+
"8+8                                                                   8+8\n"+
"8+8                     Gaming Room Commands                          8+8\n"+
"8+8                 ============================                      8+8\n"+
"8+8                                                                   8+8\n"+
"8+8  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  8+8\n"+
"8+8         Commands                         Description              8+8\n"+
"8+8  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  8+8\n"+
"8+8   list games ................... Lists playable games.            8+8\n"+
"8+8   info <game> .................. Gives information on a game.     8+8\n"+
"8+8   play <game> .................. Play <game>.                     8+8\n"+ 
"8+8   challenge <player> to <game> . Issues a challenge to an active  8+8\n"+
"8+8                                  player to play <game>.           8+8\n"+
"8+8   add game ..................... Starts the game addition process 8+8\n"+
"8+8                                  by which games are added to the  8+8\n"+
"8+8                                  room.                            8+8\n"+
"8+8   remove game <game> ........... Remove <game> from the list of   8+8\n"+
"8+8                                  playable games.                  8+8\n"+
"8+8                                                                   8+8\n"+
"8+8           -=- Mudmail Jheleg for suggestions, etc. -=-            8+8\n"+
"8+8                                                                   8+8\n"+
"8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8\n"
      );
   }
   else
   {
      write(
"8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8\n"+
"8+8                                                                   8+8\n"+
"8+8                     Gaming Room Commands                          8+8\n"+
"8+8                 ============================                      8+8\n"+
"8+8                                                                   8+8\n"+
"8+8  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  8+8\n"+
"8+8         Commands                         Description              8+8\n"+
"8+8  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  8+8\n"+
"8+8   list games ................... Lists playable games.            8+8\n"+
"8+8   info <game> .................. Gives information on a game.     8+8\n"+
"8+8   play <game> .................. Play <game>.                     8+8\n"+
"8+8   challenge <player> to <game> . Issues a challenge to an active  8+8\n"+
"8+8                                  player to play <game>.           8+8\n"+
"8+8                                                                   8+8\n"+
"8+8           -=- Mudmail Jheleg for suggestions, etc. -=-            8+8\n"+
"8+8                                                                   8+8\n"+
"8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8+8\n"
      );
   }
   say(capitalize(this_player()->query_name())+
      " reads the sign.\n", this_player());
   return 1;
}

status listgames_fun(string str)
{
   int index;

   if(!str || str != "games")
   {
      write("Syntax is 'list games'.\n");
      return 1;
   }
   if(sizeof(games) == 0)
   {
      write("There are no games currently available for play.\n");
      return 1;
   }
   write(
      "The following games are available for play:\n" +
      "*******************************************\n"
   );
   for(index = 0;index < sizeof(games);index += 4) {
      write(capitalize(games[index])+
         " ("+capitalize(games[index+3])+")\n"
      );
   }
   write("\n");
   return 1;
}

status info_fun(string str)
{
   int index;
   object ob;

   if(!str)
   {
      write("Syntax is 'info <game>'.\n");
      return 1;
   }
   index = member_array(lower_case(str), games);
   if(index < 0)
   {
      write(capitalize(str)+" does not exist in the game list.\n");
      return 1;
   }   
   write(
      "********************************************************************\n"+
      "Information on "+capitalize(str)+"\n"+
      "********************************************************************\n"
   );
   ob = clone_object("obj/more");
   move_object(ob, this_player());
   ob -> more(games[index + 1]);
   return 1;
}

status play_fun(string str)
{
   int index;

   if(!str)
   {
      write(
         "Syntax is 'play <game>' where game is a game title from\n"+
         "the game list.\n"
      );
      return 1;
   }
   if(index = member_array(lower_case(str), games) == -1)
   {
      write(
         "You can not play a game that is currently not playable.  Type\n"+
         "'list games' for a list of playable games.\n"
     );
     return 1;
   }
   write("\nYou choose to play "+capitalize(str)+".  You are moved to the\n"+
      "appropriate room.\n\n"
   );
   say(this_player()->query_name()+" is transported off to play a game "+
      "of "+capitalize(str)+".\n", this_player());
   move_object(this_player(), games[index+2]);
   command("look", this_player());
   return 1;
}

status challenge_fun(string str)
{
   string playerstr, gamestr;
   object playerobj, ticket;
   int index;

   if(!str)
   {
      write("Syntax is 'challenge <player> to <game>'.\n");
      return 1;
   }
   if(!sscanf(str, "%s to %s", playerstr, gamestr))
   {
      write("Syntax is 'challenge <player> to <game>'.\n");
      return 1;
   } 
   playerobj = find_player(lower_case(playerstr));
   if(!playerobj)
   {
      write(capitalize(playerstr)+" is currently not logged in.\n");
      return 1;
   }
   if(playerobj == this_player())
   {
      write("It would be futile, at best, to challenge yourself.\n");
      return 1;
   }
   if(index = member_array(lower_case(gamestr), games) == -1)
   {
      write(
         "You can not issue a challenge to a game that is currently\n"+
         "not playable.  Type 'list games' for a list of playable\n"+
         "games.\n"
      );
      return 1;
   }  
   tell_object(playerobj,
      capitalize(this_player()->query_name())+" challenges you to a game of "+
      capitalize(gamestr)+"!\n"+
      "You have 1 minute to 'accept' or 'decline'.\n"
   );
   write(
      "You have challenged "+capitalize(playerstr)+" to a game of "+
      capitalize(gamestr)+"!\n"+
      capitalize(playerstr)+" will have 1 minute to respond.\n"
   );
   ticket = clone_object("/d/ooc/w/jheleg/bhouse/ticket");
   ticket -> set_challenger(this_player());
   ticket -> start_timer();
   ticket -> set_game_room(games[index + 2]);
   move_object(ticket, playerobj);
   return 1;
}

status add_game_fun(string str)
{
   if(!str || str!="game")
   {
      write("You might want to try 'add game'.\n");
      return 1;
   }
   write(
      "Please enter the title of the game that you wish to add.  If you\n"+
      "wish to abort the add, enter '~q'.\n"+
      "--> "
   );
   input_to("get_title");
   return 1;
}

status get_title(string str)
{
   object editor;

   if(!str || str == "" || str == "~q")
   {
      write("\nGame addition aborted.\n");
      return 1;
   }
   write(
      "\nThe game title has been set to "+
      capitalize(new_title = lower_case(str))+".\n"
   );
   write(
      "\nPlease enter the COMPLETE filename to the game object that you wish\n"+
      "to add.  An legitimate entry would look like:\n\n"+
      "                    /players/jheleg/mygame.c\n\n"+
      "If you wish to abort the add, enter '~q'.\n"+
      "--> "
   );
   input_to("get_filename");
   return 1;
}

status get_filename(string str)
{
   if(!str || str == "" || str == "~q")
   {
      write("\nGame addition aborted.\n");
      return 1;
   }
   if(file_size(str) <=0)
   {
      write("\nThat is not a valid filename.  Please try again.\n");
      write(
         "\nPlease enter the COMPLETE filename to the game object that you wish\n"+
         "to add.  An legitimate entry would look like:\n\n"+
         "                    /players/jheleg/mygame.c\n\n"+
         "If you wish to abort the add, enter '~q'.\n"+
         "--> "
      );
      input_to("get_filename");
      return 1;
   }
   write("\nThe game's filename has been set to "+(new_filename = str)+".\n");
   write(
      "\nPlease enter the COMPLETE filename to the information/help file.\n"+
      "This is the text file that will be displayed to the player when\n"+
      "They type 'info <game>'.  An legitimate entry would look like:\n\n"+
      "                    /players/jheleg/myinfo.txt\n\n"+
      "If you wish to abort the add, enter '~q'.\n"+
      "--> "
   );
   input_to("get_info");
   return 1;
}

status get_info(string str)
{
   if(!str || str == "" || str == "~q")
   {
      write("\nGame addition aborted.\n");
      return 1;
   }
   if(file_size(str) <=0)
   {
      write("That is not a valid filename.  Please try again.\n");
      write(
         "\nPlease enter the COMPLETE filename to the information/help file.\n"+
         "This is the text file that will be displayed to the player when\n"+
         "They type 'info <game>'.  An legitimate entry would look like:\n\n"+
         "                    /players/jheleg/myinfo.txt\n\n"+
         "If you wish to abort the add, enter '~q'.\n"+
         "--> "
      );
      input_to("get_info");
      return 1;
   }
   write("\nThe game's info file has been set to "+(new_infofile = str)+".\n");
   new_author = this_player()->query_real_name();

   games += ({new_title, new_infofile, new_filename, new_author});
   write("\nNew game information has been added to the list.\n");
   save_object(GAME_LIST);
   return 1;
}

status remove_game_fun(string str)
{
   string str1, del1, del2, del3;
   int index;

   if(!str)
   {
      write("Syntax for removing a game is 'remove game <game>'.\n");
      return 1;
   }
   if(!sscanf(str, "game %s", str1))
   {
      write("Syntax for removing a game is 'remove game <game>'.\n");
      return 1;
   }
   str1 = lower_case(str1);
   index = member_array(str1, games);
   if(index < 0) {
      write(capitalize(str1)+" is not on the list of games.\n");
      return 1;
   }
   write(capitalize(str1)+" has been removed from the list of games.\n");
   del1 = games[index + 1];
   del2 = games[index + 2];
   del3 = games[index + 3]; 
   games -= ({ str1, del1, del2, del3 });
   save_object(GAME_LIST);
   return 1;
}

