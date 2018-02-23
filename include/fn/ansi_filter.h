#include <ansi.h>

string filter_ansi(string str) {
  string rest, tmp;

  str = str +"";
  while(sscanf(str,"%s"+ESC+"%sm%s",str, tmp, rest) == 3) str += rest;
  return str;
}

