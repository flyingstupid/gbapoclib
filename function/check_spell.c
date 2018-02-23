
/*** This file checks all types of functions for spells
     'Hold' -  Hold spells stop the caster from moving, and hence spoil spells.
  'Silence' -  Silence spells stop the verbal components (speaking bits) of
               a spell and thus, can stop it from being cast.
 'Nulmagic' -  Areas that are resistant to magic cannot have magic cast in them

 ***/

int check_spells(string str) {
    object obj;

    if(str == "hold" || str == "Hold") {
       if(present("Hold", environment(this_player())) ||
          present("Hold", this_player())) {
          tell_object(this_player(),
          "You attempt to move, yet some force stops you.\n");
          return 1;
       }
       return 0;
    }

    if(str == "silence" || str == "Silence") {
       if(present("Silence", environment(this_player())) ||
          environment(this_player())->query_prop("silence") ||
          present("Silence", this_player())) {
          tell_object(this_player(),
          "You utter the words of the spell, yet no sounds come from your "+
          "lips.\n");
       return 1;
       }
       return 0;
    }

    if(str == "nulmagic" || str == "Nulmagic") {
       if(present("Nulmagic", environment(this_player())) ||
          present("Nulmagic", this_player()) ||
          environment(this_player())->query_prop("nulmagic") ||
          environment(this_player())->query_prop("Nulmagic") ||
          environment(this_player())->query_nulmagic()) {
          write("Your spell fails...as if resisted by the very air around "+
          "you.\n");
          return 1;
       }
     return 0;
    }

return 0;
}

