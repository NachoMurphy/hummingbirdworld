#include <GL/glut.h>
#include <windows.h>
#include "CObject.h"

// color definitions
#define RED        1
#define GREEN      2
#define BLUE       3
#define BROWN      4
#define MAGENTA    5
#define YELLOW     6
#define WHITE      7
#define BLACK      8

const GLfloat Color[9][4] =
{ 0.0f, 0.0f, 0.0f, 1.0f,
1.0f, 0.0f, 0.0f, 1.0f, // red
0.0f, 1.0f, 0.0f, 1.0f, // green
0.0f, 0.0f, 1.0f, 1.0f, // blue
0.55f, 0.27f, 0.07f, 1.0f, // brown
1.0f, 0.0f, 1.0f, 1.0f, // magenta
1.0f, 1.0f, 0.0f, 1.0f, // yellow
1.0f, 1.0f, 1.0f, 1.0f, // white
0.0f, 0.0f, 0.0f, 1.0f  // black
};

//****CObject****
void CObject::setPos(float x, float y, float z)
{
		posX = x;
		posY = y;
		posZ = z;
		//zResetRelativeVectors();
}

void CObject::setDir(float x, float y, float z)
{

}


//****CTREE****
void CTree::draw()
{
	glPushMatrix();
	glTranslatef(posX, posY, posZ);

	glPushMatrix();
	glColor3fv(Color[BROWN]);
	glTranslatef(0.0, -1.0, 0.0);
	glScalef(0.2, 2, 0.2);
	glutSolidCube(1);
	//glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3fv(Color[GREEN]);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(1, 2, 10, 10);
	//glutWireCone(1, 2, 10, 10);
	glPopMatrix();

	glPopMatrix();
}


//****CTEAPOT****
void CTeapot::draw()
{
	glPushMatrix();
	//glTranslatef(1.0, 0.0, 0.0);
	glRotatef(180, 0.0, 0.0, 1.0);
	glColor3fv(Color[RED]);
	glutSolidTeapot(0.4);
	//glutWireTeapot(0.4);
	glPopMatrix();
}

bool CTeapot::dock()
{
	return false;
}


//****CBIRD****
void CBird::draw()
{

}

void CBird::setCamera(float x, float y, float z)
{

}

void CBird::setTarget(float x, float y, float z)
{

}

void CBird::setUp(float x, float y, float z)
{

}