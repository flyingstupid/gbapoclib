
object load_object_safe( string str )
{
    if( !str )
        return 0;

    return efun::load_object( str );
}


int is_a( string path, object ob )
{
    if( !ob )
        return 0;

    if( path[<2..] != ".c" )
    {
        path += ".c";
    }

    if( path[0] == '/' )
    {
        path = path[1..];
    }

    string *list = inherit_list( ob );

    for( int i = 0; i < sizeof( list ); i++ )
    {
        if( list[i] == path )
            return 1;
    }


    return 0;
}

