#pragma once
#ifndef AERIAL_VIEW_H
#define AERIAL_VIEW_H

#include <string>

// defines interface for the aerial world view

class AerialView
{
private:
	// x coords are for the width, y is height
	float x1, x2, y;
	std::string title;
public:
	// create new data panel; initial coords are 0,0
	AerialView(const float leftX = 0, const float rightX = 0, const float winHeight = 0);
	// draw data panel on-screen; str is the title of it
	void drawBackground();
};



#endif