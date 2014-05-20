/*
 __________________________________
| CWind.cpp - implementacja klasy. |
| Jack Flower - April 2014.        |
|__________________________________|

*/

#include "CWind.h"
#include <random>
#include <iostream>
#include <random>
using namespace std;
namespace weather
{
	namespace wind
	{
		//Konstruktor
		CWind::CWind()
		:
			m_wind_speed	(0.0f),
			m_duration_wind	(0.0f)
		{
		}

		//Konstruktor kopiuj¹cy
		CWind::CWind(const CWind& CWindCopy)
		:
			m_wind_speed	(CWindCopy.m_wind_speed),
			m_duration_wind	(CWindCopy.m_duration_wind)
		{
		}

		//Destruktor
		CWind::~CWind()
		{
			m_wind_speed	= 0.0f;
			m_duration_wind	= 0.0f;
		}

		//Metoda zwraca prêdkoœæ wiatru
		const float CWind::getWindSpped() const
		{
			return m_wind_speed;
		}

		//Metoda ustawia prêdkoœæ wiatru
		void CWind::setWindSpped(float wind_speed)
		{
			m_wind_speed = wind_speed;
		}

		//Metoda zwraca czas trwania wiatru
		const float CWind::getWindDuriation() const
		{
			return m_duration_wind;
		}

		//Metoda ustawia czas trwania wiatru
		void CWind::setWindDuriation(float duration_wind)
		{
			m_duration_wind = duration_wind;
		}

		///Metoda generuje losowe parametry wiatru
		void CWind::generateWind()
		{
			random_device rd;								// access hardware RNG
			default_random_engine e(rd());					// seed the software PRNG
			uniform_real_distribution<> d(0, 10);			// range
			m_wind_speed = d(e);							// sila wiatru
			m_duration_wind = d(e);							// czas wiatru
		}
	}//namespace wind
}//namespace weather 
