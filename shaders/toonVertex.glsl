varying vec3 N;
varying vec3 vertex;

void main(void) {
    vertex = vec3(gl_ModelViewMatrix*gl_Vertex);
    N = normalize(gl_NormalMatrix*gl_Normal);
    gl_Position = ftransform ();
} 
