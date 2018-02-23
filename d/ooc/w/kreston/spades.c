/* Coded by: Xanatos  Feb 9th, 97
  Updated for h7 by Kreston  June 10, 97
  New room and item descriptions added by Sahanna@H7 June 19, 97
*/
#include <mudlib.h>
#pragma strict_types

inherit ROOM;

#define new_deck ({\
"2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "th", "jh", "qh", "kh", "ah",\
"2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "td", "jd", "qd", "kd", "ad",\
"2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "tc", "jc", "qc", "kc", "ac",\
"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "ts", "js", "qs", "ks", "as",\
})

mixed *cards, *deck;
mixed *h;
object *p;
int gamect, turn, t1, t2, sb, suitplay;
int *book, *turns;

int find_number(object ob);
status in_hand(int playern, int cardn);
status can_play_suit(int playern, int suitcard);
status is_suit(int suitcard, int cardn);
int calc_winner();
int show_pot(status tellroom);
int create_deck();
int nf(string str);
int playerp(object ob);

status reset(status arg){
 if(arg) return 1;
 set_ooc_room(1);
set_weather(2,2,0);
set_short("Spades Parlor");
set_long(
 "A cozy little room where people can come to relax, socialize, and perhaps\n"+
 "pass some time playing a game of spades to get away from it all. The main\n"+
 "feature of this room is a round oak table with four cushioned chairs placed\n"+
 "around it. The chairs look to be exceptionally comfortable. A charming \n"+
 "fire adds warmth and a pleasant ambiance to the room. A painting rests\n"+
 "on the mantle. The only window in the room is next to the doorway on the\n"+
"north wall.  A small sign of instructions for the game hangs beside a window.\n"
);
set_day_desc("Sunlight streams in through the window.\n");
set_night_desc("Moonbeams shimmer on the glass of the window.\n");
set_smell("The smell of woodsmoke pleasantly fills the room.\n");
set_listen("Sounds of friends gathered together, enjoying each other's company\n"+
 "are often heard from the table.\n");
set_items(({
 "table#card table#oak table",
  "A medium sized round oak table is the main feature of the room. It is\n"+
  "the perfect size table for playing card games, like Spades. Pull up a \n"+
  "seat with a few friends and have some fun.\n",
 "card#cards#deck#deck of cards#playing cards",
  "A fresh deck of cards has been laid on the table. The management has\n"+
  "guaranteed them to be unmarked.\n",
 "chair#chairs",
  "Four comfortable chairs stand around the card table. A person could \n"+
 "probably sit in one of these for hours with out ever getting stiff.\n",
 "painting#picture#portrait", 
  "A painting of a half-giant female has been placed over the mantle of\n"+
  "the fireplace. She wears an architech's hat and is standing in a room\n"+
  "that looks very similar to this one probably would have looked, with\n"+
  "out the furnishings. She seems to be looking at someone not in the picture.\n",
 "window", 
  "A window on the north wall looks out on a fair city. Occasionally, a\n"+
  "strangly familiar huminoid wanders past the window.\n", 
 "fireplace#fire#hearth",
  "A blazing fire adds warmth, light and atmosphere to the Spades Parlor.\n" 

}));

add_item("sign", "\
** This is a simplified version of the game Spades **\n\
The object of the game is for your team to win the most books.\n\
To play the game, simply play a card down. \n\
Your opponents will try to beat your card by laying a higher card of the\n\
same suit or by defeating it with a spade.\n\ 2 - low, A - high\n\
You must follow suit if you have it.(same suit as first person in the book)\n\
If you *cannot* follow suit, you can play whatever card you like.\n\
Notes:\n\
  spades are always higher than the 3 other suits.\n\
  You cannot play a spade the very first book.\n\
  You cannot play spades until they've been `Broken'. (someone cant play suit)\n\
  The game is over when all 52 cards have been dealt with.(13 books played)\n\
\n\
Some commands are:\n\
team <pl1 (tm1)> <pl2 (tm2)> <pl3 (tm1)> <pl4 (tm2)>\n\
hand\n\
pot\n\
play <card>\n\
stop game\n\
");
 set_light(10);
  add_exit("d/ooc/rooms/ooc2", "north");
 book=({-1,-1,-1,-1});
 turns=({-1,-1,-1,-1});
}

void check_room(){
 write("You look around the room for some sailors or passengers.\n");
 command("look", this_player());
}

void init(){
 ::init();
// add_action("create_deck", "tdeck");
 add_action("team", "team");
 add_action("play", "play");
 add_action("pot", "pot");
 add_action("hand", "hand");
 add_action("stop", "stop");
// social functions
 add_action("sit_down", "sit");
}

int stop(string arg){
 if(!arg||lower_case(arg)!="game"||gamect==0) return 0;
 if( find_number(this_player())>0 ){
   gamect=0;
   printf("%s has stopped the game of spades.\n", this_player()->query_name());
 return 1;
 }
 return 0;
}

