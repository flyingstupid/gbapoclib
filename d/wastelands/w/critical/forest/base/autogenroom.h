#define AREA_PATH (implode( explode( file_name( this_object() ), "/" )[..<2], "/" ) + "/")

string get_short_by_id( int id )
{
	return "in a forest";
}

string get_long_by_id( int id )
{
	string * longs = ({ 
		   "Trees pepper the dense forest all around. Sounds of small\n" + 
           "creatures can occationally be heard. The ground is covered\n" +
           "in leaves and pine needles fallen from the trees over\n" + 
           "head.\n", 
	});

	return longs[id%sizeof(longs)];
}

string get_room_scav_type(string type, int id)
{
    return type + ( random(10) + 1 );
}

