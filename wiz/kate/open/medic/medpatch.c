//
//  wiz/kate/open/medic/suture.c - minor healing - requires 1 bandage, heals level + mhealing * (1-5)
//  Second Chance
//
//  Created by Krista Jastrzembski on 11/8/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//
#include <mudlib.h>


object classObj;

status medpatch(string target){
    
    object *inv = all_inventory(this_player());
    for (int i = 0; i<sizeof(inv); i++) {
        if (is_a ("wiz/kate/open/medic/medkit.c", inv[i])){
            classObj = inv[i];
        }
    }
    if (!classObj){
        tell_object(this_player(), "Can't find the medkit!");
    }
    
    target = lower_case(target);
    object victim = find_player(target);
    if (member(all_inventory( environment( this_player() )), victim) == -1){
        tell_object(this_player(), "the target is not here.\n");
        return 1;
    }
    if (classObj->query_bandages() < 1){
        tell_object(this_player(), "The required resources are not in your medkit.\n");
        return 1;
    }
    int healAmount = (this_player()->query_level() * 2) + (this_player()->query_mhealing() * (random(5)+1));
    classObj -> add_bandage(-1);
    victim->adj_hp(healAmount);
    tell_object(this_player(), "You deftly bandage " + victim->query_name() + " effectivly healing some ("+ healAmount + ") of their wounds.\n");
    tell_object(victim, this_player()->query_name() + " bandages your wounds.\n");
    
    return 1;
}