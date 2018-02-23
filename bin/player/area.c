#include <mudlib.h>

varargs area(status arg) {
  string tmp1, tmp2, tmp3;
  string wiz_name;
  object env;
  string file;

  env = (object)environment(this_player());
  file = file_name(env);
  if(sscanf(file, "%s/w/%s/%s", tmp1, wiz_name, tmp3)==3) {
    if(!arg)
      write("You are in a virtual environment created by "+
    capitalize(wiz_name) +".\n");
    return (arg) ? wiz_name : 1;
  }
  else if(sscanf(file, "players/%s/%s", wiz_name, tmp2)==2) {
    if(!arg)
      write("You are in a virtual environment created by "+
    capitalize(wiz_name)+".\n");
    return (arg) ? wiz_name : 1;
  }
  if(!arg)
    write("You are in a general virtual environment.\n");
  return (arg) ? 0 : 1;
}


