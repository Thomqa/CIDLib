//
// FILE NAME: CIDLib_Formattable.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 09/24/1996
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This header implments the mixin class, MFormattable, which bestows
//  upon its mixed into classes the ability to be formatted to a text
//  stream.
//
//  A global operator<< is provided here that will allow any formattable
//  object to be formatted to a text stream.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//  Forward references
// ---------------------------------------------------------------------------
class   TTextOutStream;



// ---------------------------------------------------------------------------
//  CLASS: MFormattable
// PREFIX: fmtbl
// ---------------------------------------------------------------------------
class CIDLIBEXP MFormattable
{
    public  :
        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        MFormattable() = default;

        virtual ~MFormattable() = default;


    protected   :
        // -------------------------------------------------------------------
        //  Declare our friends
        //
        //  The global methods below must have access to our protected
        //  stream methods.
        // -------------------------------------------------------------------
        friend TTextOutStream& operator<<
        (
                    TTextOutStream&         strmToWriteTo
            , const MFormattable&           fmtblToWrite
        );


        // -------------------------------------------------------------------
        //  Hidden but available so that our derived classes can have default
        //  generated copy and assignment.
        // -------------------------------------------------------------------
        MFormattable(const MFormattable&) = default;
        MFormattable& operator=(const MFormattable&) = default;


        // -------------------------------------------------------------------
        //  Protected virtual methods
        // -------------------------------------------------------------------
        virtual tCIDLib::TVoid FormatTo
        (
                    TTextOutStream&         strmDest
        )   const = 0;


    private :
        // -------------------------------------------------------------------
        //  Magic macros
        // -------------------------------------------------------------------
        NulObject(MFormattable)
};

#pragma CIDLIB_POPPACK


// ---------------------------------------------------------------------------
//  Provide the global operators that allow any streamable object to be
//  formatted out to a text stream. This is what the outside world uses.
// ---------------------------------------------------------------------------
inline TTextOutStream&
operator<<(TTextOutStream& strmToWriteTo, const MFormattable& fmtblToWrite)
{
    fmtblToWrite.FormatTo(strmToWriteTo);
    return strmToWriteTo;
}
