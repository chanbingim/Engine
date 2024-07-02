#pragma once

namespace GameEngine2D
{
class Actor
{
public:
	Actor() {}

	Actor(const std::string& InName)
	{
		//_Hash = std::hash<std::string>()(_Name);
	}

	~Actor() {};
public :
	// 종류
	

	// 메시

	// 키 관련
	//const std::string& GetName() const { return _Name; }
	//std::size_t GetHash() const { return _Hash; }

	// 머테리얼
	

	// 검색 관련
	//bool IsValid() const { return _Hash != Math::InvalidHash; }
	//FORCEINLINE bool operator==(const Actor& InGameObject) const;
	//FORCEINLINE bool operator!=(const Actor& InGameObject) const;
	static Actor Invalid;

	// 월드 위치 설정
	void SetWorldPosition();
	D3DXMATRIX GetWorldPostion() const { return MatWorld; }

	TransformComponent& GetTransform() { return _Transform; }
	// 렌더링 설정
	bool IsVisible() const { return _IsVisible; }
	void SetVisible(bool InVisible) { _IsVisible = InVisible; }

private:
	D3DXMATRIX MatWorld;

	bool _IsVisible = true;
	//std::size_t _Hash = Math::InvalidHash;
	std::string _Name;
	//std::size_t _MeshKey = Math::InvalidHash;
	TransformComponent _Transform;
};

/*FORCEINLINE bool Actor::operator==(const Actor& InGameObject) const
{
	return _Hash == InGameObject.GetHash();
}

FORCEINLINE bool Actor::operator!=(const Actor& InGameObject) const
{
	//return _Hash == InGameObject.GetHash();
}*/
}