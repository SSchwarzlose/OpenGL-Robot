
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "RobotParts\Robot.h"

/* Windowsize */
const int winWidth = 800;
const int winHeigth = 600;

/* Framerate */
const unsigned int frames = 1000 / 60;

Robot* m_pRobot;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, winWidth, winHeigth, 0, -1, 1);
    glClearColor(0, 0, 0, 1);

	m_pRobot = new Robot();
}

void handleInput(unsigned char key, int x, int y)
{
    
    if (key == 'w')
    {
        m_pRobot->SelectPart(m_pRobot->m_NextPart);
    }
    else if (key == 's')
    {
        m_pRobot->SelectPart(m_pRobot->m_PreviousPart);
    }

    if (key == 'a')
    {
        m_pRobot->MoveRobot(1);
    }
    else if (key == 'd')
    {
        m_pRobot->MoveRobot(-1);
    }
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(1, 1, 1);
    glTranslatef(400,500,0);
    m_pRobot->m_Draw();
    glutSwapBuffers();
}

void mainLoop(int val)
{
    render();
    glutTimerFunc(frames, mainLoop, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(winWidth, winHeigth);
    glutCreateWindow("OpenGL Robot");
    glewInit();
    init();
    glutKeyboardFunc(handleInput);
    glutTimerFunc(frames, mainLoop, 0);
    glutMainLoop();
}