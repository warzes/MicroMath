#pragma once

//=============================================================================
// Config Micro Math
//=============================================================================

// Active states
#define MM_DISABLE 0
#define MM_ENABLE 1

#if !defined(MM_ENABLE_NOSTDHEADER)
#	define MM_ENABLE_NOSTDHEADER         MM_DISABLE
#endif

#if !defined(MM_ENABLE_FORCE_INLINE)
#	define MM_ENABLE_FORCE_INLINE        MM_ENABLE
#endif

#if !defined(MM_ENABLE_ASSERT)
#	define MM_ENABLE_ASSERT              MM_ENABLE
#endif

#if !defined(MM_ENABLE_COLLISIONS)
#	define MM_ENABLE_COLLISIONS          MM_ENABLE
#endif

#if !defined(MM_ENABLE_SUPPORT_DOUBLE_TYPE)
#	define MM_ENABLE_SUPPORT_DOUBLE_TYPE MM_ENABLE
#endif

#if !defined(MM_ENABLE_SUPPORT_INT_TYPE)
#	define MM_ENABLE_SUPPORT_INT_TYPE    MM_ENABLE
#endif

//=============================================================================
// Core
//=============================================================================
#include "detail/core/Core.h"
#include "detail/core/VecType.h"

//=============================================================================
// Support Collisions
//=============================================================================
#if MM_ENABLE_COLLISIONS

#endif