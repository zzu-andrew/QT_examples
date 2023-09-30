cmake_minimum_required(VERSION 3.12)
project(qt_clion)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

if(WIN32)
    set(CMAKE_PREFIX_PATH "D:/software/Qt5.13.0/mingw73_64/lib/cmake/Qt5")
else()
    set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
endif()


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()


## 添加用户界面文件
#set(FORMS
#        mainwindow.ui
#        )

# 自动生成用户界面文件的 C++ 代码
#qt5_wrap_ui(UI_HEADERS ${FORMS})

# 自动生成用户界面文件的 C++ 代码
# 自动生成用户界面文件的 C++ 代码
#set(UI_HEADERS)
if(WIN32)

#foreach(FORM ${FORMS})
#    get_filename_component(FORM_BASE ${FORM} NAME_WE)
#    set(UI_HEADER "${CMAKE_CURRENT_BINARY_DIR}/ui_${FORM_BASE}.h")
#    list(APPEND UI_HEADERS ${UI_HEADER})
#    add_custom_command(
#            OUTPUT ${UI_HEADER}
#            COMMAND ${Qt5_DIR}/../../../bin/uic ${CMAKE_CURRENT_SOURCE_DIR}/${FORM} -o ${UI_HEADER}
#            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${FORM}
#    )
#endforeach()

else()
#    foreach(FORM ${FORMS})
#        get_filename_component(FORM_BASE ${FORM} NAME_WE)
#        set(UI_HEADER "${CMAKE_CURRENT_BINARY_DIR}/ui_${FORM_BASE}.h")
#        list(APPEND UI_HEADERS ${UI_HEADER})
#        add_custom_command(
#                OUTPUT ${UI_HEADER}
#                COMMAND /usr/bin/uic ${CMAKE_CURRENT_SOURCE_DIR}/${FORM} -o ${UI_HEADER}
#                DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${FORM}
#        )
#    endforeach()

endif()


add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ./)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})



