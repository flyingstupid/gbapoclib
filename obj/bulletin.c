/* Bulletin Board 2 */

/*
   This board gives the player greater control over notices. It uses 
   /obj/editor (a string editor), and /obj/pager (a 'more' for strings).
   These are also used by the mailer 
 */

#include <mudlib.h>
inherit TREASURE;

#include <ansi.h>

#ifndef EDITOR
#define EDITOR "obj/editor"
#endif

#ifndef PAGER
#define PAGER "obj/pager"
#endif

#define NAME    (string)this_player()->query_name()
#define REAL    (string)this_player()->query_name(1)
#define HEADER  0
#define AUTHOR  1
#define MESSAGE 2
#define TIME    ctime(time())[4..15]
#define PASTE   "/"+ PASTE_DIR +"/"+ REAL

/* bulletins */

mixed *bulletins;    /* ({ ({ header, author, message, }), }) */
static string save_file; 

/* new notice */

static object new_author;
static string new_header;
static int SECURITY_ACCESS;

static int edit_old;

void update_desc();

void reset(status arg) {
  if(arg) return;
  set_name("board");
  set_alias("bulletin board");
  set_extra_long("There is a bulletin board here.\n");
  bulletins = ({});
  update_desc();
}

 
void long(status wiz) { 
    object pager_ob;
    int i;
    string tmp;

    if(query_long()) ::long(wiz);
    tmp = "You can set up new notes with the command 'note headline'.\n";
    tmp += "Read a note with 'read num', and remove an old note(s) with\n";
    tmp += "'remove num{,num2}'.  You can clip a note to your clipboard with\n";
    tmp += "'clip num'. You can edit one of your old notes with\n";
    tmp += "'edit num'.\n";
    if(!sizeof(bulletins)) {
      tmp += "It is Empty.\n";
    }
    else if(sizeof(bulletins) == 1) {
      tmp += "The Bulletin Board contains 1 note:\n\n";
    }
    else {
      tmp += "The Bulletin Board contains "+ sizeof(bulletins) +" notes:\n\n";
    }
    say(NAME +" studies the bulletin board.\n"); 
    for(i = 0; i < sizeof(bulletins); i++) {
      tmp += (i+1) +".\t"+ bulletins[i][HEADER] +"\n";
    }
#ifdef PAGER
    pager_ob = clone_object(PAGER);
    move_object(pager_ob, this_player());
    pager_ob->page(tmp);
#else    
    write(tmp);
#endif
} 

void update_desc() {
  string temp;
  temp = "There is a bulletin board here with "+int_to_str(sizeof(bulletins));
  if(sizeof(bulletins) != 20 && sizeof(bulletins) != 30) temp += " ";
  temp += "note";
  if(sizeof(bulletins) != 1)
    temp += "s";
  temp += " on it.\n";
  set_extra_long(temp);
}
 
void set_save_file(string file) { 
  save_file = file; 
  if(save_file) restore_object(save_file); 
} 

 
status get() { 
  return 0; 
} 

status drop() { return 1; }
 

init() { 
   if(!bulletins) bulletins = ({});
   update_desc();
   add_action ("new", "note"); 
   add_action ("read", "read"); 
   add_action ("remove", "remove"); 
   add_action ("bo", "bo"); 
   add_action ("read", "clip");
   add_action ("edit", "edit");
} 


status bo() {
  long(0);
  return 1;
}

/*************************************************************************/


void add_message(string arg) {  /* quit and save from editor */
  if(new_author != this_player()) return;
  if(edit_old) { /* was editing old notice */
    bulletins = bulletins[0..(edit_old-2)]
              + bulletins[edit_old..(sizeof(bulletins)-1)];
    edit_old = 0;
  }
  bulletins += ({
                 ({
                   new_header,
                         REAL,
                          arg,
                 })
               });
  if(save_file) save_object(save_file);
  update_desc();
  new_author = 0;
  new_header = 0;
}


void editor_quit(string arg) {  /* quit, no save from editor */
  edit_old = 0;
  new_author = 0;
  new_header = 0;
}


/***********************************************************************/
/* edit old notice */


status edit(string str) {
  int i;
  string rest;
 string temp;

  if(!str || !(sscanf(str, "%d", i) || sscanf(str, "note %d", i))) return 0; 
  if(i < 1 || i > sizeof(bulletins)) { 
    write("Not that number of messages.\n"); 
    return 1; 
  } 
  i -= 1;
/* Redo by Aziz. id() only accepts string. Bulletins is mixed. :) */
temp=bulletins[i][AUTHOR];
if(!this_player()->id(temp)){
    write("Sorry, you can only edit your own notice.\n");
    return 1;
  }
  if(new_author && environment(new_author) == environment()) {
    write((string)new_author->query_name() +" is busy writing.\n"); 
    return 1; 
  } 
/* What we need to do is extract the old header, remove the editor */
/* and old time so we're left with the subject. THAT, however, is  */
/* not what's done here. Can we settle for placing the editor and  */
/* time edited AFTER the original header, or would that be nasty?  */

new_header=bulletins[i][HEADER];
new_header = extract(new_header,0,33);
new_header += "["+ capitalize(REAL)+"                         ";
new_header = extract(new_header,0,43);
new_header += " "+ TIME +"]";

/* Code is obsolete. Remove on cleanup.

if(!new_header) new_header="";
  new_header += "("+capitalize(REAL) +", "+ TIME +")";
*/
  new_author = this_player();
  edit_old = i + 1;
  clone_object(EDITOR)->edit("add_message",bulletins[i][MESSAGE],1);
  return 1;
}


