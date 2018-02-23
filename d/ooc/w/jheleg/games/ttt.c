/* 
   This Tic-Tac-Toe Game Room was coded by Jheleg Dec 96.
   After coding a few more game rooms, I will determine
   the feasibility ob making an inheritable out of it
   as a lot of the functions will be similar.  The only
   thing that will change is the logic behind each game.

   15 Dec 1996 - ANSI added so as to make it more playable.

*/

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;


static string player1 = "", player2 = "";
string *game_array = ({
    "1",  "2",  "3",  "4",  "5",
    "6",  "7",  "8",  "9", "10", 
   "11", "12", "13", "14", "15", 
   "16", "17", "18", "19", "20", 
   "21", "22", "23", "24", "25",
});
string *valid_choice = ({
    "1",  "2",  "3",  "4",  "5",
    "6",  "7",  "8",  "9", "10", 
   "11", "12", "13", "14", "15", 
   "16", "17", "18", "19", "20", 
   "21", "22", "23", "24", "25",
});
string *poss_values = ({
   BOLD+BLUE_F+"X"+OFF+" ", BOLD+BLUE_F+"X"+OFF, 
   BOLD+RED_F+"O"+OFF+" ", BOLD+RED_F+"O"+OFF,
});
string *isx = ({
   BOLD+BLUE_F+"X"+OFF+" ", BOLD+BLUE_F+"X"+OFF,
});
string *iso = ({
   BOLD+RED_F+"O"+OFF+" ", BOLD+RED_F+"O"+OFF,
});

int turns_completed;
int current_turn;
static int surrendered, playing;
status won;


void reset_game();
status CheckGrid(int start, int incr);
void display_board();
string *query_players() { return ({player1, player2}); }

void reset(status arg)
{
   ::reset(arg);
   if(!arg)
   {
      set_short("Tic-Tac-Toe Gaming Room.\n");
      set_long(
         "                        Tic-Tac-Toe Gaming Room.\n"+
         "             Please type 'info' for game-related commands.\n\n"
      );
      set_ooc_room(1);
      set_weather(2, 1, 0);
   }
}

void init()
{
   object target;

   ::init();
   add_action("join_fun",   "join");
   add_action("show_fun",   "show");
   add_action("place_fun",  "place");
   add_action("giveup_fun", "surrender");
   add_action("return_fun", "return");
   add_action("info_fun",   "info");
}


void reset_game()
{
   player1 = "";
   player2 = "";
   game_array = ({
       "1",  "2",  "3",  "4",  "5",
       "6",  "7",  "8",  "9", "10", 
      "11", "12", "13", "14", "15", 
      "16", "17", "18", "19", "20", 
      "21", "22", "23", "24", "25",
   });
   turns_completed = 0;
   surrendered = 0;
   playing = 0;
   won = 0;
   return;
}

status join_fun()
{
   if(player1 == "" && player2 == "") 
   {
      write("You are the Player 1!  Waiting for Player 2...\n");
      say("Acquisition of Player 1 complete.  Waiting for Player 2...\n",
         this_player());
      player1 = this_player()->query_real_name();
      return 1;
   }
   if(player1 != "" && player2 != "")
   {
      write("Game in progress... Please wait.\n");
      return 1;
   }
   if(this_player()->query_real_name() == player1)
   {
      write("You are already playing!\n");
      return 1;
   }
   write("You are player 2!  Player acquisition complete.\n");
   say("Acquisition of Player 2 complete.  Commence gaming...\n", 
      this_player());
   player2 = this_player()->query_real_name();
   current_turn = 1;
   playing = 1;
   display_board();
   return 1;
}

