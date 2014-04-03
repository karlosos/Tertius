#include "CCar.h"
#include "../../Rendering/Drawable/Layers.h"

using namespace rendering::drawable;

namespace logic
{
	//Chroniony konstruktor domy�lny
	CCar::CCar(const std::wstring& uniqueId)
	:
CActor		(uniqueId),//konstruktor klasy bazowej
		m_rotation_speed_body	(0.0f),
		m_rotation_speed_head	(0.0f)
	{
	}

	//Destruktor wirtualny
	CCar::~CCar(void)
	{
		m_rotation_speed_body	= 0.0f;
		m_rotation_speed_head	= 0.0f;
	}


	//Wirtualna metoda aktualizuj�ca obiekt
	void CCar::Update(float dt)
	{
	}

	//Metoda zwraca pr�dko�� rotacji body
	const float CCar::getRotationSpeedBody() const
	{
		return m_rotation_speed_body;
	}

	//Metoda ustawia pr�dko�� rotacji body
	void CCar::setRotationSpeedBody(float rotation_speed_body)
	{
		m_rotation_speed_body = rotation_speed_body;
	}

	//Metoda zwraca pr�dko�� rotacji head
	const float CCar::getRotationSpeedHead() const
	{
		return m_rotation_speed_head;
	}

	//Metoda ustawia pr�dko�� rotacji head
	void CCar::setRotationSpeedHead(float rotation_speed_head)
	{
		m_rotation_speed_head = rotation_speed_head;
	}
 

}//namespace logic

 
