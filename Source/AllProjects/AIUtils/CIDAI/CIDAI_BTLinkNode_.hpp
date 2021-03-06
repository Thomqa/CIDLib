//
// FILE NAME: CIDAI_BTLinkNode.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 12/26/2016
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header for the link type node, which exists just to link to another
//  tree, to allow trees to be used in a sub-routine type manner. It takes a parameter
//  named "LinkTarget" which is the name of the tree to link to.
//
// LOG:
//
//  $_CIDLib_Log_$
//


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//   CLASS: TAIBTLinkNode
//  PREFIX: btnode
// ---------------------------------------------------------------------------
class CIDAIEXP TAIBTLinkNode : public TAIBTNode
{
    public :
        // -------------------------------------------------------------------
        //  Constructors and Destructor
        // -------------------------------------------------------------------
        TAIBTLinkNode
        (
            const   TString&                strPath
            , const TString&                strName
        );

        TAIBTLinkNode(const TAIBTLinkNode&) = delete;

        ~TAIBTLinkNode();


        // -------------------------------------------------------------------
        //  Public, inherited methods
        // -------------------------------------------------------------------
        tCIDAI::ENodeStates eRun
        (
                    TAIBehaviorTree&        btreeOwner
        )   override;

        tCIDLib::TVoid Validate
        (
                    TAIBehaviorTree&        btreeOwner
            ,       TVector<TAIBTErr>&      colToFill
        )   override;


    private :
        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TAIBTLinkNode, TAIBTNode)
};

#pragma CIDLIB_POPPACK
