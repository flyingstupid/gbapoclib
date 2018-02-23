/*
 * File:    /std/daemons/help_d.c
 * Date:    January 1999, Sarak.
 * Purpose: This daemon reads and interprets help files and is the only
 *          interface to the help system for the help command.  The help
 *          files use a special format to allow for easy modification of
 *          help data.  The data is stored in a cache mapping once converted
 *          by the help system to avoid unnecessary conversions.  The cache
 *          is automatically updated whenever it finds a help file's
 *          modification date is later than the time its data was cached.
 *
 * History: 09/03/02, Sarak: Converted the help daemon from the archived
 *                           FDM: Castinian lib into the Heaven7 lib.  This
 *                           updates the previous copy Heaven7 was using.
 *                           NOTE: No further history is available for this
 *                           file at this time.
 *          
 */

#include <help.cfg>
#include <list_array.h>

#define max_width 75

#define FIELDS ([ \
          "#T!" : ({ "TOPIC\n", 1, }), \
          "#S!" : ({ "SYNOPSIS\n", 1, }), \
          "#D!" : ({ "DESCRIPTION\n\n", 1 }), \
          "#E!" : ({ "EXAMPLE\n\n", 0, }), \
          "#N!" : ({ "NOTES\n\n", 1, }), \
          "#R!" : ({ "ERRORS\n", 1, }), \
          "#B!" : ({ "BUGS\n\n", 1, }), \
          "#H!" : ({ "HISTORY\n\n", 1, }), \
          "#W!" : ({ "AUTHOR\n\n", 1, }), \
          "#A!" : ({ "SEE ALSO: ", 0, }), \
])

#define EOF_MARK "#C!"
#define SEE_ALSO_MARK "#A!"

mapping help_cache;  // The cache mapping.
string *help_dirs;   // The directories where help files are located.

/*
 * Function: update_dirs()
 * Date:     January 1999, Sarak.
 * Purpose:  This function searches the HELP_DIR directory and locates all
 *           directories within it.  Each of these are then put into an
 *           array called help_dirs.  The strings in the array are all
 *           relative to HELP_DIR.
 *
 * History:
 */

void update_dirs() {
  string *dirs_found, *search;
  mixed *tmp;
  int i, j;

  // First, we get the initial search underway
  search = ({ });
  tmp = get_dir(HELP_DIR+"/");
  for(i = 0; i < sizeof(tmp); i++)
    if(file_size(HELP_DIR + "/" + tmp[i]) == -2)
      search += ({ tmp[i] });
  dirs_found = search;
  while(sizeof(search)) {
    tmp = get_dir(HELP_DIR+"/"+search[0]+"/");
    for(i = 0; i < sizeof(tmp); i++) {
      if(file_size(HELP_DIR + "/" + search[0] + "/" + tmp[i]) == -2) {
        search += ({ search[0] + "/" + tmp[i] });
        dirs_found += ({ search[0] + "/" + tmp[i] });
      }
    }
    search = search[1..sizeof(search)-1];
  }
  help_dirs = dirs_found;
}

/*
 * Function:  disp_topic
 * Date:      January 1999, Sarak.
 * Purpose:   This function displays the relevant text for the topic arg.
 *            arg must point to the default description file within the
 *            topic's directory - typically the file will be called
 *            'default'.  The contents of the file and the help files within
 *            it are returned as a string.
 *
 * History:
 */

string disp_topic(string arg) {
  string tmp, tmp2, tmp3, dir, *files, *arr;
  int i;

  if(!(tmp = read_file(arg))) return 0;
  tmp += "\n";
  sscanf(arg, "%s"+DEFAULT, dir);
  files = get_dir(dir+"/");
  arr = explode(arg, "/");
  tmp3 = "-=[ "+implode(explode(capitalize(arr[sizeof(arr)-2]), "-"), " ")+
    " Category Help ]=-";
  tmp2 = "                                                      ";
  tmp2 = extract(tmp2, 0, (max_width - strlen(tmp3))/2);
  tmp = tmp2+tmp3+"\n\n"+tmp;
  arr = ({ });
  for(i = 0 ; i < sizeof(files) ; i++) {
    if(sscanf(files[i], "%s"+FILE_EXT, tmp3) == 1) {
      tmp3 = implode(explode(tmp3, "-"), " ");
      tmp3 = implode(explode(tmp3, "  "), "-");
      arr += ({ tmp3 });
    }
  }
  if(sizeof(arr)) tmp += "Available Topics :-\n\n"+list_array(arr);
  arr = ({ });
  for(i = 0 ; i < sizeof(files) ; i++) {
    if(file_size(dir+files[i]) == -2) {
      files[i] = implode(explode(files[i], "-"), " ");
      files[i] = implode(explode(files[i], "  "), "-");
      arr += ({ files[i] });
    }
  }
  if(sizeof(arr)) tmp += "\nSub Categories :-\n\n"+list_array(arr);
  return tmp;
}

