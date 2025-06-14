// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

//#ifndef PCH_H
//#define PCH_H

#include "framework.h"

#include <atlstr.h>
#include "unknwn.h"

#include "comip.h"
#include "comdef.h"
#include "asserts.h"
#include "logger.h"
#include <intrin.h>
#include <mutex>
#include <thread>
#include <heapapi.h>

#include "memory_map.h"

#include "ZPair.h"
#include "ZXString.h"
#include "ZAllocBase.h"
#include "ZAllocAnonSelector.h"
#include "ZAllocStrSelector.h"
#include "ZFatalSection.h"
#include "ZAllocEx.h"
#include "ZArray.h"
#include "ZRefCounted.h"
#include "ZRefCountedAccessor.h"
#include "ZRecyclableAvBuffer.h"
#include "ZRecyclable.h"
#include "ZRefCountedDummy.h"
#include "ZRef.h"
#include "ZMap.h"
#include "ZList.h"

#include "IGObj.h"
#include "IUIMsgHandler.h"

#include "CInPacket.h"
#include "INetMsgHandler.h"

#include "DiDeviceInstanceA.h"
#include "IDirectInputDevice8A.h"
#include "IDirectInput8A.h"

#include "FunckeyMapped.h"
#include "IDraggable.h"

#include "IWzArchive.h"
#include "IWzSerialize.h"
#include "CanvasDitherType.h"
#include "CanvasLevelMap.h"
#include "CanvasPixelFormat.h"
#include "IWzRawCanvas.h"
#include "IWzProperty.h"
#include "CanvasAlphaType.h"
#include "IWzFont.h"
#include "IWzCanvas.h"
#include "IWzRawCanvasAllocator.h"
#include "IWzShape2D.h"
#include "IWzVector2D.h"
#include "LayerBlendType.h"
#include "Gr2DAniType.h"
#include "IWzGr2DLayer.h"
#include "IWzGr2D.h"

#include "CActionMan.h"

#include "ZInetAddr.h"
#include "ZSocketBuffer.h"
#include "ZSocketBase.h"
#include "CIOBufferManipulator.h"
#include "COutPacket.h"
#include "CClientSocket.h"

#include "ConfigJoypad.h"
#include "ConfigSysOpt.h"
#include "ConfigGameOpt.h"
#include "CConfig.h"

#include "CRadioManager.h"
#include "CMonsterBookMan.h"
#include "CQuestMan.h"
#include "CMapleTVMan.h"
#include "CAnimationDisplayer.h"
#include "CMacroSysMan.h"
#include "CBattleRecordMan.h"
#include "CFuncKeyMappedMan.h"
#include "CQuickslotKeyMappedMan.h"
#include "CStage.h"
#include "CWvsPhysicalSpace2D.h"
#include "CMapLoadable.h"

#include "TSecType.h"

#include "ExtendSP.h"
#include "GW_CharacterStat.h"
#include "AvatarLook.h"
#include "AvatarData.h"
#include "CAvatar.h"
#include "CCtrlWnd.h"
#include "CWnd.h"
#include "CDialog.h"
#include "CUIToolTip.h"
#include "CCtrlButton.h"
#include "CCtrlEdit.h"
#include "CUILoginStart.h"
#include "RecommendWorldMsg.h"
#include "CFadeWnd.h"
#include "CLogin.h"
#include "CConnectionNoticeDlg.h"

#include "CLogo.h"

#include "IsMsg.h"
#include "CInputSystem.h"

#include "CSecurityClient.h"
#include "CSystemInfo.h"
#include "CUITitle.h"
#include "CWndMan.h"
#include "CWvsApp.h"

#include "WebCookie.h"
#include "CharacterData.h"
#include "BasicStat.h"
#include "SecondaryStat.h"
#include "CTemporaryStatView.h"
#include "ForcedStat.h"
#include "PartyData.h"
#include "GW_Friend.h"
#include "PartySearchSetting.h"
#include "CPartySearchRemoCon.h"
#include "GuildData.h"
#include "AllianceData.h"
#include "CalcDamage.h"
#include "CUIBattleRecord.h"
#include "CWvsContext.h"


#include "TSingleton.h"