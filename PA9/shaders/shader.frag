#version 330

varying vec2 TexCoord;
varying vec4 color;

uniform sampler2D gSampler;

void main(void)
{
	vec4 outcolor = texture2D(gSampler, TexCoord.st);
	gl_FragColor = color * outcolor;

}

