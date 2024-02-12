#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"


GameController::GameController() {
    m_shaderColor = { };
    m_shaderPosition = { };
    m_shaderDiffuse = { };
    m_meshBox = { };
    m_meshLight = { };
    m_meshBoxes.clear();
    m_camera = { }; 
}

void GameController::Initialize() {
    GLFWwindow* window = WindowController::GetInstance().GetWindow();
    M_ASSERT(glewInit() == GLEW_OK, "Failed to initialze GLEW");
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glClearColor(0.1f, 0.1f, 0.1f,0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    srand((unsigned int)time(0));

    m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame() {

    Week1::ToolWindow^ window = gcnew Week1::ToolWindow();
    window->Show();

   

    m_shaderColor = Shader();
    m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentshader");
    m_shaderPosition = Shader();
    m_shaderPosition.LoadShaders("Position.vertexshader", "Position.fragmentshader");
    m_shaderDiffuse = Shader();
    m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentshader");
    m_shaderFont = Shader();
    m_shaderFont.LoadShaders("Font.vertexshader", "Font.fragmentshader");
    

    

    Mesh m = Mesh();
    m.Create(&m_shaderColor, "../Assets/Models/Sphere.obj");
    m.SetPosition({ 0.0f, 0.0f, 0.0f });
    m.SetScale({ 0.1f, 0.1f, 0.1f });
    m.SetColor({  1.0f, 1.0f, 1.0f });
    Mesh::Lights.push_back(m);
   
    Mesh teapot = Mesh();
    teapot.Create(&m_shaderDiffuse, "../Assets/Models/Teapot.obj");
    teapot.SetCameraPosition(m_camera.GetPosition());
    teapot.SetScale({ 0.2f, 0.2f, 0.2f });
    teapot.SetPosition({ 0.0f, 0.0f, 0.0f });

    Mesh teapot2 = Mesh();
    teapot2.Create(&m_shaderPosition, "../Assets/Models/Teapot.obj");
    teapot2.SetCameraPosition(m_camera.GetPosition());
    teapot2.SetScale({ 0.2f, 0.2f, 0.2f });
    teapot2.SetPosition({ 0.0f, 0.0f, 0.0f });
    
    Mesh s = Mesh();
    s.Create(&m_shaderDiffuse, "../Assets/Models/Sphere3.obj");
    s.SetPosition({ 0.0f, 0.0f, 0.0f });
    s.SetCameraPosition(m_camera.GetPosition());
    s.SetScale({ 0.1f, 0.1f, 0.1f });
    s.SetColor({ 1.0f, 1.0f, 1.0f });
    

    
    Fonts f = Fonts();
    f.Create(&m_shaderFont, "arial.ttf", 100);


    GLFWwindow* win = WindowController::GetInstance().GetWindow();
    double lastTime = glfwGetTime();
    int fps = 0;
    string fpsS = "0";
    do {
        System::Windows::Forms::Application::DoEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        double currentTime = glfwGetTime();
        fps++;
        if (currentTime - lastTime >= 1.0) {
            fpsS = "FPS: " + to_string(fps);
            fps = 0;
            lastTime += 1.0;
        }
        f.RenderText(fpsS, 100, 50, 0.2f, { 1.0f, 1.0f, 0.0f });

        double x = 0;
        double y = 0;
        glfwGetCursorPos(win, &x, &y);

        glm::mat4 view = glm::mat4(glm::mat3(m_camera.GetView()));
        float Schannel = (float)Week1::ToolWindow::Schannel;
        float Rchannel = (float)Week1::ToolWindow::Rchannel / 100;
        float Gchannel = (float)Week1::ToolWindow::Gchannel / 100;
        float Bchannel = (float)Week1::ToolWindow::Bchannel / 100;
        int option = (float)Week1::ToolWindow::option;
        bool resetL = (float)Week1::ToolWindow::resetLight;
        bool resetT = (float)Week1::ToolWindow::resetTeapot;
        if (option == 1) {
            if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
               
                if (x < 955 && y < 525) {
                    m.MoveMesh( { 6.0f, 4.0f, 0.0f });
                }
                else if (x < 955 && y > 525) {
                    m.MoveMesh({ 6.0f, -4.0f, 0.0f });
                }
                else if (x > 955 && y > 525) {
                    m.MoveMesh({ -6.0f, -4.0f, 0.0f });
                }
                else if (x > 955 && y < 525) {
                    m.MoveMesh({ -6.0f, 4.0f, 0.0f });
                }
               
               
            }
            if (resetL) {
                m.SetPosition({ 0.0f, 0.0f, 0.0f });
                resetL = false;
            }
            teapot.Rotate();
            teapot.Render(m_camera.GetProjection() * m_camera.GetView());

            m_shaderDiffuse.SetVec3("light.specularColor", { Rchannel, Gchannel, Bchannel });
            m_shaderDiffuse.SetFloat("material.specularStrength", Schannel);
            m_shaderDiffuse.SetVec3("light.position", m.GetPosition());

            m.Render(m_camera.GetProjection() * m_camera.GetView());

            
        }
        else if (option == 2) {
            teapot2.Rotate();
            
            if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
                
                if (x < 955 && y < 525) {
                   teapot2.MoveMesh({ 6.0f, 4.0f, 0.0f });
                }
                else if (x < 955 && y > 525) {
                    teapot2.MoveMesh({ 6.0f, -4.0f, 0.0f });
                }
                else if (x > 955 && y > 525) {
                    teapot2.MoveMesh({ -6.0f, -4.0f, 0.0f });
                }
                else if (x > 955 && y < 525) {
                    teapot2.MoveMesh({ -6.0f, 4.0f, 0.0f });
                }
            }
            else if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
                if (y > 525) {
                    teapot2.MoveMesh({ 0.0f, 0.0f, 5.0f });
                }else if (y < 525) {
                    teapot2.MoveMesh({ 0.0f, 0.0f, -5.0f });
                }
            }

            if (resetT) {
                teapot2.SetPosition({ 0.0f, 0.0f, 0.0f });
                resetT = false;
            }
            teapot2.Render(m_camera.GetProjection() * m_camera.GetView());
        }
        else if (option == 3) {
            
            m.SetPosition({ 0.0f, 3.0f, -2.0f });
            m.Render(m_camera.GetProjection() * m_camera.GetView());
            
            s.Rotate();
            s.Render(m_camera.GetProjection() * m_camera.GetView());

            m_shaderDiffuse.SetVec3("light.position", m.GetPosition());
            m_shaderDiffuse.SetVec3("light.specularColor", { 1.0f, 1.0f, 1.0f });
            m_shaderDiffuse.SetFloat("material.specularStrength", 1);


            
            if (glfwGetMouseButton(win, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
                Mesh box = Mesh();
                box.Create(&m_shaderDiffuse, "../Assets/Models/Cube.obj");
                box.SetCameraPosition(m_camera.GetPosition());
               
                box.SetScale({ 0.1f, 0.1f, 0.1f });
                box.SetPosition({ glm::linearRand(-5.0f, 5.0f), glm::linearRand(-5.0f, 5.0f), glm::linearRand(-5.0f, 5.0f)});
                
                m_meshBoxes.push_back(box);
            }


            for (unsigned int count = 0; count < m_meshBoxes.size(); count++) {
                if ( (m_meshBoxes[count].GetPosition().x  < 0.01f )&& (m_meshBoxes[count].GetPosition().y  < 0.01f) && (m_meshBoxes[count].GetPosition().z  < 0.01f)) {
                    m_meshBoxes[count].Cleanup();
                    m_meshBoxes.erase(m_meshBoxes.begin()+count);
                    break;
                }
                m_meshBoxes[count].MoveToCenter();
                m_meshBoxes[count].Rotate();
                m_meshBoxes[count].Render(m_camera.GetProjection() * m_camera.GetView());
            }
            std::string text = "Cubes: " + to_string(m_meshBoxes.size()) ;
            f.RenderText(text, 100, 150, 0.2f, { 1.0f, 1.0f, 0.0f });
        }


 
        
        std::string mouseT = "Mouse Position: " + to_string(x) + ", " + to_string(y);
        f.RenderText(mouseT, 100, 100, 0.2f, {1.0f, 1.0f, 0.0f});
        
        glfwSwapBuffers(win);
        glfwPollEvents();
    } while (glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(win) == 0);
    
    teapot.Cleanup();
    teapot2.Cleanup();
    
    for (unsigned int count = 0; count < Mesh::Lights.size(); count++) {
        Mesh::Lights[count].Cleanup();
    }
    for (unsigned int count = 0; count < m_meshBoxes.size(); count++) {
        m_meshBoxes[count].Cleanup();
    }
    
    s.Cleanup();
    
    m_shaderPosition.Cleanup();
    m_shaderColor.Cleanup();
    m_shaderDiffuse.Cleanup();
}

