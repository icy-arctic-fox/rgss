#include "common.h"

VALUE function_msgbox (int argc, VALUE *argv)
{
    // TODO
    return Qnil;
}

void initFunctions ()
{
    rb_define_global_function("msgbox", RB_FUNC(function_msgbox), -1);
}
