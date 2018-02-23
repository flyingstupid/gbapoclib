inherit "inherit/treasure";


reset(arg)
{
    if (arg)
    { 
        return (0);
    }
    
    set_name("wrist_computer"); //This is so we can target it for guild skills!
    set_short("a wrist computer");
    set_alias("computer");
    set_long(writelong());
    set_weight(0);

}


status look_at()
{
    string str;
    object TP=this_player();
    
    
    str =  "==============Wrist Computer==============\n";
    str += "Nanites:" + TP->query_nanites() + "/" + TP->query_maxnanites() +"\n"; 
    str += "\n";
    str += "Current Programs running:\n";
    //str += check_affects();
    str += "==========================================\n";

    tell_object( this_player(), str );

    return 1;
}

status query_auto_load() { return 1; }
status drop(status wiz)  { return 1; }

