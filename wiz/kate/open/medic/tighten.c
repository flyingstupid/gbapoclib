
//
//  wiz/kate/open/medic/tighten.c - decrease dex - requires 1 serum, 1 syringe and 1 enzyme, decreases Dex enhancing + (enhancing * random (1-2)) duration is based on (preventing * random (5-10)) + 60
//  Second Chance
//
//  Created by Krista Jastrzembski on 11/8/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//

#include <mudlib.h>


object classObj;
int enhanceAmount;
int base;
object victim;

void remove_enhancement();

status tighten(string target){
    
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
    victim = find_player(target);
    if (member(all_inventory( environment( this_player() )), victim) == -1){
        tell_object(this_player(), "the target is not here.\n");
        return 1;
    }
    if ( (classObj->query_syringe() < 1) && (classObj->query_serum() < 1) && (classObj->query_enzymes() < 1) )
    {
        tell_object(this_player(), "The required resources are not in your medkit.\n");
        tell_object(this_player(), "You need one syringe, one vial of serum and one vial of enzymes to perform this skill.\n");
        return 1;
    }
    
    if (victim->query_enhanced()){
        tell_object(this_player(), "This person is already under the effects of enhancing serum, further enhancement can have adverse effects.\n");
        return 1;
    }
    
    
    base = victim->query_dexterity();
    enhanceAmount = victim->query_dexterity() - (this_player()->query_enhancing() + (this_player()->query_enhancing() * (random(2)+1)));
    int duration = (this_player()->query_preventing() * (random(5) + 5)) + 60;
    
    classObj -> add_syringe(-1);
    classObj -> add_serum(-1);
    classObj -> add_enzymes(-1);
    victim->adj_dexterity(enhanceAmount * -1);
    tell_object(this_player(), "You swiftly inject " + victim->query_name() + " with a anti-relaxin derivitive causing their muscles to tighten ("+ enhanceAmount + ")\n");
    tell_object(victim, this_player()->query_name() + " injects you with a strange serum.\n" +
                "You feel a cold semsation travel through your muscles as your muscles sieze up.\n");
    
    victim->set_enhanced(1);
    call_out("remove_enhancement", duration);
    return 1;
}

void remove_enhancement()
{
    victim->adj_dexterity(base);
    victim->set_enhanced(0);
    tell_object(victim, "You feel your muscles loosen slightly.\n");
}