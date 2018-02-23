/*

Medics healing ability. I am redoing everything from heal.c because its fucked :P
-Critical

*/

#define TP this_player()
#define SKILL this_player()->query_mhealing() 


status newheal(string arg)
{
    object kit;
    int skill=SKILL;
    int heal;    
    
    kit = present("medic_kit",this_player());
    if(!kit) {
    write("You need your medic's kit!\n");
    return 1;
    }
          
    heal =  (skill/2) * random(4);
    if(!arg)
    {
        write("You draw your injector, load it with healing serum and inject it into your body\nYou feel better!\n");
        say(TP->query_name() + " draws an injector and injects themselves.\n");
        TP->adj_hp(heal);
        return 1;
    }
    
    
}