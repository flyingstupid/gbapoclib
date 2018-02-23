
void master_create_wizard(string owner,string domain,object caller) {
  string txt, tmp1, tmp2;
  object access;
  int tmp;

  if(!owner) return 0;

  if(!valid_player_call(caller)) return 0;
  write_file("/log/WIZ",
    "Name: "+ owner +", By: "+ (string)this_player()->query_real_name()
   +" Time: "+ ctime(time()) +"\n");

  /* promote wizard */

  if(!domain) {
    if(file_size(WIZARD_DIR+ owner) != -2) {
      tell_object(caller,"Adding Wizard Directory...\n");
      mkdir(WIZARD_DIR+ owner);
    }
    if(file_size(WIZARD_DIR+ owner +"/open") != -2) {
      tell_object(caller,"Adding Open directory, ~/open\n");
      mkdir(WIZARD_DIR+ owner +"/open");
    }
    if(file_size(WIZARD_DIR+ owner +"/private") != -2) {
      tell_object(caller,"Adding Private directory, ~/private\n");
      mkdir(WIZARD_DIR+ owner +"/private");
    }
    if(file_size(WIZARD_DIR+ owner +"/"+ DEAD_ED) != -2) {
      tell_object(caller,"Adding dead edit directory, ~/"+ DEAD_ED +"\n");
      mkdir(WIZARD_DIR+ owner +"/"+ DEAD_ED);
    }
    if(file_size(INIT_ACCESS) > 0
    && file_size(WIZARD_DIR+ owner +"/access.c") < 0) {
      tell_object(caller,"Adding Configurable Access Object...\n");
      txt = "#define NAME \""+ owner +"\"\n";
      write_file(WIZARD_DIR+ owner +"/access.c",txt);
      txt = read_file(INIT_ACCESS);
      write_file(WIZARD_DIR+ owner +"/access.c",txt);
    }
    if(file_size(INIT_WORKROOM) > 0
    && file_size(WIZARD_DIR+ owner +"/workroom.c") < 0) {
      tell_object(caller,"Adding Workroom...\n");
       txt = "#include <mudlib.h>\ninherit ROOM;\n\n";
      write_file(WIZARD_DIR+ owner +"/workroom.c",txt);
      txt = read_file(INIT_WORKROOM);
      write_file(WIZARD_DIR+ owner +"/workroom.c",txt);
    }
  }
  else { /* Add wizard to domain */
    if(file_size(DOMAIN_DIR+ domain) != -2) {
      if(catch(call_other(DOMAIN_DIR +"access","??"))) {
        write("Error In Loading Head Domain Access Object!\n");
      }

      if(query_player_level("create domain")) {
        write("Adding New Domain...\nMaking "+ owner +" the High Lord.\n");
        if(this_player() != caller) {
          tell_object(caller,"Adding New Domain...\n"+
            "You are now High Lord over "+ domain +".\n");
        }
        mkdir(DOMAIN_DIR+ domain);


        txt = read_bytes(DOMAIN_DIR +"access.c",
                         0, file_size(DOMAIN_DIR +"access.c"));

        rm(DOMAIN_DIR +"access.bak");
        write_file(DOMAIN_DIR +"access.bak",txt);

        sscanf(txt, "%s});%s", tmp1, tmp2);
        txt = "\""+owner+"\",                     ";
        txt = txt[0..15];
        txt += "\""+ domain +"\",\n";
        txt = tmp1+txt +"    });"+ tmp2;
        rm(DOMAIN_DIR +"access.c");
        write_file(DOMAIN_DIR +"access.c",txt);
        if((access = find_object(DOMAIN_DIR +"access"))) {
          destruct(access);
        }
        if(catch(call_other(DOMAIN_DIR +"access","??"))) {
          write("Error In Reloading Head Domain Access Object!\n");
        }
      }
      else {
        write("You cannot add a New Domain.\n");
        return 0;
      }
    }
    if(file_size(DOMAIN_DIR+ domain +"/access.c") < 0) {
      txt = read_bytes(DOMAIN_ACCESS,0,file_size(DOMAIN_ACCESS));
      write_file(DOMAIN_DIR+domain+"/access.c",txt);
      if(catch(call_other(DOMAIN_DIR+ domain +"/access","??"))) {
        write("Error In Reloading Domain Access Object!\n");
      }
    }
    if(file_size(DOMAIN_DIR+ domain +"/w") != -2) {
      mkdir(DOMAIN_DIR+ domain +"/w");
    }
    if(file_size(DOMAIN_DIR+ domain +"/w/"+ owner) != -2) {
      tell_object(caller,"Adding Domain directory...\n");
      mkdir(DOMAIN_DIR+ domain +"/w/"+ owner);
    }
    if(file_size(DOMAIN_DIR+ domain +"/w/"+ owner +"/access.c") < 0) {
      tell_object(caller,"Adding Configurable Access Object...\n");
      txt = read_bytes(PLAYER_DOMAIN_ACCESS,0,file_size(PLAYER_DOMAIN_ACCESS));
      write_file(DOMAIN_DIR+ domain +"/w/"+ owner +"/access.c",txt);
      if(catch(call_other(DOMAIN_DIR+domain+"/w/"+owner+"/access","??"))) {
        write("Error In Reloading Domain Creator Access Object!\n");
      }
    }
  }
}
