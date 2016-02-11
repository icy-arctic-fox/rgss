// Common macros and definitions for use in the binding.

#ifndef COMMON_H
#define	COMMON_H

#ifdef __cplusplus
extern "C" {
#endif
#include <ruby.h>
#ifdef __cplusplus
}

// Required cast to use function references with Ruby in C++.
#define RB_FUNC(FUNCTION) reinterpret_cast<VALUE(*)(...)>(FUNCTION)

// Convenience macro to convert C true/false to Ruby true/false.
#define VALUE2BOOL(VALUE) (VALUE) ? Qtrue : Qfalse;

#endif /* __cplusplus */

#endif	/* COMMON_H */
