#include "../PreCompiled.h"

void GameEngine2D::Triangle2D::Initialize(LPDIRECT3DDEVICE9 _d3dDevice)
{
    t_d3dDevice = _d3dDevice;

    GetTransform().SetPosition(Vector3(0, 0, 0.0));
    GetTransform().SetRotation(Vector3(0.0f, 0.0f, 0.0f));
    GetTransform().SetScale(Vector3(1.0f, 1.0f, 1.0f));
    SetWorldPosition();
    
   
}

void GameEngine2D::Triangle2D::CreatActor()
{
    Vertex2D vertices[] = {
          {Vector3(0.0f,  2.0f, 0.0f), 0xfff00fff, Vector3(0.5f,0.0f,0)},
          {Vector3(-1.0f, 0.0f, 0.0f), 0xff00ffff, Vector3(0.0f,1.0f,0)},
          {Vector3(1.0f, 0.0f, 0.0f), 0xffff00ff, Vector3(1.0f,1.0f,0)},
    };

    if (FAILED(t_d3dDevice->CreateVertexBuffer(3 * sizeof(Vertex2D), 0, D3DFMT_CUSTOMVERTEX, D3DPOOL_DEFAULT,
        &m_pVB, NULL)))
    {
        return;
    }

    if (TriangleTexture != nullptr)
    {
        if (TriangleTexture->GetTextureUrl() != "")
        {
            for (Vertex2D& vertex : vertices)
            {
                vertex.Color = 0xffffffff;
            }

            t_d3dDevice->SetTexture(0, TriangleTexture->GetTexture());
            t_d3dDevice->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
        }
    }

    VOID* pVertices = nullptr;
    if (FAILED(m_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
        return;

    memcpy(pVertices, vertices, sizeof(vertices));
    m_pVB->Unlock();

    auto MatWorld = GetWorldPostion();
    t_d3dDevice->SetTransform(D3DTS_WORLD, &MatWorld);
    t_d3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(Vertex2D));
    t_d3dDevice->SetFVF(D3DFMT_CUSTOMVERTEX);
    t_d3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 1);
}


void GameEngine2D::Triangle2D::SetTexture(string url)
{
    TriangleTexture = new Texture2D();
    TriangleTexture->Initialize(t_d3dDevice, url);
}