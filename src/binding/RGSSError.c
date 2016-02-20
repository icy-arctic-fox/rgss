#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

VALUE initRGSSErrorClass() {
    return rb_define_class("RGSSError", rb_eStandardError);
}

#ifdef __cplusplus
}
#endif
