#ifndef WINDOW_CONTROLLER_H
#define WINDOW_CONTROLLER_H

#include "StandardIncludes.h"


class WindowController :public Singleton<WindowController>
{
public:
    WindowController();
    virtual ~WindowController();

    GLFWwindow* GetWindow() {
        if (m_window == nullptr) {
            NewWindow();
        }
        return m_window;
    }

    Resolution GetResolution();
    void NewWindow();
    int m_width;
    int m_height;
    int GetW() { return m_width; }
    int GetH() { return m_height; }
private:
    GLFWwindow* m_window;
    
};

#endif
