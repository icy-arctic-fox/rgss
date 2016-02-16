#ifndef RGSS_BINDING_H
#define RGSS_BINDING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ruby.h>

void Init_rgss ();

extern const char functions_rb[];

#ifdef __cplusplus
}
#endif

#endif //RGSS_BINDING_H
