#define VER		"1.01-alpha"
#define MY_PATH		"/d/affils/realestate/gen"
#define C_EXITS		MY_PATH+"/convert_exits"
#define C_ITEMS		MY_PATH+"/convert_items"

#define SAVE_FILE	"/ob_saves/keeps/"
#define NAME		(string)this_player()->query_name(1)

#define HEADER  "#include <mudlib.h>\n"+\
		"\n"+\
		"inherit ROOM;\n"+\
		"void reset(status arg) {\n"+\
		"  if(arg) return;\n\n"

#define FOOTER "\n}\n"
