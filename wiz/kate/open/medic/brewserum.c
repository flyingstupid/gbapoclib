//
//  wiz/kate/open/medic/brewserum.c - decrease dex - requires 1 serum, 1 syringe and 1 enzyme, decreases Dex enhancing + (enhancing * random (1-2)) duration is based on (preventing * random (5-10)) + 60
//  Second Chance
//
//  Created by Krista Jastrzembski on 11/8/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//

#include <mudlib.h>


object classObj;
string serumtype;
object serum;
int value;

int do_brew();

status brewserum(string type){
    
    serumtype = type;
    object *inv = all_inventory(this_player());
    for (int i = 0; i<sizeof(inv); i++) {
        if (is_a ("wiz/kate/open/medic/medkit.c", inv[i])){
            classObj = inv[i];
        }
    }
    if (!classObj){
        tell_object(this_player(), "Can't find the medkit!");
    }

    if ((classObj->query_serum() < 1) && (classObj->query_enzymes() < 1) )
    {
        tell_object(this_player(), "The required resources are not in your medkit.\n");
        tell_object(this_player(), "You need one vial of serum and one vial of enzymes to perform this skill.\n");
        return 1;
    }
    
    do_brew();
    return 1;

}

int do_brew(){
    clone_object("wiz/kate/open/medic/serum.c");
    serum = find_object("wiz/kate/open/medic/serum.c");
     tell_object(this_player(), "brewing.....\n");
    
    serum->set_type(serumtype);
    
    value = ((this_player()->query_level() * 2) + (this_player()->query_mhealing() * (random(4)+1)));
    serum->set_value(value);
    move_object( serum, this_player() );
    return 1;
}