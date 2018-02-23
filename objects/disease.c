/* DISEASE. Angel 1992.
 * This object is used in conjunction with undead.c Clerics and some temples
 * have the power to remove diseases from players. Note that this object is
 * contageous!
 */


string sympthoms;
int timer, hoarse_flag, weight, drop_flag;
 
reset(arg) {
    if (arg) return;
    sympthoms = ({
        "cough","sneeze","groan","sniff","shiver"
        });
    }
 
get() { return 1; }
 
drop() {
    if (drop_flag) return;
    return 1;
    }
 
query_auto_load() {
    return "objects/disease:"+ timer;
    }
 
init_args(arg) {
    if (!arg) return;
    sscanf(arg,"%d",timer);
    }
 
id(str) { return str == "Disease" || str == "disease"; }
query_name() { return "Disease"; }
 
init() {
    if (this_player() != environment()) return;
    set_heart_beat(1);
    if (hoarse_flag) {
        add_action("croak","shout");
        add_action("speak","say");
        add_action("speak","'",1);
        }
    }
 
croak(str) {
    if (!str) return 0;
    say(this_player()->query_name() + " croaks: " + str + "\n");
    write("You croak: "+str+"\n");
    return 1;
    }
 
speak(str) {
string what;
    if (query_verb() != "say") {
        what = extract(query_verb(),1);
        if (str) what += " " + str;
        }
    else what = str;
    if (!what) what = "";
    write("You croak: "+what+"\n");
    say(this_player()->query_name()+" croaks: "+ what +"\n");
    if (!random(10)) spread();
    return 1;
    }
 
query_weight() { return weight; }
 
heart_beat() {
    timer ++;
    if (timer > 500 && !random(40)) {
        command(sympthoms[random(sizeof(sympthoms))],environment());
        if (timer < 1000)  /* contagion */
            spread();
        }
    if (timer > 1000 && timer < 1500) {
	if (environment()->query_intoxication() <= 1)
        	environment()->add_intoxination(1); /* stay drunk */
	}
    if (timer > 1300 && timer < 1750) {
	if (environment()->query_stuffed() <= 1)
        environment() -> add_stuffed(1); /* no appetite */
	}
    if (timer > 2000 && !weight) {
        weight = 3;
        environment()->recalc_all();
        drop_flag = 1;
        transfer(this_object(),environment());
        drop_flag = 0;
        }
    if (timer > 3000 && !hoarse_flag) {
        hoarse_flag = 1;
        move_object(this_object(),environment());
        }
    if (environment()->query_ghost()) return;
    if (environment()->query_ghost()) 
        timer = 0;
    }
 
spread() {
  object *ob1;
  int i;

    ob1 = all_inventory(environment(environment()));

    for(i=0; i<sizeof(ob1); i++) {
        if(living(ob1[i]) &&
           ob1[i] -> query_security_level() < 1  &&
          !ob1[i] -> query_spell_immune("disease") &&
          ((int)ob1[i]->query_level() < 10) &&
           !present("Disease", ob1[i]) &&
            random(50) > ob1[i] -> query_constitution()) {
            move_object(clone_object("objects/disease"), ob1[i]);
        }
   }
}

