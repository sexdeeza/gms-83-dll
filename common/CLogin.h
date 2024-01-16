#pragma once

#include "CMapLoadable.h"
#include "AvatarData.h"
#include "ZFatalSection.h"
#include "CAvatar.h"
#include "CUILoginStart.h"
#include "CFadeWnd.h"
#include "RecommendWorldMsg.h"
#include "ZFatalSection.h"

class CConnectionNoticeDlg;

/*
00000000 CLogin          struc ; (sizeof=0x2C8, align=0x4, copyof_4913)
00000000 baseclass_0     CMapLoadable ?
00000148 m_pConnectionDlg ZRef<CConnectionNoticeDlg> ?
00000150 m_bIsWaitingVAC dd ?
00000154 m_bIsVACDlgOn   dd ?
00000158 m_tSentTimeVACPacket dd ?
0000015C m_nCountRelatedSvrs dd ?
00000160 m_nCountCharacters dd ?
00000164 m_nCountDataReceivedCharacters dd ?
00000168 m_bRecommandWorld dd ?
0000016C m_aAvatarDataVAC ZArray<AvatarData> ?
00000170 m_aRankVAC      ZArray<CLogin::RANK> ?
00000174 m_adwCharacterID ZArray<unsigned long> ?
00000178 m_asCharacterName ZArray<ZXString<char> > ?
0000017C m_anWorldID     ZArray<long> ?
00000180 m_lock_Avatar   ZFatalSection ?
00000188 m_lock_CountSvr ZFatalSection ?
00000190 m_lock_Character ZFatalSection ?
00000198 m_pLayerBook    _com_ptr_t<_com_IIID<IWzGr2DLayer, &_GUID_6dc8c7ce_8e81_4420_b4f6_4b60b7d5fcdf> > ?
0000019C m_nFadeOutLoginStep dd ?
000001A0 m_tStartFadeOut dd ?
000001A4 m_nLoginStep    dd ?
000001A8 m_tStepChanging dd ?
000001AC m_bRequestSent  dd ?
000001B0 m_bLoginOpt     db ?
000001B1                 db ? ; undefined
000001B2                 db ? ; undefined
000001B3                 db ? ; undefined
000001B4 m_bQuerySSNOnCreateNewCharacter dd ?
000001B8 m_nSlotCount    dd ?
000001BC m_nBuyCharCount dd ?
000001C0 m_nBaseStep     dd ?
000001C4 m_bTerminate    dd ?
000001C8 m_pFocusedUI    dd ? ; offset
000001CC m_WorldItem     ZArray<CLogin::WORLDITEM> ?
000001D0 m_nCharSelected dd ?
000001D4 m_aAvatarData   ZArray<AvatarData> ?
000001D8 m_aRank         ZArray<CLogin::RANK> ?
000001DC m_abOnFamily    ZArray<int> ?
000001E0 m_lNewEquip     ZList<CLogin::NEWEQUIP> ?
000001F4 m_nRegStatID    db ?
000001F5                 db ? ; undefined
000001F6                 db ? ; undefined
000001F7                 db ? ; undefined
000001F8 m_pLayerLight   _com_ptr_t<_com_IIID<IWzGr2DLayer, &_GUID_6dc8c7ce_8e81_4420_b4f6_4b60b7d5fcdf> > ?
000001FC m_pLayerDust    _com_ptr_t<_com_IIID<IWzGr2DLayer, &_GUID_6dc8c7ce_8e81_4420_b4f6_4b60b7d5fcdf> > ?
00000200 m_pNewAvatar    ZRef<CAvatar> ?
00000208 m_pLoginStart   ZRef<CUILoginStart> ?
00000210 m_pLoginDesc0   ZRef<CFadeWnd> ?
00000218 m_pLoginDesc1   ZRef<CFadeWnd> ?
00000220 m_pChildModal   ZRef<CDialog> ?
00000228 m_sEventCharacterID ZXString<char> ?
0000022C m_nBalloonCount dd ?
00000230 m_aBalloon      ZArray<CLogin::BALLOON> ?
00000234 m_nLatestConnectedWorldID dd ?
00000238 m_bRecommendWorldMsgLoaded dd ?
0000023C m_aRecommendWorldMsg ZArray<RECOMMENDWORLDMSG> ?
00000240 m_nCurSelectedRace dd ?
00000244 m_nCurSelectedSubJob dw ?
00000246                 db ? ; undefined
00000247                 db ? ; undefined
00000248 m_aCmd          ZXString < char> 5 dup(? )
0000025C m_tFadeInRemain dd ?
00000260 m_bNeedAgreement dd ?
00000264 m_nGender       db ?
00000265                 db ? ; undefined
00000266                 db ? ; undefined
00000267                 db ? ; undefined
00000268 m_nSubStep      dd ?
0000026C m_bSubStepChanged dd ?
00000270 m_sCheckedName  ZXString<char> ?
00000274 m_aMaleItem     ZArray < CLogin::ASITEM> 9 dup(? )
00000298 m_aFemaleItem   ZArray < CLogin::ASITEM> 9 dup(? )
000002BC m_bCharSale     dd ?
000002C0 m_nCharSaleJob  dd ?
000002C4 m_bCanHaveExtraChar dd ?
000002C8 CLogin          ends
*/
class CLogin : CMapLoadable {
public:
    /*
    00000000 CLogin::RANK    struc; (sizeof = 0x10, align = 0x4, copyof_4908)
    00000000 nWorldRank      dd ?
    00000004 nWorldRankGap   dd ?
    00000008 nJobRank        dd ?
    0000000C nJobRankGap     dd ?
    00000010 CLogin::RANK    ends
    */
    struct RANK {
        int nWorldRank;
        int nWorldRankGap;
        int nJobRank;
        int nJobRankGap;
    };

