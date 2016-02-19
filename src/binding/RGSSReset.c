#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void initRGSSResetClass() {
    rb_define_class("RGSSReset", rb_eException);
}

#ifdef __cplusplus
}
#endif
