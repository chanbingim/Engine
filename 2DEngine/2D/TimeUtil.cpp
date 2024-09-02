#include "../PreCompiled.h"

LARGE_INTEGER GameEngine2D::Time::CpuFrequency = {};
LARGE_INTEGER GameEngine2D::Time::CurrentCpuFrequency = {};
LARGE_INTEGER GameEngine2D::Time::LastCpuFrequency = {};
float GameEngine2D::Time::DeltaTime = 0.0f;

void GameEngine2D::Time::Initailize()
{
	//Cpu 고유 진동수
	QueryPerformanceFrequency((LARGE_INTEGER*)&CurrentCpuFrequency);

	//프로그램이 시작 했을 때 현재 진동수
	QueryPerformanceCounter((LARGE_INTEGER*)&LastCpuFrequency);

}

void GameEngine2D::Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&CurrentCpuFrequency);

	//LowPart, HighPart로 데이터를 반으로 쪼갤수도 있음
	//QuadPart 8바이트 데이터
	//C++에서 제공하는 형변환 static_cast<T>(변수명);
	float differenceFrequency = static_cast<float>(CurrentCpuFrequency.QuadPart - LastCpuFrequency.QuadPart);
	DeltaTime = differenceFrequency / static_cast<float>(CurrentCpuFrequency.QuadPart);

	LastCpuFrequency.QuadPart = CurrentCpuFrequency.QuadPart;
}

void GameEngine2D::Time::Render(HDC hdc)
{
	static float time = 0.0f;

	time += DeltaTime;

	wchar_t str[50] = L"";
	swprintf_s(str, 50, L"Time : %f", time);
	int len = wcsnlen_s(str, 50);

	TextOut(hdc, 0, 0, str, len);
}
