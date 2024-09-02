#pragma once

namespace GameEngine2D
{
class Actor
{
public:
	Actor() {}

	Actor(const std::string& InName)
	{
		_Hash = std::hash<std::string>()(_Name);
	}

	~Actor() {};
public :
	// ����
	

	// �޽�

	// Ű ����
	const std::string& GetName() const { return _Name; }
	void SetName(const string Name) { _Name = Name; }
	size_t GetHash() const { return _Hash; }

	// ���׸���
	

	// �˻� ����
	bool IsValid() const { return _Hash != Math::InvalidHash; }
	FORCEINLINE bool operator==(const Actor& InGameObject) const;
	FORCEINLINE bool operator!=(const Actor& InGameObject) const;
	static Actor Invalid;

	// ���� ��ġ ����
	void SetActorLocation(const Vector3& Pos);

	void SetWorldPosition();
	const D3DXMATRIX& GetWorldPostion() { return MatWorld; }

	TransformComponent& GetTransform() { return _Transform; }
	// ������ ����
	bool IsVisible() const { return _IsVisible; }
	void SetVisible(bool InVisible) { _IsVisible = InVisible; }
	virtual void CreatActor();

private:
	D3DXMATRIX MatWorld;

	string _Name;
	bool _IsVisible = true;
	size_t _Hash = Math::InvalidHash;
	size_t _MeshKey = Math::InvalidHash;
	TransformComponent _Transform;
};

FORCEINLINE bool Actor::operator==(const Actor& InGameObject) const
{
	return _Hash == InGameObject.GetHash();
}

FORCEINLINE bool Actor::operator!=(const Actor& InGameObject) const
{
	return _Hash == InGameObject.GetHash();
}
}