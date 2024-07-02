#pragma once

namespace EngineRender
{
class Vertex2D
{
public :
	Vector3 Position;
	FLOAT rhw = 0;
	DWORD Color = 0;
	Vector3 UV;

	constexpr Vertex2D() = default;
	constexpr Vertex2D(const Vector3& InPosition) : Position(InPosition) { }
	constexpr Vertex2D(const Vector3& InPosition, FLOAT Inrhw) : Position(InPosition), rhw(Inrhw) { }
	constexpr Vertex2D(const Vector3& InPosition, FLOAT Inrhw, const DWORD& InColor) : Position(InPosition), rhw(Inrhw), Color(InColor) { }
	constexpr Vertex2D(const Vector3& InPosition, FLOAT Inrhw, const DWORD& InColor, const Vector3& InUV) : Position(InPosition), rhw(Inrhw), Color(InColor), UV(InUV) { }

	constexpr Vertex2D operator*(float InScalar) const
	{
		return Vertex2D(
			Position * InScalar,
			rhw * InScalar,
			Color * InScalar,
			UV * InScalar
		);
	}

	constexpr Vertex2D operator+(const Vertex2D& InVector) const
	{
		return Vertex2D(
			Position + InVector.Position,
			rhw + InVector.rhw,
			Color + InVector.Color,
			UV + InVector.UV
		);
	}
};
}