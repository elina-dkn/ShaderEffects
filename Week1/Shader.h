#ifndef SHADER_H
#define SHADER_H

#include "StandardIncludes.h"
class Shader
{
public:
	Shader();
	virtual ~Shader(){}

	GLuint GetProgramID() { return m_programID; }
	GLuint GetAttrColors() { return m_attrColors; }
	GLuint GetAttrNormals() { return m_attrNormals; }
	GLuint GetAttrVertices() { return m_attrVertices; }
	GLuint GetAttrWVP() { return m_attrWVP; }
	GLuint GetAttrTexCoords() { return m_attrTexCoords; }
	GLuint GetSampler1() { return m_sampler1; }
	GLuint GetSampler2() { return m_sampler2; }
	void LoadShaders(const char* _vertexFilePath, const char* _fragmentFilePath);
	void Cleanup();
	void SetTextureSampler(const char* _name, GLuint _texUnit, int _texUnitID, int _value);
	void SetFloat(const char* _name, float _value);
	void SetVec3(const char* _name, glm::vec3 _value);
	void SetMat4(const char* _name, glm::mat4 _value);


private:
	void CreateShaderProgram(const char* _vertexFilePath, const char* _fragmentFilePath);
	GLuint LoadShaderFile(const char* _filePath, GLenum _type);
	void LoadAttributes();
	void EvaluateShader(int _infoLength, GLuint _id);

	GLuint m_programID;
	GLuint m_attrVertices;
	GLuint m_attrColors;
	GLuint m_attrNormals;
	GLuint m_attrTexCoords;
	GLint m_result = GL_FALSE;
	GLuint m_attrWVP;
	GLuint m_sampler1;
	GLuint m_sampler2;
	int m_infoLogLength;
};

#endif