/*
 * Function:  validate_help
 * Date:      January 1999, Sarak.
 * Purpose:   This function takes an array of strings, each of which point
 *            to a help file.  It then filters out any help files that are
 *            restricted to the character requesting the help.  A modified
 *            array of strings is returned.
 *
 * History:
 */

string * validate_help(string *arr) {
  string *valid, tmp, class, *classes;
  int i, j, check;

  valid = ({ });
  for(i = 0 ; i < sizeof(arr) ; i++) {
    check = 0;
    for(j = 0 ; j < sizeof(RESTRICTED_DIRS) ; j++)
      if(sscanf(arr[i], HELP_DIR+"/"+RESTRICTED_DIRS[j]+"/%s", tmp) == 1)
        if(this_player()->query_security_level() > 0) check = 1;
    if(!check) valid += ({ arr[i], });
  }
  return valid;
}

/*
 * Function:  convert_help_file
 * Date:      January 1999, Sarak.
 * Purpose:   This functions reads the file specified as arg and converts it
 *            from the help file format into normal text.  The converted
 *            text is then returned as a string.
 *
 * History:
 */

string convert_help_file(string arg) {
  string *buf, tot, *arr, tmp;
  int i, j, indent_flag;

  tot = "";
  buf = explode(read_file(arg), "\n");
  
  for (i = 0; i < sizeof(buf); i++) {
    if(buf[i] == EOF_MARK) break;

    if(FIELDS[buf[i]]) {
      if(!FIELDS[buf[i+1]]) {
        if(strlen(tot)) tot += "\n";
        tot += FIELDS[buf[i]][0];
        indent_flag = FIELDS[buf[i]][1];
        if(buf[i] == SEE_ALSO_MARK) {
          i++;
          arr = explode(buf[i], "|");
          tmp = "";
          for (j = 0; j < sizeof(arr); j++) {
            if(strlen(arr[j])) {
              if(strlen(tmp+(j ? ", " : "")+arr[0]) > max_width) {
                tot += tmp+",\n";
                tmp = "          "+arr[j];
              } else
                tmp += (j ? ", " : "")+arr[j];
            }
          }
          tot += tmp+".\n";
        }
      }
    } else {
      if(indent_flag) tot += INDENT;
      tot += buf[i]+"\n";
    }
  }
  return tot;
}

/*
 * Function: help_string
 * Date:     January 1999, Sarak.
 * Purpose:  This function takes a string as its first argument and an
 *           integer as its second.  If the second optional argument is
 *           specified, the first argument will be considered the absolute
 *           path to the help file required.  This file while then be
 *           converted and returned as the first and only element in an
 *           array.  If the second argument is not specifiedm all help
 *           categories available to the requesting character will be 
 *           searched for a matching name.  If more than one is found,
 *           the path to each will be returned as elements in an array.
 *           If only one is found, it will be converted (or taken from
 *           cache and returned as the first and only element in an array.
 *
 * History:
 */

