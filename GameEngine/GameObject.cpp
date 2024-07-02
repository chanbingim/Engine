#include "PreCompiled.h"

//Actor Actor::Invalid(Math::InvalidHashName);

void Actor::SetWorldPosition()
{
	D3DXMATRIX matScale, matRotation, matTransform;

	D3DXMatrixIdentity(&matRotation);
	D3DXMatrixScaling(&matScale, _Transform.GetScale().X, _Transform.GetScale().Y, _Transform.GetScale().Z);
	D3DXMatrixTranslation(&matTransform, _Transform.GetPosition().X, _Transform.GetPosition().Y, _Transform.GetPosition().Z);

	MatWorld = matScale * matRotation * matTransform;
}