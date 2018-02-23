#include <mudlib.h>

#define TP this_player()

string plan;
string set_plan(string s) { return TP->set_plan(s); }

status plan() {
  object editor;

#ifdef EDITOR
  editor = clone_object(EDITOR);
  move_object(editor, TP);
  write("Enter your plan. ");
  plan = TP->query_plan();
  editor->edit("set_plan",plan);
  return 1;
}


/* editor quit */

void editor_quit(string arg) {
  switch(arg) {
    case "set_plan":
      write("Plan unchanged.\n");
    break;
  }
}

#else
    plan = TP->query_plan();
    write("Your Old Plan:\n"+plan);
    line = 1;  
    new_text = "";  
    input_to ("chfn4");  
    write ("Enter your plan.  End with '**', abort with '~q'.\n");  
    write ("1] ");  
}  

static void chfn4(string arg) {  
    if(arg == "~q") {  
     write ("Plan aborted.\n");  
     return;  
    }  
    if(arg == "**") {  
     plan = new_text;  
     write("New Plan:\n"+((plan == "") ? "Cleared" : plan)); 
     TP->set_plan(plan);
     return;  
    }  
    new_text = new_text+arg+"\n";  
    write (++line+"] ");  
    input_to("chfn4");  
}  
#endif /* EDITOR */
