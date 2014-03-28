/*
 _______________________________________
| CFlora.h - definicja klasy.           |
| Jack Flower - March 2014.             |
|_______________________________________|

*/

#ifndef H_FLORA_JACK
#define H_FLORA_JACK

#include "../Actor/CActor.h"

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

	};
}//namespace logic
#endif//H_FLORA_JACK
