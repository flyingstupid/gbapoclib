#include <mudlib.h>
inherit "obj/shadows/shadow";

object who;

void shadow_movement(string str) {
  who = this_player();
  if(who->query_speed_object()) {
    destruct(this_object());
    return;
  }
  shadow_object(who);
}

string query_msgin() {
  return "speeds into the room";
}

string query_msgout() {
  return "speeds out with a blur of motion to the";
}

object query_speed_object() { return this_object(); }
