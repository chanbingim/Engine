#include "PreCompiled.h"

HRESULT GameEngine::CDirectX9APP::InitD3D(HWND hWnd, HINSTANCE _Instance,int _width, int _height)
{
    hdc = GetDC(hWnd);
    m_hWnd = hWnd;
    m_Instance = _Instance;
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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& GUIInfo = ImGui::GetIO(); (void)GUIInfo;
    GUIInfo.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    GUIInfo.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    GUIInfo.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    GUIInfo.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    g_GUIInfo = GUIInfo;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (GUIInfo.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(hWnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    Time::Initailize();
    OnInit();
    
    // Turn off culling, so we see the front and back of the triangle
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

    // Turn off D3D lighting, since we are providing our own vertex colors
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    

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

    // 디바이스 상태 체크
    HRESULT hr = g_pd3dDevice->TestCooperativeLevel();
    if (hr == D3DERR_DEVICELOST)
    {
        // 디바이스가 손실된 상태
        return;
    }

   


    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        Time::Render(hdc);

        OnRender();
        
      
        // Render
        g_pd3dDevice->EndScene();
    }
   
    if (g_GUIInfo.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID GameEngine::CDirectX9APP::Update()
{
    Time::Update();
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

        ImGui_ImplDX9_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        OnRelease();
    }
}
