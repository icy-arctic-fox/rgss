#include "common.h"

VALUE audioModule_setupMidi (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgmPlay (int argc, VALUE *argv, VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgmStop (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgmFade (VALUE audioModule, VALUE time)
{
    // TODO
    return Qnil;
}

VALUE audioModule_getBgmPos (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgsPlay (int argc, VALUE *argv, VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgsStop (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_bgsFade (VALUE audioModule, VALUE time)
{
    // TODO
    return Qnil;
}

VALUE audioModule_getBgsPos (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_mePlay (int argc, VALUE *argv, VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_meStop (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_meFade (VALUE audioModule, VALUE time)
{
    // TODO
    return Qnil;
}

VALUE audioModule_sePlay (int argc, VALUE *argv, VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE audioModule_seStop (VALUE audioModule)
{
    // TODO
    return Qnil;
}

VALUE initAudioModule ()
{
    VALUE audioModule = rb_define_module("Audio");

    rb_define_singleton_method(audioModule, "setup_midi", RB_FUNC(audioModule_setupMidi),  0);
    rb_define_singleton_method(audioModule, "bgm_play",   RB_FUNC(audioModule_bgmPlay),   -1);
    rb_define_singleton_method(audioModule, "bgm_stop",   RB_FUNC(audioModule_bgmStop),    0);
    rb_define_singleton_method(audioModule, "bgm_fade",   RB_FUNC(audioModule_bgmFade),    1);
    rb_define_singleton_method(audioModule, "bgm_pos",    RB_FUNC(audioModule_getBgmPos),  0);
    rb_define_singleton_method(audioModule, "bgs_play",   RB_FUNC(audioModule_bgsPlay),   -1);
    rb_define_singleton_method(audioModule, "bgs_stop",   RB_FUNC(audioModule_bgsStop),    0);
    rb_define_singleton_method(audioModule, "bgs_fade",   RB_FUNC(audioModule_bgsFade),    1);
    rb_define_singleton_method(audioModule, "bgs_pos",    RB_FUNC(audioModule_getBgsPos),  0);
    rb_define_singleton_method(audioModule, "me_play",    RB_FUNC(audioModule_mePlay),    -1);
    rb_define_singleton_method(audioModule, "me_stop",    RB_FUNC(audioModule_meStop),     0);
    rb_define_singleton_method(audioModule, "me_fade",    RB_FUNC(audioModule_meFade),     1);
    rb_define_singleton_method(audioModule, "se_play",    RB_FUNC(audioModule_sePlay),    -1);
    rb_define_singleton_method(audioModule, "se_stop",    RB_FUNC(audioModule_seStop),     0);

    return audioModule;
}
