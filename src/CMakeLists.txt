cmake_minimum_required(VERSION 3.5)

project(QOpenGLWidget VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_C_COMPILER "../usr/local/opt/gcc")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS OpenGL)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)

set(PROJECT_SOURCES
        Viwer/main.cpp
        Viwer/mainwindow.cpp
        Viwer/mainwindow.h
        Viwer/mainwindow.ui
        Viwer/myopenglwidget.h
        Viwer/myopenglwidget.cpp
        Model/facade.cpp
        Model/facade.h
        Model/singleton.cpp
        Model/singleton.h
        Model/openFile.cpp
        Model/openFile.h
        Model/reader.cpp
        Model/reader.h
        Model/viewer.c
        Model/viewer.h
        Controller/controller.h
        Controller/controller.cpp
        gifmaker/dgif_lib.c
        gifmaker/egif_lib.c
        gifmaker/gif_err.c
        gifmaker/gif_font.c
        gifmaker/gif_hash.c
        gifmaker/gif_hash.h
        gifmaker/gif_lib_private.h
        gifmaker/gif_lib.h
        gifmaker/gifalloc.c
        gifmaker/qgifglobal.h
        gifmaker/qgifimage_p.h
        gifmaker/qgifimage.h
        gifmaker/quantize.c
        gifmaker/qgifimage.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QOpenGLWidget
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QOpenGLWidget APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QOpenGLWidget SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QOpenGLWidget
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QOpenGLWidget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(QOpenGLWidget PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(QOpenGLWidget PRIVATE Qt6::OpenGL)
target_link_libraries(QOpenGLWidget PRIVATE Qt6::OpenGLWidgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QOpenGLWidget)
endif()
