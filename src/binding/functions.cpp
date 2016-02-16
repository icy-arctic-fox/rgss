#include "common.h"

// Ruby script containing the remaining functions.
// The other functions are implemented in Ruby because it's much simpler to do so.
// This string is generated from functions.rb.
extern const char functions_rb[];

VALUE function_msgbox (int argc, VALUE *argv)
{
    // TODO
    return Qnil;
}

VALUE function_rgss_main ()
{
    // TODO: Start game window.
    rb_yield_values(0);
    return Qnil;
}

VALUE function_rgss_stop ()
{
    // TODO
    return Qnil;
}

void initFunctions ()
{
    rb_define_global_function("rgss_main", RB_FUNC(function_rgss_main),  0);
    rb_define_global_function("rgss_stop", RB_FUNC(function_rgss_stop),  0);
    rb_define_global_function("msgbox",    RB_FUNC(function_msgbox),    -1);
    rb_eval_string(functions_rb); // Evaluate the ruby code to define the remaining functions.
}
