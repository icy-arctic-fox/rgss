#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void initRGSSErrorClass() {
    ID standardErrorId = rb_intern("StandardError");
    VALUE standardErrorClass = rb_const_get(rb_cObject, standardErrorId);
    rb_define_class("RGSSError", standardErrorClass);
}

#ifdef __cplusplus
}
#endif
