#version 300 es

precision mediump float;

in vec3 position;
in vec3 normal;
in vec2 texCoord;
in vec3 color;

out vec3 vNormal;
out vec2 vTexCoord;
out vec3 vColor;
out vec3 vFragPos;

uniform mat4 uViewProj;
uniform mat4 uTransform;

void main() {
    gl_Position = uViewProj * uTransform * vec4(position, 1.0f);

    vNormal = normal;
    vTexCoord = texCoord;
    vColor = color;
    vFragPos = vec3(uTransform * vec4(position, 1.0f));
}