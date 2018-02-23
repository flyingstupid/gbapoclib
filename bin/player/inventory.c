#define TP this_player()

status inventory() { 
    if((int)TP->i_light(0) < 1) {
     write("It's too dark to see what you're carrying.\n");
     return 1;
    }
    TP->show_inventory();
    return 1; 
} 
