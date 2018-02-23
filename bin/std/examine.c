#include <mudlib.h>
status examine(string str, status extra) {
  return (status)"/bin/std/look" -> look(str, extra);
}
