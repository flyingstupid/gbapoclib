#include <mudlib.h>

#define TP this_player()

string set_plan(string s) { return TP->set_plan(s); }
string plan;

status chfn() {   
    write("Place a '!' at the end if you do not wish players to see this.\n");
    write("What is your real name? [Old: "+TP->query_realname()+"]\nNew Name: ");  
    input_to("chfn2");  
    return 1;  
}  

static void chfn2(string str) {  
    if(!str || str == "") {
     write("Real name not changed.\n");
     return;
    }
    write("Real Name changed: "+(TP->set_realname(str))+"\n");
    write("Place a '!' at the end if you do not wish players to see your "+
          "eMail address.\n");
    write("What is your email address? [Old: "+TP->query_email()+"]\nNew Address: ");  
    input_to("chfn3");  
}  

static void chfn3(string str, status plan_only) {
    object editor;

    if(!plan_only) {
     if(!str || str == "") {
	 write("eMail address not changed.\n");
	 return;
     }
     write("eMail address changed: "+(TP->set_email(str))+"\n");  
    }
#ifdef EDITOR
    editor = clone_object(EDITOR);
    move_object(editor, TP);
    write("You may now change your plan.\n");
    plan = TP->query_plan();
    editor->edit("set_plan",plan);
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
