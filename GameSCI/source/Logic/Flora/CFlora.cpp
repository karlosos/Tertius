#include "CFlora.h"

namespace logic
{
	//Chroniony konstruktor domyślny
	CFlora::CFlora(const std::wstring& uniqueId)
	:
		CActor			(uniqueId)//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	CFlora::~CFlora(void)
	{
	}

	//Wirtualna metoda aktualizująca obiekt
	void CFlora::Update(float dt)
	{
		//AI flora: To Do...
	}

}//namespace logic

 
