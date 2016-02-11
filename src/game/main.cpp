#include <binding.h>
#include <symbols.h> // Generated by CMake - contains RPG classes.

// Defined in bootstrap.rb.c and generated from bootstrap.rb.
extern char *bootstrap_rb;

void initRuby (int argc, char **argv)
{
    ruby_sysinit(&argc, &argv);
    ruby_init();
    ruby_init_loadpath();
}

void initRPGScripts ()
{
    for(int i = 0; i < rpg_script_count; ++i)
        rb_eval_string(rpg_scripts[i]);
}

void displayError ()
{
    VALUE ruby_error    = rb_gv_get("$!");
    VALUE error_message = rb_funcall(ruby_error, rb_intern("message"), 0);
    VALUE error_trace   = rb_funcall(ruby_error, rb_intern("backtrace"), 0);
    VALUE error_stack   = rb_ary_join(error_trace, rb_str_new2("\n"));

    char *message_str = StringValuePtr(error_message);
    char *trace_str   = StringValuePtr(error_stack);
    printf("%s\n%s\n", message_str, trace_str);
}

int bootstrap ()
{
    int state;
    rb_eval_string_protect(bootstrap_rb, &state);
    if(state) // An error occurred.
        displayError();
    return state;
}

int main(int argc, char** argv)
{
    initRuby(argc, argv);
    Init_rgss();
    initRPGScripts();
    int state = bootstrap();
    ruby_finalize();

    return state;
}
