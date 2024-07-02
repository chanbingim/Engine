#pragma once

#include <functional>
#include <memory.h>

#include<Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#define D3DFMT_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

#include "InputManager.h"
#include "CDircectX9APP.h"
#include "CGameRender.h"

#include "2D/TransformComponent.h"
#include "2D/GameObject.h"
#include "2D/Triangle.h"

using namespace GameEngine;
using namespace GameEngine2D;