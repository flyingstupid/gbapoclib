/* config file parser */

/* used by am_allow.c and wp_allow.c to read /include/cfg/weapon.dat
   and armour.dat.  Note that the lib has been setup so any .dat
   can be read by players, regardless of path.

   
   Format: fields are strings
 
   #comment
   @Field                           # Main Field, ' ' & '\n' are stripped
   :field1, field2, field3, ....    # Array field, ' ' & '\n' are stripped
   :$field4                         # String field, '\n' are stripped
   
   => ({ Field, ({ ({ field1, field2, field3, }), field4, }), })

  The parser allows escaped characters. Useful if you need to use

  Example:

  @name
  :b o b, bobby\ joe
  :$b o b, 

  bobby joe\n

  #..........

  will create a data array,

  ({ "name", ({ "bob", "bobby joe", }), "b o b,bobby joe\n", }), })
*/

#include <mudlib.h>


string remove_comment(string str) {
  string tmp1, rest;

  while(sscanf(str,"%s#%s\n%s",str,tmp1,rest) == 3) { 
    str += rest;
  }
  return str;
}


string remove_whitespace(string str) {
  str = implode(explode(str +" "," "), "");
  str = implode(explode(str +"\n","\n"), "");
  return str;
}


/* convert escaped tokens to something else... */

string escape_string1(string str) {
  str = implode(explode(str, "\\ "), "\\*^");
  str = implode(explode(str, "\\#"), "\\$^");
  str = implode(explode(str, "\\@"), "\\~^");
  str = implode(explode(str, "\\:"), "\\!^");
  str = implode(explode(str, "\\,"), "\\&^");
  return str;
}


string escape_string2(string str) {
  str = implode(explode(str, "\\*^"), " ");
  str = implode(explode(str, "\\$^"), "#");
  str = implode(explode(str, "\\&^"), ",");
  str = implode(explode(str, "\\b"), "\b");
  str = implode(explode(str, "\\n"), "\n");
  str = implode(explode(str, "\\t"), "\t");
  str = implode(explode(str, "\\~^"), "@");
  str = implode(explode(str, "\\!^"), ":");
  str = implode(explode(str, "\\\\"), "!@#$^");
  str = implode(explode(str, "\\"), "");
  str = implode(explode(str, "!@#$^"), "\\");
  return str;
}


mixed *load_file(string file) {
  string txt, *fields, *field_data;
  mixed *data, *f_data;
  int i, j, k;

  data = ({});
  txt = read_file(file);
  if(!txt) return ({});
  txt = escape_string1(txt);
  txt = remove_comment(txt);
  fields = explode(txt, "@");

  for(i = 1; i < sizeof(fields); i++) {
    field_data = explode(fields[i],":");
    data += ({ remove_whitespace(field_data[0]), });
    f_data = ({});
    for(j = 1; j < sizeof(field_data); j++) {
      txt = field_data[j];
      if(txt == "" || txt[0] != '$') {
        txt = remove_whitespace(txt);
        txt = escape_string2(txt);      
        f_data += ({ explode(txt,","), });
      }
      else {
        txt = implode(explode(txt,"\n"), "");
        for(k = strlen(txt); k-- && txt[k] == ' ';);
        txt = extract(txt,1,k);
        txt = escape_string2(txt);
        f_data += ({ txt, });
      }
    }
    data += ({ f_data, });
  }
  return data;
}
