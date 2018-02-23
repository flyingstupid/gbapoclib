/* Quest Object - Ramses 1993, Revisions by Angel 1994.
 * Original Code by Lemat(-jj) 1992
 */

inherit "inherit/base/base_obj";

int min_level, max_level, qpoints, is_test, q_number;
string author, req_place, req_caller, hint;
string qname;

string query_object_type() { return "Quest_object"; }

void reset(status arg) {   
  if(arg) return;
    hint       = "";
    author     = "";
    req_place  = "*";
    req_caller = "*";
    qpoints    = 10;
    is_test    = 0;
    min_level  = 0;
    max_level  = 19;
    q_number   = 0;
    set_name("quest_object");
} 

 
string short(string wiz) {  
  return q_number+": "+author+"'s - \""+query_name(0)+"\""; 
}
 
status long(string wiz) {  
  object wh;

  wh = this_object();

  write(" Author: "+wh->query_author()+"\n"+
        "Min Level: "+min_level+", Max Level: "+max_level+"\n"+
        " Quest points: "+wh->query_qpoints()+", Quest name: "+ 
          wh->query_qname()+"\n"+
        " Room to complete quest: "+wh->query_req_place()+"\n"+
        " Must be called from object: "+wh->query_req_caller()+"\n");

  if(wh->query_test()) 
    write("Note: This quest is not fully tested yet.\n");

  write("Hint: "+wh->query_hint()+"\n");
  return 1;
}

/* The Set Funs */
string set_author(string who)      {  return author = who;      }
string set_hint(string str)        {  return hint = str;        }
string set_qname(string str) {
  qname = str;
  return ::set_name(str);
}
string set_req_place(string room)  {  return req_place = room;  }
string set_req_caller(string file) {  return req_caller = file; }
 
int set_min_level(int lev)         {  return min_level = lev;   }
int set_max_level(int lev)         {  return max_level = lev;   }
int set_qpoints(int num)           {  return qpoints = num;     }
 
status set_test(status flag)       {  return is_test = flag;    }


/* The Query Funs */
int query_min_level()     { return min_level;     }
int query_max_level()     {  return max_level;    }
int query_qpoints()       {  return qpoints;      }
status query_test()       {  return is_test;      }
string query_qname()      { return qname;         }
string query_name()       { return qname;         }
string query_hint()       {  return hint;         }
string query_author()     {  return author;       }
string query_req_place()  {  return req_place;    }
string query_req_caller() {  return req_caller;   }
