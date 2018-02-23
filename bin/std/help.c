#include <mudlib.h>
#include <rtlimits.h>
inherit BASE;


#include <bad_file.h>

/* 
   help calls this_player() for valid_help(subtopic)
   if it returns 1 the player will see help

 */

#define DEFAULT_FILE      "misc.hlp"
#define DEFAULT_SUBTOPIC  "general"
#define HELP_DIR          "/data/help/"
#define MANUAL_DIR        "/data/manuals/"
#define MANUAL_DAEMON	  "/function/manuals"
#define DELIMITER         "^#^\n"
#define MAX_LENGTH        4000   /* max. characters in help text */
#define MAX_READ_BYTE     8192   /* read file in 8 KB blocks */
#define FILE_SIZE(X)      (int)MASTER->master_file_size(X)

/* position offset */

#define TOPIC    0
#define SUBTOPIC 1
#define HELP_TXT 2

/* error codes */

#define NO_HELP      0
#define READ_ERROR   1
#define TOPIC_EXISTS 2
#define CORRUPT      3
#define OVERSIZE     4
#define NO_ACCESS    5
#define CAT_ERROR    6

void reset(status arg) {
  if(arg) return;
  set_name("help");
  set_alt_name("help maker");
  set_short("Help Maker");
  set_long(
"                    -=[ Help Maintainer ]=-\n\n"+
"help [topic]                                     Show Help\n"+
"convert [file] [topic name] [<topic category>]   File->Help Data\n"+
"hdir [directory] [category]                      Dir->Help Data\n"+
"ut                                               Update All Categories\n"+
"uh [file] [topic]                                Update Help Data\n"+
"extract [file] [topic]                           Help Data->File\n"+
"del [topic]                                      Delete Help Data\n"+
"delcat [category]                                Delete a Category\n");
}


void init() {
  add_action("help","help");
  add_action("convert","convert");
  add_action("convert_dir","hdir");
  add_action("update","ut");
  add_action("ext", "extract");
  add_action("uh","uh");
  add_action("delete_topic","del");
  add_action("delete_category","delcat");
}
  
status get() { return 1; }

status drop(status arg) { return 1; }

/************************************************************************/
/* error codes */

string help_error(int code) {
  string s = ({ 
     "No Help is Available.\n",
     "Error Reading File.\n",
     "Topic Already Exists.\n",
     "Help File Corrupt\n",
     "Help File too large to convert.\n",
     "Help File is not relevant to you.\n",
     "Error in Category File.\n",
  })[code];
  notify_fail(s);
  return s;
}


/************************************************************************/
/* convert category files into subtopic data array */

string *load_subtopic_file(string file) {
  string *data, file_data, tmp;

  if(!(file_data = read_bytes(file,0,FILE_SIZE(file)))) {
    help_error(READ_ERROR);
    return ({});
  }
  while(sscanf(file_data,"%s\n\n%s",file_data,tmp)) file_data += "\n" + tmp;
  data = explode(file_data, "\n");
  if(data[sizeof(data)-1] == "") data = data[0..(sizeof(data)-2)];
  return data;
}


/*************************************************************************/
/* convert help data files into help data array */

string *load_help_file(string topic_file) {
  string help_data, *tmp_data, *topic_data;
  string subtopic;
  int fp, fp_end;

  for(topic_data = ({}), fp = 0; fp < FILE_SIZE(topic_file); fp += fp_end) { 
    fp_end = MAX_READ_BYTE;
    if(fp_end + fp > FILE_SIZE(topic_file)) fp_end = FILE_SIZE(topic_file)-fp;
    if(!(help_data = read_bytes(topic_file,fp,fp_end))) {
      help_error(READ_ERROR);
      return ({});
    }
    tmp_data = explode(help_data, DELIMITER);
    if(sizeof(tmp_data) < 2 && sizeof(topic_data) < 2) {
      help_error(CORRUPT);
      return ({});
    }
    if(sizeof(topic_data) > 1) {
      topic_data = topic_data[0..(sizeof(topic_data)-2)]
                 + ({ topic_data[sizeof(topic_data)-1] + tmp_data[0], });
    }
    if(sizeof(tmp_data) > 1) topic_data += tmp_data[1..(sizeof(tmp_data)-1)];
   
  }
  return topic_data;
}


/*************************************************************************/
/* get the help text from the help data files */

