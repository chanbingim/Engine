#include "../PreCompiled.h"

LARGE_INTEGER GameEngine2D::Time::CpuFrequency = {};
LARGE_INTEGER GameEngine2D::Time::CurrentCpuFrequency = {};
LARGE_INTEGER GameEngine2D::Time::LastCpuFrequency = {};
float GameEngine2D::Time::DeltaTime = 0.0f;

void GameEngine2D::Time::Initailize()
{
	//Cpu ���� ������
	QueryPerformanceFrequency((LARGE_INTEGER*)&CurrentCpuFrequency);

	//���α׷��� ���� ���� �� ���� ������
	QueryPerformanceCounter((LARGE_INTEGER*)&LastCpuFrequency);

}

void GameEngine2D::Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&CurrentCpuFrequency);

	//LowPart, HighPart�� �����͸� ������ �ɰ����� ����
	//QuadPart 8����Ʈ ������
	//C++���� �����ϴ� ����ȯ static_cast<T>(������);
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
