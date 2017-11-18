uniform float time;
varying vec3 N;
varying vec3 vertex;

#define shininess 20.0

void main (void)
{
    float theta = time*0.002;
    
    vec3 dir1 = vec3(cos(theta),2,sin(theta));
    vec3 dir2 = vec3(sin(theta),2,cos(theta));
    
    float diffuse1 = pow(dot(N,dir1),2.0);
    float diffuse2 = pow(dot(N,dir2),2.0);
    
    //Color MONZA;MONZA.r = 0.81;MONZA.g = 0.0;MONZA.b = 0.06;
    //Color GOLD;GOLD.r = 0.83f;GOLD.g = 0.69f;GOLD.b = 0.22f;
    vec3 col1 = diffuse1 * vec3(0.83,0.69,0.22);
    vec3 col2 = diffuse2 * vec3(0.81,0,0.06);
    
    gl_FragColor = vec4(col1 + col2, 1.0);
    
    
}

