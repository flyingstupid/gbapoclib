status dos2unix(string str)  {
  string text, src, dest;
  notify_fail("Usage: dos2unix <file> [<dest>]\n");
  if (!str) return 0;
  if (sscanf(str, "%s %s", src, dest) != 2)
   dest = src = str;
  src = this_player()->make_path(src);
  dest = this_player()->make_path(dest);
  if ((string)this_player()->valid_read(src) == 0)
   return
    notify_fail("dos2unix: Read access denied.\n");
  if (file_size(src) < 0)
   return
    notify_fail("dos2unix: File not found.\n");
  if ((string)this_player()->valid_write(dest) == 0)
   return
    notify_fail("dos2unix: Write access denied.\n");
  if (src != dest && file_size(dest) > 0)
   return
    notify_fail("dos2unix: Destination already exists.\n");
  text = implode(explode(read_file(src), "\r"), "");
  if (src == dest && rm(src) == 0)
    return
     notify_fail("dos2unix: Failed to overwrite.\n");
  if (write_file(dest, text) == 0)
   return
    notify_fail("dos2unix: Failed to write.\n");
  write("Done.\n");
  return 1;
  }
