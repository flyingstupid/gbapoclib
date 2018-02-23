/* A generic library book 
 * make sure that the defines are the same as those from the 
 * library room itself
 * v1.02, Angel January 1994
 */


#include <mudlib.h>
#include "/d/coronos/w/moonwolf/library/library.cfg"

void make_short();
string book;
status open;

inherit TREASURE;
void reset(status arg) {
  if(arg) return;
  set_name("book");
  set_alias("tome");
  set_value(50);
  set_sell_destruct(1);  /* just in case */
  set_weight(5);
  make_short();
  set_smell("The book smells of leather.\n");
  set_listen("You hear the rustle of pages...\n");
}

void make_short() {
  string *shorts;
  shorts = ({
     "A fine leather tome",
     "A smooth black book",
     "A huge black book",
     "A large brown book",
     "A huge leather tome",
     "A tome of soft leather",
     "A book of old, dusty leather",
  });
  this_object()->set_short(shorts[random(sizeof(shorts))]);
}

void long(string wiz) {
  write("This large collection of works is titled '");
  write(LIBRARY->write_spaces(book+"'.\n"));
  write(
  "Along the spine are silvery marks depicting the seal\n"+
  "of the "+MUD_NAME+" library. ");
  if(!open)
    write("The book is closed.\n");
  else
    write("Perhaps you could read it?\n");
}
  
/* further things for the book */
string set_book(string str) { return book = str; }
string query_book()         { return book;       }

void init() {
  ::init();
  add_action("open_book",  "open");
  add_action("close_book", "close");
  add_action("read_me",    "read");
}

status open_book(string str) {
  if(str != "book" && str != "tome" && str != book) {
    notify_fail("Open what?\n");
    return 0;
  }
  if(open) {
    notify_fail("The book is already open.\n");
    return 0;
  }
  write("You open the book titled '"+LIBRARY->write_spaces(book)+"'.\n");
  say(this_player()->query_name()+" opens a book.\n");
  open = 1;
  return 1;
}

status close_book(string str) {
  if(str != "book" && str != "tome" && str != book) {
    notify_fail("Close what?\n");
    return 0;
  }
  if(!open) {
    notify_fail("The book is already closed.\n");
    return 0;
  }
  write("You close the book titled '"+LIBRARY->write_spaces(book)+"'.\n");
  say(this_player()->query_name()+" closes a book.\n");
  open = 0;
  return 1;
}

status read_me(string str) {
  object ob;

  if(!str) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(str != "book" && str == "tome" && str != book) {
    return 0;
  }
  if(!open) {
    notify_fail("But the book is closed!\n");
    return 0;
  }
  write("You read the book...\n\n");

  if((member_array(book, VALID_RACES) != -1) &&
    !(status)this_player()->query_language(book)) {
    if(INT/3 >
      sizeof((string *)this_player()->query_languages_known())) {
      if(random(INT) < random(LEARN_CHANCE)) {
        write("As you being to read the book it all starts to make sense.\n"+
              "You now know the language "+book+"!\n\n");

        this_player()->add_language(book);
      }
    }
    else {
      write("The book is written in "+book+" and doesn't make much sense.\n");
      return 1;
    }
  }

  ob = clone_object("obj/more");
  move_object(ob, this_player());
  ob -> more(CATALOGUE+book);  
  return 1;
}

status drop(string quit) {
  write("You drop the book.\n");
  LIBRARY -> return_book("book");  /* force it to return */
  return 1;
}
