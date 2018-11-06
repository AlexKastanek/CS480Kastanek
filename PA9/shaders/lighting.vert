#version 330

layout (location = 0) in vec4 v_position;
layout (location = 1) in vec2 TexCoords;
layout (location = 2) in vec3 v_normal;

out vec2 TexCoord;
out vec3 fN;
out vec3 fE;
out vec3 fL;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;

uniform vec4 lightPos;

void main()
{
    fN = v_normal;
    fE = v_position.xyz;
    fL = lightPos.xyz;

    if(lightPos.w != 0.0){
        fL = lightPos.xyz - v_position.xyz;
    }

    TexCoord = TexCoords;
    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * v_position;
} 
