/***  Marriage - alain  ***/

#define ENV    environment
#define NAME   (string)this_player()->query_name()
#define TP     this_player()
#define CAP    capitalize

 
status marry(string str) { 
  string name1, name2; 
  object player1, player2; 
  object wedding_ring; 
 

  if(!str || sscanf(str, "%s and %s", name1, name2) != 2) {
    notify_fail("marry <man> and <wife>?\n");
    return 0; 
  }
  if(this_player()->query_level() < 15) {
    write("You need to be of higher status within the church.\n");
    return 1;
  }
  player1 = present(name1, ENV(TP)); 
  player2 = present(name2, ENV(TP)); 
 
  if(!player1) { 
    write(CAP(name1)+" is not here.\n"); 
    return 1; 
  } 
  if(!player2) { 
    write(CAP(name2)+" is not here.\n"); 
    return 1;
  } 
  if((int)player1->query_gender() == (int)player2->query_gender()){ 
    write("You cannot marry two players of the same sex!\n"); 
    return 1; 
  } 
  if(player1->query_npc()) { 
    write("But "+CAP(name1)+" is not a player!\n"); 
    return 1; 
  } 
  if(player2->query_npc()) { 
    write("But "+CAP(name2)+" is not a player!\n"); 
    return 1; 
  } 
  if(player1->query_spouse()) { 
    write("But "+CAP(name1)+" is already married!\n"); 
    return 1;  
  } 
  if(player2->query_spouse()) { 
    write("But "+CAP(name2)+" is already married!\n"); 
    return 1; 
  } 
  player1 -> set_spouse(CAP(name2)); 
  player2 -> set_spouse(CAP(name1)); 
  write("You marry "+CAP(name1)+" and "+CAP(name2)+".\n");
  say(NAME +" marries "+ CAP(name1) +" and "+ CAP(name2) +"\n");
  wedding_ring = clone_object("obj/skills/ring");
  move_object(wedding_ring, player1); 
  wedding_ring = clone_object("obj/skills/ring");
  move_object(wedding_ring, player2); 
  shout("The heavens rejoice in the union of "+
    CAP(name1) +" and "+ CAP(name2) +" !\n");     
  return 1; 
} 

