#include "PreCompiled.h"

void GameEngine::CGame::OnInit()
{
    D3DVIEWPORT9 vp;
    GetClientRect(m_hWnd, &rect);

    float m_scale = 1.0f;
    vp.X = 0;
    vp.Y = 0;
    vp.Width = rect.right - rect.left;
    vp.Height = rect.bottom - rect.top;
    vp.MinZ = 0.0f;
    vp.MaxZ = 1.0f;

    m_Eye.x = 10.0f;
    m_Eye.y = 10.0f;
    m_Eye.z = -10.0f;

    m_At.x = 0.0f;
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

    // Turn off culling
    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    // Turn off D3D lighting
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

}


void GameEngine::CGame::OnRender()
{
    Triangle TriangleMesh;
    TriangleMesh.CreateTranlge(g_pd3dDevice);
}

void GameEngine::CGame::OnUpdate()
{

}

void GameEngine::CGame::OnLateUpdate()
{

}

void GameEngine::CGame::OnRelease()
{

}