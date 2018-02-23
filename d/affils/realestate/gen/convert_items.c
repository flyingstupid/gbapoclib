string convert_items(mixed *arr) {
  string txt;

  if(!arr) {
    notify_fail("No exits in argument.\n");
    return 0;
  }

  if(!sizeof(arr)) return 0;
  txt = implode(arr, "\", \n    \"");
  txt = "    \""+ txt +"\"\n";
  txt = "  set_items(({ \n"+ txt +"  }));\n";
  return txt;
}
