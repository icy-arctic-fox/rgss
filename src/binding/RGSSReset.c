#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void initRGSSResetClass() {
    ID exceptionId = rb_intern("Exception");
    VALUE exceptionClass = rb_const_get(rb_cObject, exceptionId);
    rb_define_class("RGSSReset", exceptionClass);
}

#ifdef __cplusplus
}
#endif
