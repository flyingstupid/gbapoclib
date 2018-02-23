#include <mudlib.h>

status lb(string str, mixed alt_type, string class) {
  if(!class) class = "mage";
  return (status)"/bin/skills/classes/mage/lightning" ->
	lightning("bolt "+str, alt_type, class);
}
