#include "PreCompiled.h"

HRESULT GameEngine::CDirectX9APP::InitD3D(HWND hWnd, int _width, int _height)
{
    m_hWnd = hWnd;
    m_WIDTH = _width;
    m_HEIGHT = _height;

    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;

    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    OnInit();

    return S_OK;
}

void GameEngine::CDirectX9APP::Run()
{
    Update();
    LateUpdate();

    //DrawActor
    Render();
}

VOID GameEngine::CDirectX9APP::Render()
{
    if (NULL == g_pd3dDevice)
        return;

    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        OnRender();

        // Render
        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID GameEngine::CDirectX9APP::Update()
{
    OnUpdate();
}

void GameEngine::CDirectX9APP::LateUpdate()
{
    OnLateUpdate();
}

VOID GameEngine::CDirectX9APP::Cleanup()
{
    {
        // Release
        if (g_pd3dDevice != NULL)
            g_pd3dDevice->Release();

        if (g_pD3D != NULL)
            g_pD3D->Release();
        OnRelease();
    }
}
