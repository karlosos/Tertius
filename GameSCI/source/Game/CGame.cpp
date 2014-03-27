/*
 __________________________________
| CGame.cpp - class implementation |
| SCI - July 2012.                 |
|__________________________________|

*/

#include <iostream>
#include "CGame.h"

#include "../ResourceManager/CResourceManager.h"
#include "../ResourceManager/CFont.h"
#include "../Rendering/Animations/CAnimationManager.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Weather/CWeather.h"
#include "../Factory/CEnemyTemplate.h"
#include "../Factory/CMonsterTemplate.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/CLogic.h"
#include "../Map/CMap.h"

using namespace resource;
using namespace rendering::displayable;
using namespace rendering::animation;
using namespace logic;
using namespace listener;
using namespace game;
using namespace weather;
using namespace mapengine;

template<> CGame* CSingleton<game::CGame>::m_singleton = 0;

namespace game
{
	//Konstruktor domyœlny
	CGame::CGame(void)
	:
		m_render_window	(0),
		m_clock			()
	{
		printf("CGame::CGame()\n");
		gGameProperties.Load("data/xml_data/game_config/game_config.xml");
		gGameProperties.UpdateWindow();
		
		m_clock.Reset();
		printf("m_clock.Reset()\n");
	}

	//Destruktor
	CGame::~CGame(void)
	{
		printf("CGame::~CGame()\n");
		Cleanup();
	}

	//Wirtualna metoda czyszcz¹ca singleton
	void CGame::Cleanup()
	{
		m_render_window = NULL;
		printf("CGame::Cleanup() done...\n");
	}

	//Metoda zwraca wskaŸnik na okno gry
	sf::RenderWindow* CGame::GetRenderWindow()
	{
		return m_render_window;
	}

	//Metoda ustawia wskaŸnik na okno gry
	void CGame::SetRenderWindow(sf::RenderWindow * renderWindow)
	{
		m_render_window = renderWindow;
		printf("CGame::SetRenderWindow()\n");
	}

	//Metoda uruchamia g³ówn¹ pêtlê gry
	void CGame::Run()
	{
		mainLoop();
	}

	//Metoda aktualizuje stan gry
	void CGame::Update(float dt)
	{
		//aktulizacja listenerów...
		std::set<IFrameListener*>::iterator i;
		for (i = m_frameListeners.begin(); i != m_frameListeners.end(); i++)
			(*i)->FrameStarted(dt);

		//rysujemy obiekty na scenie
		gDrawableManager.DrawFrame();

		//wyliczamy FPS
		FPS_Game.UpdateFPS();
		fps_text.setString("FPS: "+ stringutils::ToString<int>(FPS_Game.GetFPS()));
	}

	//Metoda zwraca referencjê do obiektu klasy sf::Event
	sf::Event& CGame::GetGameEvent()
	{
		return m_event;
	}


	//implementacja metod private:

