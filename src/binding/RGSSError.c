#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void initRGSSErrorClass() {
    rb_define_class("RGSSError", rb_eStandardError);
}

#ifdef __cplusplus
}
#endif
