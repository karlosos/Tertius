/*
 _______________________________________
| CMonster.cpp - implementacja klasy.   |
| SCI - January 2014.                   |
|_______________________________________|

*/

#include "CMonster.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Game/CGame.h"

using namespace game;

namespace logic
{
	//Chroniony konstruktor domyœlny
	CMonster::CMonster(const std::wstring& uniqueId)
	:
		CActor(uniqueId)//konstruktor klasy bazowej
	{
	}

	//Destruktor wirtualny
	CMonster::~CMonster(void)
	{
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CMonster::Update(float dt)
	{
		CPhysical::Update(dt);
		//napisz sobie sam....
		//printf("jestem potwor ciasteczkowy\n");
		//tutaj bêdzie AI naszego potwora...
		sf::Vector2i position = sf::Mouse::getPosition(*gGame.GetRenderWindow());

		if(	position.x >= GetPosition().x - GetDisplayableBody()->getGlobalBounds().width * 0.5f && 
			position.x <= GetPosition().x + GetDisplayableBody()->getGlobalBounds().width * 0.5f && 
			position.y >= GetPosition().y - GetDisplayableBody()->getGlobalBounds().height * 0.5f &&
			position.y <= GetPosition().y + GetDisplayableBody()->getGlobalBounds().height * 0.5f)


		{
			SetColorBody(sf::Color::Red);
			RotateBody(-0.25f);
			RotateHead(0.25f);
		}
		else
			RestoreColorBody();

	}

}//namespace logic
