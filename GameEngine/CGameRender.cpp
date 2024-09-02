#include "PreCompiled.h"

float GetXAxisInput()
{
    bool isLeft = GetAsyncKeyState(VK_LEFT);
    bool isRight = GetAsyncKeyState(VK_RIGHT);
    if (isLeft ^ isRight)
    {
        return isLeft ? -1.f : 1.f;
    }
    return 0.f;
}

float GetYAxisInput()
{
    bool isDown = GetAsyncKeyState(VK_DOWN);
    bool isUp = GetAsyncKeyState(VK_UP);
    if (isDown ^ isUp)
    {
        return isDown ? -1.f : 1.f;
    }
    return 0.f;
}

void GameEngine::CGame::OnInit()
{
    D3DVIEWPORT9 vp;
    GetClientRect(m_hWnd, &rect);
    auto Triangle = std::make_unique<Triangle2D>();
    Triangle->Initialize(g_pd3dDevice);
    Triangle->SetName("Triangle");
    _Scene.push_back(std::move(Triangle));

    auto Triangle2 = std::make_unique<Triangle2D>();
    Triangle2->Initialize(g_pd3dDevice);
    Triangle2->SetName("Triangle2");
    Triangle2->SetActorLocation(Vector3(2, 1, 0));
    Triangle2->SetWorldPosition();

    _Scene.push_back(std::move(Triangle2));
 

    float m_scale = 1.0f;
    vp.X = 0;
    vp.Y = 0;
    vp.Width = rect.right - rect.left;
    vp.Height = rect.bottom - rect.top;
    vp.MinZ = 0.0f;
    vp.MaxZ = 1.0f;

    m_Eye.x = 0.0f;
    m_Eye.y = 0.0f;
    m_Eye.z = -30.0f;

    m_At.x = 1.0f;
    m_At.y = 0.0f;
    m_At.z = 0.0f;

    m_Up.x = 0.0f;
    m_Up.y = 1.0f;
    m_Up.z = 0.0f;

    D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

    D3DXMatrixPerspectiveFovLH(&m_matproj, D3DX_PI / 4, 1.0f, 1.0f, 1000.0f);
    g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matproj);
    g_pd3dDevice->SetViewport(&vp);
    
    CameraInput.SetInputAxis(InputAxis::XAxis, GetXAxisInput);
    CameraInput.SetInputAxis(InputAxis::YAxis, GetYAxisInput);
    // Turn off culling
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    // Turn off D3D lighting
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}


void GameEngine::CGame::OnRender()
{
    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    for (int i = 0; i < _Scene.size(); i++)
    {
        auto object = _Scene[i].get();
        object->CreatActor();
    }

    ImGui::Begin("Hierarchy");        
    for (int i = 0; i < _Scene.size(); i++)
    {
        auto object = _Scene[i].get();
        ImGui::Button(object->GetName().c_str(), ImVec2(200, 50));
    }// Create a window called "Hello, world!" and append into it.
    ImGui::End();
   
    ImGui::EndFrame();

    

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}
void GameEngine::CGame::OnUpdate()
{
    float moveSpeed = 50.f;
    
    Vector2 inputVector = Vector2(CameraInput.GetAxis(InputAxis::XAxis), CameraInput.GetAxis(InputAxis::YAxis)).GetNormalize();
    Vector2 deltaPosition = inputVector *moveSpeed * 0.001;

    m_At.x += deltaPosition.X;
    m_At.y += deltaPosition.Y;

    D3DXMatrixLookAtLH(&m_matView, &m_Eye, &m_At, &m_Up);
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);
}

void GameEngine::CGame::OnLateUpdate()
{

}

void GameEngine::CGame::OnRelease()
{
    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}
