#version 300 es

precision mediump float;

in vec3 vNormal;
in vec2 vTexCoord;
in vec3 vColor;
in vec3 vFragPos;

out vec4 FragColor;

uniform vec3 uLightPos;
uniform bool uHasTexture;
uniform sampler2D uTexture;

vec3 getAmbient(vec3 normal, vec3 lightColor) {
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;

    return ambient;
}

vec3 getDiffuse(vec3 normal, vec3 lightColor) {
    vec3 lightDir = normalize(uLightPos - vFragPos);
    float diff = max(dot(normal, lightDir), 0.0f);
    vec3 diffuse = diff * lightColor;

    return diffuse;
}

void main() {
    vec3 objectColor;

    if(uHasTexture) {
        vec4 texColor = texture(uTexture, vTexCoord);
        objectColor = vec3(texColor);
    } else {
        objectColor = vec3(1, 1, 1);
    }

    vec3 normal = normalize(vNormal);
    vec3 lightColor = vec3(1, 1, 1);

    vec3 result = (getAmbient(normal, lightColor) + getDiffuse(normal, lightColor)) * objectColor;
    FragColor = vec4(result, 1.0f);
    // FragColor = vec4(normalize(uLightPos - vFragPos), 1);
}
