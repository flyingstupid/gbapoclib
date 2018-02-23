#define AREA_PATH (implode( explode( file_name( this_object() ), "/" )[..<2], "/" ) + "/")

string get_short_by_id( int id )
{
	return "megaplex corridor";
}

string get_long_by_id( int id )
{
	string * longs = ({
           "The once smooth walls of the corridor now fallen into disrepair surround you.\n" +
           "One place looks just like the next\n",
           "Each step has you thinking you have been here before, as the walls and decore\n"+
           "all look the same",
	});

	return longs[id%sizeof(longs)];
}

string get_room_scav_type(string type, int id)
{
    return type + ( random(10) + 1 );
}

void common_reset(status arg)
{

}
