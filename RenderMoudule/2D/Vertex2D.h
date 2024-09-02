#pragma once

namespace EngineRender
{
class Vertex2D
{
public :
	Vector3 Position;
	DWORD Color = 0;
	Vector3 UV;

	constexpr Vertex2D() = default;
	constexpr Vertex2D(const Vector3& InPosition) : Position(InPosition) { }
	constexpr Vertex2D(const Vector3& InPosition,const DWORD& InColor) : Position(InPosition), Color(InColor) { }
	constexpr Vertex2D(const Vector3& InPosition, const DWORD& InColor, const Vector3& InUV) : Position(InPosition), Color(InColor), UV(InUV) { }

	constexpr Vertex2D operator*(float InScalar) const
	{
		return Vertex2D(
			Position * InScalar,
			Color * InScalar,
			UV * InScalar
		);
	}

	constexpr Vertex2D operator+(const Vertex2D& InVector) const
	{
		return Vertex2D(
			Position + InVector.Position,
			Color + InVector.Color,
			UV + InVector.UV
		);
	}
};
}