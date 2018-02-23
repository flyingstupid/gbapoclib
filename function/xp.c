#define DEBUG 0
status calc_xp() {
  int level, xp;

  level = (int)this_player()->query_level();
  if(DEBUG)
    write("Level: "+ level +"\n");
  
  if(level < 5)        xp = 1000;
  else if(level < 10)  xp = 1250;
  else if(level < 25)  xp = 2000;
  else                 xp = 3000;

  return xp;
}
 

