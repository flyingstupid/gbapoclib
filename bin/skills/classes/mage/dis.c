#include <mudlib.h>

status dis(string str, mixed alt_type, string class) {
  if(!alt_type) alt_type = "alteration";
  if(!class)    class    = "mage";

  return (status)"/bin/skills/classes/mage/disintegrate" ->
	disintegrate(str, alt_type);
}
