#include <binding.h>
#include <symbols.h> // Generated by CMake - contains RPG classes.

// Defined in bootstrap.rb.c and generated from bootstrap.rb.
// The bootstrap script is what loads the RPG Maker project scripts and executes them.
// It loads Data/Scripts.rvdata2 and processes the scripts inside it.
extern const char bootstrap_rb[];

// Defined in inifile.rb.c and generated from inifile.rb.
// The inifile code was taken from here: https://github.com/twp/inifile
// This code is used to load the Game.ini file.
extern const char inifile_rb[];

void initRuby (int argc, char **argv)
{
    ruby_sysinit(&argc, &argv);
    ruby_init();
    ruby_init_loadpath();
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

int initRPGScripts ()
{
    int state = 0;

    for(int i = 0; i < rpg_script_count; ++i)
    {
        rb_eval_string_protect(rpg_scripts[i], &state);
        if(state)
        {
            // An error occurred.
            displayError();
            break; // Don't process anymore scripts.
        }
    }

    return state;
}

int initIniFile ()
{
    int state;
    rb_eval_string_protect(inifile_rb, &state);
    if(state) // An error occurred.
        displayError();
    return state;
}

int bootstrap ()
{
    int state;
    rb_eval_string_protect(bootstrap_rb, &state);
    if(state) // An error occurred.
        displayError();
    return state;
}

int main (int argc, char** argv)
{
    initRuby(argc, argv);

    // Don't continue processing if an error occurs anywhere along the way.
    int state;
    if(!(state = initIniFile()))
    {
        Init_rgss();
        if (!(state = initRPGScripts()))
            state = bootstrap();
    }

    ruby_finalize();
    return state;
}
