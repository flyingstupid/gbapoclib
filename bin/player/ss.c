#define TP this_player()

status ss() { 
    write ("-*- HP: "+ TP->query_hp() +" ("+ TP->query_max_hp() +")  EXP: "+ 
      TP->query_exp() +" -*-\n");
    return 1; 
} 
