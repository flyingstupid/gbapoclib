/**************************************************************************
 * Inheritable Color Object for the Heaven 7 Mudlib.                      *
 *                                                                        *
 * OBJECT DESCRIPTION                                                     *
 * ******************                                                     *
 * This object is designed to be inherited by the player object and used  *
 * in conjunction with the ansi system to allow a player to customise the *
 * color which they see for certain parts of the mud.                     *
 *                                                                        *
 * OBJECT HISTORY                                                         *
 * **************                                                         *
 * 1998.10.08 - Incorporated and modified from the system used on the     *
 *              Castinian mudlib (Sarak).                                 *
 *                                                                        *
 **************************************************************************/

#include <mudlib.h>
#include <ansi.h>

mapping color_attributes;

void reset(status arg) {
  if(arg) return;
  if(!color_attributes) color_attributes = ([ ]);
}

string set_color_attribute(string attr, string color) {
  if(!color_attributes) color_attributes = ([ ]);
  if(!color_attributes[attr])
    color_attributes += ([ attr : color ]);
  else
    color_attributes[attr] = color;
  return color;
}

string query_color_attribute(string attr) {
  if(!color_attributes) color_attributes = ([ ]);
  if(!color_attributes[attr])
    return OFF;
  else
    return color_attributes[attr];
}
