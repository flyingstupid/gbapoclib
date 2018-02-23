
#define TP this_player()

status shout(string str) { 
    string str1, str2, char, speak_language; 
    int i; 

    if(!str) { 
      write("You shout.... nothing.\n"); 
      return 1; 
    } 
    if(TP->query_name(1) == "guest") {
      write("I'm sure you don't have anything to shout about yet...\n"); 
      return 1; 
    }
    if(TP->query_age() < (30 * 60)) { 
      write("A youngster like you, shouting?\n"); 
      return 1; 
    } 
    if(TP->query_ghost()) { 
      write("Your ethereal vocal chords arn't strong enough...\n"); 
      return 1; 
    } 
    speak_language = TP->query_speak_language();
    if(!speak_language) {
      speak_language = "common";
      TP->set_speak_language(speak_language);
    }
    /* the ansi code  [0m switches off ansi graphics */
    if(speak_language == "common") {
      check_shout(TP->query_name()+" shouts from "+
       lower_case((string)environment(TP)->short()) +
      ": "+str+"\n");
      write("You shout: "+ str +"\n");
    }
    else {
      check_shout(TP->query_name() +" shouts in "+speak_language+
		  ": "+ str +" \n",speak_language);
      write("You shout in "+speak_language+": "+ str +"\n");
    }
    return 1; 
} 
