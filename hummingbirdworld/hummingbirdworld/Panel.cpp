// defines implementations for ControlPanels, DataPanels, and DebugMsgs

#include <GL/glut.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "Panel.h"

using namespace std;

ControlPanel::ControlPanel(const float leftX, const float rightX, const float winHeight)
	: x1(leftX), x2(rightX), y(winHeight)
{}

void ControlPanel::draw(char * string)
{	// draws the control panel w/ outline &  title
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex2f(x1, y);
	glVertex2f(x2, y);
	glVertex2f(x2, y - (y / 7));
	glVertex2f(x1, y - (y / 7));
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1 + 2, y - 2);
	glVertex2f(x2 - 2, y - 2);
	glVertex2f(x2 - 2, y - (y / 7));
	glVertex2f(x1 + 2, y - (y / 7));
	glEnd();
	glLineWidth(1);
	glRasterPos2f(x1 + 10, y - (y / 9));
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
	glFlush();
}

DataPanel::DataPanel(const float leftX, const float rightX, const float winHeight)
	: x1(leftX), x2(rightX), y(winHeight)
{}

void DataPanel::draw(char * string)
{	// draws the data panel w/ outline &  title
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glVertex2f(x1, 0);
	glVertex2f(x2, 0);
	glVertex2f(x2, (y / 7));
	glVertex2f(x1, (y / 7));
	glEnd();
	glColor3f(0.2, 0.2, 0.2);
	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1 + 2, 2);
	glVertex2f(x2 - 1, 2);
	glVertex2f(x2 - 1, (y / 7));
	glVertex2f(x1 + 2, (y / 7));
	glEnd();
	glLineWidth(1);
	glRasterPos2f(x1 + 10, (y / 50) + 5);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	glFlush();
}

void DebugMsg::print(std::string str)
{
	cout << str << endl;
}
