#pragma once

#include <cassert>

#include <intrin.h>
#include "Platform.h"

#include <string>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>

//수학 기본 구조에 대한 해더
#include "MathUtil.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

//행렬 기본구조에 대한 해더
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "Matrix4x4.h"

//화면에 점과 색상에 관련된 해더
#include "ScreenPoint.h"
#include "Color32.h"
#include "LinearColor.h"
#include "HSVColor.h"

//회전 이동에 관련된 해더
#include "Rotator.h"
#include "Quaternion.h"
#include "Transform.h"

//도형에 관련된 해더
#include "Plane.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "Box.h"

using namespace EngineMath;