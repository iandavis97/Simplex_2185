#include "MyEntityManager.h"
using namespace Simplex;
//  MyEntityManager
MyEntityManager* MyEntityManager::m_pInstance = nullptr;
void MyEntityManager::Init(void)
{
	m_pInstance = nullptr;
	m_uEntityCount = 0;
}
void MyEntityManager::Release(void)
{
	ReleaseInstance();
	m_uEntityCount = 0;
}
MyEntityManager* MyEntityManager::GetInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new MyEntityManager();
	}
	return m_pInstance;
}
void MyEntityManager::ReleaseInstance()
{
	SafeDelete(m_pInstance);
}
int Simplex::MyEntityManager::GetEntityIndex(String a_sUniqueID)
{
	int index = -1;
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID)
			index = i;
	}
	return index;
}
//Accessors
Model* Simplex::MyEntityManager::GetModel(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetModel();
}
Model* Simplex::MyEntityManager::GetModel(String a_sUniqueID)
{
	Model* temp = nullptr;
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID) 
		{
			temp = GetModel(i);
			break;
		}
	}
	return temp;
}
RigidBody* Simplex::MyEntityManager::GetRigidBody(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetRigidBody();
}
RigidBody* Simplex::MyEntityManager::GetRigidBody(String a_sUniqueID)
{
	RigidBody* temp = nullptr;
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID)
		{
			temp = GetRigidBody(i);
			break;
		}
	}
	return temp;
}
matrix4 Simplex::MyEntityManager::GetModelMatrix(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetModelMatrix();
}
matrix4 Simplex::MyEntityManager::GetModelMatrix(String a_sUniqueID)
{
	matrix4 temp=IDENTITY_M4;
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID)
		{
			temp = GetModelMatrix(i);
			break;
		}
	}
	return temp;
}
void Simplex::MyEntityManager::SetModelMatrix(matrix4 a_m4ToWorld, String a_sUniqueID)
{
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID)
		{
			m_entityList[i]->SetModelMatrix(a_m4ToWorld);
			break;
		}
	}
}
void Simplex::MyEntityManager::SetModelMatrix(matrix4 a_m4ToWorld, uint a_uIndex)
{
	m_entityList[a_uIndex]->SetModelMatrix(a_m4ToWorld);
}
//The big 3
MyEntityManager::MyEntityManager(){Init();}
MyEntityManager::MyEntityManager(MyEntityManager const& other) { m_entityList = other.m_entityList; }
MyEntityManager& MyEntityManager::operator=(MyEntityManager const& other) { return *this; }
MyEntityManager::~MyEntityManager(){Release();};
// other methods
void Simplex::MyEntityManager::Update(void)
{

}
void Simplex::MyEntityManager::AddEntity(String a_sFileName, String a_sUniqueID)
{
	MyEntity temp(a_sFileName, a_sUniqueID);
	m_entityList.push_back(&temp);
}
void Simplex::MyEntityManager::RemoveEntity(uint a_uIndex)
{
	m_entityList.erase(m_entityList.begin()+a_uIndex);
}
void Simplex::MyEntityManager::RemoveEntity(String a_sUniqueID)
{
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID() == a_sUniqueID) 
		{
			RemoveEntity(i);
			break;
		}
	}
}
String Simplex::MyEntityManager::GetUniqueID(uint a_uIndex)
{
	return m_entityList[a_uIndex]->GetUniqueID();
}
MyEntity* Simplex::MyEntityManager::GetEntity(uint a_uIndex)
{
	return m_entityList[a_uIndex];
}
void Simplex::MyEntityManager::AddEntityToRenderList(uint a_uIndex, bool a_bRigidBody)
{
	m_entityList[a_uIndex]->AddToRenderList(a_bRigidBody);
}
void Simplex::MyEntityManager::AddEntityToRenderList(String a_sUniqueID, bool a_bRigidBody)
{
	for (int i = 0; i < m_entityList.size(); i++)
	{
		if (m_entityList[i]->GetUniqueID == a_sUniqueID) 
		{
			AddEntityToRenderList(i, a_bRigidBody);
			break;
		}
	}
}