/******************************************************************/ 
/*  Mudlib Configuration File */

#ifndef MUDLIB_H
#define MUDLIB_H

//#pragma pedantic
//#pragma strict_types
#pragma save_types
#pragma verbose_errors
#pragma warn_deprecated

#include "/include/config.h"

#define MUD_VERSION LIBVERSION /* version of Heaven7 mudlib */


#undef MUD_NAME
#define MUD_NAME       MUDNAME
#define INTERMUD_NAME  MUDNAME

/*
 * Directories
 */

#define DOMAIN_DIR             "/d/"
#define WIZARD_DIR             "/wiz/"

               

/*
 * Central Mudlib Objects
 */

#define MASTER                  "secure/master"
#define TEST                    ((string)this_player()->query_name() == "Phaedrus")


#define SIMUL_EFUN             "secure/simul_efun"
#define SPARE_SIMUL_EFUN_FILE  SIMUL_EFUN
#define BASE                   "inherit/base/base_obj"
#define SECURITY_FILE          "secure/security"
#define ACTIONS                "inherit/base/actions"
#define BIN_D                  "secure/bin_d"
#define BINCMD                 "inherit/base/bincmd"
#define PLAYER                 "obj/player"
#define RACE_DIR               "inherit/base/races"
#define WIZARD                 "obj/wizard"
#define COMMUNICATION_FN        "inherit/base/comms"
#define COMBAT_FN               "inherit/base/combat"
#define SORTER                  "/function/sorter"
#define SHIPS                   "d/affils/ships/shipnew"
#define SHIP                    "d/affils/ships/shipnew"
#define SPELL_FN                "inherit/base/spell"
#define SOUL_D                  "std/daemons/soul"
#define SOUL_I                  "std/inherit/soul"                        
#define RESOURCE_D              "/wiz/emraef/open/scav/resource_d.c"

/*
 * General Mudlib Objects
 * please keep it in alphabetical order?
 */

#define ACTIONS_BIN       "/function/actions"
#define AFFILIATION       "inherit/affils"
#define AFFILIATION_OB    "obj/skills/affils/affils"
#define ARMOUR            "inherit/armour"
#define BANK              "inherit/std_bank"
#define BULLETIN          "obj/bulletin"
#define BULLETIN_BOARD    BULLETIN
#define CHANNEL_D         "/std/daemons/channel"
#define CHURCH            "/d/coronos/w/angel/city/temple/hall4"
#define CLOTHING          "inherit/clothing"
#define CONTAINER         "inherit/contain"
#define DRINK             "inherit/drink"
#define FOOD              "inherit/food"
#define GUILD             "inherit/guild"
#define INNER             "d/ooc/creator/inner1"
#define LIVING            "inherit/base/living"
#define MAGIC_ARMOUR      "inherit/m_armour"
#define MAGIC_POTION      "objects/potion"
#define MAGIC_SCROLL      "objects/scroll"
#define MAGIC_WAND        "objects/wand"
#define MAGIC_WEAPON      "inherit/m_weapon"
#define MAIL_DIR          "room/post/"
#define MONEY             "obj/money"
#define MONSTER           "inherit/monster"
#define MORE_OB           "obj/more"
#define PASTE_DIR         "open/paste"
#define POST_OFFICE       "d/ooc/rooms/post"
#define PUB               "inherit/std_pub"
#define OBJ_MAN           "inherit/base/obj_man"
#define SCROLL            MAGIC_SCROLL
#define SHADOW            "inherit/shadows/shadow"
#define SHUTD             "obj/shut"
#define SIGN              "inherit/sign"                              
#define STORE             "inherit/store"
#define TARX              "secure/tarx"
#define TEMPERATURE       "inherit/temperature"
#define TREASURE          "inherit/treasure"
#define UNDEAD            "inherit/undead"
#define VOID              "room/void"
#define WAND              "inherit/wand"
#define WEAPON            "inherit/weapon"

/*
 * Room Defines
 */
#define SCAV_ROOM         "/wiz/emraef/open/scav/scavroom.c"
#define VMAP_ROOM         "inherit/vmaproom"
#define ROOM_BASE         "inherit/room2"
#define ROOM              SCAV_ROOM
#define STORE_ROOM        "/wiz/emraef/open/scav/storeroom.c"

/*
 * If the following are not defined, the relevant object will be 
 * removed from usage in player objects.                        
 */

#define PARTY_DAEMON      "obj/party/party_d"
#define MAIL_FIELD_LOADER "obj/mail_ldr"
#define MAILER            "obj/mail_rdr"
#define EDITOR            "obj/editor"
#define PAGER             "obj/pager"
#define DEBUG             "secure/debug"
#define SOUL              "obj/soul"                                   
#define SOUL_FUNC_FILE    "/obj/soul_fcn.c"
#define QUEST_ROOM        "/obj/quests/quest_rm"



/* just in case its making problems of late */
/******************************************************************/ 
/* a shorter time string */

#define DATE(T) ctime(T)[4..10]+((ctime(T)[20..23] == ctime(time())[20..23])\
  ? ctime(T)[11..15] : ctime(T)[20..23])



/*******************************************************************/
/* Money things. The ratio of types */

#define PLATINUM 1000
#define GOLD     100
#define SILVER   10
#define COPPER   1


/********************************************************************/
/* misc items */
#define BS(n)   "\n"

/*********************************************************************/
/* Are we an RPG mud? */
#define RPG
#ifdef RPG                                                    
#define IC_ENTER "/d/wastelands/w/critical/secondtry/city1"
#define OOC_ENTER "/d/ooc/rooms/ooc1"
#endif /* RPG */



/* Modules */

#define M_TEMP_VAR                 "/std/inherit/modules/m_temp_var"
#endif /* MUDLIB_H */           
