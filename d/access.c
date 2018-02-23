/* DO NOT ADD ANYTHING BELOW HERE */
string *HIGHLORDS;

void reset(status arg) {
  if(arg) return;
  HIGHLORDS = ({
  "angel",        "tempus",
    "alena",        "ooc",
    "angel",        "aff",
    "angel",        "affils",
    "angel",        "sorcery",
    "sarak",        "minos",
    "leanai",       "statiu",
    "critical",     "wastelands",
    });
}

/* DO NOT ADD ANYTHING ABOVE HERE */

/* Domain access object, this will update itself with create_wizard()
 * It is important to that you don't touch anything above this comment.
 *
 * Only Arches have write access to this.
 */

/* Valid Write control over /d/  */

status valid_write(string fname, string name) {
 string domain, file;
  int i;

  if(sscanf(fname,"/d/%s/%s", domain, file) == 2) {
    for(i = 0; i < sizeof(HIGHLORDS); i += 2) {
      if(name == HIGHLORDS[i] && domain == HIGHLORDS[i+1]) return 1;
    }
    if(file == "access.c") return 0;
    return (status)call_other("/d/"+domain+"/access","valid_write",fname,name);
  }
  return 0;
}

/* Valid Read for /d */

status valid_read(string fname, string name) {
  string domain, who, file;
  int i;

  if(valid_write(fname,name)) return 1;
  if(sscanf(fname,"/d/%s/%s",domain,file) == 2) {
    return (status)call_other("/d/"+domain+"/access","valid_read",fname,name);
  }
  if(sscanf(fname,"/d/%s", file) == 1) { /* Highlords have read access */
    if(member_array(name,HIGHLORDS) != -1) return 1;
  }
}

status query_domain_lord(string domain) {
  int i;
  string name;

  name = (string)this_player()->query_name(1);
  for(i = 0; i < sizeof(HIGHLORDS); i += 2) {
    if(name == HIGHLORDS[i] && domain == HIGHLORDS[i+1]) return 1;
  }
  return 1;
}

/* end access */