int team(string str){
 int i;
 string *t;
 
 t=({ "","","","" });
 if(gamect) return nf("There is a game in progress.\n");
 if( !str || !sscanf(str, "%s %s %s %s", t[0], t[1], t[2], t[3]) )
   return nf("Use: team Team1 Team2 Team1 Team2\n");

 p=({});
 for(i=0;i<4;i++)
   if( t[i] && present(t[i]) && playerp(present(t[i])) ){
     if( member(p, present(t[i])) == -1 )
       p += ({ present(t[i]) });
   }
   else
     return nf( sprintf("%s isn't a valid player.\n", t[i]) );

 if(sizeof(p) < 4) return nf("Not enough players.\n");

 tell_room(this_object(), 
       sprintf("%s will start the game by laying down a card.\n", 
       p[0]->query_name()) );

 create_deck();
 turns[0]=0;
 turn=0;
 t1=0; 
 t2=0;
 sb=0;
 suitplay=0;
 gamect=1;
 
 return 1;
}

int play(string arg){
 int cardn, playern, cpos, winner;
 if(!arg) return 0;
 playern=find_number(this_player());
 if(playern<0) return nf("You're not in this game of cards.\n");
 if( this_player()->query_real_name() != p[turn]->query_real_name() )
   return nf("It is not your turn to play a card.\n");

 arg=lower_case(arg);
 cardn=member(new_deck, arg);
 if(cardn==-1) return 0;
 
 cpos = in_hand(playern, cardn);
 if(cpos == -1) return nf("You don't have that card.\n");
 
 if(gamect==1) // assume they dont have all spades, dont let spades be played
   if( cardn > 38 ) return nf("You can't open with spades.\n");
 if( cardn > 38 && suitplay==0 && !sb)
   return nf("Spades have not been broken yet.\n");

 if(suitplay==0){
 }
 else{
   // can they follow suit?

   if( can_play_suit(playern, book[0]) ){
     if( !is_suit(book[0], cardn) )
       return nf("You must follow suit.\n");
       // idea: show them their cards of that suit
   }
   else{
     // they couldn't follow suit, can play whatever they want
     // (falls through)
     if(cardn>38) sb=1; // spades broken
   }
 }
 
 tell_room(this_object(), sprintf("%s lays a %s.\n", 
           this_player()->query_name(), new_deck[cardn]) );

 book[suitplay]=cardn;
 turns[suitplay]=turn;
 h[playern] -= ({ cardn }); // take away played card
 
// tell_room(this_object(), sprintf("turns[%d]=%d, book[%d]=%s\n",
//   suitplay, turn, suitplay, new_deck[cardn]) );

 suitplay++;

 if(suitplay>3)
 { // calc winner of "book"
   winner = calc_winner();
//tell_room(this_object(), "Winner/turn: "+winner+"\n");
   // award point
   if(winner==0 || winner==2){
    t1++;
    tell_room(this_object(), "** Team 1 has taken the book.\n");
   }
   else{
    t2++;
    tell_room(this_object(), "** Team2 has taken the book.\n");
   }
   show_pot(1);
   suitplay=0;
   gamect++;
//tell_room(this_object(), sprintf("gamect is: %d\n", gamect) );

   if(gamect>13){
     // game over
     tell_room(this_object(), "** The game has ended.\n");
     if( t1 > t2 ){
       tell_room(this_object(), sprintf("** Team1, %s and %s have won the game!\n",
           p[0]->query_name(), p[2]->query_name()) );
     }
     else{
       tell_room(this_object(), sprintf("** Team2, %s and %s have won the game!\n",
           p[1]->query_name(), p[3]->query_name()) );
     }
     gamect=0;
     return 1;
   }
   // calc turn (winner goes)
   turn=winner-1;
 }
 
// if(turn>3) 
//   turn=0;
// else
   turn++;
 if(turn>3) 
   turn=0;
   
// tell_room(this_object(), sprintf("turn is: %d\n", turn) );

 tell_room(this_object(), sprintf("%s will play the next card.\n", 
           p[turn]->query_name()) );

 return 1;
}

int calc_winner(){
  int i, t, win_card;
  win_card = book[0];
  t=turns[0];
/*
for(i=0;i<4;i++)
 printf("%s %d| ", new_deck[book[i]], book[i]);
write("\n");
*/
  for(i=1;i<4;i++)
    if( is_suit(book[0], book[i]) ){
      if( book[i] > win_card){
        t=turns[i];
        win_card=book[i];
      }
    }
    else{ // didn't follow suit
      if(book[i]>38 && book[i] > win_card){
        t=turns[i];
        win_card=book[i];
      }
    }
   
//tell_room(this_object(), sprintf("win card is: %s\n", new_deck[win_card]) );
  return t;
}

status in_hand(int playern, int cardn){
 return member( h[playern], cardn);
}

