#define ACCESS_D "secure/security"
#define CALLER_NAME this_player()->query_real_name()
#define CREATOR "usr/creators/"

int chmod(string arg)
{
  string  str, name, rights, a1, a2;
  string  new_access, file, new_type;
  int     tmp;
  string  *permissions;
  int     i;
  string  outstr;
  string  tempstr;
  int     return_code;

  if(!arg)
  {
    permissions = ACCESS_D -> query_permissions(CALLER_NAME);
    if(!permissions || sizeof(permissions) == 0)
    {
      write("\nNo outstanding permissions.\n\n");
    }
    else
    {
      outstr="\nName             Path                            Access\n";
      outstr+="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
      for(i=0; i<sizeof(permissions); i+=3)
      {
        tempstr = capitalize(permissions[i]);
        tempstr += "                                                       ";
        tempstr = extract(tempstr,0,16);
        outstr += tempstr;
        tempstr = permissions[i+1];
        tempstr += "                                                       ";
        tempstr = extract(tempstr,0,31);
        outstr += tempstr;
        tempstr = permissions[i+2];
        tempstr += "                                                       ";
        tempstr = extract(tempstr,0,4);
        outstr += tempstr + "\n";
      }
      write(outstr+"\n");
    }
    return 1;
  }

  if (sscanf(arg, "%s %s", name, rights) != 2)
  {
    notify_fail("## Syntax: chmod <name> <+/-> <write/read>\n"+
                "##         chmod\n"+
                 "## You must be in the directory to be altered.\n");
    return 0;
  }

  if (sscanf(rights, "%s %s", a1, a2) == 2)
  {
    new_access = a2;
     new_type = " "+a1;
    if (sscanf(new_type, "%s+%s", str, arg) == 2)
    {
      tmp = 1;
    }
    else if (sscanf(new_type, "%s-%s", str, arg) == 2)
    {
      tmp = 2;
    }
    else
    {
      write("## Syntax: chmod <name> <+/-> <write/read>\n"+
            "##         chmod\n"+
            "## You must be in the directory to be altered.\n");
      return 1;
    }
  }
   else 
  {
    write("## Syntax: chmod <name> <+/-><write/read>\n"+
          "##         chmod\n"+
          "## You must be in the directory to be altered.\n");
    return 1;
  }

  if(file_size(CREATOR+name+".o") == -1)
  {
    write(capitalize(name)+" is not a valid creator name.\n");
    return 1;
  }

  if (a2 != "read" && a2 != "write")
  {
    write("## Unknown option. Options are: <read> or <write>\n");
    return 1;
  }

  file = "/" + (string)this_player()->query_path();

  if(tmp == 1)
  {
    return_code = (int)call_other(ACCESS_D, ((a2 == "read") ? "add_player_read" : "add_player_write") , name, file);
    switch(return_code)
    {
      case 0:
        write("You are not the owner of " + file + ".\n");
        break;
      case 1:
        write(file + " -> " + name + "+" + a2 + ": Ok.\n");
        break;
      case 2:
        write("Permission does not exist.\n");
    }
    return 1;
  }
  if(tmp == 2)
  {
    return_code = (int)call_other(ACCESS_D, ((a2 == "read") ? "remove_player_read" : "remove_player_write") , name, file);
    switch(return_code)
    {
      case 0:
        write("You are not the owner of " + file + ".\n");
        break;
      case 1:
        write(file + " -> " + name + "-" + a2 + ": Ok.\n");
        break;
      case 2:
        write("Permission does not exist.\n");
    }
    return 1;
  }
  return 0;
}
