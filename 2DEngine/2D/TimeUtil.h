#pragma once

namespace GameEngine2D
{
class Time
{
public :
	static void Initailize();
	static void Update();
	static void Render(HDC hdc);
	static constexpr float GetDeltaTime() { return DeltaTime; }

private :
	static LARGE_INTEGER CpuFrequency;
	static LARGE_INTEGER CurrentCpuFrequency;
	static LARGE_INTEGER LastCpuFrequency;
	static float DeltaTime;
};
}