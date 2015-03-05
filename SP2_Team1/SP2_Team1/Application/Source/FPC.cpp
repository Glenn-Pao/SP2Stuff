#include "FPC.h"
#include "Application.h"
#include "Mtx44.h"
#include "functions.h"
/******************************************************************************/
/*!
\file	FPC.cpp
\author Rayner Tay
\par	
\brief
		First Person Camera with mouse control
*/
/******************************************************************************/
FPC::FPC()
{
}

FPC::~FPC()
{

}

/******************************************************************************/
/*!
\brief
Initialize default camera position, target, and tilt
\param pos - camera position
\param target - camera target
\param up - camera up direction
\param _allowFlight - controls whether players can take to the skies when moving forward and looking up
*/
/******************************************************************************/
void FPC::Init(const Vector3& pos, const Vector3& target, const Vector3& up, bool _allowFlight/* = false*/)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();

	pitchDist = 0.0f;
	SetSensitivity(1, 1);
	SetSpeed(100, 80);
	allowFlight = _allowFlight;

	collideW = collideS = collideD = collideA = false;
	move = true;
}

/******************************************************************************/
/*!
\brief
Sets camera position, target and up vectors
\param pos - camera position
\param target - camera target
\param up - camera up direction
\param _allowFlight - controls whether players can take to the skies when moving forward and looking up
*/
/******************************************************************************/
void FPC::Set(const Vector3& pos, const Vector3& target, const Vector3& up, bool _allowFlight/* = false*/)
{
	this->position = pos;
	this->target = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = right.Cross(view).Normalized();
	allowFlight = _allowFlight;
}

