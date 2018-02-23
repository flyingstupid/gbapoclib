/****************************************************************************
 * Inheritable Soul Object for the Heaven 7 mudlib.                         *
 *                                                                          *
 * OBJECT DESCRIPTION                                                       *
 * ******************                                                       *
 *                                                                          *
 * This object is inherited by all soul objects to provide the basic        *
 * functionality of the Soul Daemon system.                                 *
 *                                                                          *
 * OBJECT HISTORY                                                           *
 * **************                                                           *
 * 1998.08.09 - Object incorporated from the Castinian mudlib.              *
 *                                                                          *
 ****************************************************************************/

private string sOriginFormat;
private string sTargetFormat;
private string sOtherFormat;
private string sDefaultAdverb;
private int iAdverbRequired;

nomask static void set_origin_view(string sFormatString)
{
  sOriginFormat = sFormatString;
}


nomask static void set_target_view(string sFormatString)
{
  sTargetFormat = sFormatString;
}


nomask static void set_other_view(string sFormatString)
{
  sOtherFormat = sFormatString;
}


nomask static void set_default_adverb(string sVerb)
{
  sDefaultAdverb = sVerb;
}


nomask static int set_adverb_required(int i) { return iAdverbRequired = i; }
nomask int query_adverb_required() { return iAdverbRequired; }

nomask string query_origin_view()
{
  return sOriginFormat;
}


nomask string query_target_view()
{
  return sTargetFormat;
}


nomask string query_other_view()
{
  return sOtherFormat;
}


nomask string query_default_adverb()
{
  return sDefaultAdverb;
}
