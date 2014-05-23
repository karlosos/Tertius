/*
 _______________________________________
| CFlora.h - definicja klasy.           |
| Jack Flower - March 2014.             |
|_______________________________________|

*/

#ifndef H_FLORA_JACK
#define H_FLORA_JACK

#include "../Actor/CActor.h"
#include "../../Weather/CWeather.h"

//#define gWeather CWeather::GetSingleton()

namespace logic
{
	///
	///Klasa reprezentuje obiekty - ro�linno�� (drzewa, krzewy, etc...)
	///
	class CFlora : public CActor
	{

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
//Aby uzyska� obiekt CFlora, nale�y wywo�a�
//CPhysicalManager::CreateFlora();

	protected:
		///
		///Chroniony konstruktor domy�lny
		///
		CFlora(const std::wstring& uniqueId);

		///
		///Destruktor wirtualny
		///
		virtual ~CFlora(void);

	public:

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

		public:

		///
		///Metoda zwraca pr�dko�� rotacji body
		///
		const float getRotationSpeedBody() const;

		///
		///Metoda ustawia pr�dko�� rotacji body
		///
		///@param rotation_speed_body - pr�dko�� rotacji body
		///
		void setRotationSpeedBody(float rotation_speed_body);

		///
		///Metoda zwraca pr�dko�� rotacji head
		///
		const float getRotationSpeedHead() const;

		///
		///Metoda ustawia pr�dko�� rotacji head
		///
		///@param rotation_speed_head - pr�dko�� rotacji head
		///
		void setRotationSpeedHead(float rotation_speed_head);


	private:

		float m_rotation_speed_body;//pr�dko�� rotaacji body
		float m_rotation_speed_head;//pr�dko�� rotaacji head

	};
}//namespace logic
#endif//H_FLORA_JACK
