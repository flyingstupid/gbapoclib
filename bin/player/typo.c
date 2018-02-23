#include <mudlib.h>
#include <pad_str.h>
#define GENERATE_CREATOR(X) "/bin/player/area"->area(X)

#define TP this_player()

status typo(string str){
  object obj;
  string room_file, domain, creator_name, tmp, file;

  file = capitalize(query_verb());
  if(!file) return 0;
  if(!str) {  
    write("Give an argument.\n");  
    return 1;  
  }  
  room_file = file_name(environment(TP));
  log_file(file,"\n"+ TP->query_name() +" ("+ room_file +"):\n");
  log_file(file, str + "\n");
  if(file == "Idea")
     write("Please use the board in the "+ MUD_NAME +" OOC area for "+
     "major game ideas.\n");
  if(creator_name = (GENERATE_CREATOR(1))) {
    write_file("/log/reports/"+ creator_name +".rep",
      "Report Type: "+ file +"  Room: "+ room_file +"\nTime: "+ 
       ctime(time()) +"\n"+ pad_str("REPORT: ",str,75) +"\n");
    if(obj = find_player(creator_name)) {
      tell_object(obj, "A "+file+" report has been generated for your area.\n");

    }
  }  
  write(file +" logged.\n");  
  return 1;  
}  
