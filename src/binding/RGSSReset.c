#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

VALUE initRGSSResetClass() {
    return rb_define_class("RGSSReset", rb_eException);
}

#ifdef __cplusplus
}
#endif
