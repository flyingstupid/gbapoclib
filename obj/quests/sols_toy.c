/* Another quest by Angel */
inherit "/secure/questdef";

void reset(status arg){
  if(arg)return;

  set_author("Angel");
  set_qname("sol's toy");

  set_hint(
	"When Archmagus Sol, one of the Council of Nine from the Isle of \n"+
	"Sorcery, was here on a diplomatic visit he misplaced a personal \n"+
	"item of great importance.                                       \n\n"+
	"With our own University of Power, and it's magical studies, our \n"+
	"diplomatic ties with the black robed mage, and indeed the Nine, \n"+
	"are of vital importantance. We therefore ask you to visit him   \n"+
	"and return to him that which he has lost.                       \n"+
	"			(Quest Points: 10. Difficulty: Routine)  \n");

  set_min_level(1);
  set_max_level(10);
  set_req_place("d/affils/rooms/brm");
  set_req_caller("d/affils/rooms/brm");
  set_qpoints(10);
}
