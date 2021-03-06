//
// FILE NAME: CIDLib_ExpCharBuf.cpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 07/14/1999
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This file implements the TExpCharBuf class.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//  Facility specific includes
// ---------------------------------------------------------------------------
#include    "CIDLib_.hpp"


// ---------------------------------------------------------------------------
//  Do our RTTI macros
// ---------------------------------------------------------------------------
RTTIDecls(TExpCharBuf,TObject)



// ---------------------------------------------------------------------------
//   CLASS: TExpCharBuf
//  PREFIX: expb
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  TExpCharBuf: Constuctors and Destructor
// ---------------------------------------------------------------------------
TExpCharBuf::TExpCharBuf(const tCIDLib::TCard4 c4InitAlloc) :

    m_c4CurSize(c4InitAlloc)
    , m_c4CurOfs(0)
    , m_pszBuffer(0)
{
    // If the init size was zero, then set it to 256
    if (!m_c4CurSize)
        m_c4CurSize = 256;

    // Add one to leave room for the null
    m_pszBuffer = new tCIDLib::TCh[m_c4CurSize + 1];
}


TExpCharBuf::~TExpCharBuf()
{
    delete [] m_pszBuffer;
}


// ---------------------------------------------------------------------------
//  TExpCharBuf: Public, non-virtual methods
// ---------------------------------------------------------------------------
tCIDLib::TVoid TExpCharBuf::Append(const tCIDLib::TCh chToAppend)
{
    // Expand it if we have to
    if (m_c4CurOfs == m_c4CurSize)
    {
        // Create a new size 1.5 times larger
        const tCIDLib::TCard4 c4NewSize = tCIDLib::TCard4(m_c4CurSize * 1.5);

        // Allocate a temp, making sure to add one for the null
        tCIDLib::TCh* pszTmp = new tCIDLib::TCh[c4NewSize + 1];

        //
        //  Now copy over the old content and delete the old buffer. Be sure
        //  to account for character size!
        //
        TRawMem::CopyMemBuf
        (
            pszTmp
            , m_pszBuffer
            , m_c4CurSize * kCIDLib::c4CharBytes
        );
        delete [] m_pszBuffer;

        // Store the new pointer and size
        m_pszBuffer = pszTmp;
        m_c4CurSize = c4NewSize;
    }

    // Store the char and bump the current offset
    m_pszBuffer[m_c4CurOfs++] = chToAppend;
}


tCIDLib::TCard4 TExpCharBuf::c4Chars() const
{
    return m_c4CurOfs;
}


const tCIDLib::TCh* TExpCharBuf::pszBuffer() const
{
    m_pszBuffer[m_c4CurOfs] = kCIDLib::chNull;
    return m_pszBuffer;
}


tCIDLib::TCh* TExpCharBuf::pszReplicateBuffer() const
{
    // Cap it off and then replicate the buffer and return it
    m_pszBuffer[m_c4CurOfs] = kCIDLib::chNull;
    return TRawStr::pszReplicate(m_pszBuffer);
}


tCIDLib::TVoid TExpCharBuf::RemoveTrailingSpace()
{
    // If not chars, then nothing to do
    if (!m_c4CurOfs)
        return;

    // Get a temp pointer past the end of the input
    tCIDLib::TCh* pszTmp = &m_pszBuffer[m_c4CurOfs];

    //
    //  Test the previous char to see if its a space. If so, then move the
    //  pointer backwards. If go past the base address, then it was all space
    //  so just cap it at the zeroth char. If not a space then break out and
    //  cap it where we are.
    //
    while (TRawStr::bIsSpace(*(pszTmp - 1)))
    {
        pszTmp--;
        if (pszTmp == m_pszBuffer)
        {
            // Its was all space
            *m_pszBuffer = kCIDLib::chNull;
            return;
        }
    }

    // Cap it off where we are currently pointing
    *pszTmp = kCIDLib::chNull;
}


tCIDLib::TVoid TExpCharBuf::Reset()
{
    m_c4CurOfs = 0;
}


