#ifndef CSHAPE
#define CSHAPE

#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>

#define CNONE 0
#define CFLOWER 1
#define CTREE 2
#define CTEAPOT 3
#define CBIRD 4

class CObject
{
protected:

	float posX, posY, posZ; // location in the world

	float dirX, dirY, dirZ;     // orientation direction vector

	int type;                         // object type: 1=flower, 2=tree, 3=teapot, 4=bird …
									  // other private data & methods

public:

	CObject(int type = CNONE) { }  // constructor

	virtual void draw() = 0;        // draws the object at the current location & orientation

	void setPos(float x, float y, float z);

	void setDir(float x, float y, float z);

	// other public interface members

};

class CTree : public CObject

{

	CObject *  treeHead;    // ptr to a list of elements making up a tree (cylinder, torus, sphere, cone, …)

							// start out simple – a tree is either a green sphere or cone on a brown cylinder

public:

	CTree() : CObject(CTREE) {}

	void draw();  // draw all the objects in Tree the linked list

				  // other methods

};

class CBird : public CObject

{

	float cameraX, cameraY, cameraZ;    // camera position – usually same as posX, posY, posZ except for overhead view

	float targetX, targetY, targetZ;           // point being looked at

	float upX, upY, upZ;                         // camera orientation – usually same as dirX, dirY, dirZ except for overhead view

	void * birdHead;

public:

	CBird() : CObject(CBIRD) {}

	void draw();  // draws bird (behind the camera out of view

	void setCamera(float x, float y, float z);

	void setTarget(float x, float y, float z);

	void setUp(float x, float y, float z);

};

class CTeapot : public CObject

{

	float radius, stacks, slices;     // drawing info (I don’t have my book!)

public:

	CTeapot() : CObject(CTEAPOT) {}

	void draw();      // call glSolidTeapot() rotated & translated to position

	bool dock();     // somehow we have to know if the bird is docked & sucking all the honey from the pot

};

#endif