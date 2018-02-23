/*
 * File: /std/inherit/modules/m_temp_var.c
 * Date:    9 March 2002, Sarak.
 * Purpose: This file is used to give objects the ability to store
 *          temporary data using player objects as the key.  This method
 *          ensures data is not confused between players and that the
 *          mapping is kept relatively clean by the high turnover of player
 *          objects.
 *
 * History:
 */

static mapping temp_variables;

/*
 * Function: query_temp(object, string)
 * Date:     9 March 2002, Sarak.
 * Purpose:  This function provides the ability to retrieve a value that
 *           has previously been stored for a player.
 *
 * History:
 */

mixed query_temp(object who, string variable) {
  mapping pl_map;
  mapping extra;  
  int i;
  string *explodedstat;

  if(!temp_variables || !who || !variable || !strlen(variable) ||
      !temp_variables[who])
    return 0;
  
  pl_map = temp_variables[who];

  explodedstat = explode(variable, "|");
  extra = pl_map;
  for(i = 0; i < sizeof(explodedstat) - 1; i++) {
      if(!extra[explodedstat[i]]) return 0;
      extra = extra[explodedstat[i]];
  }
  if(!extra[explodedstat[sizeof(explodedstat) - 1]]) return 0;
  return extra[explodedstat[sizeof(explodedstat) - 1]];
}

/*
 * Function: set_temp(object, string, mixed)
 * Date:     9 March 2002, Sarak.
 * Purpose   This function sets a temporary value under the key of
 *           variable under who's key.
 */

mixed set_temp(object who, string variable, mixed value) {
  mapping pl_map;
  string map1, map2;
  
  if(!who) return 0;
  if(!temp_variables) temp_variables = ([ ]);
  if(!temp_variables[who]) temp_variables[who] = ([ ]);

  pl_map = temp_variables[who];

  if(sscanf(variable, "%s|%s", map1, map2) == 2) {
    if(!pl_map[map1]) pl_map[map1] = ([ ]);
    pl_map[map1][map2] = value;
    temp_variables[who] = pl_map;
    return value;
  }
  pl_map[variable] = value;
  temp_variables[who] = pl_map;
  return value;
}

/*
 * Function: clear_temp
 * Date:     9 March 2002, Sarak.
 * Purpose:  This function clears all values currently stored.  This action
 *           cannot be reversed.
 *
 * History:
 */

void clear_temp() { temp_variables = ([ ]); }
