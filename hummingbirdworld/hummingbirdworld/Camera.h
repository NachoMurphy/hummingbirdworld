#include <windows.h>
#include <windowsx.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <math.h>

#define GE_TARGET_RELATIVE 0
#define GE_TARGET_FIXED 1
#define GE_MOVE_LOCKED 2
#define GE_MOVE_FREE 3

#define GE_PI		3.1415926535897932384626433832795
#define GE_PI_2		1.5707963267948966192313216916395
#define GE_2PI		6.283185307179586476925286766558

struct geVector {
	float x;
	float y;
	float z;
};

class Camera {

public:
	Camera();
	~Camera();

	void		Center(void);
	void		Look(void);

	//**********HeadControl Functions**************
	void		TiltDown(float amount);
	void		TiltUp(float amount);
	void		TurnLeft(float amount);
	void		TurnRight(float amount);

	//**********DirectionControl Functions**************
	void		MoveDown(float amount);
	void		MoveUp(float amount);
	void		MoveLeft(float amount);
	void		MoveRight(float amount);

	//**********MoveControl Functions**************
	void		MoveForward(float amount);
	void		MoveBack(float amount);


	void		MoveTo(float x, float y, float z);
	geVector	Position(void);
	void		SetMovementType(int move_type);
	void		SetTarget(float x, float y, float z);
	void		SetTargetType(int target_type);


private:
	void		zMoveLR(float amount);
	void		zMoveFB(float amount);
	void		zTilt(float amount);
	void		zTurn(float amount);
	void		zMoveUD(float amount);
	void		zResetRelativeVectors();
	int			zTargetType;
	int			zMoveType;
	geVector	zPosition;
	geVector	zTarget;
	geVector	zUp;
	float		zAV;
	float		zAH;

};