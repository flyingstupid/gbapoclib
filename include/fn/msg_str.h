string msg_str(string msg, int line_len, int tab_len) {
  string *arr;
  int i, j;

  msg = (string)this_player()->filter_ansi(msg);
  msg = sprintf("%-=*s", line_len - tab_len, msg);
  arr = explode(msg, "\n");
  msg = arr[0];
  for(i = 1 ; i < sizeof(arr); i++) {
    msg += "\n";
    for(j = 0 ; j < tab_len ; j++)
      msg += " ";
    msg += arr[i];
  }
  return msg;
}

