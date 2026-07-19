cmake_minimum_required(VERSION 3.21)

project(Jarvis
    VERSION 1.0.0
    DESCRIPTION "Jarvis Desktop AI Assistant"
    LANGUAGES CXX
)

# -------------------------------
# C++ Standard
# -------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# Qt Automatic Features
# -------------------------------

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# -------------------------------
# Find Qt
# -------------------------------

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
)

# -------------------------------
# Create Executable
# -------------------------------

qt_add_executable(Jarvis

    src/main.cpp

    src/app/Application.cpp
    src/app/Application.h

    src/ui/windows/mainwindow/MainWindow.cpp
    src/ui/windows/mainwindow/MainWindow.h
    src/ui/windows/mainwindow/MainWindow.ui

    src/ui/widgets/sidebar/SidebarWidget.cpp
    src/ui/widgets/sidebar/SidebarWidget.h

    src/ui/pages/chat/ChatPage.cpp
    src/ui/pages/chat/ChatPage.h

    src/core/AIManager.cpp
    src/core/AIManager.h
    src/data/ConversationManager.cpp
    src/data/ConversationManager.h
)

# -------------------------------
# Include Directories
# -------------------------------

target_include_directories(Jarvis PRIVATE

    src
    src/app
    src/ui/windows/mainwindow
    src/core
    src/data
    src/utils
    src/plugins
    src/integration
    src/ui/widgets/sidebar
    src/ui/pages/chat

)

# -------------------------------
# Link Qt Libraries
# -------------------------------

target_link_libraries(Jarvis PRIVATE

    Qt6::Widgets

)

# -------------------------------
# Deploy Qt runtime DLLs (Windows)
# -------------------------------
# Copies the required Qt DLLs and plugins (platforms/, styles/, etc.)
# next to Jarvis.exe so it can run standalone and under the VS debugger.

if(WIN32)
    get_target_property(_qmake_exe Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_exe}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET Jarvis POST_BUILD
            COMMAND "${WINDEPLOYQT_EXECUTABLE}"
                    --no-translations
                    --no-compiler-runtime
                    "$<TARGET_FILE:Jarvis>"
            COMMENT "Deploying Qt runtime dependencies with windeployqt"
            VERBATIM
        )
    endif()
endif()