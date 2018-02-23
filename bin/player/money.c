#include <mudlib.h>

status money(string arg) {
  int mon;

  mon = this_player()->query_money();
  write(((!mon)
     ? "Your money pouch is empty...\n"
     : "You have "+
       ((MONEY->convert(mon)) ? (string)MONEY->convert(mon) : (mon + "")) +
       "coins in your pouch.\n"));
  return 1;
}
