/* Fill Medkit 

This skill is used to break down medical resources into
usable things by medics for their class powers. The better
the preventing, the better ratio you can get out of the
resources!

*/

#define TP      this_player()

int ratio();

status fillkit(string arg){

    object *inv=({});
    object *medicine=({});
    object kit;
    
    kit = present("medic_kit",TP);
    
    if(!kit)
    {
        write("ERROR: No KIT!\n");
        return 1;
    }
    
    inv = all_inventory(TP);
    
    if(!arg || !inv)
    {   
        write("Render resources into what?\n");
        write("render healing, strength, combat, antibotics, epinephrine\n");
        return 1;
    }
    
        for(int i=0; i < sizeof(inv); i++)
        {
            if(inv[i]->query_object_type("resource") && inv[i]->get_resource_type("medicine"))
            {
                medicine += ({inv[i]});
            }
        
        }


    if(!medicine)
    {
        write("You have nothing to render!\n");
        return 1;
    }

    lower_case(arg);


    switch( arg )
    {
    case "healing" :    
        if(sizeof(medicine) >= 1)
        {
            kit->add_healingserum(ratio());
            destruct(medicine[0]);
            write("You sift through the supplies and find enough medicine to make\n" + ratio() + " healing serums.\n");
        }
        else
        {
            write("You need more medicine to render that\n");
        }        
        break;
    
    
    case "strength" :    
        if(sizeof(medicine) >= 2)
        {
            kit->add_strengthserum(ratio());
            destruct(medicine[0]);
            destruct(medicine[1]);
            write("You sift through the supplies and find enough medicine to make\n" + ratio() + " strength serums.\n");            
        }
        else
        {
            write("You need more medicine to render that\n");
        }        
    break;    
    
    
    case "combat" : 
    
        
        if(sizeof(medicine) >= 3)
        {
            kit->add_combatserum(ratio());
            destruct(medicine[0]);
            destruct(medicine[1]);
            destruct(medicine[2]);
            write("You sift through the supplies and find enough medicine to make\n" + ratio() + " combat serums.\n");        
        }
        else
        {
            write("You need more medicine to render that\n");
        }
    break;
    
    
    case "antibotics" : 
    
        
        if(sizeof(medicine) >= 2)
        {
            kit->add_antiboticsserum(ratio());
            destruct(medicine[0]);
            destruct(medicine[1]);
            write("You sift through the supplies and find enough medicine to make\n" + ratio() + " antibotics.\n");
        }
        else
        {
            write("You need more medicine to render that\n");
        }
    break;
    
       
    case "epinephrine" :
    
        
        if(sizeof(medicine) >= 5)
        {
            kit->add_epinephrineserum(ratio());
            destruct(medicine[0]);
            destruct(medicine[1]);
            destruct(medicine[2]);
            destruct(medicine[3]);
            destruct(medicine[4]);
            write("You sift through the supplies and find enough medicine to make\n" + ratio() + " epinephrine shots.\n");            
        }
        else
        {
            write("You need more medicine to render that\n");
        }
    break;
    }
    

    return 1;
}


int ratio()
{
    int ratio;
    ratio=max( 1, TP->query_mhealing() / 10 );
    ratio=random(ratio)+1;
    return ratio;
}
    
    