status show_fun()
{
   if(player2 == "")
   {
      write("No game in progress.\n");
      return 1;
   }
   write("\n\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[0]+"     %    "+(string)game_array[1]+
"     %    "+(string)game_array[2]+"     %    "+(string)game_array[3]+
"     %    "+(string)game_array[4]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[5]+"     %    "+(string)game_array[6]+
"     %    "+(string)game_array[7]+"     %    "+(string)game_array[8]+
"     %    "+(string)game_array[9]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   "+
BOLD+BLUE_F+"X"+OFF+" - "+
capitalize(player1)+"\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[10]+"    %    "+(string)game_array[11]+
"    %    "+(string)game_array[12]+"    %    "+(string)game_array[13]+
"    %    "+(string)game_array[14]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   "+
BOLD+RED_F+"O"+OFF+" - "+
capitalize(player2)+"\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[15]+"    %    "+(string)game_array[16]+
"    %    "+(string)game_array[17]+"    %    "+(string)game_array[18]+
"    %    "+(string)game_array[19]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[20]+"    %    "+(string)game_array[21]+
"    %    "+(string)game_array[22]+"    %    "+(string)game_array[23]+
"    %    "+(string)game_array[24]+"\n"+
"          %          %          %          %          \n\n"+
(((turns_completed < (sizeof(game_array)-1) && (won==0)))   
  ? ("Turn: "+  ((current_turn == 1)       
    ?  (capitalize(player1)+"\n") 
    :  (capitalize(player2)+"\n"))
    ) 
  : 
 (""))
   );
   return 1;
}

void display_board()
{
   tell_room(this_object(),"\n\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[0]+"     %    "+(string)game_array[1]+
"     %    "+(string)game_array[2]+"     %    "+(string)game_array[3]+
"     %    "+(string)game_array[4]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[5]+"     %    "+(string)game_array[6]+
"     %    "+(string)game_array[7]+"     %    "+(string)game_array[8]+
"     %    "+(string)game_array[9]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   "+
BOLD+BLUE_F+"X"+OFF+" - "+
capitalize(player1)+"\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[10]+"    %    "+(string)game_array[11]+
"    %    "+(string)game_array[12]+"    %    "+(string)game_array[13]+
"    %    "+(string)game_array[14]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   "+
BOLD+RED_F+"O"+OFF+" - "+
capitalize(player2)+"\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[15]+"    %    "+(string)game_array[16]+
"    %    "+(string)game_array[17]+"    %    "+(string)game_array[18]+
"    %    "+(string)game_array[19]+"\n"+
"          %          %          %          %          \n"+
"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n"+
"          %          %          %          %          \n"+
"    "+(string)game_array[20]+"    %    "+(string)game_array[21]+
"    %    "+(string)game_array[22]+"    %    "+(string)game_array[23]+
"    %    "+(string)game_array[24]+"\n"+
"          %          %          %          %          \n\n"+
(((turns_completed < (sizeof(game_array)-1)) && (won==0))   
  ? ("Turn: "+  ((current_turn == 1)       
    ?  (capitalize(player1)+"\n") 
    :  (capitalize(player2)+"\n"))
  ) 
  : (""))
   );
   return;
}


status place_fun(string str)
{
   string mark;
   int index;

   if(this_player()->query_real_name() != player1 &&
      this_player()->query_real_name() != player2)
   {
      write("You are not playing!  Stop trying to interfere!\n");
      return 1;
   }
   write(current_turn+"\n");
   if(current_turn == 1 && this_player()->query_real_name() != player1)
   {
      write("It's not your turn, silly.\n");
      return 1;
   }        
   if(current_turn == 2 && this_player()->query_real_name() != player2)
   {
      write("It's not your turn, silly.\n");
      return 1;
   }
   if(!str || member_array(str, valid_choice) == -1)
   {
      write(
         "Syntax is 'place <number>' where <number> is the square you\n"+
         "wish to place your piece.\n"
      );
      return 1;
   }
   mark = (this_player()->query_real_name() == player1) 
      ? (BOLD+BLUE_F+"X"+OFF) 
      : (BOLD+RED_F+"O"+OFF);
   if(member_array(game_array[(int)str-1], poss_values) != -1)
   {
      write("That spot is already taken.  Please choose another spot.\n");
      return 1;
   }
   game_array[(int)str-1] = (((int)str>=11) 
      ? (mark+" ") 
      : mark);
   current_turn = ((current_turn == 1) ? 2 : 1);
   if(turns_completed >= 4)
   {
      for(index = 0; index < sizeof(game_array); index++)
      {
         if(index==0 || index==1 || index==5 || index==6 || index==10 ||
            index==11 || index==15 || index==16 || index==20 || index==21)
            if(CheckGrid(index, 1)==1)
            {
               won = 1;
               break;
            }
         if(index==3 || index==4 || index==8 || index==9) 
            if(CheckGrid(index, 4)==1)
            {
               won = 1;
               break;
            }
         if(index==0 || index==1 || index==2 || index==3 || index==4 ||
            index==5 || index==6 || index==7 || index==8 || index==9)
            if(CheckGrid(index, 5)==1)
            {
               won = 1;
               break;
            }
         if(index == 0 || index==1 || index==6)
            if(CheckGrid(index, 6)==1)
            {
               won = 1;
               break;
            }
      }
      if(won == 1)
      {
         display_board();
         write("\nYou Won!\n");
         say("\n"+capitalize(this_player()->query_real_name())+" won!\n",
            this_player());
         reset_game();
         return 1;
      }
      else
      {
         display_board();
         if(++turns_completed == sizeof(game_array))
         {
            tell_room(this_object(),"\nThe game has ended in a draw.\n");
            reset_game();
         }
         return 1;
      }
   }
   else
   {
      display_board();
      turns_completed++;
      return 1;
   }
}
int CheckGrid(int start, int incr)
{
   if((member_array(game_array[start], isx)!=-1 &&
       member_array(game_array[start+(1*incr)], isx)!=-1 &&
       member_array(game_array[start+(2*incr)], isx)!=-1 &&
       member_array(game_array[start+(3*incr)], isx)!=-1) ||
      (member_array(game_array[start], iso)!=-1 &&
       member_array(game_array[start+(1*incr)], iso)!=-1 &&
       member_array(game_array[start+(2*incr)], iso)!=-1 &&
       member_array(game_array[start+(3*incr)], iso)!=-1))
      {
         return 1;         
      }
   return 0;
}

