status vmap() {

    write("You take a good look around your surroundings\n");
    environment( this_player() )->do_vmap( this_player() );
    write("\n");    
    return 1;  
}  
