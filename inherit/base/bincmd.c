#include <mudlib.h>
#include <bad_file.h>

string *cmd_paths;
mapping env_vars;

status add_path(string str) {
 int file_exists;

 if(!str) return 0;

  if(member(cmd_paths, str) == -1) {
    file_exists = file_size(str);
    if(file_exists != -2) {
      notify_fail("That path does not exist.\n");
      return 0;
    }
    if(file_size(str+"/access.c") > 0) {
      if(!call_other(str+"/access.c", 
		"valid_read",
		(string)this_object()->query_name(1),
		(int)this_object()->query_security_level())) {
        write("Error: No access to that bin directory.\n");
        return 0;
      }
    }

    cmd_paths += ({ str });
    if((int)this_player()->query_security_level()) {
      printf("You add %s to your command path.\n",str);
//      printf("%O\n",cmd_paths);
    }
    return 1;
  }

  else {
    notify_fail("You already have that path!\n");
    return 0;
  }
}


status remove_path(string str) {
  if(!str) return 0;
  if(member(cmd_paths, str) >= 0) {
    cmd_paths -= ({ str });
    if((int)this_player()->query_security_level()) {
      printf("You remove %s from you command path.\n",str);
      printf("%O\n",cmd_paths);
    }
    return 1;
  }
  else {
    notify_fail("You do not have that path!\n");
    return 0;
  }
}



string *query_paths() { return cmd_paths; }

status set_env_var(string str) {
  string var, val;

  if(!env_vars) env_vars = ([]);

  if(sscanf(str, "%s %s", var, val) == 2) {
    if(member(env_vars, var)) {
      env_vars -= ([ var ]);
      env_vars += ([ var: val ]);
      printf("Environment variable %s changed to %s.\n", var, val);
      return 1;
    }
    env_vars += ([ var: val ]);
    printf("Environment variable %s set to %s.\n",var, val);
    return 1;
  }
  else {
    if(member(env_vars, var)) {
      env_vars -= ([ var ]);
      env_vars += ([ var: val ]);
      printf("Environment variable %s already set.\n", var);
      return 1;
    }
    env_vars += ([ var: val ]);
    printf("Environment variable %s set.\n",var);
    return 1;
  }
}


status unset_env_var(string str) {
  if(!env_vars) env_vars = ([]);
  if(member(env_vars, str)) {
    env_vars -= ([ str ]);
    printf("Environment variable %s unset.\n",str);
    return 1;
  }
  else {
    printf("No such variable '%s'.\n",str);
    return 1;
  }
}



mapping query_env_var(string str) {
  if(!env_vars) env_vars = ([]);
  return (member(env_vars, str)) ? env_vars[str,0] : 0;
}

mapping query_env_vars() { return env_vars; }

void recalc_sk() {
  string *dirs;
  int i;
  string *tmp;

  dirs = ({ });
  cmd_paths = ({ });
  tmp = (string *)this_object()->query_classes();
  if(sizeof(tmp))
    for(i=0; i<sizeof(tmp); i++) 
      add_path("/bin/skills/classes/"+ tmp[i] +"/");

  tmp = (string *)this_object()->query_affiliations();
  if(sizeof(tmp))
    for(i=0; i<sizeof(tmp); i++) 
      add_path("/bin/skills/affils/"+ tmp[i] +"/");

  if(this_object()->query_security_level())
    add_path("/bin/creator/");
  add_path("/bin/player/");
  add_path("/bin/std/");
}
