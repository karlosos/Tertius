
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


	//Wirtualna metoda zwalniaj�ca zas�b
	void CCarTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CCarTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml �aduje cechy CMonster
	bool CCarTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacj�, �e jest to jaka� //ro�linno��
		if (xml.GetString(xml.GetRootNode(), "type") != "car")
			return false;

		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//gdy w klasie CCar byd� dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale�ay utworzy� takie same pola oraz je uwzgl�dni�
		//�adujemy dane o pr�dko�ci obrotu
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

		//gdy w klasie CCar byd� dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale�ay utworzy� takie same pola oraz je uwzgl�dni�

		return Car;
	}

	//Wirtualna metoda wype�niaj�ca danymi obiekt klasy CCar
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
