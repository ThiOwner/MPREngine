#version 330 core
out vec4 FragColor;

in vec3 fragPos;
in vec3 normal;

uniform vec3 lightDir;
uniform vec3 lightColor;
uniform vec3 baseColor;

void main()
{
    float ambientStrength = 0.25f;
    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(normal);
    vec3 sceneLightDir = normalize(-lightDir);

    float diff = max(dot(norm, sceneLightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * baseColor;
    FragColor = vec4(result, 1.0f);
}