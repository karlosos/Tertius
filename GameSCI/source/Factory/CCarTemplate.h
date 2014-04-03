/*
 ___________________________________________
| CCarTemplate.h - definicja klasy.       |
| SCI - March 2014.                         |
|___________________________________________|

*/

#ifndef H_Car_TEMPLATE_SCI
#define H_Car_TEMPLATE_SCI

#include "CActorTemplate.h"
#include "../Logic/Car/CCar.h"

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
	///Klasa reprezentuje generyczny wzorzec roœlinnoœci
	///
	class CCarTemplate : public CActorTemplate
	{

	public:

		///
		///Konstruktor
		///
		CCarTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CCarTemplate();

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje cechy CCar
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiek klasy CCar
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CCar* Create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CCar
		///
		///@param *Car - wskaŸnik na obiekt klasy CCar
		///
		virtual void Fill(CCar *Car);

		//gdy w klasie CCar byd¹ dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale¿ay utworzyæ takie same pola oraz je uwzglêdniæ
		float m_rotation_speed_body_template; //prêdkoœæ rotacji body
		float m_rotation_speed_head_template; //prêdkoœæ rotacji head

	};
}//namespace factory
#endif //H_Car_TEMPLATE_SCI
