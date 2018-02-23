//
//  wiz/kate/open/medic/suture.c - major healing - requires 3 bandages, heals level * 4 + mhealing * (3-6)
//  Second Chance
//
//  Created by Krista Jastrzembski on 11/8/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//
#include <mudlib.h>


object classObj;

status suture(string target){
    
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
    
    if(this_player()->query_attack()){
        tell_object(this_player(), "Suturing requires too much concentration to be performed during combat.\n");
        return 1;
    }
    
    
    int healAmount = (this_player()->query_level() * 4) + (this_player()->query_mhealing() * (random(4)+3));
    classObj -> add_bandage(-1);
    victim->adj_hp(healAmount);
    tell_object(this_player(), "You carefully suture " + victim->query_name() + "'s wounds. ("+ healAmount + ")\n");
    tell_object(victim, this_player()->query_name() + " bandages your wounds.\n");
    
    return 1;
}