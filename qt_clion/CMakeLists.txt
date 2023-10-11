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
    set(CMAKE_PREFIX_PATH D:/software/Qt5.13.0/mingw73_64/lib/cmake/Qt5)
else()
    set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/Qt5")
endif()


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()


add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ./
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_autogen/include)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})