    /*
    00000000 CLogin::CHANNELITEM struc ; (sizeof=0x14, align=0x4, copyof_4904)
    00000000 sName           ZXString<char> ?
    00000004 nUserNo         dd ?
    00000008 nWorldID        dd ?
    0000000C nChannelID      dd ?
    00000010 bAdultChannel   dd ?
    00000014 CLogin::CHANNELITEM ends
    */
    struct CHANNELITEM {
        ZXString<char> sName;
        int nUserNo;
        int nWorldID;
        int nChannelID;
        bool bAdultChannel;
    };

    /*
    00000000 CLogin::WORLDITEM struc; (sizeof = 0x20, align = 0x4, copyof_4906)
    00000000 nWorldID        dd ?
    00000004 sName           ZXString<char> ?
    00000008 nWorldState     dd ?
    0000000C sWorldEventDesc ZXString<char> ?
    00000010 nWorldEventEXP_WSE dd ?
    00000014 nWorldEventDrop_WSE dd ?
    00000018 nBlockCharCreation dd ?
    0000001C ci              ZArray<CLogin::CHANNELITEM> ?
    00000020 CLogin::WORLDITEM ends
    */
    struct WORLDITEM {
        int nWorldID;
        ZXString<char> sName;
        int nWorldState;
        ZXString<char> sWorldEventDesc;
        int nWorldEventEXP_WSE;
        int nWorldEventDrop_WSE;
        int nBlockCharCreation;
        ZArray<CLogin::CHANNELITEM> ci;
    };

    /*
    00000000 CLogin::NEWEQUIP struc; (sizeof = 0xC, align = 0x4, copyof_4907)
    00000000 nGender         dd ?
    00000004 nType           dd ?
    00000008 nItemId         dd ?
    0000000C CLogin::NEWEQUIP ends
    */
    struct NEWEQUIP {
        int nGender;
        int nType;
        int nItemId;
    };

    /*
    00000000 CLogin::BALLOON struc ; (sizeof=0xC, align=0x4, copyof_4909)
    00000000 nX              dd ?
    00000004 nY              dd ?
    00000008 sMessage        ZXString<char> ?
    0000000C CLogin::BALLOON ends
    */
    struct BALLOON {
        int nX;
        int nY;
        ZXString<char> sMessage;
    };

