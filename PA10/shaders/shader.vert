#version 330
#define MAX_LIGHTS 10
layout (location = 0) in vec3 v_position;
layout (location = 1) in vec2 v_texture;
layout (location = 2) in vec3 v_normal;

uniform struct Light{
    vec3 position;
    vec3 intensities;
    float attenuationProduct;
    vec4 ambientProduct, diffuseProduct, specularProduct;
    vec4 lightPosition;
    vec3 lightDirection;
    float lightAngle;
    float shininess;
} allLights[MAX_LIGHTS];


out vec4 color;
out vec2 texture;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

/*uniform vec4 ambientProduct, diffuseProduct, specularProduct;
uniform vec4 lightPosition;
uniform vec3 lightDirection;
uniform float lightAngle;
uniform float shininess;
uniform float attenuationProduct;
*/
uniform sampler2D gSampler;

void main(void)
{
vec3 linearColor = vec3(0);

for(int i = 0; i < numLights; ++i){

linearColor +={
    vec4 v = vec4(v_position, 1.0);
    vec3 pos = ((viewMatrix * modelMatrix) * v).xyz;

    vec3 L = normalize(allLights[i].lightPosition.xyz - (modelMatrix * vec4(v_position, 1.0)).xyz);
    vec3 E = normalize(-pos);
    vec3 H = normalize(L + E);

    vec3 N = normalize((viewMatrix * modelMatrix) * vec4(v_normal, 0.0)).xyz;

    vec4 ambient = allLights[i].ambientProduct;

    float Kd = max(dot(L,N), 0.0);
    vec4 diffuse = Kd * allLights[i].diffuseProduct;

    float Ks = pow(max(dot(N,H), 0.0), shininess);
    vec4 specular = Ks * allLights[i].specularProduct;
    if (dot(L,N) < 0.0)
    {
        specular = vec4(0.0, 0.0, 0.0, 1.0);
    }

    //calculate attenuation
    float distanceToLight = length(allLights[i].lightPosition.xyz - (modelMatrix * v).xyz);
    float attenuation = 1.0 / (1.0 + allLights[i].attenuationProduct * pow(distanceToLight, 2));

    //if object is outside the cone of influence, set attenuation to zero
    vec3 direction = normalize(allLights[i].lightDirection);
    float lightToSurfaceAngle = degrees(acos(dot(-L,direction)));
    if (lightToSurfaceAngle > allLights[i].lightAngle)
    {
        attenuation = 0.0;
    }

    vec3 linearColor = (ambient + (attenuation * (diffuse + specular))).xyz;

    vec3 gamma = vec3(1.0/2.2);

    gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * v;

    texture = v_texture;

    color = vec4(pow(linearColor, gamma), 1.0);
}}
}
