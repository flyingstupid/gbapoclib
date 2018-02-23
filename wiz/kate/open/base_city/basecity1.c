//
//  wiz/kate/open/city/basecity/basecity1.c
//  Second Chance
//
//  Created by Krista Jastrzembski on 10/12/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//

#include <mudlib.h>
inherit "wiz/kate/open/city.c";

void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Empty field");
    set_long(
             " Empty Filed \n"+
             "EMPTY FIELD DESC PLACEHOLDER\n");
    set_exits(({"wiz/kate/open/city/basecity/basecity5","east",
                "wiz/kate/open/city/basecity/basecity2","south",   }));
}