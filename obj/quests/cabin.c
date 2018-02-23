// The Cabin quest.
// Code by Aziz

inherit "/secure/questdef";

void reset(status arg){
        if(arg)return;
set_author("Aziz");
set_qname("Cabin");
set_hint("An important letter sent by the major has not reached it's\n"+
        "destination. The postman was caught in a snowstorm when he was\n"+
        "crossing some mountains a few days ago. We can only hope that\n"+
        "he found the small cabin up in the Salago mountains. Go there\n"+
        "and find him, and bring the letter to its destination.\n");
set_min_level(1);
set_max_level(10);
set_req_place("/players/aziz/cabin/entrance");
set_req_caller("/players/aziz/cabin/note");
set_qpoints(20);
set_test(1);
}
