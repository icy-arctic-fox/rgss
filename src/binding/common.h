// Common macros and definitions for use in the binding.

#ifndef COMMON_H
#define	COMMON_H

#include <ruby.h>

#ifdef __cplusplus

// Required cast to use function references with Ruby in C++.
#define RB_FUNC(FUNCTION) reinterpret_cast<VALUE(*)(...)>(FUNCTION)

// Convenience macro to convert C true/false to Ruby true/false.
#define VALUE2BOOL(VALUE) (VALUE) ? Qtrue : Qfalse;

// Ruby values for each module and class.
extern VALUE audioModule, graphicsModule, inputModule,
        bitmapClass, colorClass, fontClass, PlaneClass,
        rectClass, tableClass, tilemapClass, toneClass,
        viewportClass, spriteClass, windowClass;

#endif /* __cplusplus */

#endif	/* COMMON_H */
