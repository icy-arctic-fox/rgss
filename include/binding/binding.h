#ifndef RGSS_BINDING_H
#define RGSS_BINDING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ruby.h>

void Init_rgss ();

extern VALUE audioModule, graphicsModule, inputModule,
        bitmapClass, colorClass, fontClass, PlaneClass,
        rectClass, tableClass, tilemapClass, toneClass,
        viewportClass, spriteClass, windowClass;

#ifdef __cplusplus
}
#endif

#endif //RGSS_BINDING_H