/*************************************************************************/
/* add new notice */

status new(string hd) { 
  string this_file, temp;
  string *temp2, file2;
  int i;
  if(!hd) {
    notify_fail("You must give a title.\n");
    return 0; 
  }
  if(!this_player()->secure(SECURITY_ACCESS)) {
    notify_fail("Only a creator may place notes here.\n");
    return 0;
  }

  if(new_author && environment(new_author) == environment()) {
    write((string)new_author->query_name() +" is busy writing.\n"); 
    return 1; 
  } 
  if(sizeof(bulletins) == 30) { 
    write("Removing old notices first.\n");
    temp2 = explode(save_file, "/");
    file2 = "/log/boards/"+temp2[sizeof(temp2)-1];
    for (i = 0 ; i < 5 ; i++) {
write_file(file2,bulletins[i][0]+"\n"+bulletins[i][1]+"\n***\n"+
bulletins[i][2]+"\n");
    }
      bulletins = bulletins[0..-1]+
        bulletins[sizeof(bulletins)-25..sizeof(bulletins)-1];
    if(save_file) save_object(save_file);
  } 
  if(strlen(hd) > 50) { 
    write("Too long header to fit the paper.\n"); 
    return 1; 
  } 
  hd = (string)this_player()->filter_ansi(hd); /* all headers filtered */
  new_author = this_player();  
  new_header = hd +"..............................................";
  new_header = extract(new_header,0,33);
  new_header += "["+ capitalize(REAL)+"                         ";
  new_header = extract(new_header,0,43);
  new_header += " "+ TIME +"]";
  clone_object(EDITOR)->edit("add_message",0,1);
  return 1; 
} 

/**************************************************************************/
/* read notice */

status read(string str) { 
  int i, k; 
  object pager_ob; 

  if(!str || (sscanf(str, "%d", i) && sscanf(str, "note %d", i))) { 
    if(query_verb() == "clip") 
      notify_fail("Usage: clip <note number>\n");
    return 0;
  }
  if(i < 1 || i > sizeof(bulletins)) { 
    notify_fail("Not that number of messages.\n"); 
    return 0; 
  }
  i -= 1;
  say(NAME +" reads a note titled '"+ bulletins[i][HEADER] +"'.\n"); 
  if(query_verb() == "clip") {
    str = bulletins[i][MESSAGE];
  }
  else if(this_player()->ansi_on()) {
    str = bulletins[i][MESSAGE] + OFF;
  }
  else {
    str = (string)this_player()->filter_ansi(bulletins[i][MESSAGE]);
  }
  if(query_verb() == "clip") {
    rm(PASTE);
    write("The note is titled '" + bulletins[i][HEADER] + 
          "' has been copied to your Clipboard.\n"); 
    write_file(PASTE, str);
  }
  else {
    write("The note is titled '" + bulletins[i][HEADER] + "':\n\n"); 
#ifdef PAGER
    pager_ob = clone_object(PAGER);
    move_object(pager_ob, this_player());
    pager_ob->page(str);
#else
    write(str); 
#endif
  }
  return 1; 
} 
 

status remove(string str) { 
  int i, j, k; 
 
  if(!str || !(sscanf(str, "%d,%d", i, j) || sscanf(str, "note %d", i)
  || sscanf(str, "%d", i))) {
    notify_fail("remove <number>\nremove <number1,number2>\n");
    return 0; 
  }
  if(i < 1 || i > sizeof(bulletins)) { 
    notify_fail("Not that number of messages.\n"); 
    return 0; 
  }
  if(j < i) j = i;
  if(j > sizeof(bulletins)) j = sizeof(bulletins);
  for(i -= 1, j -= 1; j >= i; j--) {
    if(!(this_player()->id(bulletins[j][AUTHOR]) ||
         this_player()->query_security_level())) {
       write("Sorry, you will have to ask a creator to remove the message "+
             (j+1) +"for you.\n");
       continue;
    }
    say(NAME +" removed a note titled '"+ bulletins[j][HEADER] +"'.\n"); 
    write("You remove the note "+ bulletins[j][HEADER] +"...\n");
    bulletins = bulletins[0..j-1]+bulletins[j+1..sizeof(bulletins)-1];
  }
  if(save_file) save_object(save_file);
  update_desc();
  return 1;
} 


status id(string str) { 
  return str == "board" ||
         str == "bulletin board";
}

status set_creator_only(status arg) { return SECURITY_ACCESS = arg; }
