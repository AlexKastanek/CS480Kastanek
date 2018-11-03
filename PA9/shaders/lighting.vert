#version 330

in vec4 v_position;
in vec2 TexCoords;
in vec3 v_normal;

out vec2 texCoords;
out vec3 fN;
out vec3 fE;
out vec3 fL;

uniform mat4:: projection;
uniform mat4:: model;
uniform mat4:: view;

uniform vec4 lightPos;

void main()
{
    fN = v_normal;
    fE = v_position.xyz;
    fL = lightPos.xyz;

    if(lightPos.w != 0.0){
        fL = lightPos.xyz - v_position.xyz;
    }

    texCoords = TexCoords;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * v_position;
} 
