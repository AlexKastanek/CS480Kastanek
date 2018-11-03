#version 330

attribute vec4 v_position;
attribute vec2 v_texture;
attribute vec3 normal;

varying vec2 TexCoord;
varying vec4 color;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

uniform vec4 ambientProduct, diffuseProduct, specularProduct;
uniform vec4 lightPos;
uniform float shine;

uniform float ball;

void main(void)
{
    if(ball == 1.0){
        vec4 light = vec4( 0, 1, 1, 1) * (viewMatrix * modelMatrix);
        vec3 lightDirection = light.xyz;

        vec4 color1 = gl_FrontMaterial.specular;
        vec4 color2 = gl_FrontMaterial.diffuse + vec4( 2, 2, 2, 1);
        vec4 color3 = gl_FrontMaterial.ambient + vec4( 2, 2, 2, 1);

        float angleIncidence = dot(normalize(normal), normalize(lightDirection));
        angleIncidence = clamp(angleIncidence, 0, 1);
        color = (color1 + color2 + color3) * angleIncidence + vec4( 0.1, 0.1, 0.1, 1.0);

        TexCoord = v_texture;

        gl_Position = (projectMatrix * viewMatrix * modelMatrix) * v_position;
    } else{
        vec3 pos = ((viewMatrix * modelMatrix) * v_position.xyz;
        vec3 L = normalize(lightPos.xyz - pos);
        vec3 E = normalize(-pos);
        vec3 H = normalize(L + E);

        vec3 I = normalize( (viewMatrix * modelMatrix) * vec4(normal, 0.0)).xyz;
        vec4 ambient = ambientProduct;

        float Kd = max(dot(L, N), 0.0);
        vec4 diffuse = Kd * diffuseProduct;
        float Ks = pow(max(dot(N, H), 0.0), shine);
        vec4 specular = Ks * specularProduct;
        if(dot(L, N) < 0.0) specular = vec4(0.0, 0.0, 0.0, 1.0);
        gl_Position = (projectionMatrix * viewMatrix * modelMatrix * v_position;

        TexCoord = v_texture;
        color = ambient + diffuse + specular;
        color.a = 1.0;
    }
}