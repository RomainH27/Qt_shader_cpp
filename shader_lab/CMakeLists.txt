cmake_minimum_required(VERSION 3.20)
project(shader_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

# message(STATUS "TEST LOG LALALA")

qt_standard_project_setup()

add_executable(shader_lab
    cpp/main.cpp
    cpp/mainwindow.cpp
    cpp/glwidget.cpp
)

target_link_libraries(shader_lab
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)