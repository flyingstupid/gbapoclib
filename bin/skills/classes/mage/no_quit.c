/* complements the cleric hold spell for realism (Tamsyn,
  requested by Dax ) */


status drop() { return 1; } status get() { return 0; }

void init(){ add_action("no_quit","quit"); }

status no_quit() { 
	write("You can't quit when you're holding a player!\n");
	return 1;
}

void start(int t) {
	call_out("destruct_me",t);
}

void destruct_me() { destruct(this_object()); }

