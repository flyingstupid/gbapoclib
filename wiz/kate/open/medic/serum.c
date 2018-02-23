//
//  wiz/kate/open/medic/serum.c
//  Second Chance
//
//  Created by Krista Jastrzembski on 11/13/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//

#include <mudlib.h>
inherit BASE;


//functions
void set_type(string type);
string query_type();
void set_value(int value);
int query_value();
int inject(string serum);

//variables
string type;
int healValue;


void reset(status arg) {
    
    if(arg) return;
    
    set_name("serum");
    set_short("Vial of serum");
    set_long("An autoinjector of a greenish serum.\n");
    set_weight(1);
    set_value (10);

}
void init(){
    
    ::init();
    
    add_action("inject", "inject");
}

int inject(string serum){
    tell_object(this_player(), "Injecting....increasing health by " + healValue + "\n");
    this_player()->adj_hp(this_object()->query_value());
    destruct( this_object() );
    return 1;
}

status get()
{
    return 1;
}

void set_type(string type){
    type = type;
}
string query_type(){
    return type;
}
void set_value(int value){
    healValue = value;
}
int query_value(){
    return value;
}