string query_help_string(string topic) {
  int position;
  object pager;
  string alpha, topic_file;
  string *help_data;
  string subtopic, *subtopic_list;


  alpha = topic[0..0];
  alpha = lower_case(alpha);
  if(alpha[0] < 'a' || alpha[0] > 'z') {    
    topic_file = HELP_DIR + DEFAULT_FILE;
  }
  else {
    topic_file = HELP_DIR + alpha + alpha + alpha +".hlp";
  }
  if(FILE_SIZE(topic_file) < 1) {
    help_error(NO_HELP);
    return 0;
  }
  if(!sizeof((help_data = load_help_file(topic_file)))) return 0;
  if((position = member_array(topic, help_data)) == -1) {
    help_error(NO_HELP);
    return 0;
  }
  if(position + HELP_TXT >= sizeof(help_data)) {
    help_error(CORRUPT);
    return 0;
  }
  sscanf(help_data[position+SUBTOPIC],"SUBTOPIC-%s",subtopic);
  subtopic_list = explode(subtopic,"/");
  if(!this_player()->valid_help(subtopic_list)) {
    help_error(NO_ACCESS);
    return 0;
  }
  return help_data[position+HELP_TXT] +"\nCategory: "+ subtopic +" help.\n";
}


/*************************************************************************/
/* get formated text from subtopic (category) data files */
 
string query_subtopic_string(string subtopic) {
  string tmp, *data, str;
  int i;
  object pager;

  sscanf(subtopic,"%s %s",subtopic,tmp);  
  if(bad_file(subtopic)) return 0;
  if(FILE_SIZE(HELP_DIR +"subtopic/"+ subtopic +".sub") < 1) {
    help_error(CAT_ERROR);
    return 0;
  }
  data = load_subtopic_file(HELP_DIR +"subtopic/"+ subtopic +".sub");
  if(!sizeof(data)) return 0;
  if(!this_player()->valid_help(({ subtopic, }))) {
    help_error(NO_ACCESS);
    return 0;
  }
  for(i = 0; i < sizeof(data); i++) {
    data[i] += "                                       ";
    data[i] = extract(data[i],0,24) +" ";
    if(!((i+1)%3)) data[i] += "\n";
  }
  str = "                      -=[ "+ capitalize(subtopic) +" Help ]=-\n\n";
  str += implode(data,"") +"\n";
  return str +"\nThere are "+ i +" topics in "+ subtopic +" help.\n";
}


/************************************************************************/
/* add a 'help' file to the help data files */

status convert_file(string file, string topic, string subtopic) {
  string alpha, topic_file, file_data, *subtopic_data;
  string *help_data, topic_txt, *subtopic_list;
  int i, position;
  int data_size;

  if(FILE_SIZE(file) > MAX_LENGTH) {
    help_error(OVERSIZE);
    return 0;
  }
  if(!(topic_txt = read_bytes(file,0,FILE_SIZE(file)))) {
    help_error(READ_ERROR);
    return 0;
  }
  if(!topic) {
    for(i = strlen(file)-1; file[i] != '/' && i; i--);
    topic = file[(i+1)..(strlen(file)-1)];
  }
  alpha = topic[0..0];
  alpha = lower_case(alpha);
  if(alpha[0] < 'a' || alpha[0] > 'z') {    
    topic_file = HELP_DIR + DEFAULT_FILE;
  }
  else {
    topic_file = HELP_DIR + alpha + alpha + alpha +".hlp";
  }
  if(!subtopic) subtopic = DEFAULT_SUBTOPIC;
  /* check help for same topic */

  help_data = load_help_file(topic_file);
  if((position = member_array(topic, help_data)) == -1) {
    write("Adding Topic....\n");
    write_file(topic_file, DELIMITER + topic 
                         + DELIMITER + "SUBTOPIC-"+ subtopic
                         + DELIMITER + topic_txt);
    subtopic_list = explode(subtopic, "/");
    for(i = 0; i < sizeof(subtopic_list); i++) {
     subtopic_data 
       = load_subtopic_file(HELP_DIR+"subtopic/"+subtopic_list[i]+".sub");
     if(member_array(topic, subtopic_data) != -1) break;
     subtopic_data += ({ topic, });
     write("Sorting "+ subtopic_list[i] +" category....\n");
     subtopic_data 
       = sort_array(subtopic_data,"alphabetical_order",this_object());
     file_data = implode(subtopic_data,"\n") +"\n";
     rm(HELP_DIR +"subtopic/"+ subtopic_list[i] +".sub");
     write_file(HELP_DIR +"subtopic/"+subtopic_list[i]+".sub", file_data);
    }
    write("Help Updated\n");
    return 1;
  }
  help_error(TOPIC_EXISTS);
  return 0;
}


