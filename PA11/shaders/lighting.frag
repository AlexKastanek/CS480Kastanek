#version 330
#define MAX_LIGHTS 10

in vec4 fLightSpacePos;
in vec3 fN;
//in vec3 fE;
in vec3 fP;
in vec2 uv;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

uniform int numLights;
uniform struct Light {
    vec4 ambientProduct, diffuseProduct, specularProduct;
    vec4 lightPosition;
    vec3 lightDirection;
    float lightAngle;
    float shininess;
    float attenuationProduct;
    bool directional;
    bool shadowed;    
} lights[MAX_LIGHTS];

uniform vec3 cameraPosition;

uniform sampler2D gSampler;
uniform sampler2D shadowMap;

float CalculateShadow(vec4 posLightSpace, float bias)
{
    // manual perspective divide (unnecessary if orthographic projection)
    vec3 projCoords = posLightSpace.xyz / posLightSpace.w;

    // shift coordinates from [-1, 1] to [0, 1]
    projCoords = projCoords * 0.5 + 0.5;

    // get closest depth value from light's perspective
    float closestDepth = texture(shadowMap, projCoords.xy).r;

    // get depth of current fragment
    float currentDepth = projCoords.z;

    // if in shadow set to 0
    float shadow = (currentDepth - bias) > closestDepth ? 1.0 : 0.0;

    return shadow;
}

void main()
{
    vec3 N = normalize(fN);
    vec3 E = normalize(cameraPosition);

    vec3 linearColor = vec3(0);

    for (int i = 0; i < numLights; i++)
    {
        vec3 fL = lights[i].lightPosition.xyz;
        if(lights[i].lightPosition.w != 0.0)
        {
            fL = lights[i].lightPosition.xyz - fP;
        }

        vec3 L = normalize(fL);
        vec3 H = normalize(L + E);

        vec4 ambient = lights[i].ambientProduct;

        float Kd = max(dot(L,N), 0.0);
        vec4 diffuse = Kd * lights[i].diffuseProduct;

        float Ks = pow(max(dot(N, H), 0.0), lights[i].shininess);
        vec4 specular = Ks * lights[i].specularProduct;
        if(dot(L,N) < 0.0){
            specular = vec4(0.0, 0.0, 0.0, 1.0);
        }

        //calculate attenuation
        float distanceToLight = length(lights[i].lightPosition.xyz - fP);
        float attenuation = 1.0 / (1.0 + lights[i].attenuationProduct * pow(distanceToLight, 2));

        if (!lights[i].directional)
        {
            //if object is outside the cone of influence, set attenuation to 
            //zero
            vec3 direction = normalize(lights[i].lightDirection);
            float lightToSurfaceAngle = degrees(acos(dot(-L,direction)));
            if (lightToSurfaceAngle > lights[i].lightAngle)
            {
                attenuation = 0.0;
            }
        }
        else
        {
            attenuation = 1.0;
        }

        //calculate shadows if this light casts shadows
        float shadow;
        if (lights[i].shadowed)
        {
            // set the bias
            float bias = max(0.07 * (1.0 - dot(N, L)), 0.007);

            shadow = CalculateShadow(fLightSpacePos, bias);
        }
        else
        {
            shadow = 0.0;
        }

        linearColor += (ambient + (1.0 - shadow) * (attenuation * (diffuse + specular))).xyz;
    }

    vec3 gamma = vec3(1.0/2.2);

    gl_FragColor = vec4(pow(linearColor, gamma), 1.0) * texture2D(gSampler, uv.st);
    gl_FragColor.a = 1.0;

}