/******************************************************************************/
/*!
\brief
Sets the mouse sensitivity of the camera
\param _mouseSensX - horizontal mouse sensitivity
\param _mouseSensY - vertical mouse sensitivity
*/
/******************************************************************************/
void FPC::SetSensitivity(float _mouseSensX, float _mouseSensY)
{
	if (_mouseSensX == 0 || mouseSensY == 0)
	{
		return;
	}

	mouseSensX = _mouseSensX;
	mouseSensY = _mouseSensY;
}
/******************************************************************************/
/*!
\brief
Sets the camera default moving speed
\param _moveSpeed - default movement speed for the camera
\param _rotSpeed - default rotation speed for the camera (when using arrow keys)
*/
/******************************************************************************/
void FPC::SetSpeed(float _moveSpeed, float _rotSpeed)
{
	defaultMoveSpeed = _moveSpeed;
	defaultRotSpeed = _rotSpeed;
}
/******************************************************************************/
/*!
\brief
Sets whether the player can fly
\param _allowFlight - controls whether players can take to the skies when moving forward and looking up
*/
/******************************************************************************/
void FPC::SetFlight(bool _allowFlight/* = true*/)
{
	allowFlight = _allowFlight;
}
/******************************************************************************/
/*!
\brief
Camera controls
*/
/******************************************************************************/
void FPC::Update(double dt, vector<CObjects> list)
{
	const float MAX_PITCH = 80.0f;
	const double SPRINT_MODIFIER = 3.0;
	const double WALK_MODIFIER = 0.25;

	/*
	 * Sprinting & Walking
	 */
	float moveSpeed;
	float rotSpeed;


	if(Application::IsKeyPressed(VK_CONTROL))
	{
		moveSpeed = defaultMoveSpeed * WALK_MODIFIER;
		rotSpeed = defaultRotSpeed * WALK_MODIFIER;
	}
	else
	{
		moveSpeed = defaultMoveSpeed;
		rotSpeed = defaultRotSpeed;
	}

	/*
	 * Movement
	 */
	Vector3 oldPos = position;
	Vector3 oldTar = target;

	if (move == true)
	{

		if(Application::IsKeyPressed('A'))
		{
			if (Application::IsKeyPressed('D') == 0)
			{
				collideA = Collision(position,list);
				Vector3 view = (target - position).Normalized();
				Vector3 right = view.Cross(up);
				right.y = 0;
				right.Normalize();

				position -= right * moveSpeed * dt;
				target -= right * moveSpeed * dt;
				
				if (position.x > 1100 || position.x <-1100 || position.z > 695 || position.z < -935|| (collideA == true && collideD == false))
				{
					position += right * moveSpeed * dt;
					target += right * moveSpeed * dt;
				}

				if (position.z >= -37 && position.z <= 47 && position.x >= 395 && position.x <= 495) {
					if (position.z < -30 || position.z > 40) {
						position += right * moveSpeed * dt;
						target += right * moveSpeed * dt;
					}
				}
			}
		}
		if(Application::IsKeyPressed('D'))
		{
			if (Application::IsKeyPressed('A') == 0)
			{
				collideD = Collision(position,list);
				Vector3 view = (target - position).Normalized();
				Vector3 right = view.Cross(up);
				right.y = 0;
				right.Normalize();

				position += right * moveSpeed * dt;
				target += right * moveSpeed * dt;

				if (position.x > 1100 || position.x <-1100 || position.z > 695 || position.z < -935 || (collideD == true && collideA == false))
				{
					position -= right * moveSpeed * dt;
					target -= right * moveSpeed * dt;
				}

				if (position.z >= -37 && position.z <= 47 && position.x >= 395 && position.x <= 495) {
					if (position.z < -30 || position.z > 40) {
						position -= right * moveSpeed * dt;
						target -= right * moveSpeed * dt;
					}
				}
			}
		}

		if(Application::IsKeyPressed('W'))
		{
			if (Application::IsKeyPressed('S') == 0)
			{
				collideW = Collision(position,list);
				Vector3 view = (target - position).Normalized();
				position += view * moveSpeed * dt;
				target += view * moveSpeed * dt;

				if (position.x > 1100 || position.x <-1100 || position.z > 695 || position.z < -935 || (collideW == true && collideS == false))
				{
					position -= view * moveSpeed * dt;
					target -= view * moveSpeed * dt;
				}

				if (position.z >= -37 && position.z <= 47 && position.x >= 395 && position.x <= 495) {
					if (position.z < -30 || position.z > 40) {

						position -= view * moveSpeed * dt;
						target -= view * moveSpeed * dt;
					}
				}
			}
		}

		if(Application::IsKeyPressed('S'))
		{
			if (Application::IsKeyPressed('W') == 0)
			{
				collideS = Collision(position,list);
				Vector3 view = (target - position).Normalized();
				position -= view * moveSpeed * dt;
				target -= view * moveSpeed * dt;

				if (position.x > 1100 || position.x <-1100 || position.z > 695 || position.z < -935 || (collideS == true && collideW == false))
				{
					position += view * moveSpeed * dt;
					target += view * moveSpeed * dt;
				}

				if (position.z >= -37 && position.z <= 47 && position.x >= 395 && position.x <= 495) {
					if (position.z < -30 || position.z > 40) {
						position += view * moveSpeed * dt;
						target += view * moveSpeed * dt;
					}
				}
			}
		}
	}

	if (!allowFlight)
	{
		target.y = oldTar.y;
		position.y = oldPos.y;
	}
	/*
	 * Look - Mouse Control
	 */
	double midScreenX = (Application::returnWindowSize(true)/2);
	double midScreenY = (Application::returnWindowSize(false)/2);

	double mouseX = ((midScreenX - Application::GetMouseinput(true)) /32) * mouseSensY;
	double mouseY = ((midScreenY - Application::GetMouseinput(false)) /32) * mouseSensX;

	if(mouseX != 0)
	{
		Mtx44 rotation;
		target -= position;
		rotation.SetToRotation(mouseX, 0, 1, 0);
		target = rotation * target;
		up = rotation * up;
		target += position;
	}

	if(mouseY != 0)
	{
		if ((mouseY > 0 && pitchDist < MAX_PITCH) || 
			(mouseY < 0 && pitchDist > -MAX_PITCH))
		{
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			target -= position;
			rotation.SetToRotation(mouseY, right.x, right.y, right.z);
			target = rotation * target;
			target += position;

			pitchDist += mouseY;
		}
	}

	// Reset cursor to the center
	Application::SetMouseinput(midScreenX, midScreenY);
	

	if (Application::IsKeyPressed('R'))
	{
		Reset();
	}
}


/******************************************************************************/
/*!
\brief
Resets camera to default camera position
*/
/******************************************************************************/
void FPC::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
	pitchDist = 0.0f;
}