/************************************************************************/
/* delete topic from help data files */

status delete_topic(string topic) {
  int position, i;
  object pager;
  string alpha, topic_file, txt;
  string *help_data, *data;
  string subtopic, *subtopic_list;


  alpha = topic[0..0];
  alpha = lower_case(alpha);
  if(alpha[0] < 'a' || alpha[0] > 'z') {    
    topic_file = HELP_DIR + DEFAULT_FILE;
  }
  else {
    topic_file = HELP_DIR + alpha + alpha + alpha +".hlp";
  }
  if(FILE_SIZE(topic_file) < 1) {
    help_error(NO_HELP);
    return 0;
  }
  help_data = load_help_file(topic_file);
  if(!sizeof(help_data)) return 0;
  if((position = member_array(topic, help_data)) == -1) {
    help_error(NO_HELP);
    return 0;
  }
  if(position + HELP_TXT >= sizeof(help_data)) {
    help_error(CORRUPT);
    return 0;
  }
  sscanf(help_data[position + SUBTOPIC],"SUBTOPIC-%s",subtopic);
  help_data = help_data[0..(position-1)]
            + help_data[(position+3)..(sizeof(help_data)-1)]; /* delete */
  rm(topic_file);
  for(i = 0; i < sizeof(help_data); i += 3) {
    txt = DELIMITER + implode(help_data[i..(i+2)],DELIMITER);
    write_file(topic_file,txt);
  }
  write("Deleted "+ topic +" from Help Data File.\n");
  subtopic_list = explode(subtopic, "/");

  for(i = 0; i < sizeof(subtopic_list); i++) {
    write("Updating "+ subtopic_list[i] +" Category....\n");
    if(FILE_SIZE(HELP_DIR +"subtopic/"+ subtopic_list[i] +".sub") < 1) {
      help_error(CAT_ERROR);
      return 0;
    }
    data = load_subtopic_file(HELP_DIR+"subtopic/"+subtopic_list[i]+".sub");
    if(!sizeof(data)) return 0;
    if((position = member_array(topic, data)) == -1) {
      help_error(CAT_ERROR);
      return 0;
    }
    data = data[0..(position-1)] + data[(position+1)..(sizeof(data)-1)];
    txt = implode(data, "\n") +"\n";
    rm(HELP_DIR +"subtopic/"+ subtopic_list[i] +".sub");
    write_file(HELP_DIR +"subtopic/"+ subtopic_list[i] +".sub", txt);
  }
  return 1;
}

