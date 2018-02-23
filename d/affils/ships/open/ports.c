/* All the areas to sail to in the world! */
/* ship.c uses this file 		  */

mapping allports() {
  return ([
    "minos" : ([ 
	"file" 	: "/d/minos/w/sarak/minos/rooms/island/start",
        "xy"   	: ({ 50, 50, }),
              ]),

    "skol island" : ([ 
        "file"  : "/d/affils/ships/island/jetty",
	"xy"	: ({ 100,100,}), 
	      ]),

    "isle of sorcery" : ([
	"file"	: "/d/sorcery/w/angel/dock1", 
	"xy"	: ({ 90, 80, }),
	      ]),


    "griffin" : ([
	"file" : "/d/affils/ships/island2/beach2",
	"xy"   : ({ 50, 90, }),
	     ]),

    "ille coronos" : ([
	"file" 	: "/d/coronos/w/angel/city/docks/dock1", 
	"xy"	: ({ 10, 150, }),
	      ]),

  ]);
}

mixed *ports_to_array() {
  string *names;
  mapping map1, map2;
  int i;
  mixed  *xyz;

  names = m_indices(allports());
  map1 = allports();
  xyz = ({ });

  for(i=0; i<sizeof(names); i++) {
    map2 = map1[names[i]];
    xyz += ({ ({ names[i], map2["xy"], map2["xy"], }), });
  }
  return xyz;
}

