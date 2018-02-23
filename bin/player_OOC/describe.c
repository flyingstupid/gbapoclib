#include <mudlib.h>

#define TP this_player()

string description;

string set_description(string des) { return (string)TP->set_description(des); }
status describe() {  
  object editor;

  if(TP->query_ghost()) {  
    write ("You are in an immaterial state with no description.\n");  
    return 1;  
  }  
#ifdef EDITOR
  write("Enter your character's description.\n");
  editor = clone_object(EDITOR);
  move_object(editor, TP);
  editor->edit("set_description", description);
  TP->set_description(description);
  return 1;
}

#else
  line = 1;  
  new_text = "";  
  input_to ("get_desc");  
  write ("Enter your description.  End with '**', abort with '~q'.\n");  
  write ("1] ");  
  TP->set_description(description);
  return 1;  
}  

static void get_desc(string arg) {  
  if(arg == "~q") {  
    write ("Description aborted.\n");  
    return;  
  }  
  if(arg == "**") {  
    description = new_text;  
    write("New description:\n"+((description == "") ? "Cleared" : description)); 
    return;
  }  
  new_text = new_text+arg+"\n";  
  write (++line+"] ");  
  input_to ("get_desc");  
}  

#endif /* EDITOR */
