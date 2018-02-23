#ifndef LPC_FUNCTIONLIST_H
#define LPC_FUNCTIONLIST_H

#ifndef __DRIVER_SOURCE__
#include "lpctypes.h"
#endif

#define NAME_INHERITED      0x80000000 /* Defined by inheritance         */
#define TYPE_MOD_STATIC     0x40000000 /* Static function or variable    */
#define TYPE_MOD_NO_MASK    0x20000000 /* The nomask => not redefineable */
#define TYPE_MOD_PRIVATE    0x10000000 /* Can't be inherited             */
#define TYPE_MOD_PUBLIC     0x08000000 /* Force inherit through private  */
#define TYPE_MOD_VARARGS    0x04000000 /* Used for type checking         */
#define TYPE_MOD_VIRTUAL    0x02000000  /* can be re- and cross- defined  */
#define TYPE_MOD_PROTECTED  0x01000000 /* cannot be called externally    */
#define TYPE_MOD_XVARARGS   0x00800000  /* accepts optional arguments     */
#define TYPE_MOD_NOSAVE     0x00400000  /* vars: can't be saved           */
#define NAME_CROSS_DEFINED  0x00080000 /* function defined from other program */
#define NAME_HIDDEN         0x00000800 /* Not visible for inheritance    */
#define NAME_PROTOTYPE      0x00000400 /* Defined by a prototype only    */
#define NAME_UNDEFINED      0x00000200 /* Not defined yet                */
#define NAME_TYPES_LOST     0x00000100 /* inherited, no save_types       */

/* Return value flag types for functionlist() */

#define RETURN_FUNCTION_NAME	0x01
#define RETURN_FUNCTION_FLAGS	0x02
#define RETURN_FUNCTION_TYPE	0x04
#define RETURN_FUNCTION_NUMARG	0x08
#define RETURN_FUNCTION_ARGTYPE 0x10 /* not implemented */

/* Return value flag types for function_exists() */

#define FEXISTS_PROGNAME  (0)
#define FEXISTS_FILENAME  (1)
#define FEXISTS_LINENO    (2)
#define FEXISTS_ALL       (3)

#endif /* LPC_FUNCTIONLIST_H */