	//pêtla g³ówna gry
	void CGame::mainLoop()
	{
		CMap mapa;
		mapa.Load("data/xml_data/maps/level_001.xml");
		mapa.RespawnMapObjects(true);

		/*
		//rêczna, bezpieczna inicjacja niektórych singleton
		initSingletons();

		//jakaœ funkcja ³aduj¹ca na pocz¹tku zasoby dla poprawy wydajnoœci...

		//bardzo Ÿle napisane...mo¿na poni¿sze opakowaæ do jakiejœ klasy/metody?
		CFont font = *gResourceManager.GetFont("data/fonts/tahoma.ttf");
		fps_text.setString("Zaczynamy");
		fps_text.setFont(font);
		fps_text.setCharacterSize(20);
		fps_text.setColor(sf::Color::Blue);
		fps_text.setPosition(10,10);

	
		//³adowanie danych z poziomu CResourceManager'a
		if(gResourceManager.LoadPhysicalTemplate("data/xml_data/units_enemy/destroyer.xml") == false)
			printf("Data not loaded...\n");
		if(gResourceManager.LoadPhysicalTemplate("data/xml_data/units_monster/monster.xml") == false)
			printf("Data not loaded...\n");


		//tworzê fabrykê i inicjujê j¹ danymi pobramymi z CResourceManager'a uprzednio za³adowanymi
		CEnemyTemplate *p_enemy_template = (CEnemyTemplate*)gResourceManager.GetPhysicalTemplate("data/xml_data/units_enemy/destroyer.xml");
		//ten kod jest testowy, bo tworzenie (respawn) obiektów bêdzie z poziomu ³adowania mapy (level'a)
		CEnemy *p_enemy = p_enemy_template->Create(L"ID_enemy");

		
		if(p_enemy)
		{
			p_enemy->SetUseDisplayableBody(false);
			p_enemy->setSmoothing(false);
			p_enemy->SetPosition(400, 200);
			p_enemy->SetScale(2.5f);
			p_enemy->SetScaleHead(1.0f,1.0f);
			p_enemy->SetColorHead(sf::Color::Transparent);
			p_enemy->SetColorShadow(sf::Color::Transparent);
			p_enemy->SetAnimationHead("backpack_anim");
			p_enemy->SetAnimationBody("backpack_anim");
			

			//p_enemy->SetRotationBody(32.f);
			//p_enemy->SetRotationHead(310);

			//testy...sprawdziæ...jak to dzia³a...
			//p_enemy->SetColorHead(sf::Color::Blue);	//kolorujemy obiekt body na niebiesko
			//p_enemy->SetColorBody(sf::Color::Red);	//kolorujemy obiekt head na czerwono

			//p_enemy->RestoreColor();				//odzyskujemy oryginalny kolor body and head
			//p_enemy->RestoreColorBody();			//odzyskujemy oryginalny kolor body
			//p_enemy->RestoreColorHead();			//odzyskujemy oryginalny kolor head
		}


		//tworzê fabrykê i inicjujê j¹ danymi pobramymi z CResourceManager'a uprzednio za³adowanymi
		CMonsterTemplate *p_monster_template = (CMonsterTemplate*)gResourceManager.GetPhysicalTemplate("data/xml_data/units_monster/monster.xml");
		//ten kod jest testowy, bo tworzenie (respawn) obiektów bêdzie z poziomu ³adowania mapy (level'a)
		CMonster *p_monster = p_monster_template->Create(L"ID_monster");

		if(p_monster)
		{
			//p_enemy->SetUseDisplayableBody(false);
			p_monster->setSmoothing(false);
			p_monster->SetPosition(550, 200);
			//p_enemy->SetScale(2.5f);
			//p_enemy->SetScaleHead(1.0f,1.0f);
			//p_enemy->SetColorHead(sf::Color::Transparent);
			//p_enemy->SetColorShadow(sf::Color::Transparent);
			//p_enemy->SetAnimationHead("backpack_anim");
			//p_enemy->SetAnimationBody("backpack_anim");
		}
		*/
		printf("CGame::Run()\n");

		while (m_render_window->isOpen())
		{
			//zegar
			float elapsedTime = m_clock.GetElapsedTime();
			m_clock.Reset();

			//mo¿na te¿ skorzystaæ z poni¿szego zegara...
			//float elapsedTime = gClock.GetElapsedTime();
			//gClock.Update();

			while (m_render_window->pollEvent(m_event))
			{
				switch (m_event.type)
				{
				case sf::Event::Closed:
					m_render_window->close();
					return;

				case sf::Event::KeyPressed:
					for (std::set<IKeyListener*>::iterator i = m_keyListeners.begin() ; i != m_keyListeners.end(); i++ )
						(*i)->KeyPressed(m_event.key);
					break;
				
				default:
					break;

				}
			}

			//m_render_window->clear(sf::Color(255,255,255));
			m_render_window->clear(sf::Color::Blue);
			Update(elapsedTime);				//aktualizacja gry
			m_render_window->draw(fps_text);	//statystyki...

			
			m_render_window->display();			//wyœwietlenie sceny w oknie
		}
	}

	//Metoda inicjuje singletny
	const void CGame::initSingletons()
	{
		gGame;
		gGameProperties;
		gResourceManager;
		gDrawableManager;
		gAnimationManager;
		gWeather;
		gPhysicalManager;
		gLogic;
	}

	//Metoda dodaje do zbioru wskaŸniki obiektów aktualizowanych aktualizuj¹cych logikê
	void CGame::AddFrameListener(listener::IFrameListener* frameListener)
	{
		m_frameListeners.insert(frameListener);
	}

	//Metoda dodaje do zbioru wskaŸniki obiektów aktualizowanych zdarzenia klawiatury
	void CGame::AddKeyListener(listener::IKeyListener* keyListener)
	{
		m_keyListeners.insert(keyListener);
	}

	//Metoda dodaje do zbioru wskaŸniki obiektów aktualizowanych zdarzenia myszy
	void CGame::AddMouseListener(listener::IMouseListener* mouseListener)
	{
		m_mouseListeners.insert(mouseListener);
	}
}//namespace game