status giveup_fun(int start)
{
   if(player2=="")
   {
      write("There is no one for you to surrender to!\n");
      return 1;
   }
   if(this_player()->query_real_name() == player1)
   {
      write("You surrender to your oppenent!.\n");
      say(capitalize(player1)+" surrenders.\n", this_player());
   }
   else if(this_player()->query_real_name() == player2)
   {
      write("You surrender to your oppenent!.\n");
      say(capitalize(player2)+" surrenders.\n", this_player());
   }
   else
   {
      write("You are not playing and, therefore, can not surrender.\n");
      return 1;
   }
   surrendered = 1;
   tell_room(this_object(), 
      "You are transported back to the gaming room.\n\n"
   );
   tell_room("d/ooc/w/jheleg/bhouse/gamerm",
      capitalize(player1)+" and "+capitalize(player2)+" arrive from playing "+
      "their game.\n");
   if(find_living(player1))
   {
      move_object(find_living(player1), "/d/ooc/w/jheleg/bhouse/gamerm");
      command("look", find_living(player1));
   }
   if(find_living(player2))
   {
      move_object(find_living(player2), "/d/ooc/w/jheleg/bhouse/gamerm");
      command("look", find_living(player2));
   }
   reset_game();
   return 1;
}

status info_fun()
{
   string *games;
   int index;
   object ob;

   games=call_other("/d/ooc/w/jheleg/bhouse/gamerm","query_games_array");
   if(index=member_array("/"+file_name(this_object())+".c", games))
   {
      ob = clone_object("obj/more");
      move_object(ob, this_player());
      ob -> more(games[index - 1]);
   }
   else
   {
      write("FATAL GAME ERROR:  Report to Jheleg at once!\n");
   }
   return 1;
}

status return_fun()
{
   if(playing==1)
   {
      if(this_player()->query_real_name() == player1 ||
         this_player()->query_real_name() == player2)
      {
         write(
            "You can not return to the Gaming Room while you are in\n"+
            "the middle of playing a game.  Either finish the game to\n"+
            "its completion or use the 'surrender' command.\n"
         );
         return 1;
      }
   }
   write("You return to the Gaming Room.\n");
   say(this_player()->query_name()+" returns to the Gaming Room.\n",
      this_player());
   tell_room("/d/ooc/w/jheleg/bhouse/gamerm",
   this_player()->query_name()+" arrives.\n");
   move_object(this_player(), "/d/ooc/w/jheleg/bhouse/gamerm"); 
   return 1;
}

status exit()
{
   if(surrendered == 1) return 0;
   if(this_player()->query_real_name() == player1 ||
      this_player()->query_real_name() == player2)
   {
      tell_object(this_player(),
         "\nYou terminated the game upon leaving the room.\n\n");
      say("Game termination caused by player exit.\n");
      reset_game();
   }
   return 0;
}

