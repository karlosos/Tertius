/*
 _______________________________________
| CCar.h - definicja klasy.           |
| Jack Flower - March 2014.             |
|_______________________________________|

*/

#ifndef H_Car_JACK
#define H_Car_JACK

#include "../Actor/CActor.h"

namespace logic
{
	///
	///Klasa reprezentuje obiekty - roœlinnoœæ (drzewa, krzewy, etc...)
	///
	class CCar : public CActor
	{

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
//Aby uzyskaæ obiekt CCar, nale¿y wywo³aæ
//CPhysicalManager::CreateCar();

	protected:
		///
		///Chroniony konstruktor domyœlny
		///
		CCar(const std::wstring& uniqueId);

		///
		///Destruktor wirtualny
		///
		virtual ~CCar(void);

	public:

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

		public:

		///
		///Metoda zwraca prêdkoœæ rotacji body
		///
		const float getRotationSpeedBody() const;

		///
		///Metoda ustawia prêdkoœæ rotacji body
		///
		///@param rotation_speed_body - prêdkoœæ rotacji body
		///
		void setRotationSpeedBody(float rotation_speed_body);

		///
		///Metoda zwraca prêdkoœæ rotacji head
		///
		const float getRotationSpeedHead() const;

		///
		///Metoda ustawia prêdkoœæ rotacji head
		///
		///@param rotation_speed_head - prêdkoœæ rotacji head
		///
		void setRotationSpeedHead(float rotation_speed_head);


	private:

		float m_rotation_speed_body;//prêdkoœæ rotaacji body
		float m_rotation_speed_head;//prêdkoœæ rotaacji head

	};
}//namespace logic
#endif//H_Car_JACK
