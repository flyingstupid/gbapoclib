/****************************************************************************
 * Inheritable Communication object for the Heaven 7 mudlib.                *
 *                                                                          *
 * OBJECT DESCRIPTION                                                       *
 * ******************                                                       *
 *                                                                          *
 * This object is inherited by living objects to perform language functions *
 * and the say command.                                                     *
 *                                                                          *
 * OBJECT HISTORY                                                           *
 * **************                                                           *
 * 1996.12.?? - Object Created by Angel                                     *
 * 1998.12.08 - Altered the existing communicate function to allow for      *
 *              compatibility with ansi.  The format of the display was     *
 *              also updated (Sarak).                                       *
 *                                                                          *
 ****************************************************************************/

#pragma strict_types
#pragma save_types
#pragma combine_strings


#include <mudlib.h>
#include <ansi.h>
#include <ansi_filter.h>
#include <msg_str.h>

string *languages_known;     /* list of languages known */
static string speak_language;/* Language being spoken */

string *set_languages_known(string *arr) {
  return languages_known = (arr) ? arr : ({});
}

status set_speak_language(string str) {  
  speak_language = (this_object()->query_language(str)) ?  speak_language : "common";
  return (str == speak_language) ? 1 : 0; 
}  

status change_language(string str) {
  if(str == "common" || this_object()->query_language(str)) {
    write("You begin to speak in "+ str +".\n");
    speak_language = str;
    return 1;
  }
  write("You don't know the language "+ str +".\n");
  return 1;
}

string *query_languages_known()  { return languages_known;   }

string query_speak_language()    { 
  return (speak_language) ? speak_language : "common";
}


status query_language(string str){  
  if(this_player() && this_object()->query_security_level()) return 1;
  if(!languages_known) languages_known = ({ });
  return (member_array(str, languages_known) == -1) ? 0 : 1;
} 


void add_language(string str){  
  if(!query_language(str) && str) languages_known += ({ str, });
}  

void remove_language(string str){  
  int i;
  if((i = member_array(str, languages_known)) != -1 && str != "common") {  
    languages_known = languages_known[0..i-1]
                    + languages_known[i+1..sizeof(languages_known)-1];
  }
}     



status communicate(string str) {  
  string tmp1, tmp2;
  int extract_size;  
  string verb, temp;  
  string padded_str1, padded_str2, prefix, prefix2;  
  string filtered_str;
  string tp_head, ob_head;
  string tp_msg, ob_msg;
  object *env;
  int i;
  
  if(this_object()->check_spell("Silence")) {
    write("You cannot speak, there seems to be a magical silence about you.\n");
    return 1;
  }  
  if(!speak_language) {  
    if(!this_player()->query_npc()) {  
      speak_language = "common";  
    }
    else  if(!(speak_language = (string)this_player()->query_race(0))) { 
      speak_language = "common";  
    }
  }  
  
  verb = query_verb();

  if(verb[0] == "'"[0]) {
    verb = extract(verb, 1);
    if(!str)
      str = verb;
    else
      str = verb + " " + str;
  }

  if(!str) str = ""; 

  if(str == "" || str == " ") {  
    tell_object(this_player(),"You mumble incoherently.\n");  
    say(this_object()->query_name() + " mumbles incoherently.\n");  
    return 1;
  }  

  if((int)this_object()->query_intoxication() >
     (int)this_object()->query_constitution() * 2) {
    str = implode(explode(str+"s","s"),"sh");
  }

  /* this is an RP thing for the Magia/Heaven7 mud world 8)  */
  if(sscanf(lower_case(str), "%sskandle%s", tmp1, tmp2)) {
    if(!random(5)) {
      shout("There is a rumbling in the heavens...\n");
      write("There is a rumbling in the heavens...\n");
    }
  }

  prefix  = (sscanf(str,"%s!",temp))
          ? " exclaim"
          : (sscanf(str,"%s?",temp))
          ? " ask"
          : " say";  

  prefix2 = (speak_language != "common")
         ? " in " + speak_language + ": "
         : ": ";  

  str = filter_ansi(str);

  padded_str1 = (string)this_object()->pad_str(
	(string)this_object()->query_name()+prefix+"s"+prefix2, str, 79);
  padded_str2 = (string)this_object()->pad_str(
	"You"+prefix+prefix2, str, 79);

  filtered_str = filter_ansi(padded_str1);

  tp_head = "You"+prefix+prefix2;
  ob_head = (string)this_object()->query_name()+prefix+"s"+prefix2;
  tp_msg = msg_str("\""+str+"\"", 75, strlen(filter_ansi(tp_head))+1);
  ob_msg = msg_str("\""+str+"\"", 75, strlen(filter_ansi(ob_head))+1);

  if(this_object()->ansi_on())
    tp_head = this_object()->query_color_attribute("say")+tp_head+OFF;
  tell_object(this_object(),tp_head+tp_msg+"\n");
  env = all_inventory(environment());
   
  for(i = 0; i < sizeof(env); i++) {
    if(!living(env[i])) continue;
    if(env[i] != this_object()) {
      if(env[i]->query_language(speak_language)) {
        if(env[i]->ansi_on()) {
          tell_object(env[i], env[i]->query_color_attribute("say")+
            ob_head+OFF+ob_msg+"\n");
        }
        else {
          tell_object(env[i],ob_head+ob_msg+"\n");
        }
      }
      else {
        tell_object(env[i],this_object()->query_name() +" says something in a language "+
        "that you don't understand.\n");
      }
    }
  }
  return 1;
}

