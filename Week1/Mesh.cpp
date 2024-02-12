#include "Mesh.h"
#include "Shader.h"

vector<Mesh> Mesh::Lights;

Mesh::Mesh() {
    m_shader = nullptr;
    m_texture = {};
    m_texture2 = {};
    m_vertexBuffer = 0;
    m_indexBuffer = 0;
    m_world = glm::mat4();
    m_cameraPosition = { 0, 0,0 };
    m_position = { 0, 0, 0 };
    m_rotation = { 0, 0, 0 };
    m_scale = { 1, 1, 1 };
    m_lightColor = { 1, 1,1 };
    m_lightPosition = { 0, 0,0 };
}

Mesh::~Mesh() {}

void Mesh::Create(Shader* _shader, string _file) {
    m_shader = _shader;

    objl::Loader Loader;
    M_ASSERT(Loader.LoadFile(_file) == true, "Failed to load mesh");
    for (unsigned int i = 0; i < Loader.LoadedMeshes.size(); i++) {
        objl::Mesh curMesh = Loader.LoadedMeshes[i];
        for (unsigned int j = 0; j < curMesh.Vertices.size(); j++) {
            m_vertexData.push_back(curMesh.Vertices[j].Position.X);
            m_vertexData.push_back(curMesh.Vertices[j].Position.Y);
            m_vertexData.push_back(curMesh.Vertices[j].Position.Z);
            m_vertexData.push_back(curMesh.Vertices[j].Normal.X);
            m_vertexData.push_back(curMesh.Vertices[j].Normal.Y);
            m_vertexData.push_back(curMesh.Vertices[j].Normal.Z);
            m_vertexData.push_back(curMesh.Vertices[j].TextureCoordinate.X);
            m_vertexData.push_back(curMesh.Vertices[j].TextureCoordinate.Y);
        }
    }
    string diffuseMap = Loader.LoadedMaterials[0].map_Kd;
    const size_t last_slash_idx = diffuseMap.find_last_of("\\");
    if (std::string::npos != last_slash_idx) {
        diffuseMap.erase(0, last_slash_idx + 1);
    }
    if (!diffuseMap.empty()) {
        m_texture = Texture();
        m_texture.LoadTexture("../Assets/Textures/" + diffuseMap);
        m_texture2 = Texture();
        m_texture2.LoadTexture("../Assets/Textures/" + diffuseMap);
    }
   
   
    glGenBuffers(1, &m_vertexBuffer);// VERTEX BUFFER ISIN THE GPU RAM
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);//COPY DATA FROM RAM INTO GPU MEMORY
}

string Mesh::Concat(string _s1, int _index, string _s2) {
    string index = to_string(_index);
    return(_s1 + index + _s2);
}

void Mesh::Cleanup() {
    glDeleteBuffers(1, &m_indexBuffer);
    m_texture.Cleanup();
    m_texture2.Cleanup();
    glDeleteBuffers(1, &m_vertexBuffer);
}

void Mesh::BindAttributes() {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);

    glEnableVertexAttribArray(m_shader->GetAttrVertices());
    glVertexAttribPointer(m_shader->GetAttrVertices(), 3/*size*/, GL_FLOAT/*type*/, GL_FALSE/*normalized*/, 8 * sizeof(float)/*stride*/, (void*)0/*offset*/);

    glEnableVertexAttribArray(m_shader->GetAttrNormals());
    glVertexAttribPointer(m_shader->GetAttrNormals(), 3/*size*/, GL_FLOAT/*type*/, GL_FALSE/*normalized*/, 8 * sizeof(float)/*stride*/, (void*)(3 * sizeof(float))/*offset*/);


    glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
    glVertexAttribPointer(m_shader->GetAttrTexCoords(), 2/*size*/, GL_FLOAT/*type*/, GL_FALSE/*normalized*/, 8 * sizeof(float)/*stride*/, (void*)(6 * sizeof(float))/*offset*/);


    
}

void Mesh::CalculateTransform() {
    m_world = glm::translate(glm::mat4(1.0f), m_position);
    m_world = glm::rotate(m_world, m_rotation.x, glm::vec3(1, 0, 0));
    m_world = glm::scale(m_world, m_scale);
    
}

void Mesh::MoveToCenter() {
    glm::vec3 direction = glm::vec3({0.0f, 0.0f, 0.0f }) - m_position;
    direction = glm::normalize(direction);
    direction = direction * 0.001f;
    glm::vec3 pos = direction;
    m_position += pos;
}
void Mesh::MoveMesh(glm::vec3 v) {
    glm::vec3 direction = v - m_position;
    direction = glm::normalize(direction);
    direction = direction * 0.01f;
    glm::vec3 pos = direction;
    m_position += pos;
}


void Mesh::SetShaderVariable(glm::mat4 _pv) {
    m_shader->SetMat4("World", m_world);
    m_shader->SetMat4("WVP", _pv*m_world);
    m_shader->SetVec3("CameraPosition", m_cameraPosition);

    for (unsigned int i = 0; i < Lights.size(); i++) {
        m_shader->SetVec3("light.ambientColor", {0.5f, 0.5f, 0.5f });
        m_shader->SetVec3("light.diffuseColor", Lights[i].GetColor());
        m_shader->SetVec3("light.color", Lights[i].GetColor());

        m_shader->SetFloat("light.constant",1.0f);
        m_shader->SetFloat("light.linear", 0.09f);
        m_shader->SetFloat("light.quadratic", 0.032f);

        m_shader->SetFloat("light.coneAngle", glm::radians(5.0f));
        m_shader->SetFloat("light.falloff", 200);
    }

    m_shader->SetTextureSampler("material.diffuseTexture", GL_TEXTURE0, 0, m_texture.GetTexture());
    m_shader->SetTextureSampler("material.specularTexture", GL_TEXTURE1, 1, m_texture2.GetTexture());

    
}

void Mesh::Rotate() {
    m_rotation.x += 0.001f;
}

void Mesh::Render(glm::mat4 _pv) {
    glUseProgram(m_shader->GetProgramID());
   
    
   
    CalculateTransform();
    SetShaderVariable(_pv);
    BindAttributes();

    glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size()/8);
    glDisableVertexAttribArray(m_shader->GetAttrVertices());
    glDisableVertexAttribArray(m_shader->GetAttrNormals());
    glDisableVertexAttribArray(m_shader->GetAttrTexCoords());
}
