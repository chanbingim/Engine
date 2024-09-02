#include "PreCompiled.h"
#include <iostream>

void GameEngine2D::Texture2D::Initialize(LPDIRECT3DDEVICE9 _d3dDevice, string _url)
{
    t_d3dDevice = _d3dDevice;
    TextureUrl = _url;
    if (InitGeometry() == E_FAIL)
        TextureUrl = "";
}

HRESULT GameEngine2D::Texture2D::InitGeometry()
{
    LPCWSTR url = convertWSTR(TextureUrl);
    if (FAILED(D3DXCreateTextureFromFile(t_d3dDevice, url, &g_pTexture)))
    {
        url = convertWSTR(string("..\\").append(TextureUrl));
        if (FAILED(D3DXCreateTextureFromFile(t_d3dDevice, url, &g_pTexture)))
        {
            return E_FAIL;
        }
    }

    return S_OK;
}

LPCWSTR GameEngine2D::Texture2D::convertWSTR(string _word)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, _word.c_str(), (int)_word.size(), NULL, 0);
    wchar_t* wideString = new wchar_t[size_needed + 1];
    MultiByteToWideChar(CP_UTF8, 0, _word.c_str(), (int)_word.size(), wideString, size_needed);
    wideString[size_needed] = L'\0';
    return wideString;
}
