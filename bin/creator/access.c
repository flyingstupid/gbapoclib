#include <mudlib.h>

status valid_write(string name, int secLevel) {
  return 0;
}

status valid_read(string name, int secLevel) {
  if(valid_write(name, secLevel)) return 1;
  return (secLevel) ? 1 : 0;
}

