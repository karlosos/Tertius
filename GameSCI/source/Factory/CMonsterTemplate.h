/*
 _____________________________________________
| CMonsterTemplate.h - definicja klasy.       |
| SCI - January 2014.                         |
|_____________________________________________|

*/

#ifndef H_MONSTER_TEMPLATE_SCI
#define H_MONSTER_TEMPLATE_SCI

#include "CActorTemplate.h"
#include "../Logic/Monster/CMonster.h"
#include <string>
#include <vector>

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec potwora
	///
	class CMonsterTemplate : public CActorTemplate
	{

	public:

		///
		///Konstruktor
		///
		CMonsterTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CMonsterTemplate();

		///
///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach  ///pochodnych
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml �aduje cechy CEnemy
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiek klasy CMonster
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		logic::CMonster* Create(std::wstring id = L"");

	private:

		//gdyby w klasie CMonster by�y jakie� pola
		//to tutaj, w klasie jej fabryki,
		//nale�a�oby utworzy� takie same pola,
		//aby fabryka by�a kompletna i mog�a uzbroi� potwora
		//w te pola, kt�re s� w jej klasie bazowej CActor
		//i jej w�asne - tylko pola nale��ce do tej klasy (potwora)

	};
}//namespace factory
#endif //H_MONSTER_TEMPLATE_SCI
