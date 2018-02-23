
#include "/include/ansi.h"

string replace_string( string str, string pattern, string replace )
{
    return implode( explode( str, pattern ), replace );
}

string remove_char_from_string( string str, string *strs )
{
    for( int i = 0; i < sizeof(strs); i++ )
    {
        str = replace_string( str, strs[i], "" );
    }
    return str;
}

