// defines implementations for ControlPanels, DataPanels, and DebugMsgs

#include <GL/glut.h>
#include <stdio.h>
#include <string>
#include "AerialView.h"

AerialView::AerialView(const float leftX, const float rightX, const float winHeight)
	: x1(leftX), x2(rightX), y(winHeight)
{}

void AerialView::drawBackground()
{	// Draws outline of this area, just like a panel but with differences
	glColor3f(0.3, 0.3, 1.0);
	glBegin(GL_QUADS);
	glVertex2f(x1, 0);
	glVertex2f(x2, 0);
	glVertex2f(x2, (y / 7));
	glVertex2f(x1, (y / 7));
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1, 1);
	glVertex2f(x2, 1);
	glVertex2f(x2, (y / 7) + 1);
	glVertex2f(x1, (y / 7) + 1);
	glEnd();
	int h, v;
	glColor3f(0.6, 0.6, 0.6);

	for (h = 2; h < (y / 7) + 1; h += (((y / 7) + 1) / 20))
	{
		glBegin(GL_LINES);
		glVertex2f(x1, h);
		glVertex2f(x2 - 1, h);
		glEnd();
	}
	for (v = x1 + (x1 / 40); v < x2; v += (x1 / 40))
	{
		glBegin(GL_LINES);
		glVertex2f(v, 2);
		glVertex2f(v, y / 7);
		glEnd();
	}
	glFlush();
}
