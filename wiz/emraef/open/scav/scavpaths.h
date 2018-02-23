#ifndef __SCAV_PATHS_H__
#define __SCAV_PATHS_H__

#define SCAV_PATH       "/wiz/emraef/open/scav/"

//#ifndef RESOURCE_D
//#define RESOURCE_D      (SCAV_PATH+"resource_d.c")
//#endif

#define SCAVBAG         SCAV_PATH+"scavbag.c"
#define RESOURCE        SCAV_PATH+"resource.c"
#define GATHER_SOURCE   SCAV_PATH+"gather_source.c"

#define LOG(XXX) (tell_object( find_player( "emraef" ), "" +XXX + "\n" ))

#define R_NAME 0
#define R_PLURAL 1
#define R_SHORT 2
#define R_WEIGHT 3
#define R_ALIAS 4
#define R_DEFAULT_VALUE 5
#define R_DEFAULT_COST 6

#define S_NAME 0
#define S_SHORT 1
#define S_LONG 2
#define S_ALIAS 3
#define S_RESOURCETYPE 4
#define S_MAXAMOUNT 5
#define S_DIFFICULTY 6
#define S_REQUIRED_ITEM 7

#endif //__SCAV_PATHS_H__
