cmake_minimum_required(VERSION 3.16)

project(shader_lab VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Quick Widgets OpenGL OpenGLWidgets REQUIRED)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(shader_lab
   cpp/main.cpp
)

# qt_add_qml_module(helloworld
#     URI hello
#     QML_FILES
#         main.qml
#         FramedImage.qml
#     RESOURCES
#         img/world.png
# )


qt_add_qml_module(shader_lab
    URI hello
    QML_FILES
        ui/Main.qml
        
)

target_link_libraries(shader_lab PRIVATE
    Qt6::Quick
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)