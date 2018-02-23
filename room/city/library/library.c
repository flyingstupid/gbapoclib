/* LIBRARY. v1.02 Angel, January 1994
 * Make sure the configs for this room remain the same as
 * the book which is cloned to the player, otherwise they
 * may not be able to read the files properly
 * All library files go in an 'open' dir as below
 *
 * 
 */ 

#include <mudlib.h>
#include "/room/city/library/library.cfg"

/* fn specs */
string check_borrowed(string str);
string write_spaces(string str);
string write_underlines(string str);
mixed *write_catalogue(string str, int silently);
status borrow_book(string arg);


string *books_borrowed;

inherit ROOM;
void reset(status arg) {
  reset_doors(arg);

  if(arg) return;
/**
  load_door(({
	"direction", "south door",
	"file",        "room/city/knowl1",
	"long",
	"A tall door of red wood, bound with iron and bronze.\n",
  }));
**/


  set_weather(2,1,0);
  set_long(
	"Tall book shelves tower upwards towards a high vaulted ceiling \n"+
	"covered with ornate frescoes dating back to the origin of the  \n"+
	"great city of Tempus. A long counter of red-brown timber extends\n"+
	"along the back half of the library. At one end are two piles of \n"+
	"books, obviously ones that have been borrowed and are now awaiting\n"+
	"return back to their places on the shelves. At the other end is \n"+
	"a few large, leather bound books which contain the list of books\n"+
	"within the library.\n");
  set_short("the "+MUD_NAME+" library");
  set_exits(({ }));
  set_sign_message(
     "\t-=[ The "+MUD_NAME+" Library ]=-  \n"+
     "Commands: borrow <book name>        \n"+
     "          return <book name>        \n"+
     "          browse <catalogue|index>  \n");

  set_smell("The musty scent of ancient leathers abound in the library.\n");
  set_listen("All is silent in this room.\n");

  set_items(({
	"counter",
	"The counter is made from the same wood as the shelves around you, \n"+
	"polished to a high sheen. The mirror like surface and ornate      \n"+
	"etchings around the top are unmistakably elven in design",

	"library",
	"You're standing in the main library chamber",

	"book#books#piles#pile",
	"There are two piles of books at the far end of the counter that \n"+
	"the citizens of Tempus have borrowed, and now returned to the library",

	"shelf#shelves",
	"The shelves are made from a sturdy, yet ancient red wood, donated \n"+
	"from the elven cities to the north when Tempus was built. They now\n"+
	"serve to hold thousands of volumes of knowledge. Something the     \n"+
	"elves value greatly",

	"ceiling#vaulted ceiling",
	"High above you, covered in shadow, is the ceiling of the library",

	"shadow#shadows",
	"It's too dark up there to see",
  }));


  books_borrowed = ({});
}

void init() {
  ::init();
  add_action("write_catalogue", "browse");
  add_action("borrow_book",     "borrow");
  add_action("return_book",     "return");
}


/* turn '_' into spaces...looks better for a list of books 
   rather than a list of files 
*/
string write_spaces(string str) {
  string tmp1, tmp2;
  while(sscanf(str, "%s_%s", tmp1, tmp2))
    str = tmp1+" "+tmp2;
  return str;
}

string write_underlines(string str) {
  string tmp1, tmp2;
  while(sscanf(str, "%s %s", tmp1, tmp2))
    str = tmp1+"_"+tmp2;
  return str;
}


string check_borrowed(string str) {
  string tmp;
  tmp = write_spaces(str);
  tmp = tmp +".....................................................";
  tmp = extract(tmp,0,50);
  if(member_array(str, books_borrowed) != -1) 
    tmp += "Borrowed";
  else 
    tmp += "Available";
  return tmp;
}


mixed *write_catalogue(string str, int silently) {
  string *books, tmp;
  object ob;
  int i;

  books = get_dir(CATALOGUE);

  if(!str) str == "catalogue";

  if(!sizeof(books)) {
    notify_fail("The library is empty.\n");
    return 0;
  }
  tell_object(this_player(), "You browse through the catalogue...\n\n");
  if(!this_player()->query_invis())
    say(this_player()->query_name()+" browses through the catalogue.\n",
      this_player());
  else
    say("You hear some pages turning...\n",this_player());

  if(!silently) {
    write("\t\tThe Books of the "+MUD_NAME+" Library\n");
    for(i=0; i<sizeof(books); i++) { 
      if(i+1 < 10)
        tmp = (" "+(i+1)+") "+capitalize(check_borrowed(books[i]))+"\n");
      else
        tmp = ((i+1)+") "+capitalize(check_borrowed(books[i]))+"\n");
      write_file(CATALOGUE+"cat.txt", tmp);
    }
    ob = clone_object("obj/more");
    move_object(ob, this_player());
    ob -> more(CATALOGUE+"cat.txt");
    rm(CATALOGUE+"cat.txt");
  }
  return books;
}

status borrow_book(string arg) {
  string *books;
  object ob;
  int i;

  if(!arg) {
    notify_fail("Borrow what?\n");
    return 0;
  }

  books = get_dir(CATALOGUE);
  arg   = lower_case(arg);

  if(!arg) {
    notify_fail("Borrow what?\n");
    return 0;
  }

  sscanf(arg, "%d", i);
  if(i) {
    if(i > sizeof(books)) {
      notify_fail("There are not that many books.\n");
      return 0;
    }
    borrow_book(books[i-1]);
    return 1;
  }

  if(stringp(arg)) {
    arg = write_underlines(arg);
    if(member_array(arg, books_borrowed) > -1) {
      notify_fail("That book has already been borrowed.\n");
      return 0;
    }    
    if(this_player()->query_invis()) {
      notify_fail("But no one can see you!\n");
      return 0;
    }
    if(member_array(arg, books) == -1) {
      notify_fail("There is no such book.\n");
      return 0;
    }
    if(!this_player()->add_weight(5)) {
      notify_fail("You can't carry the book!\n");
      return 0;
    }
    write("You borrow the book '"+capitalize(write_spaces(arg))+"'.\n");
    say(this_player()->query_name()+" borrows a book.\n",this_player());
    books_borrowed += ({ arg, });
    ob = clone_object(BOOK);
    ob -> set_book(arg);
    ob -> set_library(file_name(this_object()));
    move_object(ob, this_player());
    return 1;
  }
  return 0;
}
  
status return_book(string str) {
  object ob;
  int i; 

  if(!str) {
    notify_fail("Return what book?\n");
    return 0;
  }
  ob = present(str, this_player());

  if(!ob) {
    notify_fail("You have nothing by that name.\n");
    return 0;
  }
  if(!ob->query_book()) {
    notify_fail("That is not a library book.\n");
    return 0;
  }

  if((i = member_array(ob->query_book(), books_borrowed)) != -1) {
    books_borrowed = books_borrowed[0..i-1]
                 + books_borrowed[i+1..sizeof(books_borrowed)-1];
    if(present(this_player(), this_object())) {
      write("You return the book "+write_spaces(ob->query_book())+".\n");
      say(this_player()->query_name()+" returns a book.\n");
    }
    else {
      tell_object(this_player(), "The book vanishes, as if by magic.\n");
    }
  }
  else {
    write("Error: Book not in borrowed array.\n");
  }

  destruct(ob);
  return 1;
}     

string *query_books_borrowed() { return books_borrowed; }
status query_race_book(string str) {
  string *races;

  races = VALID_RACES;
  return (member_array(str, races) == -1) ? 0 : 1;
}
