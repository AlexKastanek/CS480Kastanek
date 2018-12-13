#version 330

in vec2 fragTexture;

out vec4 FragColor;

uniform sampler2D depthMap;

void main()
{             
	//float depthValue = texture(depthMap, fragTexture).r;
	//FragColor = vec4(vec3(depthValue), 1.0);
}  