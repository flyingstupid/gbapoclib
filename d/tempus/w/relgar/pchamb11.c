inherit "players/relgar/temple/main";

reset(arg){

    reset_doors(arg);
    load_door(({
	"destination","d/tempus/w/relgar/tside1",
	"direction","west door",
	"key","None yet.",
	"long",
	"This is an ornately crafted, red oak door.\n",
	"door number",1,
      }));
    load_door(({
	"destination","d/tempus/w/relgar/pchamb12",
	"direction","east door",
	"long",
	"An old oaken door.",
	"key_id","None yet.",
	"door number",2,
      }));
    if(arg) return;
    set_exits(({
      }));
    set_short("An antechamber of the cathedral");
    set_light(2);
    set_long(
      "\tYou are standing in a small antechamber of the cathedral. There is a\n"+
      "small lamp here to allow the priests that live in the chambers above to see\n"+
      "to get up the staircase that spirals up in the northeast corner of the "+
      "room.\n"+
      "There are several pictures on the walls and they appear to be former high\n"+
      "priests and bishops.\n"
    );
    set_items(({
	"lamp#small lamp","This small lamp casts a warm glow over the room and is "+
	"much less smokey\nthan the torches in the main part of the cathedral.\n",
	"staircase","The staircase spirals up to the second floor here in the "+
	"northeast\ncorner of the room.\n"+
	"",
	"pictures#picture","The pictures on the walls depict several of the former "+
	"archbishops and high\npriests that would oversee the operations of the "+
	"cathedral. They\nmainly depict them with bloody implements of war or "+
	"torture ready at\ntheir sides.\n",
	"implements","One of the pictures shows a priest wielding a blood soaked "+
	"ceremonial\nknife while another shows a priest with a long needle "+
	"covered with\nwhat appears to be brain matter.\n",
      }));
} /* End of reset */
