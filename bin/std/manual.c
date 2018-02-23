#include <mudlib.h>

#define MANUAL_DAEMON	"/function/manuals"
#define MANUAL_DIR	"/data/manuals"
#define MANUAL_HELP	"/data/manuals/manhelp"
#define HELP_DAEMON	"/bin/std/help"
#define SEC_ACCESS	(int)this_player()->query_security_level()


status manual(string str) {
  string categories;
  string filename;
  string file;
  int i, count;
  string *list;
  string tmp, txt;
  string tmp1, tmp2;
  object pager;

  tmp = "";
  txt = "";
  categories = "";

  if(!str) {
    write("Usage: man <category|manual file>\n"); 
    HELP_DAEMON->help("manuals");
    return 1;
  }

  if(str == "manuals") {
    txt = read_bytes(MANUAL_HELP);
    write(txt);

    txt = (string)MANUAL_DAEMON->write_manuals(1);
    
    pager = clone_object(MORE_OB);
    move_object(pager, this_player());
    pager->more(txt);
    return 1;
  }



  filename = (string)MANUAL_DAEMON->query_manual(str);

  if(file = (string)MANUAL_DAEMON->query_manual_type(str)) {
    if(file == "creator manual" && !SEC_ACCESS) {
      notify_fail("No access to Creator Manuals\n");
      return 0;
    }
    
    if(file == "sub-category") {
      list = get_dir(filename +"/");
      write("\t"+ capitalize(file) +": "+filename+"\n\n");
      for(i=sizeof(list); i--;) {
        if(MANUAL_DAEMON->query_manual_type(list[i]) == "sub-category")
          categories += " "+ list[i] +"\n";
        else if(sscanf(list[i], "%s.wiz", tmp1))
          tmp = " "+ tmp1 +"                            ";
        else if(sscanf(list[i], "%s.man", tmp2))
          tmp = " "+ tmp2 +"                            ";
        else
          tmp = " "+ list[i] +"                         ";
        tmp = extract(tmp,0,24);
        txt += tmp;
        count += 1;
        if(count > 2) {
          count = 0;
          txt += "\n";
        }
      }
      write(txt+"\n");
      write("\tSub-categories for "+capitalize(str)+":\n"+categories+"\n");
      return 1;
    }

    write("Category file: "+ filename +"\n\n");
    txt = filename; /* was txt = read_file(filename); for the pager */
    pager = clone_object(MORE_OB);
    move_object(pager, this_player());
    pager->more(txt);
    return 1;
  }
  notify_fail("Man <file> ?\n");
  return 0;
}
    
