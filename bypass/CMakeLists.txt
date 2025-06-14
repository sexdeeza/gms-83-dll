cmake_minimum_required(VERSION 3.26)
project(bypass VERSION 1.0.0)

add_library(bypass SHARED
        dllmain.cpp
        ${CMAKE_SOURCE_DIR}/common/memedit.cpp
        ${CMAKE_SOURCE_DIR}/common/hooker.cpp
        ${CMAKE_SOURCE_DIR}/common/logger.cpp
        ${CMAKE_SOURCE_DIR}/common/CClientSocket.cpp
        ${CMAKE_SOURCE_DIR}/common/CConfig.cpp
        ${CMAKE_SOURCE_DIR}/common/COutPacket.cpp
        ${CMAKE_SOURCE_DIR}/common/CSystemInfo.cpp
        ${CMAKE_SOURCE_DIR}/common/CWndMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CWvsApp.cpp
        ${CMAKE_SOURCE_DIR}/common/CWvsContext.cpp
        ${CMAKE_SOURCE_DIR}/common/CActionMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CInputSystem.cpp
        ${CMAKE_SOURCE_DIR}/common/CSecurityClient.cpp
        ${CMAKE_SOURCE_DIR}/common/CFuncKeyMappedMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CQuickslotKeyMappedMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CAnimationDisplayer.cpp
        ${CMAKE_SOURCE_DIR}/common/CMacroSysMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CBattleRecordMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CMapleTVMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CQuestMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CMonsterBookMan.cpp
        ${CMAKE_SOURCE_DIR}/common/CRadioManager.cpp
        ${CMAKE_SOURCE_DIR}/common/CStage.cpp
        ${CMAKE_SOURCE_DIR}/common/CLogin.cpp
        ${CMAKE_SOURCE_DIR}/common/CLogo.cpp
        ${CMAKE_SOURCE_DIR}/common/CUITitle.cpp
        ${CMAKE_SOURCE_DIR}/common/ZSocketBuffer.cpp
        ${CMAKE_SOURCE_DIR}/common/CIOBufferManipulator.cpp
        ${CMAKE_SOURCE_DIR}/common/ZSocketBase.cpp
)

# Set additional include directories if needed
target_include_directories(bypass PRIVATE ${CMAKE_SOURCE_DIR}/common)
target_link_libraries(bypass PRIVATE ${CMAKE_SOURCE_DIR}/common/detours.lib)
target_link_libraries(bypass PRIVATE build_config)

# Link against Ws2_32.lib
if (WIN32)
    target_link_libraries(bypass PRIVATE Ws2_32.lib)
    target_link_libraries(bypass PRIVATE winmm.lib)
    target_link_libraries(bypass PRIVATE comsuppw.lib)
endif()

set_target_properties(bypass PROPERTIES OUTPUT_NAME "bypass-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")