mapping zones;

void reset(status arg) {
  if(arg) return;

  zones = ([ "ille coronos" : ([  "Treasure" : 1,
					"Clothing" : 1,
					"Armour"   : 3,
					"Weapon"   : 4,
					"Food"     : 1,
					"Drink"    : 1,
				]),

		"scanthian"   :  ([	"Treasure" : 3,
					"Clothing" : 2,
					"Armour"   : 1,
					"Weapon"   : 2,
					"Food"     : 1,
					"Drink"    : 1,
				]),

		"minos"	:   ([ "Treasure" : 1,
					"Clothing" : 3,
					"Armour"   : 3,
					"Weapon"   : 3,
					"Food"     : 4,
					"Drink"    : 2,
				]),
  ]);
}
	

mapping get_modifiers(string Azone) {
  if(!Azone) Azone = "ille coronos";
  return zones[Azone];
}

