//
// FILE NAME: CIDIDL_StructInfo.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 05/29/2017
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file implements the structure info class.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include    "CIDIDL.hpp"


// ---------------------------------------------------------------------------
//  Magic macros
// ---------------------------------------------------------------------------
RTTIDecls(TStructMem,TObject)
RTTIDecls(TStructInfo,TObject)



// ---------------------------------------------------------------------------
//   CLASS: TStructMem
//  PREFIX: tInfo
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TStructMem: Constructors and Destructor
// ---------------------------------------------------------------------------
TStructMem::TStructMem() :

    m_bIsSubStruct(kCIDLib::False)
{
}

TStructMem::TStructMem(const TXMLTreeElement& xtnodeType)
{
    Set(xtnodeType);
}

TStructMem::~TStructMem()
{
}


// ---------------------------------------------------------------------------
//  Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TBoolean TStructMem::bIsSubStruct() const
{
    return m_bIsSubStruct;
}


const TString& TStructMem::strName() const
{
    return m_strName;
}


const TString& TStructMem::strType() const
{
    return m_strType;
}


tCIDLib::TVoid TStructMem::Set(const TXMLTreeElement& xtnodeMem)
{
    m_bIsSubStruct = (xtnodeMem.strQName() == L"CIDIDL:SubStruct");
    m_strName = xtnodeMem.xtattrNamed(L"CIDIDL:Name").strValue();
    m_strType = xtnodeMem.xtattrNamed(L"CIDIDL:Type").strValue();
}



// ---------------------------------------------------------------------------
//   CLASS: TStructInfo
//  PREFIX: mparm
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TStructInfo: Constructors and Destructor
// ---------------------------------------------------------------------------
TStructInfo::TStructInfo(const TXMLTreeElement& xtnodeStruct)
{
    m_strType = xtnodeStruct.xtattrNamed(L"CIDIDL:Type").strValue();

    TStructMem memEmpty;
    const tCIDLib::TCard4 c4ChildCount = xtnodeStruct.c4ChildCount();
    for (tCIDLib::TCard4 c4Index = 0; c4Index < c4ChildCount; c4Index++)
    {
        TStructMem& memNew = m_colMembers.objAdd(memEmpty);
        memNew.Set(xtnodeStruct.xtnodeChildAtAsElement(c4Index));
    }
}

TStructInfo::~TStructInfo()
{
}


// ---------------------------------------------------------------------------
//  TStructInfo: Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TCard4 TStructInfo::c4MemberCount() const
{
    return m_colMembers.c4ElemCount();
}


const TStructMem& TStructInfo::memAt(const tCIDLib::TCard4 c4At) const
{
    return m_colMembers[c4At];
}


const TString& TStructInfo::strType() const
{
    return m_strType;
}

