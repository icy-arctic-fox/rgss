#include "common.h"

// Ruby script containing the remaining functions.
// The other functions are implemented in Ruby because it's much simpler to do so.
// This string is generated from functions.rb.
extern const char functions_rb[];

// Can't seem to find an easy way to communicate between function_rgss_main, function_rgss_main_cb, and function_rgss_main_rescue.
// So, this global is set to true when RGSSReset is raised in rgss_main.
bool rgss_reset;

VALUE function_rgss_main_cb (VALUE args)
{
    rgss_reset = false;
    return rb_yield_values(0);
}

VALUE function_rgss_main_rescue (VALUE args, VALUE exception)
{
    rgss_reset = true;
    return Qnil;
}

VALUE function_msgbox (int argc, VALUE *argv)
{
    // TODO
    return Qnil;
}

VALUE function_rgss_main ()
{
    rb_need_block();

    // TODO: Start game window.

    // Get the class representing RGSSReset.
    // That's the only exception we want to respond to.
    ID resetId = rb_intern("RGSSReset");
    VALUE resetClass = rb_const_get(rb_cObject, resetId);

    do
    {
        // rb_rescue() doesn't catch exceptions thrown by pure Ruby, rb_rescue2() does.
        rb_rescue2(RB_FUNC(function_rgss_main_cb), Qnil, RB_FUNC(function_rgss_main_rescue), Qnil, resetClass, (VALUE)0);
    } while(rgss_reset);

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
