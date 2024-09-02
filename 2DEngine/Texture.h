#pragma once

using namespace std;

namespace GameEngine2D
{
class Texture2D
{
private:
	LPDIRECT3DDEVICE9   t_d3dDevice;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	LPDIRECT3DTEXTURE9 g_pTexture;
	string TextureUrl;

public :
	Texture2D() = default;
	void Initialize(LPDIRECT3DDEVICE9 _d3dDevice, string _url);
	HRESULT InitGeometry();

	LPCWSTR convertWSTR(string _word);
	string GetTextureUrl() { return TextureUrl; }
	constexpr LPDIRECT3DTEXTURE9 GetTexture() { return g_pTexture; }
};
}