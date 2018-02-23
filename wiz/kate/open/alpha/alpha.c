//
//  wiz/kate/open/base_city/base_city.c
//  Second Chance
//
//  Created by Krista Jastrzembski on 10/12/12.
//  Copyright (c) 2012 Krista. All rights reserved.
//

#include <mudlib.h>

inherit "wiz/kate/open/city.c";

void reset(status arg) {
    if(arg) return;
    leaders = ({});
    citizens = ({});
    buildings = ({});
    set_city_size(1);
}