#define AREA_PATH "wiz/kate/open/forest/"

string get_short_by_id( int id )
{
	return "Kate's Forest";
}

string get_long_by_id( int id )
{
	string * longs = ({ 
		   "blah blah blah Kate's forest", 
	});

	return longs[id%sizeof(longs)];
}
