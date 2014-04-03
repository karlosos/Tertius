
/*
 ___________________________________________
| CCarTemplate.cpp - implementacja klasy. |
| SCI - March 2014.                         |
|___________________________________________|

*/

#include "CCarTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/CPhysicalManager.h"

namespace factory
{
	//Konstruktor
	CCarTemplate::CCarTemplate()
	:
		CActorTemplate				(),//konstruktor klasy bazowej
		m_rotation_speed_body_template 	(0.0f),
		m_rotation_speed_head_template 	(0.0f)
	{
	} 

	//Destruktor wirtualny
	CCarTemplate::~CCarTemplate()
	{
		m_rotation_speed_body_template = 0.0f;
		m_rotation_speed_head_template = 0.0f;
	}


	//Wirtualna metoda zwalniaj¹ca zasób
	void CCarTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CCarTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml ³aduje cechy CMonster
	bool CCarTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest to jakaœ //roœlinnoœæ
		if (xml.GetString(xml.GetRootNode(), "type") != "car")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//gdy w klasie CCar byd¹ dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale¿ay utworzyæ takie same pola oraz je uwzglêdniæ
		//³adujemy dane o prêdkoœci obrotu
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "rotation_speed"))
		{
		m_rotation_speed_body_template = xml.GetFloat(node, "rotation_speed_body");
		m_rotation_speed_head_template = xml.GetFloat(node, "rotation_speed_head");
		}

		return true;
	}

	//Metoda tworzy obiek klasy CCar
	CCar* CCarTemplate::Create(std::wstring id)
	{
		CCar* Car = gPhysicalManager.CreateCar(id);
		Fill(Car);

		//gdy w klasie CCar byd¹ dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale¿ay utworzyæ takie same pola oraz je uwzglêdniæ

		return Car;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CCar
	void CCarTemplate::Fill(CCar *Car)
	{
		CActorTemplate::Fill(Car);
		//ewentualnie reszta
		if(Car)
		{
			Car->setRotationSpeedBody(m_rotation_speed_body_template);
			Car->setRotationSpeedHead(m_rotation_speed_head_template);
		}
	}
}//namespace factory
