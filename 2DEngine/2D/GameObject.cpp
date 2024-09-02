#include "../PreCompiled.h"

//Actor Actor::Invalid(Math::InvalidHashName);

void GameEngine2D::Actor::SetWorldPosition()
{
	D3DXMATRIX matScale, matRotation, matTransform;
	D3DXMatrixIdentity(&MatWorld);

	D3DXMatrixScaling(&matScale, _Transform.GetScale().X, _Transform.GetScale().Y, _Transform.GetScale().Z);
	D3DXMatrixRotationYawPitchRoll(&matRotation, _Transform.GetRotation().X, _Transform.GetRotation().Y, _Transform.GetRotation().Z);
	D3DXMatrixTranslation(&matTransform, _Transform.GetPosition().X, _Transform.GetPosition().Y, _Transform.GetPosition().Z);

	MatWorld = matScale *matRotation* matTransform;
}

void GameEngine2D::Actor::CreatActor()
{

}

void GameEngine2D::Actor::SetActorLocation(const Vector3& Pos)
{
	_Transform.SetPosition(Pos);
	SetWorldPosition();
}