status is_suit(int suitcard, int cardn){
 int suit, msuit;
 switch(suitcard){
  case  0..12: { suit=0; break; }
  case 13..25: { suit=1; break; }
  case 26..38: { suit=2; break; }
  case 39..51: { suit=3; break; }
 }
 switch(cardn){
   case  0..12: { msuit = 0; break; }
   case 13..25: { msuit = 1; break; }
   case 26..38: { msuit = 2; break; }
   case 39..51: { msuit = 3; break; }
 }
 return suit==msuit;
}

status can_play_suit(int playern, int suitcard){
 int i, t, suit, msuit;
 switch(suitcard){
  case  0..12:{ suit=0; break; }
  case 13..25:{ suit=1; break; }
  case 26..38:{ suit=2; break; }
  case 39..51:{ suit=3; break; }
 }
 for(i=0,t=sizeof(h[playern]);i<t;i++){
   switch(h[playern][i]){
     case  0..12:{ msuit = 0; break; }
     case 13..25:{ msuit = 1; break; }
     case 26..38:{ msuit = 2; break; }
     case 39..51:{ msuit = 3; break; }
   }
   if(msuit==suit) return 1;
 }
 return 0;
}

int show_pot(status tr){
//   write( sprintf("%-28s %5i\n",(string)ob->short(), x ) );
 int i, t;
 if(gamect==0) return nf("There is no game in progress.\n");
 for(i=0;i<4;i++){
   printf("%s", p[i]->query_name());
   if(i==0||i==2) printf("(t1)   "); else printf("(t2)   ");
 }
 write("\n");
// write("*");
 if(tr)
   tell_room(this_object(), 
     sprintf("Hand: %d.  Team1: %d, Team2: %d\n", gamect, t1, t2));
 else
   printf("Hand: %d.  Team1: %d, Team2: %d\n", gamect, t1, t2);
 for(i=0;i<suitplay;i++)
  if(tr)
    tell_room(this_object(), 
      sprintf("%-5s %-15s\n", new_deck[book[i]], p[turns[i]]->query_name()));
  else
    printf("%-5s %-15s\n", new_deck[book[i]], p[turns[i]]->query_name());
 if(suitplay<4)
   if(p[turn]==this_player())
     write("It is your turn to play a card.\n");
   else
     printf("It is %s's turn to play a card.\n", p[turn]->query_name() );
 return 1;
}

int pot(){
 return show_pot(0);
}

int hand(){
 int i, n, t;
 if( gamect==0 ) return nf("There is no game in progress.\n");
 n=find_number(this_player());
 if( n < 0 ) return nf("You are not included in this game.\n");
 for(i=0,t=sizeof(h[n]);i<t;i++)
   printf("%s ", new_deck[ h[n][i] ]);
 write("\n");
 return 1;
}

int find_number(object ob){
 int i;
 for(i=0;i<4;i++)
   if( objectp(p[i]) && p[i]->query_real_name()==ob->query_real_name() )
     return i;
 return -1;
}

void shuffle(){
 int i, r;
 deck=({});
 for(i=0;i<52;i++){
   r = random( sizeof(cards) );
   deck += ({ cards[r] });
   cards -= ({ cards[r] });
 }
 cards=deck;
// write("... shuffled. \n");
}

mixed *sort(mixed *arr){
 int i,j, tmp;
  for(i=0;i<13;i++)
    for(j=i;j<13;j++)
     if(arr[j] < arr[i]){
       tmp=arr[j];
       arr[j]=arr[i];
       arr[i]=tmp;
    }
 return arr;
}

void deal(){
 int i, j;
 h=({ ({}), ({}), ({}), ({}) });
 for(i=0;i<52;i+=4){
   h[0] += ({ deck[i] });
   h[1] += ({ deck[i+1] });
   h[2] += ({ deck[i+2] });
   h[3] += ({ deck[i+3] });
 }

 for(j=0;j<4;j++){
   sort(h[j]);
 }
/*   for(i=0;i<13;i++)
     printf("%O ",h[j][i]);
   write("\n");
 }
 // printf("sizeof: %d\n%O\n", sizeof(new_deck), new_deck);
 for(j=0;j<4;j++){
   for(i=0;i<13;i++)
     printf("%O ", new_deck[ h[j][i] ]);
   write("\n");
 }
*/
}

int create_deck(){
 int i, j;
 cards=({});
 for(i=0;i<52;i++)
   cards += ({ i });
 for(i=0;i<8;i++)
   shuffle();
 deal();
 return 1;
}

// h7 modifications
int nf(string str)
{
 notify_fail(str);
 return 0;
// drawback: now the parser will stop looking for other commands of same name.
}

int playerp(object ob)
{
 return !ob->query_npc() && interactive(ob);
}

// new functions @H7
// Sahanna, social for sit.
status sit_down(string str){
 string tmp1;
 if( str && member( ({"down","chair","table"}), str ) >-1 ){
  say( sprintf("%s sits down at the card table.\n", this_player()->query_name()) );  
  write("You sit down at the card table.\n");
  return 1;
 }
 return nf("Sit where?\n");
}
