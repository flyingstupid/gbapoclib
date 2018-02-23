/* VALID WRITE
 */

status valid_write(string fname, string name) {
    return 0;
}   


/* VALID READ. 
 */

status valid_read(string fname, string name) {
    if(valid_write(fname,name)) return 1;
    if(sscanf(fname,"/d/tempus/w/relgar/%s",fname)){return 1;}
    return 0;
}   

