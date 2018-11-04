#version 330

in vec2 TexCoord;
in vec3 fN;
in vec3 fL;
in vec3 fE;

out vec4 FragColor;

uniform vec4 ambientProduct, diffuseProduct, specularProduct;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

uniform vec4 lightPos;
uniform float shine;

uniform sampler2D gSampler;


void main()
{
    vec3 N = normalize((viewMatrix * modelMatrix) * vec4(fN, 0.0)).xyz;
    vec3 E = normalize(fE);
    vec3 L = normalize(fL);

    vec3 H = normalize(L + E);
    vec4 ambient = ambientProduct;

    float Kd = max(dot(L,N), 0.0);
    vec4 diffuse = Kd * diffuseProduct;

    float Ks = pow(max(dot(N, H), 0.0), shine);
    vec4 specular = Ks * specularProduct;

    if(dot(L,N) < 0.0){
        specular = vec4(0.0, 0.0, 0.0, 1.0);
    }

    FragColor = (ambient + diffuse + specular) * texture2D(gSampler, TexCoord.xy);
    FragColor.a = 1.0;

}

