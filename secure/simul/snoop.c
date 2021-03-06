
mixed snoop(mixed snoopee) {
    int result;

    if (snoopee && query_snoop(snoopee)) {
     write("Busy.\n");
     return 0;
    }
    result = snoopee ? efun::snoop(this_player(), snoopee)
               : efun::snoop(this_player());
    switch (result) {
     case -1:
         write("Busy.\n");
     case  0:
         write("Failed.\n");
     case  1:
         write("Ok.\n");
    }
    if (result > 0) return snoopee;
}
