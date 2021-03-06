//
// FILE NAME: CIDMacroDbg.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 02/14/2003
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the main public header for the facility. It is the single point
//  of contact for the outside world. By including it, they get what we
//  have to offer.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


// ---------------------------------------------------------------------------
//  Set up our import/export attributes
// ---------------------------------------------------------------------------
#if     defined(PROJ_CIDMACRODBG)
#define CIDMACRODBGEXP    DLLEXPORT
#else
#define CIDMACRODBGEXP    DLLIMPORT
#endif


// ---------------------------------------------------------------------------
//  Include our needed underlying headers.
// ---------------------------------------------------------------------------
#include    "CIDCtrls.hpp"
#include    "CIDWUtils.hpp"
#include    "CIDMacroEng.hpp"


// ---------------------------------------------------------------------------
//  Include our public headers
// ---------------------------------------------------------------------------
#include    "CIDMacroDbg_Type.hpp"
#include    "CIDMacroDbg_ErrorIds.hpp"
#include    "CIDMacroDbg_ResourceIds.hpp"
#include    "CIDMacroDbg_Constant.hpp"

#include    "CIDMacroDbg_StateInfo.hpp"
#include    "CIDMacroDbg_SrcTab.hpp"
#include    "CIDMacroDbg_DbgMainWnd.hpp"
#include    "CIDMacroDbg_ThisFacility.hpp"


// ---------------------------------------------------------------------------
//  Export the facility object lazy evaluator function.
// ---------------------------------------------------------------------------
extern CIDMACRODBGEXP TFacCIDMacroDbg& facCIDMacroDbg();


