//
// FILE NAME: TestAI.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 12/25/2016
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the main header file of the CIDLib AI engine test app. This is
//  a standard CIDLib test framework test app.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// -----------------------------------------------------------------------------
//  Include underlying headers
// -----------------------------------------------------------------------------
#include    "CIDAI.hpp"
#include    "TestFWLib.hpp"



// ---------------------------------------------------------------------------
//  CLASS: TCIDAITestApp
// PREFIX: tfwapp
//
//  This is our implementation of the test framework's test program framework.
//  We just create a derivative and override some methods.
// ---------------------------------------------------------------------------
class TCIDAITestApp : public TTestFWApp
{
    public  :
        // -------------------------------------------------------------------
        //  Constructor and Destructor
        // -------------------------------------------------------------------
        TCIDAITestApp();

        TCIDAITestApp(const TCIDAITestApp&) = delete;

        ~TCIDAITestApp();


        // -------------------------------------------------------------------
        //  Public, inherited methods
        // -------------------------------------------------------------------
        tCIDLib::TBoolean bInitialize
        (
                    TString&                strErr
        )   override;

        tCIDLib::TVoid LoadTests() override;

        tCIDLib::TVoid PostTest
        (
            const   TTestFWTest&            tfwtFinished
        )   override;

        tCIDLib::TVoid PreTest
        (
            const   TTestFWTest&            tfwtStarting
        )   override;

        tCIDLib::TVoid Terminate() override;


    private :
        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TCIDAITestApp,TTestFWApp)
};

