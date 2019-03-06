// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_LogSrvServerBase.hpp
//  DATE: Tue, Feb 26 15:38:53 2019 -0500
//    ID: 7F1112BEFF72CF9A-1A3600EA74289F30
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------
#pragma once

#pragma CIDLIB_PACK(CIDLIBPACK)

class CIDORBUCEXP TCIDLogSrvServerBase : public TOrbServerBase
{
    public :
        // --------------------------------------------------------------------
        // Public, static data
        // --------------------------------------------------------------------
        static const TString strInterfaceId;
        static const TString strScope;
        static const TString strAdminBinding;
        static const TString strBinding;


        // --------------------------------------------------------------------
        // Constructors and destructor
        // --------------------------------------------------------------------
        TCIDLogSrvServerBase(const TCIDLogSrvServerBase&) = delete;
        ~TCIDLogSrvServerBase();

        // --------------------------------------------------------------------
        // Public operators
        // --------------------------------------------------------------------
        TCIDLogSrvServerBase& operator=(const TCIDLogSrvServerBase&) = delete;

        // --------------------------------------------------------------------
        // Public, pure virtual methods
        // --------------------------------------------------------------------
        virtual tCIDLib::TBoolean bGetLiveEvents
        (
            tCIDLib::TCard4& c4NextEventId
            , TVector<TLogEvent>& colToFill
        ) = 0;

        virtual tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4MaxToReturn
        ) = 0;

        virtual tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4Minutes
            , const tCIDLib::TCard4 c4MaxToReturn
        ) = 0;

        virtual tCIDLib::TCard4 c4QueryEvents
        (
            TVector<TLogEvent>& colToFill
            , const tCIDLib::TCard4 c4MaxToReturn
            , const TString& strHostExpr
            , const TString& strProcExpr
            , const TString& strFacExpr
            , const TString& strThreadExpr
            , const tCIDLib::TCard8 c8SevLevels
            , const tCIDLib::TCard8 c8ErrClasses
        ) = 0;

        virtual tCIDLib::TVoid DebugDump
        (
            tCIDLib::TCard4& c4BufSz_mbufData
            , THeapBuf& mbufData
        ) = 0;

        virtual tCIDLib::TVoid LogSingle
        (
            const TLogEvent& logevToSend
        ) = 0;

        virtual tCIDLib::TVoid LogMultiple
        (
            const TBag<TLogEvent>& colErrors
        ) = 0;

        virtual tCIDLib::TVoid RemoveAll() = 0;

    protected :
        // --------------------------------------------------------------------
        // Hidden constructors
        // --------------------------------------------------------------------
        TCIDLogSrvServerBase();
        TCIDLogSrvServerBase(const TOrbObjId& ooidThis);

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
        RTTIDefs(TCIDLogSrvServerBase,TOrbServerBase)
};

#pragma CIDLIB_POPPACK
