#define TP this_player()


status medicfix(string arg)
{
   
    object kit;
    
    
    write("Fixing your class...\n");
    kit = present("medic_kit",TP);

    if(!kit)
    {
        write("Restoring Kit\n");
        move_object(clone_object("/objects/medkit.c"),TP);
    }

    return 1;
}