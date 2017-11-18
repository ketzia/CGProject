#include "ShaderObject.h"
#include "StringUtils.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <windows.h>
#include "glew.h"
#include "freeglut.h"
#endif

ShaderObject::ShaderObject (char *fragment):shader_id(0),num_vars(0){
    initShaders (fragment);
}

ShaderObject::ShaderObject(char *vertex, char *fragment):shader_id(0),num_vars(0){
    initShaders(vertex, fragment);
}

#ifdef USE_GEOMETRY_SHADERS
ShaderObject::ShaderObject(char *vertex, char *fragment, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive):shader_id(0),num_vars(0){
    initShaders(vertex, fragment, geometry, inPrimitive, outPrimitive);
}

ShaderObject::ShaderObject(char *vertex, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive):shader_id(0),num_vars(0){
    initShaders(vertex, geometry, inPrimitive, outPrimitive);
}
#endif

ShaderObject::~ShaderObject(){
    if(shader_id) glDeleteShader (shader_id);
}

char *ShaderObject::loadShaderCode (char* filename){
    FILE *shFile;
    //std::ifstream file;
    unsigned long len, readLen;
    char* fileData;
    
    struct stat f_status;
    
    if(stat(filename, &f_status)) return NULL;
    len = f_status.st_size;
    
    shFile = fopen(filename, "r");
    if(shFile == NULL) return NULL;
    
    fileData = new char[len+1];
    
    memset(fileData, ' ', len+1);
    readLen = fread(fileData, 1, len, shFile);
    fileData[len]=0;
    
    fclose(shFile);
    
    return fileData;
}

void ShaderObject::initShaders(char *fragment) {
    int progLinkSuccess;
    const char* Shader;
    GLuint fragmentHandler;
    GLuint programObject;
    shader_id = 0;
    
    if ((Shader = (const char *)loadShaderCode (fragment))==NULL){
        fprintf(stderr, "Unable to Load  Shader  %s \n",fragment);
        exit (1);
    }
    fragmentHandler = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource    (fragmentHandler  , 1, &Shader, NULL);
    if (Shader) delete [] Shader, Shader = NULL;
    
    glCompileShader (fragmentHandler);
    
    programObject = glCreateProgram ();
    glAttachShader (programObject, fragmentHandler);
    
    glLinkProgram (programObject);
    
    
    glDeleteShader(fragmentHandler);
    
    glGetProgramiv (programObject, GL_LINK_STATUS, &progLinkSuccess);
    
    if (!progLinkSuccess) {
        
        glGetProgramiv (programObject, GL_INFO_LOG_LENGTH, &progLinkSuccess);
        Shader = new char [progLinkSuccess];
        glGetProgramInfoLog (programObject, progLinkSuccess, NULL, (char*)Shader);
        fprintf (stdout, "\n%s\n", Shader);
        fprintf(stderr, "Shader could not be linked %s\n",fragment);
        delete [] Shader;
        Shader = NULL;
        exit(1);
    }
    fprintf (stdout, "%s\nbuild succeeded...\n", fragment);
    shader_id = programObject;
    glUseProgram (shader_id);
    num_vars=0;
    initVarInfo();
    
}