    /*
    00000000 CLogin::ASITEM  struc; (sizeof = 0x8, align = 0x4, copyof_4934)
    00000000 nItemId         dd ?
    00000004 sItemName       ZXString<char> ?
    00000008 CLogin::ASITEM  ends
    */
    struct ASITEM {
        int nItemId;
        ZXString<char> sItemName;
    };

    virtual ~CLogin() = default;

    ZRef<CConnectionNoticeDlg> m_pConnectionDlg;
    int m_bIsWaitingVAC;
    int m_bIsVACDlgOn;
    int m_tSentTimeVACPacket;
    int m_nCountRelatedSvrs;
    int m_nCountCharacters;
    int m_nCountDataReceivedCharacters;
    int m_bRecommandWorld;
    ZArray<AvatarData> m_aAvatarDataVAC;
    ZArray<CLogin::RANK> m_aRankVAC;
    ZArray<unsigned long> m_adwCharacterID;
    ZArray<ZXString<char>> m_asCharacterName;
    ZArray<long> m_anWorldID;
    ZFatalSection m_lock_Avatar;
    ZFatalSection m_lock_CountSvr;
    ZFatalSection m_lock_Character;
    IWzGr2DLayer *m_pLayerBook;
    int m_nLoginStep;
    int m_tStepChanging;
    int m_bRequestSent;
    int m_nFadeOutLoginStep;
    int dummy1;
    int dummy2;
    unsigned __int8 dummy3;
    int m_bTerminate;
    int dummy5;
    ZArray<CLogin::WORLDITEM> m_WorldItem;
    int m_nCharSelected;
    int dummy8;
    int dummy9;
    int dummy10;
    int dummy11;
    int dummy12;
    int dummy13;
    int dummy14;
    int dummy15;
    int dummy16;
    int dummy17;
    int dummy18;
    int dummy19;
    int dummy20;
    int dummy21;
    IWzGr2DLayer *m_pLayerLight;
    IWzGr2DLayer *m_pLayerDust;
    int dummy24;
    ZRef<CAvatar> m_pNewAvatar;
    int dummy26;
    ZRef<CUILoginStart> m_pLoginStart;
    int dummy28;
    int dummy29;
    int dummy30;
    int dummy31;
    int dummy32;
    ZRef<CDialog> m_pChildModal;
    int dummy34;
    int m_nBalloonCount;
    ZArray<CLogin::BALLOON> m_aBalloon;
    int m_nLatestConnectedWorldID;
    int m_bRecommendWorldMsgLoaded;
    ZArray<RecommendWorldMsg> m_aRecommendWorldMsg;
    int m_nCurSelectedRace;
    ZXString<char> m_aCmd[5];
    int m_nGender;
    ZXString<char> m_sCheckedName;
    ZArray<CLogin::ASITEM> m_aMaleItem[9];
    ZArray<CLogin::ASITEM> m_aFemaleItem[9];
    ZArray<AvatarData> m_aAvatarData;
    ZArray<CLogin::RANK> m_aRank;
    ZArray<int> m_abOnFamily;
    ZList<CLogin::NEWEQUIP> m_lNewEquip;
    unsigned __int8 m_nRegStatID;
    ZRef<CFadeWnd> m_pLoginDesc0;
    ZRef<CFadeWnd> m_pLoginDesc1;
    ZXString<char> m_sEventCharacterID;
    int m_nCurSelectedSubJob;
    unsigned int Unknown7;
    unsigned int Unknown8;
    int m_tFadeInRemain;
    bool m_bNeedAgreement;
    unsigned int Unknown9;
    unsigned int Unknown10;
    unsigned int Unknown11;
    int m_nSubStep;
    bool m_bSubStepChanged;
    bool m_bCharSale;
    int m_nCharSaleJob;
    bool m_bCanHaveExtraChar;
};