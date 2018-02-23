
#ifndef _CONFIG_DEFS_H_
#define _CONFIG_DEFS_H_

// Naming
#define MUDNAME			"Heaven7"
#define MUDLIB				"Heaven7"
#define LIBVERSION			"4.0 Alpha 2"

// Files
#define WELCOME			"/data/info/WELCOME"

#define INIT_FILE 		    "/secure/init_file"

// Common Logs
#define DEBUG_LOG   "/log/h7.debug.log"
#define MAIN_LOG    "/log/log"


// Settings
#define false 			        0
#define true 			        1
#define null 			        0
// use parse_command for get,put,drop
#define USE_PARSE_COMMAND		1


// Some get_dir() constants.
#define GD_FILES    1
#define GD_SIZES    2
#define GD_TIMES    4

// ed() settings
#define DEAD_ED      ".dead_ed_files"
#define ED_SAVE      ".edrc"


#endif /* _CONFIG_DEFS_H_ */

/*
 * $Log: config.h,v $
 * Revision 1.3  2003/12/20 19:51:21  phaedrus
 * Mudlib updated for alpha 2 release
 *
 * Revision 1.2  2003/11/21 23:54:14  phaedrus
 * *** empty log message ***
 *
 * Revision 1.1  2003/11/21 22:08:30  phaedrus
 * initial revision
 *
 * Revision 1.3  2003/11/02 15:34:26  phaedrus
 * WELCOME file has correct path now
 *
 * Revision 1.2  2003/11/01 21:22:18  phaedrus
 * most of the mudlib works with LDMud
 *
 * Revision 1.1  2003/10/26 04:54:12  phaedrus
 * Initial LDMud support
 *
 *
 */
 
