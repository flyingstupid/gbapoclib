/* access.c for /d/coronos/w/darkness */

/* Domain Creator Directory Access Control Object */
 
/* This is your domain access object, so you have access control of files.
   You can give access to files in your directory. However, the domain
   lord can override access to your files.
  
   A return of 1 will give 'name' access to the file, fname.  */
 
/* VALID WRITE */

 
status valid_write(string fname, string name) {
  if (name == "newstar") return 1;
  return 0;
}
 
 
/* VALID READ. */

 
status valid_read(string fname, string name) {
  if(valid_write(fname,name)) return 1;
  
  return 0;
}
