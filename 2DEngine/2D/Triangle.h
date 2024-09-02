#pragma once

namespace GameEngine2D
{
class Triangle2D : public Actor
{
private:
	LPDIRECT3DDEVICE9   t_d3dDevice = nullptr;
	LPDIRECT3DVERTEXBUFFER9 m_pVB = nullptr;
	Texture2D*  TriangleTexture = nullptr; 
	LPD3DXMESH renderMesh;

public :
	Triangle2D() = default;

	void Initialize(LPDIRECT3DDEVICE9 _d3dDevice);
	virtual void CreatActor();
	void SetTexture(string url);
};
}