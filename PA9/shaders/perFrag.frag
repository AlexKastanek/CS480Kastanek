

varying vec2 texcoord;
varying vec4 colorV;  


uniform sampler2D sampler; 

void main(void)
{
  vec4 outcolor = texture2D(sampler, texcoord.xy);
  gl_FragColor = colorV * outcolor;
}
