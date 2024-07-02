#pragma once
namespace GameEngine
{
	class CDirectX9APP
	{
	protected:
		LPDIRECT3D9         g_pD3D;
		LPDIRECT3DDEVICE9   g_pd3dDevice;
		HWND m_hWnd;
		RECT rect;
		int m_WIDTH;
		int m_HEIGHT;

	public:
		HRESULT InitD3D(HWND hWnd, int _width, int _height);
		void Run();
		void Render();
		void Update();
		void LateUpdate();
		void Cleanup();

	protected:
		virtual void OnInit() = 0;
		virtual void OnRender() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnLateUpdate() = 0;
		virtual void OnRelease() = 0;

	};
}