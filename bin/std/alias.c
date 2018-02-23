#include <mudlib.h>
#include <player.cfg>

#define TP this_player()

void remove_alias(string str, string *alias_commands);

status alias (string str) {
    string com, tmp1, tmp2, *alias_commands;
    int i;

    alias_commands = TP->query_alias_commands();
    if(!str) {
     write("Aliases: ");
     for(i = 0; i < sizeof(alias_commands); i += 2) {
	 if(i) write("         ");
	 write(alias_commands[i]+": "+alias_commands[i+1]+"\n");
     }
     if(!sizeof(alias_commands)) write("None.\n");
     return 1;
    }
    if(!sscanf(str,"%s %s",str,com)) {
     remove_alias(str, alias_commands);
     write("Alias: "+str+" removed.\n");
     return 1;
    }
    if(!sscanf(com,"%s %s",tmp1,tmp2)) {
     tmp1 = com;
    }
    if(str == tmp1) {
     write("Error: Tautological alias.\n");
     return 1;
    }
    if(!(member_array(tmp1,alias_commands)%2)) {
     write("Error: Cannot have an alias calling an alias.\n");
     return 1;
    }
    if(!((i = member_array(str,alias_commands))%2)) {
     alias_commands[i+1] = com;
    }
    else {
     if(sizeof(alias_commands) >= MAX_ALIAS_COMMANDS * 2) {
	 write("You can only have "+MAX_ALIAS_COMMANDS+" aliases.\n");
	 return 1;
     }
     alias_commands += ({ str, com, });
    }
    write("New Alias: "+str+" -> "+com+"\n");
    TP->set_alias_commands(alias_commands);
    return 1;
}

void remove_alias(string str, string *alias_commands) {
    int i;
    if((i = member_array(str,alias_commands)) != -1) {
     if(i%2) {
	 write("Error in Removing Alias.\nAttempting Fix....\n");
	 remove_alias(alias_commands[i-1], alias_commands);
	   return;
       }
	 alias_commands = alias_commands[0..i-1]
	 + alias_commands[i+2..sizeof(alias_commands)-1];
    }
    TP->set_alias_commands(alias_commands);
}
