#pragma once

namespace GameEngine2D
{
class TransformComponent
{
public :
	TransformComponent() = default;

public :
	void SetPosition(const Vector3& InPosition) { _Position = InPosition; }
	void AddPosition(const Vector3& InDeltaPosition) { _Position += InDeltaPosition; }
	void SetScale(const Vector3& InScale) { _Scale = InScale; }
	void SetRotation(const Vector3&  InDegree) { _Rotation = InDegree; }
	void AddRotation(const Vector3& InDegree) { _Rotation += InDegree; }
	Vector3 GetPosition() const { return _Position; }
	Vector3 GetScale() const { return _Scale; }
	Vector3 GetRotation() const { return _Rotation; }

private :
	Vector3 _Position = Vector3::One;
	Vector3 _Rotation = Vector3::Zero;
	Vector3 _Scale = Vector3::One;
};
}