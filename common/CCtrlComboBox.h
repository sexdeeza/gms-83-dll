#include "CCtrlWnd.h"
#include "ZRef.h"
#include "IWzCanvas.h"
#include "IWzFont.h"
#include "CCtrlEdit.h"
#include "FontType.h"
#include <comdef.h>
#include "CCtrlComboBoxSelect.h"
#include "CCtrlScrollBar.h"

struct CCtrlComboBox : CCtrlWnd {
    struct ITEM_INFO {
        ZXString<char> sItemName;
        unsigned int dwParam;
    };

    ZList<CCtrlComboBox::ITEM_INFO> m_lItemInfo;
    ZRef<CCtrlComboBoxSelect> m_pCtrlCBS;
    ZRef<CCtrlEdit> m_pCtrlEdit;
    ZRef<CCtrlScrollBar> m_pCtrlScrollBar;
    int m_nType;
    int m_nComboBoxState;
    int m_nSelect;
    int m_nPrevSelect;
    int m_tBtClicked;
    int m_nBackColor;
    int m_nBackFocusedColor;
    int m_nBorderColor;
    FONT_TYPE m_fType;
    FONT_TYPE m_fTypeFocused;
    FONT_TYPE m_fTypeSelect;
    FONT_TYPE m_fTypeSelectFocused;
    int m_nBoxPosX;
    int m_nBoxPosY;
    int m_nBoxWidth;
    int m_nBoxHeight;
    int m_nBoxTextLeftOffset;
    int m_nTextOffset_Y;
    int m_nDesign;
    int m_nMaxItem_Shown;
    int m_nType_ScrollBar;
    unsigned int m_Id_ScrollBar;
    int m_bButtonOnLeft;
    int m_bAlwaysFocusOnText;
    int m_bDeleteEnable;
    _bstr_t m_sUOL;
    int m_ItemListPos;
    IWzCanvas *m_pCanvasButton[5];
    IWzCanvas *m_pCanvasCbStart[5];
    IWzCanvas *m_pCanvasCbLine[5];
    IWzFont *m_pFont;
    IWzFont *m_pFontFocused;
};
