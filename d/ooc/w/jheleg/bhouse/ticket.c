#include <mudlib.h>
inherit TREASURE;

static int time;
object challenger;
string game_room;

void start_timer();
void count_down();
object set_challenger(object c) { return challenger = c; }
string set_game_room(string room) { return game_room = room; }

void reset(status arg)
{
   ::reset(arg);

   if(!arg)
   {
      set_name("#challenge_ticket#");
      set_short(0);
      set_long(
         "This is the 'challenge' object used by the gaming system.\n"
      );
      set_value(0);
      set_weight(0);
   }
}

void init()
{
   ::init();
   add_action( "accept_fun", "accept");
   add_action("decline_fun", "decline");
}

status accept_fun()
{
   tell_object(challenger, capitalize(this_player()->query_name())+
      " has accepted the challenge!\n"
   );
   write("You accept the challenge!  Prepare to play...\n");
   remove_call_out("count_down");
   call_out("move_to_room", 3);
   return 1;
}

void move_to_room()
{
   write(
      "You feel a funny feeling fill you throughout as you are\n"+
      "pulled away.\n"
   );
   tell_object(challenger,
      "You are moved to the room you will be playing the game in.\n"
   );
   say(this_player()->query_name()+" is transported away to play a game!\n",
      this_player());
   move_object(this_player(), game_room);
   move_object(challenger, game_room);
   command("look", this_player());
   command("look", challenger);
   say(this_player()->query_name()+" appears and looks ready to play "+
      "a game.\n", this_player());
   destruct(this_object());
}

status decline_fun()
{
   tell_object(challenger, capitalize(this_player()->query_name())+
      " has declined the challenge.\n"
   );
   write("You decline the challenge.\n");
   destruct(this_object());
   return 1;
}

void start_timer()
{
   time = 1;
   count_down();
}

void count_down()
{
   if(time <= 30)
   {
      ++time;
      call_out("count_down",1);
   }
   else
   {
      tell_object(environment(),
         "Time has expired.  The challenge is no longer valid.\n"
      );
      tell_object(challenger, capitalize(environment()->query_name())+
         " failed to respond to your challenge in the allotted\n"+
         "amount of time.  Re-issue the challenge if you like.\n"
      );
      destruct(this_object());
   }
}

drop() { return 1; }
give() { return 1; }

