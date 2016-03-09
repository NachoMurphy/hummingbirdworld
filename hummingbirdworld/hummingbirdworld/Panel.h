#pragma once
#ifndef PANEL_H
#define PANEL_H

#define	CURRENTPOS	0
#define ELAPSEDTIME	1
#define NODOCKS		2
#define OOBCOUNT	3

#define DOCK		A
#define HEAD		B
#define DIRECTION	C
#define MOVE		D
#define OTHER		E

#include <string>

// defines interfaces for ControlPanels, DataPanels, and DebugMsgs

class ControlPanel
{
private:
	// x coords are for the width, y is height
	float x1, x2, y;
	std::string title;
public:
	// create new data panel; initial coords are 0,0
	ControlPanel(const float leftX = 0, const float rightX = 0, const float winHeight = 0);
	// draw data panel on-screen; str is the title of it
	void draw(char *string);
};

class DataPanel
{
private:
	// x coords are for the width, y is height
	float x1, x2, y;
	std::string title;
public:
	// create new data panel; initial coords are 0,0
	DataPanel(const float leftX = 0, const float rightX = 0, const float winHeight = 0);
	// draw data panel on-screen; str is the title of it
	void draw(char *string);
};

class DebugMsg
{
public:
	void print(std::string str);
};

#endif