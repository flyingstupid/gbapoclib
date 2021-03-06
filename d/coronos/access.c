 /* Domain Lord Access Control Object */
#define LORD "terral"
#define SAGE "darkness"
#define BLAH "vorax"




/* As domain lord you have access control to files in your domain.
 * You have access to all your domain files. Using the 'domain' command you
 * can add more creators to your domain. You can set up your own hierachy
 * of creators if you wish. It is important to note that you have complete
 * control. You can block as well as give access. Only Arches, and you can
 * can add new creator directories (through the 'domain' cmd). Only the
 * highlord of the domain and arches can edit this file.
 *
 * A return of 1 will give 'name' access to the file, fname.
 * A return of 0 will give default access. (I think its sec level 60
 * for valid write to d/domain/w/, and sec level 50 for valid_read)
 */

/* VALID WRITE
 */

status valid_write(string fname, string name) {
  string domain, who, file;

  if(LORD == name) return 1;
  if(SAGE == name) return 1;
  if(name == "kreston") return 1;
if(BLAH == name) return 1;
  if(sscanf(fname,"/d/%s/w/%s/%s", domain, who, file) == 3) {
    if(name == who) return 1;        /* owner gets auto access to files */
    if(file == "access.c") return 0; /* only let owner edit access ob   */
    if(call_other("/d/"+domain+"/w/"+who+"/access","valid_write",fname,name)){
      return 1; /* owner access ob says they have write access to file */
    }
  }
  return 0;
}   


/* VALID READ. 
 */

status valid_read(string fname, string name) {
  string domain, who, file;

  return 1;
  /* an old domain, completed. creators have moved on
     so we're now openning it all up to reading for other
     creators to show them and so they can learn :)
   */
  if(valid_write(fname,name)) return 1;
  if(sscanf(fname,"/d/%s/w/%s", domain, who)) {
    if(who == name) return 1;
  }
  if(sscanf(fname,"/d/%s/w/%s/%s", domain, who, file) == 3) {
    if(name == who) return 1;
    if(call_other("/d/"+domain+"/w/"+who+"/access","valid_read",fname,name)){
      return 1;
    }
  }
  return 0;
}   

