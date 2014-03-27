/*
 _______________________________________
| CMonster.h - definicja klasy.         |
| SCI - January 2014.                   |
|_______________________________________|

*/

#ifndef H_MONSTER_SCI
#define H_MONSTER_SCI

#include "../Actor/CActor.h"

namespace logic
{
	///
	///Klasa reprezentuje potwora
	///
	class CMonster : public CActor
	{
		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
//Aby uzyskaæ obiekt CMonster, nale¿y wywo³aæ //CPhysicalManager::CreateMonster();

	protected:
		///
		///Chroniony konstruktor domyœlny
		///
		CMonster(const std::wstring& uniqueId);

		///
		///Destruktor wirtualny
		///
		virtual ~CMonster(void);

	public:
		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	};
}//namespace logic
#endif // H_MONSTER_SCI
