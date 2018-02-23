#define AREA_PATH (implode( explode( file_name( this_object() ), "/" )[..<2], "/" ) + "/")

string get_short_by_id( int id )
{
	return "plot of land";
}

string get_long_by_id( int id )
{
	string * longs = ({ 
		   "This is a cleared and leveled plot of land ready for development.\n"
	});

	return longs[id%sizeof(longs)];
}
