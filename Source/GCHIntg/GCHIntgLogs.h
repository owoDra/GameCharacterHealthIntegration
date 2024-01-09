// Copyright (C) 2024 owoDra

#pragma once

#include "Logging/LogMacros.h"

GCHINTG_API DECLARE_LOG_CATEGORY_EXTERN(LogGCHI, Log, All);

#if !UE_BUILD_SHIPPING

#define GCHILOG(FormattedText, ...) UE_LOG(LogGCHI, Log, FormattedText, __VA_ARGS__)

#define GCHIENSURE(InExpression) ensure(InExpression)
#define GCHIENSURE_MSG(InExpression, InFormat, ...) ensureMsgf(InExpression, InFormat, __VA_ARGS__)
#define GCHIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) ensureAlwaysMsgf(InExpression, InFormat, __VA_ARGS__)

#define GCHICHECK(InExpression) check(InExpression)
#define GCHICHECK_MSG(InExpression, InFormat, ...) checkf(InExpression, InFormat, __VA_ARGS__)

#else

#define GCHILOG(FormattedText, ...)

#define GCHIENSURE(InExpression) InExpression
#define GCHIENSURE_MSG(InExpression, InFormat, ...) InExpression
#define GCHIENSURE_ALWAYS_MSG(InExpression, InFormat, ...) InExpression

#define GCHICHECK(InExpression) InExpression
#define GCHICHECK_MSG(InExpression, InFormat, ...) InExpression

#endif