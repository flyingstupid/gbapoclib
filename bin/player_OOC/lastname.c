#include <mudlib.h>

#define TP this_player()

string lastname;

status lastname() {
  if(TP->query_level() < 10) {
    write("You are not of high enough level to have earned a last name!\n");
    return 1;
  }
  lastname = TP->query_lastname();
  if(strlen(lastname)) {
    write("You already have a family name.\n");
    return 1;
  }


  write("A last name is as much a title as it is an identifier of your \n"+
        "roleplaying activities in the mud. Some characters who enjoy  \n"+
        "slaying goblins have known to use the name 'goblinbane', and  \n"+
        "for a paladin's heart was as strong as the metal it was named \n"+
	"for, Maddison 'Steel'.\n\n"+
	"Choosing a last name is an important step within the mud. To  \n"+
	"continue, enter your choice for your last name. To quit, enter\n"+
	"'~q' and it will not be set. > ");
  input_to("lastname2");
  return 1;
}

status lastname2(string str) {
  if(!str || str == "" || str == "~q") {
    write("Lastname aborted.\n");
    return 1;
  }
  write("Your family name/last name has been set to '"+str+"'.\n");
  lastname = capitalize(str);
  TP->set_lastname(lastname);
  return 1;
}
