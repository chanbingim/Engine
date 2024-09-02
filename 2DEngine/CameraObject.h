#pragma once

namespace GameEngine2D
{
class CameraObject : public Actor
{
public :
	CameraObject() = default;
	~CameraObject() {}

public :
	//Camera Screen Point
	const ScreenPoint& GetViewportSize() const { return _ViewportSize; }

private :
	ScreenPoint _ViewportSize;
};
}