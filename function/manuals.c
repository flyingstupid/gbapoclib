/* MANUALS DAEMON v1.0  (c) Angel
 *
 * Previously all manual files were contained in a single directory.
 * When you needed to access one file you had to sort through heaps
 * of file just to find the one you wanted.
 *
 * Next came sub-directories. Files were contained in various dirs
 * but to find a file you had to sort thru lots of dirs. You also
 * could no longer type 'man <file>' You had to know what sub-category
 * it came from.
 *
 * The new version allows a player to type 'man <file>' and the whole
 * file will be returned to the system to allow it to find the file.
 * The system will auto_load all the manual files list so it will know
 * where every manual is.
 *
 * When you make a new manual file make sure you update this object.
 */

#include <mudlib.h>
#include <linewrap.h>
#include <ansi.h>

string write_categories(string type);

static string *paths;
mapping filesMap;

mapping initialize_manuals();


void reset(status arg) {
  if(arg) return;
  initialize_manuals();
}

mapping query_all_manual_data() { return filesMap; }

string query_manual(string str) {
  mapping tmp;
  if(!str) return 0;
  tmp = filesMap[str];
  if(tmp) return tmp["filename"];
}



mapping query_manual_data(string str) {
  mapping tmp;
  if(!str) return 0;
  tmp = filesMap[str];
  return (tmp) ? tmp : 0;
}

string query_manual_type(string str) {
  mapping tmp;
  if(!str) return 0;
  tmp = filesMap[str];
  return (tmp) ? tmp["type"] : 0;
}

string query_manual_filename(string str) {
  mapping tmp;
  if(!str) return 0;
  tmp = filesMap[str];
  return (tmp) ? tmp["filename"] : 0;
}


mapping initialize_manuals() {
  string *files, tmpFile, thisFile, *fileParts;
  int i, j;
  string tmp;
  mapping tmpMap;

  if(!paths)    paths = ({ "/data/manuals", });
  if(!filesMap) filesMap = ([ ]);

  for(i=0; i<sizeof(paths); i++) {
    files = get_dir(paths[i] +"/");

    for(j=0; j<sizeof(files); j++) {
      tmpMap = ([ ]);
      tmpFile = paths[i] +"/"+ files[j];
      fileParts = explode(tmpFile, "/");
      thisFile  = fileParts[sizeof(fileParts)-1];

      if(file_size(tmpFile) == -2) {
        paths += ({ tmpFile, });
        filesMap[thisFile] = ([ "type"     : "sub-category",
                               "filename" : tmpFile, ]);
      }

      if(file_size(tmpFile) > 0) {
        if(sscanf(thisFile, "%s.wiz", tmp))
          filesMap[tmp] = ([ "type" : "creator manual",
                             "filename" : tmpFile, ]);
        else if(sscanf(thisFile, "%s.man", tmp))
          filesMap[tmp] = ([ "type" : "player manual",
                             "filename" : tmpFile, ]);
        else
          filesMap[thisFile] = ([ "type" : "general manual",
                                  "filename" : tmpFile, ]);

      }
    }
  }
  return filesMap;
}


mapping sort_categories() {
  int i;
  string *player_list, *creator_list, *general_list, *subcat;
  string category;
  string *keys;
  mapping map;

  player_list  = ({ });
  creator_list = ({ });
  general_list = ({ });
  subcat       = ({ });

  keys = m_indices(filesMap);

  for(i=0; i<sizeof(keys); i++) {
    category = query_manual_type(keys[i]);

    switch(category) {
      case "sub-category" :
        subcat += ({ keys[i], });
        break;

      case "player manual" :
        player_list += ({ keys[i], });
      break;

      case "creator manual" :
        creator_list += ({ keys[i], });
      break;

      default :
        general_list += ({ keys[i], });
      break;
    }
  }

  return ([
        "general manuals" : general_list,
        "player manuals"  : player_list,
        "creator manuals" : creator_list,
        "sub-categories"  : subcat,
  ]);
}



string write_manuals(status silently) {
  object pager;
  string txt;
  string final_txt;
  string linetxt;
  string tmp, str;
  string *keys;
  string *values;
  int i, j, z;
  int linecount;
  mapping categories;

  categories = sort_categories();
  keys       = m_indices(categories);

  final_txt = "";
  tmp = "";
  txt = "";
  linetxt = "";

  for(i=sizeof(keys); i--;) {
    str = " "+ keys[i] +" ";


    for(z=0; z< (75 - strlen(str))/2; z = z + 2)
      tmp += "-=";

    str = BLUE_F+tmp+CYAN_F+BOLD+str+OFF+BLUE_F+tmp+tmp;
    str = ansi_extract(str,0,75);

    final_txt += (str +"\n"+ write_categories(keys[i]) +"\n");
    tmp = "";
  }

  if(!silently) {
#ifdef PAGER
    pager = clone_object(PAGER);
    move_object(pager, this_player());
    pager->page(final_txt);
#else
    writelw(final_txt);
#endif  /* PAGER */
  }
  return final_txt;
}

string write_categories(string type) {
  int i;
  int count;
  string tmp, txt;
  mapping list;
  string *keys;
  string *values;

  list   = sort_categories();
  values = list[type];

  tmp = "";
  txt = "";

  
  for(i = 0; i < sizeof(values); i++) {
    tmp = " "+values[i] +"                                     ";
    tmp = extract(tmp,0,24);
    txt += tmp;
    count += 1;

    if(count >= 3) {
      count = 0;
      txt += "\n";
    }
  }
  return txt;
}
