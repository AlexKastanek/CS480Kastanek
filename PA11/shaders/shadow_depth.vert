#version 330

layout (location = 0) in vec3 v_position;
layout (location = 1) in vec2 v_texture;

out vec2 fragTexture;

uniform mat4 lightSpaceMatrix;
uniform mat4 modelMatrix;

void main()
{
	fragTexture = v_texture;
    gl_Position = (lightSpaceMatrix * modelMatrix) * vec4(v_position, 1.0);
} 