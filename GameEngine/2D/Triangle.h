#pragma once

namespace GameEngine2D
{
class Triangle : public Actor
{
private:
	LPDIRECT3DDEVICE9   t_d3dDevice;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;

public :
	Triangle() = default;

	void CreateTranlge(LPDIRECT3DDEVICE9 _inputDevice);
};
}