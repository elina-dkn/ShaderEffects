#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
#include "Texture.h"
class Shader;

class Mesh
{
public:
    Mesh();
    virtual ~Mesh();

    void SetPosition(glm::vec3 _position) { m_position = _position; }
    glm::vec3 GetPosition() { return m_position; }
    void SetScale(glm::vec3 _scale) { m_scale = _scale; }
    void SetColor(glm::vec3 _color) { m_color = _color; }
    glm::vec3 GetColor() { return m_color; }
    void SetLightPosition(glm::vec3 _lightPosition) { m_lightPosition = _lightPosition; }
    void SetLightColor(glm::vec3 _lightColor) { m_lightColor = _lightColor; }
    void SetCameraPosition(glm::vec3 _cameraPosition) { m_cameraPosition = _cameraPosition; }

    void Create(Shader* _shader, string _file);
    void Cleanup();
    void CalculateTransform();
    void Render(glm::mat4 _pv);
    void MoveToCenter();
    void MoveMesh(glm::vec3 v);
    void Rotate();
    static vector<Mesh> Lights;
private:
    void SetShaderVariable(glm::mat4 _pv);
    void BindAttributes();
    string Concat(string _s1, int _index, string _s2);

    Shader* m_shader;
    Texture m_texture;
    Texture m_texture2;
    GLuint m_vertexBuffer;
    GLuint m_indexBuffer;
    std::vector<GLfloat> m_vertexData;
    std::vector<GLubyte> m_indexData;

    glm::mat4 m_world;
    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;

    glm::vec3 m_lightPosition;
    glm::vec3 m_lightColor;
    glm::vec3 m_cameraPosition;
    glm::vec3 m_color;
};

#endif

