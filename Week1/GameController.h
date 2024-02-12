#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Fonts.h"

class GameController : public Singleton<GameController>
{
public:
    GameController();
    virtual ~GameController() { }

    void Initialize();
    void RunGame();

private:
    Shader m_shaderColor;
    Shader m_shaderPosition;
    Shader m_shaderDiffuse;
    Mesh m_meshBox;
    Mesh m_meshLight;
    vector<Mesh> m_meshBoxes;
    Camera m_camera;
    Shader m_shaderFont;
};

#endif //

