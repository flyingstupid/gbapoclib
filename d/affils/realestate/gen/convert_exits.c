string convert_exits(mixed *arr) {
  string txt;

  if(!arr)
    arr = (string *) environment(this_player())->query_exits();
  txt = implode(arr, "\", \n	\"");
  txt = "	\""+ txt +"\"\n";
  txt = "  set_exits(({ \n"+ txt +"  }));\n";
  return txt;
}
