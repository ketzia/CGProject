#ifndef __shader_object
#define __shader_object
#include <stdio.h>

#define SHADER_OBJECT_MAX_VARIABLES 32
#define USE_GEOMETRY_SHADERS
#define USE_GI_MODELS

#define USE_INSTANCING

class ShaderObject{
public:
    ShaderObject(char *vertex, char *fragment);
    ShaderObject(char *fragment);
#ifdef USE_GEOMETRY_SHADERS
    ShaderObject(char *vertex, char *fragment, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive);
    ShaderObject(char *vertex, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive);
#endif
    ~ShaderObject();
    void setUniformi(char *name, int value);
    void setUniformf(char *name, float value);
    void setUniformiv(char *name, int *value, int size);
    void setUniformfv(char *name, float *value, int size);
    void setUniformMatrix(char *name, float *value, int size);
    void setBindableUniform (char *name, unsigned int buffer);
    void unSetBindableUniform (char *name);
    void getMaxVertexBindableUniforms(int &val);
    void getMaxGeometryBindableUniforms(int &val);
    void getMaxFragmentBindableUniforms(int &val);
    void getMaxBindableUniformSize(int &val);
    int  getBindableUniformSize(char *name);
    
    void activate();
    static void deactivate();
    
    unsigned int shader_id;
    int num_vars;
    char *variable_names[SHADER_OBJECT_MAX_VARIABLES];
    int variable_ids[SHADER_OBJECT_MAX_VARIABLES];
    unsigned int variable_types[SHADER_OBJECT_MAX_VARIABLES];
    int variable_sizes[SHADER_OBJECT_MAX_VARIABLES];
private:
    void initShaders(char *fragment);
    void initShaders(char *vertex, char *fragment);
#ifdef USE_GEOMETRY_SHADERS
    void initShaders(char *vertex, char *fragment, char *geometry, unsigned int input, unsigned int output);
    void initShaders(char *vertex, char *geometry, unsigned int inPrimitive, unsigned int outPrimitive);
#endif
    char *loadShaderCode (char* fileName);
    void initVarInfo();
};

#endif

