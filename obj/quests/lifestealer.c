inherit "secure/questdef";

void reset(status arg) {
  if(arg) return;

  set_author("Angel");
  set_qname("LifeStealer");

  set_hint(
"The Circle has learned that the drow house Noquar has acquired a powerful \n"+
"weapon to use against our troops in battle. It is believed to be a sword  \n"+
"of great power that has the ability to drain the living essence from a    \n"+
"person.\n\n"+
"You must find this weapon and return it to Sir Alastaire. He will know what \n"+
"to do with the item. (Quest Points: 50. Difficulty: Hard)\n");

  set_min_level(15);
  set_max_level(25);
  set_req_place("d/coronos/w/angel/city/chambers/pkoffice");
  set_req_caller("d/coronos/w/angel/city/monst/curzon");
  set_qpoints(50);
}

