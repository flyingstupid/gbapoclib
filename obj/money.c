#include <mudlib.h>
inherit BASE;
int money;

void reset(int arg) {
    if (arg) return;
set_plural("piles of chips");
    money = 1;
}

query_weight() { return 0; }

short() {
    if (money == 0)
	return 0;
    return convert(money) +" chips";
}

/*
 * If we are picked up by a player, then move the money to his "purse",
 * and destruct this object.

 901128: Changed by JnA to not destruct object until surely picked by the
 player, i.e. object moved to the players inventory with move_object()
*/
init()
{
  if (environment(this_object())==this_player()) {
    call_other(this_player(), "add_money", money);
    money = 0;
    set_heart_beat(1);
  }
}

get()
{
  return money>0;
}

set_money(m) {
    money = m;
}

id(str) {
    if (str == "chips")
	return 1;
    if (str == "money")
	return 1;
}

heart_beat() {
    if (money == 0)
	destruct(this_object());
}

/* Add money added by Kingbilly, to allow for incremental */
/* change of amounts */

add_money(m)
{
money += m;
}

/* Money Converter.
   This wil convert all players copper coins to give a message of a
   how many platinum, gold, silver and copper coins they have.
   When a player receives money, it will automatically renew all
   coins into lowest denominator amounts; first platinum, then
   gold, silver and finnaly copper.
 */




string convert(int i) {
  string tmp;

  tmp = "";
  if(i >= PLATINUM) tmp += (i/PLATINUM +" Burgundy chips ");
  while(i >= PLATINUM)
    i -= PLATINUM;
  if(i >= GOLD) tmp += (i/GOLD + " Black chips ");
  while(i >= GOLD) 
    i -= GOLD;
  if(i >= SILVER) tmp += (i/SILVER +" Blue chips ");
  while(i >= SILVER) 
    i -= SILVER;
  if(i) tmp += (i +" White chips  ");
  return tmp;
}

string convert_money(int i) { return convert(i); }
