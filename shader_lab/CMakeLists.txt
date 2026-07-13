cmake_minimum_required(VERSION 3.16)

project(shader_lab VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.11 COMPONENTS 
Quick
Widgets
OpenGL
OpenGLWidgets
ShaderTools
REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(shader_lab
   cpp/main.cpp
   cpp/scan.cpp
)

qt_add_shaders(shader_lab shaders
    PREFIX /
    GLSL "440"
    FILES
        shaders/custom_shader.vert
        shaders/custom_shader.frag
)

qt_add_qml_module(shader_lab
    URI hello
    VERSION 1.0

    QML_FILES
        ui/Main.qml
        ui/MySlider.qml
        
    RESOURCES
        resources/images.jpg
)

target_link_libraries(shader_lab PRIVATE
    Qt6::Quick
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)