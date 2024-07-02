#include "Precompiled.h"

Rectangle::Rectangle(const std::vector<Vector2> InVertices)
{
	for (const auto& v : InVertices)
	{
		*this += v;
	}
}