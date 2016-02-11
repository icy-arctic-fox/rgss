#include "common.h"

VALUE inputModule_update (VALUE inputModule)
{
    // TODO
    return Qnil;
}

VALUE inputModule_isPressed (VALUE inputModule, VALUE sym)
{
    // TODO
    return Qnil;
}

VALUE inputModule_isTriggered (VALUE inputModule, VALUE sym)
{
    // TODO
    return Qnil;
}

VALUE inputModule_isRepeating (VALUE inputModule, VALUE sym)
{
    // TODO
    return Qnil;
}

VALUE inputModule_dir4 (VALUE inputModule)
{
    // TODO
    return Qnil;
}

VALUE inputModule_dir8 (VALUE inputModule)
{
    // TODO
    return Qnil;
}

void initInputModule ()
{
    VALUE inputModule = rb_define_module("Input");

    rb_define_singleton_method(inputModule, "update",   RB_FUNC(inputModule_update),      0);
    rb_define_singleton_method(inputModule, "press?",   RB_FUNC(inputModule_isPressed),   1);
    rb_define_singleton_method(inputModule, "trigger?", RB_FUNC(inputModule_isTriggered), 1);
    rb_define_singleton_method(inputModule, "repeat?",  RB_FUNC(inputModule_isRepeating), 1);
    rb_define_singleton_method(inputModule, "dir4",     RB_FUNC(inputModule_dir4),        0);
    rb_define_singleton_method(inputModule, "dir8",     RB_FUNC(inputModule_dir8),        0);

    rb_define_const(inputModule, "DOWN",  ID2SYM(rb_intern("DOWN")));
    rb_define_const(inputModule, "LEFT",  ID2SYM(rb_intern("LEFT")));
    rb_define_const(inputModule, "RIGHT", ID2SYM(rb_intern("RIGHT")));
    rb_define_const(inputModule, "UP",    ID2SYM(rb_intern("UP")));
    rb_define_const(inputModule, "A",     ID2SYM(rb_intern("A")));
    rb_define_const(inputModule, "B",     ID2SYM(rb_intern("B")));
    rb_define_const(inputModule, "C",     ID2SYM(rb_intern("C")));
    rb_define_const(inputModule, "X",     ID2SYM(rb_intern("X")));
    rb_define_const(inputModule, "Y",     ID2SYM(rb_intern("Y")));
    rb_define_const(inputModule, "Z",     ID2SYM(rb_intern("Z")));
    rb_define_const(inputModule, "L",     ID2SYM(rb_intern("L")));
    rb_define_const(inputModule, "R",     ID2SYM(rb_intern("R")));
    rb_define_const(inputModule, "SHIFT", ID2SYM(rb_intern("SHIFT")));
    rb_define_const(inputModule, "CTRL",  ID2SYM(rb_intern("CTRL")));
    rb_define_const(inputModule, "ALT",   ID2SYM(rb_intern("ALT")));
    rb_define_const(inputModule, "F5",    ID2SYM(rb_intern("F5")));
    rb_define_const(inputModule, "F6",    ID2SYM(rb_intern("F6")));
    rb_define_const(inputModule, "F7",    ID2SYM(rb_intern("F7")));
    rb_define_const(inputModule, "F8",    ID2SYM(rb_intern("F8")));
    rb_define_const(inputModule, "F9",    ID2SYM(rb_intern("F9")));
}