// added by phaedrus so that we can quickly remove
// the old driver help docs
int delete_category(string cat) {
	string *list, *cats, tmp, cat_data, *categories;
	
	cats = list = categories = ({});
	
	if(!cat || cat == "") {
		write("That's certianly not a category!\n");
		return 1;
	}
	
	list = get_dir(HELP_DIR +"subtopic/.");
	foreach(string thing : list) {
	 if(sscanf(thing, "%s.sub", tmp) == 1)
	 		cats += ({ tmp });
	}
	if(member(cats, cat) != -1) {
		cat_data = read_file(HELP_DIR + "subtopic/"+cat+".sub");
		categories = explode(cat_data, "\n") - ({""});
		foreach(string s : categories) {
			//avoid eval costs
			limited(#'delete_topic, ({ 2000000 }), s);
		}
	}
	else {
		printf("%s is not a valid category name.\n", cat);
		return 1;
	}
	return 1;
}

/***************************************************************************/
/* update topic in help data files */

status update_topic(string topic, string txt) {
  int position, i;
  object pager;
  string alpha, subtopic, topic_file;
  string *help_data, *data;
  string *subtopic_list;


  alpha = topic[0..0];
  alpha = lower_case(alpha);
  if(alpha[0] < 'a' || alpha[0] > 'z') {    
    topic_file = HELP_DIR + DEFAULT_FILE;
  }
  else {
    topic_file = HELP_DIR + alpha + alpha + alpha +".hlp";
  }
  if(FILE_SIZE(topic_file) < 1) {
    help_error(NO_HELP);
    return 0;
  }
  help_data = load_help_file(topic_file);
  if(!sizeof(help_data)) return 0;
  if((position = member_array(topic, help_data)) == -1) {
    help_error(NO_HELP);
    return 0;
  }
  if(position + HELP_TXT >= sizeof(help_data)) {
    help_error(CORRUPT);
    return 0;
  }
  sscanf(help_data[position +SUBTOPIC],"SUBTOPIC-%s",subtopic);
  help_data[position + HELP_TXT] = txt; /* update help text */
  rm(topic_file);
  for(i = 0; i < sizeof(help_data); i += 3) {
    txt = DELIMITER + implode(help_data[i..(i+2)],DELIMITER);
    write_file(topic_file,txt);
  }
  write("Updated "+ topic +" in Help Data File.\n");
  return 1;
}


/**************************************************************************/
/* help command */

status invalid_help(string subtopic) {
  sscanf(subtopic,"%s.sub",subtopic);
  return (status)this_player()->valid_help(({ subtopic, }));
}

status help(string help, string helpdir) {
  string txt, tmp;
  string tmpDir;
  string tmp1, tmp2;
  string *list;
  int i;
  int count, C;
  object pager;

  if(!help) help = DEFAULT_SUBTOPIC;
  if(!(txt = query_subtopic_string(help))) {
    if(!(txt = query_help_string(help))) {
      return 0;
    }
  }
  if(helpdir) txt = "";

  switch(help) {
    case "categories":
    case DEFAULT_SUBTOPIC:
      list = get_dir(HELP_DIR +"subtopic/.");
      list = filter(list,"invalid_help",this_object());
      txt += "\nCategories Available:\n\n";
      for(i = 0; i < sizeof(list); i++) {
        if(sscanf(list[i], "%s.sub", tmp) == 1) {
          tmp += "                                       ";
          tmp = extract(tmp,0,24) +" ";
          txt += tmp;     
        }
        if(!((i+1)%3)) txt += "\n";
      }
      txt += "\n";
    break;

    case "manuals":
      MANUAL_DAEMON->write_manuals();

#ifdef OLD_MANUAL_SYSTEM
      if(helpdir) {
        tell_object(this_player(), 
	"Current manuals sub-category: "+ helpdir +"\n");
        this_player()->set_manual_dir(helpdir);
      }
      if(helpdir) 
        list = get_dir(MANUAL_DIR + helpdir +".");
      else
        list = get_dir(MANUAL_DIR +".");
      txt += "\nManuals available:\n\n";



      for(i = 0; i < sizeof(list); i++) {
        if(sscanf(list[i],"%s.man",tmp)) {
          tmp += "                                       ";
          tmp = extract(tmp,0,24) +" ";
          txt += tmp;
          count += 1;
        }
        if(this_player()->query_security_level()) {
          if(sscanf(list[i],"%s.wiz",tmp)) {
            tmp += "                                       ";
            tmp = extract(tmp,0,24) +" ";
            txt += tmp;
            count += 1;
          }
        }
        if(count >= 3) {
          count = 0;
          txt += "\n";
        }
      }
      txt += "\n";

      txt += "\nSub-categories available:\n\n";
      count = 0;
      for(i = 0; i < sizeof(list); i++) {
        if(helpdir) tmpDir = MANUAL_DIR+ helpdir;
        else tmpDir = MANUAL_DIR;
        if(FILE_SIZE(tmpDir + list[i] +"/") == -2) {
          if(sscanf(list[i], "%screator%s", tmp1, tmp2) &&
            !(int)this_player()->query_security_level()) continue;
            tmp = list[i] +"/                             ";
            tmp = extract(tmp,0,24) +" ";
            txt += tmp;
            count += 1;
            C = 1;
          if(count >= 3) {
            txt += "\n";
            count = 0;
          }
        }
      }
     if(!C) txt += "None.\n";

#endif /* OLD_STUFF */
    break;
  }

#ifdef PAGER
  pager = clone_object(PAGER);
  move_object(pager, this_player());
  pager->page(txt);
#else
  write(txt);
#endif /* PAGER */
  return 1;
}


/* convert command */

status convert(string str) {
  string file;
  string topic;
  string subtopic;

  if(!str || sscanf(str,"%s %s <%s>", file, topic, subtopic) != 3) {
    write("Usuage: convert [file] [topic name] [<category>]\n\n"+
          "    eg. convert heal.txt heal <cleric>\n");
    return 1;
  }
  file = (string)this_player()->make_path(file);
  return convert_file(file,topic,subtopic);
}


/* update help command */

status uh(string str) {
  string topic;
  string txt, file;

  if(!str || sscanf(str,"%s %s", file, topic) != 2) {
    write("Usuage: uh [file] [topic name]\n\n"+
          "    eg. uh heal.txt heal\n");
    return 1;
  }
  file = (string)this_player()->make_path(file);
  if(!(txt = read_bytes(file,0,FILE_SIZE(file)))) {
    help_error(READ_ERROR);
    return 0;
  }
  return update_topic(topic,txt);
}


/* convert directory to hel[ data files */

status convert_dir(string str) {
  string *files, file, subtopic, tmp;
  int i;

  if(!str || sscanf(str,"%s %s",str,subtopic) != 2) {
    write("Usuage: conv [directory] [category]\n\n"+
          "    eg. conv /doc/helpdir/cleric cleric\n");
    return 1;
  }
  str = (string)this_player()->make_path(str);
  files = get_dir(str +"/.");
  for(i = 0; i < sizeof(files); i++) {
    file = str +"/"+ files[i];
    sscanf(file,"%s.c",file);
    if(FILE_SIZE(file) > 0) {    
      if(convert_file(file,files[i],subtopic)) {
        write("File "+ file +" Converted.\n");
      }
      else {
        write("Unable to convert "+ file +"\n");
      }
    }
  }
  return 1;
}



/* update all subtopic files */ 

status update(string arg) {
  string *list, *help_data, tmp, subtopic, *subtopic_list;
  string file_data;
  int i, j, k, start_number;
  string *subtopic_data;

  if(arg) sscanf(arg, "%d", start_number);

  write("Removing Subtopics....\n");
  subtopic_list = get_dir(HELP_DIR +"subtopic/.");
  for(i = 0; i < sizeof(subtopic_list); i++) {
    if(sscanf(subtopic_list[i],"%s.sub",tmp)) {
      rm(HELP_DIR +"subtopic/"+ subtopic_list[i]);
    }
  }
  write("Updating Subtopics....\n");  
  list = get_dir(HELP_DIR +".");
  for(i = 0; i < sizeof(list); i++) {
    if(sscanf(list[i],"%s.hlp",tmp) == 1) {
      help_data = load_help_file(HELP_DIR + list[i]);
      if(!start_number) start_number = 0;
      for(j = start_number; j < sizeof(help_data); j += 3) {
        subtopic = 0;
        sscanf(help_data[j+SUBTOPIC],"SUBTOPIC-%s",subtopic);
        if(!subtopic) {
          log_file("HELP","Error: "+ help_data[j] +"\n"+
                                     help_data[j+SUBTOPIC] +"\n\n");
          continue;
        }
        write("Adding "+ help_data[j] +" to "+ subtopic +"\n");
        subtopic_list = explode(subtopic,"/");
        for(k = 0; k < sizeof(subtopic_list); k++) {
          subtopic = subtopic_list[k];
          write_file(HELP_DIR+"subtopic/"+subtopic+".sub",help_data[j] +"\n");
        }
      }
    }
  }
  write("Sorting Subtopics....\n");
  subtopic_list = get_dir(HELP_DIR +"subtopic/.");
  for(i = 0; i < sizeof(subtopic_list); i++) {
   if(sscanf(subtopic_list[i],"%s.sub",tmp)) {
     subtopic_data = load_subtopic_file(HELP_DIR+"subtopic/"+subtopic_list[i]);
     subtopic_data 
       = sort_array(subtopic_data,"alphabetical_order",this_object());
     file_data = implode(subtopic_data,"\n") +"\n";
     rm(HELP_DIR +"subtopic/"+ subtopic_list[i]);
     write_file(HELP_DIR +"subtopic/"+ subtopic_list[i], file_data);
   }
  }
  write("Subtopics Updated\n");
  return 1;
}

status alphabetical_order(string one, string two) {
  int i, len_1, len_2;

  len_1 = strlen(one);
  len_2 = strlen(two);
  one = lower_case(one);
  two = lower_case(two);
  for(i = 0; i < len_1 && i < len_2 && one[i] == two[i]; i++);
  if(i >= len_1 || i >= len_2) {
    return (len_1 > len_2) ? 1 : ((len_1 == len_2) ? 0 : -1);
  }
  return (one[i] > two[i]) ? 1 : -1;
}



  

status ext(string str) {
  string file, txt, tmp;

  if(!str || sscanf(str,"%s %s",file,str) != 2) {
    write("Usuage: extract <file> <topic>\n\n"+
          "Notes: writes to <file> the help <topic> from help data.\n");
    return 1;
  }
  file = (string)this_player()->make_path(file);
  if(FILE_SIZE(file) > 0) {
    write("File Already exists.\n");
    return 1;
  }
  if(!(txt = query_help_string(str))) {
    help_error(NO_HELP);
    return 0;
  }
  sscanf(txt,"%s\nCategory: %s help.\n",txt,tmp);
  write_file(file, txt);
  write("Extracted "+ str +"->"+ file +"\n");
  return 1;
}

