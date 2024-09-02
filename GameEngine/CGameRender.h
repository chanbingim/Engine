#pragma once

namespace GameEngine
{
	class CGame : public CDirectX9APP
	{
	private :
		D3DXMATRIX m_matView;
		D3DXMATRIX m_matproj;
		D3DXVECTOR3 m_Eye, m_At, m_Up;
		LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
		std::vector<std::unique_ptr<Actor>> _Scene;
		InputManager CameraInput;

	public :
		CGame() {};
		~CGame() {};

		virtual void OnInit();
		virtual void OnRender();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRelease();

		std::function<void(InputManager&)> _InputBindingFunc;
	};
}