varargs string * help_string(string arg, int option) {
  string help_file, help_data, *flist, *results, tmp, tmp2;
  string *sub_files, *ext, orig, *arr;
  int i, j, k;

  help_file = HELP_DIR+"/"+arg+FILE_EXT;
  if(!help_cache) help_cache = ([ ]);
  if(!help_dirs) update_dirs();
  orig = arg;
  arg = implode(explode(arg, "-"), "--");
  arg = implode(explode(arg, " "), "-");

  results = ({ });

  if(!option) {
    if(member_array(arg, help_dirs) != -1)
      results += ({ HELP_DIR+"/"+arg+"/"+DEFAULT, });
    for(i = 0 ; i < sizeof(help_dirs) ; i++) {
      if(file_size(HELP_DIR+"/"+help_dirs[i]+"/"+arg) == -2)
        results += ({ HELP_DIR+"/"+help_dirs[i]+"/"+arg+"/"+DEFAULT, });
      if(file_size(HELP_DIR+"/"+help_dirs[i]+"/"+arg+FILE_EXT) >= 0)
        results += ({ HELP_DIR+"/"+help_dirs[i]+"/"+arg+FILE_EXT, });
    }
  } else {
    results = ({ arg, });
    if(sscanf(arg, "%s"+FILE_EXT, arg) == 1) {
      arr = explode(arg, "/");
      orig = arr[sizeof(arr)-1];
    }
  }
  results = validate_help(results);
  if(!sizeof(results)) {
    notify_fail("No help on that topic.\n");
    return 0;
  }
  if(sizeof(results) == 1) {
    help_file = results[0];

    if(sscanf(help_file,"%s"+DEFAULT, tmp) == 1)
      return ({ disp_topic(help_file), });

    if(file_size(help_file) == -1) {
      notify_fail("No help on that topic.\n");
      return 0;
    }
    if(!help_cache[help_file] ||
       help_cache[help_file][0] < file_time(help_file))
      help_cache[help_file] = ({ file_time(help_file),
                                 convert_help_file(help_file) });

    help_data = help_cache[help_file][1];

    if(sscanf(help_data, "%sSEE ALSO: %s.\n%s", help_data, tmp, tmp2) == 3) {
      tmp = implode(explode(tmp, "\n          "), " ");
      arr = explode(tmp, ", ");
      flist = ({ });
      for(i = 0 ; i < sizeof(arr); i++) {
        arr[i] = implode(explode(arr[i], " "), "-");
        if(member_array(arr[i], help_dirs) != -1)
          flist += ({ HELP_DIR+"/"+arr[i]+"/"+DEFAULT, });
        for(j = 0 ; j < sizeof(help_dirs) ; j++) {
          if(file_size(HELP_DIR+"/"+help_dirs[j]+"/"+arr[i]) == -2)
            flist += ({ HELP_DIR+"/"+help_dirs[i]+"/"+arr[i]+"/"+DEFAULT, });
          if(file_size(HELP_DIR+"/"+help_dirs[j]+"/"+arr[i]+FILE_EXT) >= 0)
            flist += ({ HELP_DIR+"/"+help_dirs[j]+"/"+arr[i]+FILE_EXT, });
        }
      }
      flist = validate_help(flist);
      arr = ({ });
      for(i = 0 ; i < sizeof(flist) ; i++) {
        if(sscanf(flist[i], "%s"+FILE_EXT, tmp) != 1)
          sscanf(flist[i], "%s/"+DEFAULT, tmp);
        sub_files = explode(tmp, "/");
        if(member_array(sub_files[sizeof(sub_files)-1], arr) == -1)
          arr += ({ sub_files[sizeof(sub_files)-1] });
      }
      for(i = 0 ; i < sizeof(arr) ; i++)
        arr[i] = implode(explode(arr[i], "-"), " ");
      if(sizeof(arr)) {
        tmp = "SEE ALSO: ";

        for(i = 0 ; i < sizeof(arr) ; i++)
          if(strlen(arr[i]))
            if(strlen(tmp+(i ? ", " : "")+arr[0]) > max_width) {
              help_data += tmp+",\n";
              tmp = "          "+arr[i];
            } else
              tmp += (i ? ", " : "")+arr[i];
        help_data += tmp+".\n"+tmp2;
      } else
        help_data += tmp2;
    }
    tmp = "-=[ "+capitalize(orig)+" ]=-";
    tmp2 = "                                                              ";
    tmp2 = extract(tmp2, 0, (max_width-strlen(tmp))/2);
    help_data = tmp2+tmp+"\n\n"+help_data;
    help_data += "\nLast Updated: "+ctime(file_time(help_file))+".\n";
    sscanf(help_file, HELP_DIR+"/"+"%s"+FILE_EXT, tmp);
    ext = explode(tmp, "/");
    if(sizeof(ext) < 2) return 0;
    help_data += "Category: "+capitalize(implode(explode(ext[sizeof(ext)-2],
       "-"), " "))+" help.\n";
    return ({ help_data, });
  } else {
    return results;
  }
}

