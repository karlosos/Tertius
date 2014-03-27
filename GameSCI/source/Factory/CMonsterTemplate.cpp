/*
 _____________________________________________
| CMonsterTemplate.cpp - implementacja klasy. |
| SCI - January 2014.                         |
|_____________________________________________|

*/

#include "CMonsterTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/CPhysicalManager.h"

namespace factory
{
	//Konstruktor
	CMonsterTemplate::CMonsterTemplate()
	:
		CActorTemplate()//konstruktor klasy bazowej
	{
	} 

	//Destruktor wirtualny
	CMonsterTemplate::~CMonsterTemplate()
	{
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
	void CMonsterTemplate::Drop()
	{
		delete this;
	}

	//Metoda �aduj�ca dane
	bool CMonsterTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda �aduj�ca dane z xml �aduje cechy CMonster
	bool CMonsterTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacj�, �e jest potw�r
		if (xml.GetString(xml.GetRootNode(), "type") != "monster")
			return false;

		//sprawdzamy, czy mo�na za�adowa� dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
			return false;

		//gdyby w klasie CMonster by�y jakie� pola
		//to tutaj, w klasie jej fabryki
		//nale�a�oby wczyta� te pola z pliku xml,
		//aby fabryka by�a kompletna

		return true;
	}

	//Metoda tworzy obiek klasy CMonster
	CMonster* CMonsterTemplate::Create(std::wstring id)
	{
		CMonster* monster = gPhysicalManager.CreateMonster(id);
		Fill(monster);

		//gdyby w klasie CMonster by�y jakie� pola
		//to tutaj, nele�a�oby te pola przekaza� z fabryki do potwora,
		//aby fabryka by�a kompletna

		return monster;
	}
}//namespace factory
 
