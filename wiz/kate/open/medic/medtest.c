#include <mudlib.h>

inherit BASE;

status test(){
    tell_object(this_player(), "you are in the test file.\n");
    return 1;
}