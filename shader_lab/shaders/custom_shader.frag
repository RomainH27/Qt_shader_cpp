#version 440

layout(location = 0) in vec2 coord;
layout(location = 0) out vec4 fragColor;
layout(std140, binding = 0) uniform buf {
    mat4 qt_Matrix;
    float qt_Opacity;

    int isLeft;
};

layout(binding = 1) uniform sampler2D src;

void main() {

    vec4 tex = texture(src, coord);
    if(isLeft == 1){
        vec2 flippedCoord = vec2(1.0 - coord.x, coord.y);
        tex = texture(src, flippedCoord);
    }



    fragColor = tex * qt_Opacity;
}