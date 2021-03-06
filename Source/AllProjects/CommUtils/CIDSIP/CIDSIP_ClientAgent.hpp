//
// FILE NAME: CIDSIP_ClientAgent.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 5/19/2013
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header for the CIDSIP_ClientAgent.cpp file. This implements
//  the client side agent. It derives from the base agent class and provides
//  client side specific functionality.
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
//   CLASS: TSIPCAgent
//  PREFIX: sipcag
// ---------------------------------------------------------------------------
class CIDSIPEXP TSIPCAgent : public TSIPAgent
{
    public  :
        // -------------------------------------------------------------------
        //  Destructor
        // -------------------------------------------------------------------
        TSIPCAgent
        (
            const   TString&                strLocAddr
            , const TString&                strLocContact
            , const TString&                strLocDisplay
        );

        ~TSIPCAgent();


        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------


    protected :
        // -------------------------------------------------------------------
        //  Protected, non-virtual methods
        // -------------------------------------------------------------------


    private :
        // -------------------------------------------------------------------
        //  Unimplemented constructors and operators
        // -------------------------------------------------------------------
        TSIPCAgent(const TSIPCAgent&);
        tCIDLib::TVoid operator=(const TSIPCAgent&);


        // -------------------------------------------------------------------
        //  Magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TSIPCAgent, TSIPAgent)
};


#pragma CIDLIB_POPPACK



