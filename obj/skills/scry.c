/* scry controller */

object scry;

void init() {
  add_action("dispel", "dispel");
}

status dispel(string str) {
  if(str != "scry") return 0;
  if(!scry) {
    destruct(this_object());
    return 0;
  }
  scry->time_out();
  return 1;
}

void set_scry(object ob) { scry = ob;   }
object query_scry()      { return scry; }

status id(string str) {
  return str == "spell"
      || str == "scry";
}

