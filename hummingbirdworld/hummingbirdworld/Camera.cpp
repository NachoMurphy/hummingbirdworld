#include "Camera.h"
#define _XOPEN_SOURCE

Camera::Camera()
{
	zPosition.x = 0;
	zPosition.y = 2;
	zPosition.z = 5; //

	zTarget.x = 0;
	zTarget.y = 0;
	zTarget.z = 0; //

	zUp.x = 0; //
	zUp.y = 1; //
	zUp.z = 0; //

	zAH = 0; //
	zAV = 0; //

	zTargetType = GE_TARGET_RELATIVE;
	zMoveType = GE_MOVE_LOCKED;
}

Camera::~Camera()
{

}

void Camera::Center()
{
	zAH = 0;
	zAV = 0;
}

void Camera::Look()
{
	zResetRelativeVectors();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(zPosition.x, zPosition.y, zPosition.z, zTarget.x, zTarget.y, zTarget.z, zUp.x, zUp.y, zUp.z);
}

void Camera::MoveBack(float amount)
{
	zMoveFB(-amount);
}

void Camera::MoveDown(float amount)
{
	zMoveUD(-amount);
}

void Camera::MoveForward(float amount)
{
	zMoveFB(amount);
}

void Camera::MoveLeft(float amount)
{
	zMoveLR(-amount);
}

void Camera::MoveRight(float amount)
{
	zMoveLR(amount);
}

void Camera::MoveTo(float x, float y, float z)
{

	if ((x == zPosition.x || x == NULL)
		&& (y == zPosition.y || y == NULL)
		&& (z == zPosition.z || z == NULL))
		return;

	if (x != NULL)
		zPosition.x = x;
	if (y != NULL)
		zPosition.y = y;
	if (z != NULL)
		zPosition.z = z;
	zResetRelativeVectors();
}

void Camera::MoveUp(float amount)
{
	zMoveUD(amount);
}

geVector Camera::Position()
{
	return zPosition;
}

void Camera::SetMovementType(int move_type)
{
	zMoveType = move_type;
}

void Camera::SetTarget(float x, float y, float z)
{
	zTarget.x = x;
	zTarget.y = y;
	zTarget.z = z;
}

void Camera::SetTargetType(int Target_type)
{
	zTargetType = Target_type;
}

void Camera::TiltDown(float amount)
{
	zTilt(-amount);
}

void Camera::TiltUp(float amount)
{
	zTilt(amount);
}

void Camera::TurnLeft(float amount)
{
	zTurn(amount);
}
void Camera::TurnRight(float amount)
{
	zTurn(-amount);
}


void Camera::zMoveFB(float amount)
{
	if (zMoveType == GE_MOVE_FREE)
	{
		zPosition.y += (amount * cos(GE_PI_2 - zAV));
		zPosition.x += (amount * (sin(GE_PI_2 - zAV) * sin(zAH)));
		zPosition.z -= (amount * (sin(GE_PI_2 - zAV) * cos(zAH)));
	}
	else
	{
		zPosition.x += (amount * sin(zAH));
		zPosition.z -= (amount * cos(zAH));
	}
}

void Camera::zMoveLR(float amount)
{
	zPosition.x += (amount * cos(zAH));
	zPosition.z += (amount * sin(zAH));
}

void Camera::zMoveUD(float amount)
{
	if (zMoveType == GE_MOVE_FREE)
	{
		zPosition.x += (amount * zUp.x);
		zPosition.y += (amount * zUp.y);
		zPosition.z += (amount * zUp.z);
	}
	else
	{
		zPosition.y += amount;
	}
}

void Camera::zTilt(float amount)
{
	zAV += amount;
	if (zAV > GE_2PI)
		zAV -= GE_2PI;
	else if (zAV < -GE_2PI)
		zAV += GE_2PI;
	zResetRelativeVectors();
}
void Camera::zTurn(float amount)
{
	zAH -= ((zUp.y / fabs(zUp.y)) * amount);
	if (zAH > GE_2PI)
		zAH -= GE_2PI;
	else if (zAH < -GE_2PI)
		zAH += GE_2PI;
	zResetRelativeVectors();
}

void Camera::zResetRelativeVectors()
{
	if (zTargetType == GE_TARGET_RELATIVE)
	{
		zTarget.x = zPosition.x + sin(GE_PI_2 - zAV) * sin(zAH);
		zTarget.y = zPosition.y + cos(GE_PI_2 - zAV);
		zTarget.z = zPosition.z - sin(GE_PI_2 - zAV) * cos(zAH);


		zUp.y = cos(zAV);
		zUp.x = sin(zAV) * cos(GE_PI_2 + zAH);
		zUp.z = sin(zAV) * sin(GE_PI_2 + zAH);
	}
}