inherit "inherit/treasure";

void reset(status arg) {
   if(arg) return;
   set_name("book");
   set_alias("manual");
   set_long(
  "A large, hard covered book about six inches think. Its pages are old and\n"+
  "yellowed, with words scribbled all over them. The cover has the words \n"+
  "'Newbie Creator Instruction and General Practice Manual' written in heavy\n"+
  "black letters. You can read the introduction with <read intro>!\n");

   set_weight(1);
   set_short(
	"Newbie Creator Instruction and General Practice Manual");
   set_value(0);
}

query_auto_load() {return ("/objects/wiz_book:");}

void init() {
   ::init();
   add_action("read", "read");
   add_action("move", "move");
}

status read(string str) {
   object obj;
   if(str == "intro") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/introduction.wiz");
      return 1;
   }
   if(str == "chapter 1") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/room.wiz");
      return 1;
   }
   if(str == "chapter 2") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/monster.wiz");
      return 1;
   }
   if(str == "chapter 3") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/weapon.wiz");
      return 1;
   }
   if(str == "chapter 4") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/armour.wiz");
      return 1;
   }
   if(str == "chapter 5") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/clothing.wiz");
      return 1;
   }
   if(str == "chapter 6") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/coding/door.wiz");
      return 1;
   }
   if(str == "chapter 7") {
      obj = clone_object("obj/more");
      move_object(obj, this_player());
      obj -> more("/data/manuals/creator/DosAndDonts.wiz");
      return 1;
   }
}

status drop(string quit) { return 1; }

status move(string str) {
   if(find_living(str)) {
       move_object(this_object(), find_living(str));
       return 1;
   }
}
