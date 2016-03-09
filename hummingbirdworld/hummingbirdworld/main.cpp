#include <GL/glut.h>
#include <stdio.h>
#include "Camera.h"
#include "CObject.h"
#include "AerialView.h"
#include "Panel.h"

// color definitions
#define RED        1
#define GREEN      2
#define BLUE       3
#define BROWN      4
#define MAGENTA    5
#define YELLOW     6
#define WHITE      7
#define BLACK      8
#define GOLD	   9
#define GREY	   10

const GLfloat Color[11][4] =
{ 0.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f,		// red
0.0f, 1.0f, 0.0f, 1.0f,		// green
0.0f, 0.0f, 1.0f, 1.0f,		// blue
0.55f, 0.27f, 0.07f, 1.0f,	// brown
1.0f, 0.0f, 1.0f, 1.0f,		// magenta
1.0f, 1.0f, 0.0f, 1.0f,		// yellow
1.0f, 1.0f, 1.0f, 1.0f,		// white
0.0f, 0.0f, 0.0f, 1.0f,		// black
1.0f, 0.8f, 0.0f, 1.0f,		// gold
0.8f, 0.8f, 0.8f, 1.0f		// grey
};


//static int year = 0, day = 0, sun = 0;
//bool anime = false;
Camera *cam;
CTree *tree1;
CTree *tree2;
CTeapot *teapot1;

float birdSpeed = 0.1f;
float winWidth = 1000.0, winHeight = 700.0;
float birdViewW = winWidth, birdViewH = 700.0 / 7 * 5; // size of window for World View, 1000 * 500;

													   
DebugMsg testMsg;	// use to debug on console
// set up data & aerial panels at top of screen and control panels at bottom
DataPanel panel1(0.0, winWidth / 5, winHeight);
DataPanel panel2(winWidth / 5, 2 * (winWidth / 5), winHeight);
AerialView aerialView(2 * (winWidth / 5), 3 * (winWidth / 5), winHeight);
DataPanel panel3(3 * (winWidth / 5), 4 * (winWidth / 5), winHeight);
DataPanel panel4(4 * (winWidth / 5), winWidth, winHeight);
ControlPanel cpanel1(0.0, winWidth / 5, winHeight);
ControlPanel cpanel2(winWidth / 5, 2 * (winWidth / 5), winHeight);
ControlPanel cpanel3(2 * (winWidth / 5), 3 * (winWidth / 5), winHeight);
ControlPanel cpanel4(3 * (winWidth / 5), 4 * (winWidth / 5), winHeight);
ControlPanel cpanel5(4 * (winWidth / 5), winWidth, winHeight);

void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	cam = new Camera();
	tree1 = new CTree();
	tree1->setPos(1.0f, 2.0f, 0.0f);
	tree2 = new CTree();
	tree2->setPos(2.0f, 2.0f, -3.0f);
	teapot1 = new CTeapot();
	teapot1->setPos(1.0f, 4.0f, 0.0f);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glColor3f(0.0f, 6.0f, 0.0f);

	//Create Checkerboard
	glBegin(GL_QUADS);
	for (float i = -winHeight; i < winHeight;)
	{
		for (float w = -winWidth; w < winWidth;)
		{
			glVertex3f(w, 0.0f, i);
			glVertex3f(w, 0.0f, i+100);
			glVertex3f(w + 100, 0.0f, i + 100);
			glVertex3f(w+100, 0.0f, i);
			w = w + 100;
		}
		i = i + 100;
	}
	glEnd();

	// viewport for World View, lowerleft point at (0, 100), window size = 1000 * 500;
	glViewport(0, winHeight / 7, birdViewW, birdViewH);
	cam->Look();

	tree1->draw();
	tree2->draw();
	teapot1->draw();
	//glPushMatrix();
	//glColor3fv(Color[BROWN]);
	//glTranslatef(0.0, -1.0, 0.0);
	//glScalef(0.2, 2, 0.2);
	//glutWireCube(1);
	//glPopMatrix();

	//glPushMatrix();
	//glColor3fv(Color[GREEN]);
	//glRotatef(-90, 1.0, 0.0, 0.0);
	//glutWireCone(1, 2, 10, 10);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(1.0, 0.0, 0.0);
	//glRotatef(180, 0.0, 0.0, 1.0);
	//glColor3fv(Color[RED]);
	//glutWireTeapot(0.4);
	//glPopMatrix();
	// draw data panels
	glViewport(0, 0, (GLsizei)winWidth, (GLsizei)winHeight);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0, winWidth, winHeight, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	panel1.draw("Data Panel 1");
	panel2.draw("Data Panel 2");
	aerialView.drawBackground();
	panel3.draw("Data Panel 3");
	panel4.draw("Data Panel 4");
	cpanel1.draw("Dock Controls");
	cpanel2.draw("Head Controls");
	cpanel3.draw("Direction Controls");
	cpanel4.draw("Move Controls");
	cpanel5.draw("Other Controls");

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glFlush();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}



void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		//****HeadControl: u-up; d-down; l-left; r-right;****
	case 'u':
		cam->TiltUp(0.1);
		glutPostRedisplay();
		break;
	case 'd':
		cam->TiltDown(0.1);
		glutPostRedisplay();
		break;
	case 'l':
		cam->TurnLeft(0.1);
		glutPostRedisplay();
		break;
	case 'r':
		cam->TurnRight(0.1);
		glutPostRedisplay();
		break;

		//****MoveControl: f-forward; b-reverse; s-slow; a-fast;****
	case'f':
		cam->MoveForward(birdSpeed);
		glutPostRedisplay();
		break;
	case'b':
		cam->MoveBack(birdSpeed);
		glutPostRedisplay();
		break;
	case's':
		if (birdSpeed < 0.05) break;
		else
		{
			birdSpeed -= 0.05;
			glutPostRedisplay();
			break;
		}
	case'a':
		birdSpeed += 0.05;
		glutPostRedisplay();
		break;
	case 'h':
		cam->Center();
		glutPostRedisplay();
		break;
	case 'q':
		exit(0);
	default:
		break;
	}
}


void processSpecialKeys(int key, int xx, int yy)
{
	//****DirectionControl****
	switch (key) {
	case GLUT_KEY_LEFT:
		cam->MoveLeft(birdSpeed);
		break;
	case GLUT_KEY_RIGHT:
		cam->MoveRight(birdSpeed);
		break;
	case GLUT_KEY_UP:
		cam->MoveUp(birdSpeed);
		break;
	case GLUT_KEY_DOWN:
		cam->MoveDown(birdSpeed);
		break;
	}
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight); // 1000 * 700 window
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HummingBird");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(processSpecialKeys);
	//glutIdleFunc(idle);

	glutMainLoop();
}