void ShaderObject::initShaders(char *vertex, char *fragment){
    int progLinkSuccess;
    const char *Shader;
    GLuint vertexHandler, fragmentHandler;
    GLuint programObject;
    shader_id = 0;
    
    if ((Shader = (const char *)loadShaderCode (vertex))==NULL){
        fprintf(stderr, "Unable to Load Vertex Shader %s\n", vertex);
        exit (1);
    }
    vertexHandler = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource     (vertexHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    if ((Shader = (const char *)loadShaderCode (fragment))==NULL){
        fprintf(stderr, "Unable to Load  Shader %s\n", fragment);
        exit (1);
    }
    fragmentHandler = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource    (fragmentHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    glCompileShader    (vertexHandler);
    glCompileShader (fragmentHandler);
    
    programObject = glCreateProgram ();
    glAttachShader (programObject, vertexHandler);
    glAttachShader (programObject, fragmentHandler);
    
    glLinkProgram (programObject);
    
    glDeleteShader(vertexHandler);
    glDeleteShader(fragmentHandler);
    
    glGetProgramiv (programObject, GL_LINK_STATUS, &progLinkSuccess);
    
    if (!progLinkSuccess) {
        
        glGetProgramiv (programObject, GL_INFO_LOG_LENGTH, &progLinkSuccess);
        Shader = new char [progLinkSuccess];
        glGetProgramInfoLog (programObject, progLinkSuccess, NULL, (char*)Shader);
        fprintf (stdout, "\n%s\n", Shader);
        fprintf(stderr, "Shader could not be linked %s\n", vertex, fragment);
        delete [] Shader;
        Shader = NULL;
        exit(1);
    }
    
    fprintf (stdout, "%s\n%s\nbuild succeeded...\n", vertex, fragment);
    shader_id = programObject;
    glUseProgram (shader_id);
    num_vars=0;
    initVarInfo();
}

#ifdef USE_GEOMETRY_SHADERS
void ShaderObject::initShaders(char *vertex, char *fragment, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive){
    int progLinkSuccess;
    const char *Shader;
    GLuint vertexHandler, fragmentHandler, geometryHandler;
    GLuint programObject;
    shader_id = 0;
    
    if ((Shader = (const char *)loadShaderCode (vertex))==NULL){
        fprintf(stderr, "Unable to Load Vertex Shader %s\n", vertex);
        exit (1);
    }
    vertexHandler = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource     (vertexHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    if ((Shader = (const char *)loadShaderCode (geometry))==NULL){
        fprintf(stderr, "Unable to Load  Shader %s\n", geometry);
        exit (1);
    }
    geometryHandler = glCreateShader(GL_GEOMETRY_SHADER_EXT);
    glShaderSource    (geometryHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    if ((Shader = (const char *)loadShaderCode (fragment))==NULL){
        fprintf(stderr, "Unable to Load  Shader %s\n", fragment);
        exit (1);
    }
    fragmentHandler = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource    (fragmentHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    glCompileShader    (vertexHandler);
    glCompileShader (geometryHandler);
    glCompileShader (fragmentHandler);
    
    programObject = glCreateProgram ();
    glAttachShader (programObject, vertexHandler);
    glAttachShader (programObject, geometryHandler);
    glAttachShader (programObject, fragmentHandler);
    
    glProgramParameteriEXT(programObject,GL_GEOMETRY_INPUT_TYPE_EXT ,  inPrimitive );
    glProgramParameteriEXT(programObject,GL_GEOMETRY_OUTPUT_TYPE_EXT , outPrimitive );
    glProgramParameteriEXT(programObject,GL_GEOMETRY_VERTICES_OUT_EXT, 6);
    
    glLinkProgram (programObject);
    
    glDeleteShader(vertexHandler);
    glDeleteShader(geometryHandler);
    glDeleteShader(fragmentHandler);
    
    glGetProgramiv (programObject, GL_LINK_STATUS, &progLinkSuccess);
    
    if (!progLinkSuccess) {
        
        glGetProgramiv (programObject, GL_INFO_LOG_LENGTH, &progLinkSuccess);
        Shader = new char [progLinkSuccess];
        glGetProgramInfoLog (programObject, progLinkSuccess, NULL, (char*)Shader);
        fprintf (stdout, "\n%s\n%s\n%s\n%s\n", vertex, geometry, fragment,Shader);
        fprintf(stderr, "Shader could not be linked\n");
        delete [] Shader;
        Shader = NULL;
        exit(1);
    }
    fprintf (stdout, "%s\n%s\n%s\nbuild succeeded...\n", vertex, geometry, fragment);
    shader_id = programObject;
    glUseProgram (shader_id);
    num_vars=0;
    initVarInfo();
}

void ShaderObject::initShaders(char *vertex,  char *geometry, unsigned int inPrimitive, unsigned int outPrimitive){
    int progLinkSuccess;
    const char *Shader;
    GLuint vertexHandler, geometryHandler;
    GLuint programObject;
    shader_id = 0;
    
    if ((Shader = (const char *)loadShaderCode (vertex))==NULL){
        fprintf(stderr, "Unable to Load Vertex Shader %s\n", vertex);
        exit (1);
    }
    vertexHandler = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource     (vertexHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    if ((Shader = (const char *)loadShaderCode (geometry))==NULL){
        fprintf(stderr, "Unable to Load  Shader %s\n", geometry);
        exit (1);
    }
    geometryHandler = glCreateShader(GL_GEOMETRY_SHADER_EXT);
    glShaderSource    (geometryHandler  , 1, &Shader, NULL);
    delete[] Shader;
    
    glCompileShader    (vertexHandler);
    glCompileShader (geometryHandler);
    
    programObject = glCreateProgram ();
    glAttachShader (programObject, vertexHandler);
    glAttachShader (programObject, geometryHandler);
    
    glProgramParameteriEXT(programObject,GL_GEOMETRY_INPUT_TYPE_EXT ,  inPrimitive );
    glProgramParameteriEXT(programObject,GL_GEOMETRY_OUTPUT_TYPE_EXT , outPrimitive );
    glProgramParameteriEXT(programObject,GL_GEOMETRY_VERTICES_OUT_EXT, 4);
    
    glLinkProgram (programObject);
    
    glDeleteShader(vertexHandler);
    glDeleteShader(geometryHandler);
    
    glGetProgramiv (programObject, GL_LINK_STATUS, &progLinkSuccess);
    
    if (!progLinkSuccess) {
        
        glGetProgramiv (programObject, GL_INFO_LOG_LENGTH, &progLinkSuccess);
        Shader = new char [progLinkSuccess];
        glGetProgramInfoLog (programObject, progLinkSuccess, NULL, (char*)Shader);
        fprintf (stdout, "\n%s\n%s\n%s\n", vertex, geometry, Shader);
        fprintf(stderr, "Shader could not be linked\n");
        delete [] Shader;
        Shader = NULL;
        exit(1);
    }
    fprintf (stdout, "%s\n%s\nbuild succeeded...\n", vertex, geometry);
    shader_id = programObject;
    glUseProgram (shader_id);
    num_vars=0;
    initVarInfo();
}

#endif

void ShaderObject::initVarInfo(){
    char *buffer;
    int len, bufLen;
    if(!shader_id) return;
    
    num_vars = 0;
    glGetProgramiv(shader_id, GL_ACTIVE_UNIFORMS, &num_vars);
    glGetProgramiv(shader_id, GL_ACTIVE_UNIFORM_MAX_LENGTH, &bufLen);
    buffer = new char[bufLen+1];
    
    for(int i=0; i<num_vars; ++i){
        variable_ids[i] = i;
        glGetActiveUniform (shader_id, i, bufLen, &len, &variable_sizes[i], &variable_types[i], buffer);
        buffer[len+1]=0;
        variable_names[i] = StringUtils::registerString(buffer);
    }
    delete[] buffer;
}

void ShaderObject::setUniformi(char *name, int value){
    int i;
    for(i=0; i<num_vars; ++i){
        if(strcasecmp(name, variable_names[i])){
            glUniform1iARB    (variable_ids[i], value);
            break;
        }
    }
    //    i = glGetUniformLocationARB (shader_id, name);
    //    glUniform1iARB(i, value);
}

void ShaderObject::setUniformf(char *name, float value){
    int i;
    for(i=0; i<num_vars; ++i){
        //printf(variable_names[i]);
        //printf("\n");
        if(strcasecmp(name, variable_names[i])){
            glUniform1fARB    (variable_ids[i], value);
            break;
        }
    }
    
}

void ShaderObject::setUniformiv(char *name, int *value, int size){
    unsigned int i;
    
    
    i = glGetUniformLocation(shader_id, name);
    
    switch(size){
        case 1:
            glUniform1ivARB (i, 1, value);
            break;
        case 2:
            glUniform2ivARB (i, 1, value);
            break;
        case 3:
            glUniform3ivARB (i, 1, value);
            break;
        case 4:
            glUniform4ivARB (i, 1, value);
            break;
    }
    
}

void ShaderObject::setUniformfv(char *name, float *value, int size){
    unsigned int i;
    
    i = glGetUniformLocation(shader_id, name);
    switch(size){
        case 1:
            glUniform1fv(i, 1, value);
            break;
        case 2:
            glUniform2fv(i, 1, value);
            break;
        case 3:
            glUniform3fv(i, 1, value);
            break;
        case 4:
            glUniform4fv(i, 1, value);
            break;
    }
}

void ShaderObject::setUniformMatrix(char *name, float *value, int size)
{
    unsigned int i;
    
    i = glGetUniformLocation(shader_id, name);
    switch (size)
    {
        case 2:
            glUniformMatrix2fv(i, 1, GL_FALSE, value);
            break;
        case 3:
            glUniformMatrix3fv(i, 1, GL_FALSE, value);
            break;
        case 4:
            glUniformMatrix4fv(i, 1, GL_FALSE, value);
            break;
    }
    
}

void ShaderObject::activate(){
    glUseProgram(shader_id);
    //glUseProgramObjectARB(shader_id);
}

void ShaderObject::deactivate(){
    glUseProgramObjectARB(0);
}

void ShaderObject::setBindableUniform (char *name, unsigned int buffer)
{
    unsigned int i;
    for (i=0;i<(unsigned int) num_vars; ++i) {
        if(!strcmp(name, variable_names[i])){
            glUniformBufferEXT(shader_id, variable_ids[i], buffer);
            break;
        }
    }
}

void ShaderObject::unSetBindableUniform (char *name)
{
    unsigned int i;
    for (i=0;i<(unsigned int) num_vars; ++i) {
        if(!strcmp(name, variable_names[i])){
            glUniformBufferEXT(shader_id, variable_ids[i], 0);
            break;
        }
    }
}


int ShaderObject::getBindableUniformSize(char *name) {
    unsigned int i;
    for (i=0;i<(unsigned int) num_vars; ++i) {
        if(!strcmp(name, variable_names[i])){
            return glGetUniformBufferSizeEXT(shader_id, variable_ids[i]);
        }
    }
    return 0;
}

void ShaderObject::getMaxBindableUniformSize (int &val)
{
    glGetIntegerv (GL_MAX_BINDABLE_UNIFORM_SIZE_EXT, &val);
}

void ShaderObject::getMaxVertexBindableUniforms (int &val)
{
    glGetIntegerv (GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT, &val);
}

void ShaderObject::getMaxFragmentBindableUniforms(int &val)
{
    glGetIntegerv (GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT, &val);
}

void ShaderObject::getMaxGeometryBindableUniforms (int &val)
{
    glGetIntegerv (GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT, &val);
}


