#pragma once

#include <functional>
#include <memory>

#include<Windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#define D3DFMT_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#include "2D/TimeUtil.h"
#include "Texture.h"
#include "2D/TransformComponent.h"

#include "2D/GameObject.h"
#include "CameraObject.h"
#include "2D/Triangle.h"

using namespace GameEngine2D;