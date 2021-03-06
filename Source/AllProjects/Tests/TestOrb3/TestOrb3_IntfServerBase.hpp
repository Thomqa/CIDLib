// ----------------------------------------------------------------------------
//  FILE: TestOrb3_IntfServerBase.hpp
//  DATE: Tue, Feb 26 15:38:53 2019 -0500
//    ID: 9E7B4A7A069E4160-578F52288498BBF0
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

class  TTestOrb3IntfServerBase : public TOrbServerBase
{
    public :
        // --------------------------------------------------------------------
        // Public, static data
        // --------------------------------------------------------------------
        static const TString strInterfaceId;
        // --------------------------------------------------------------------
        // Constructors and destructor
        // --------------------------------------------------------------------
        TTestOrb3IntfServerBase(const TTestOrb3IntfServerBase&) = delete;
        ~TTestOrb3IntfServerBase();

        // --------------------------------------------------------------------
        // Public operators
        // --------------------------------------------------------------------
        TTestOrb3IntfServerBase& operator=(const TTestOrb3IntfServerBase&) = delete;

        // --------------------------------------------------------------------
        // Public, pure virtual methods
        // --------------------------------------------------------------------
        virtual tCIDLib::TVoid AddToBuf
        (
            tCIDLib::TCard4& c4BufSz_mbufToAdjust
            , THeapBuf& mbufToAdjust
        ) = 0;

        virtual tCIDLib::TCard4 c4AddTo
        (
            const tCIDLib::TCard4 c4ToAdjust
        ) = 0;

        virtual tCIDLib::TVoid DelayRet() = 0;

        virtual tCIDLib::TVoid NoParmsNoRet() = 0;

        virtual TString strFormatValue
        (
            const tCIDLib::TCard4 c4ToFormat
        ) = 0;

        virtual tCIDLib::TVoid UploadBuf
        (
            const tCIDLib::TCard4 c4BufSz_mbufUpload
            , const TMemBuf& mbufUpload
        ) = 0;

    protected :
        // --------------------------------------------------------------------
        // Hidden constructors
        // --------------------------------------------------------------------
        TTestOrb3IntfServerBase();
        TTestOrb3IntfServerBase(const TOrbObjId& ooidThis);

        // --------------------------------------------------------------------
        // Protected, inherited methods
        // --------------------------------------------------------------------
        tCIDLib::TVoid Dispatch
        (
            const  TString&      strMethodName
            ,      TOrbCmd&      orbcToDispatch
        )   override;

    private :
        // --------------------------------------------------------------------
        // Magic macros
        // --------------------------------------------------------------------
        RTTIDefs(TTestOrb3IntfServerBase,TOrbServerBase)
};

#pragma CIDLIB_POPPACK

