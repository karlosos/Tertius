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
	///Klasa reprezentuje generyczny wzorzec ro�linno�ci
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
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml �aduje cechy CCar
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
		///Wirtualna metoda wype�niaj�ca danymi obiekt klasy CCar
		///
		///@param *Car - wska�nik na obiekt klasy CCar
		///
		virtual void Fill(CCar *Car);

		//gdy w klasie CCar byd� dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale�ay utworzy� takie same pola oraz je uwzgl�dni�
		float m_rotation_speed_body_template; //pr�dko�� rotacji body
		float m_rotation_speed_head_template; //pr�dko�� rotacji head

	};
}//namespace factory
#endif //H_Car_TEMPLATE_SCI
