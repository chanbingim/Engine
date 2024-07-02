#include "PreCompiled.h"

void GameEngine2D::Triangle::CreateTranlge(LPDIRECT3DDEVICE9 _inputDevice)
{
    t_d3dDevice = _inputDevice;
    GetTransform().SetPosition(Vector3(500.f, 200.f, 0));
    GetTransform().SetScale(Vector3(0.5f, 1.0f, 1.0f));

    auto Scale = GetTransform().GetScale() * 100.f;
    Vertex2D vertices[] = {
       { GetTransform().GetPosition() + Vector3(0.0f, -Scale.Y,0.0f),1.0f, 0xff00ffff},
       { GetTransform().GetPosition() + Vector3(-Scale.X, Scale.Y,0.0f),1.0f, 0xff00ffff},
       { GetTransform().GetPosition() + Vector3(Scale.X, Scale.Y,0.0f), 1.0f, 0xffff0000},
    };

    if (FAILED(t_d3dDevice->CreateVertexBuffer(3 * sizeof(Vertex2D), 0, D3DFMT_CUSTOMVERTEX, D3DPOOL_DEFAULT,
        &m_pVB, NULL)))
    {
        return;
    }

    VOID* pVertices = nullptr;
    if (FAILED(m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
        return;

    memcpy(pVertices, vertices, sizeof(vertices));
    m_pVB->Unlock();

    t_d3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(Vertex2D));
    t_d3dDevice->SetFVF(D3DFMT_CUSTOMVERTEX);
    t_d3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 1);
}