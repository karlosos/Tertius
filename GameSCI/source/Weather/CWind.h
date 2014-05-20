/*
 __________________________________
| CWind.h - definicja klasy.       |
| Jack Flower - April 2014.        |
|__________________________________|

*/

#ifndef H_WIND_JACK
#define H_WIND_JACK


namespace weather
{
	namespace wind
	{
		///
		///Klasa reprezentuje funkcjonalno�� wiatru
		///
		class CWind
		{

		public:

			///
			///Konstruktor
			///
			CWind();

			///
			///Konstruktor kopiuj�cy
			///
			///@param &CWindCopy - sta�a referencja na obiekt klasy
//CWind
			///
			CWind(const CWind& CWindCopy);

			///
			///Destruktor
			///
			~CWind();

			///
			///Metoda zwraca pr�dko�� wiatru
			///
			const float getWindSpped() const;

			///
			///Metoda ustawia pr�dko�� wiatru
			///
			///@param wind_speed - pr�dko�� wiatru
			///
			void setWindSpped(float wind_speed);

			///
			///Metoda zwraca czas trwania wiatru
			///
			const float getWindDuriation() const;

			///
			///Metoda ustawia czas trwania wiatru
			///
			///@param duration_wind - czas trwania wiatru
			///
			void setWindDuriation(float duration_wind);

			///
			///Metoda generuje losowe parametry wiatru
			///
			void generateWind();

		private:
			
			float	m_wind_speed;	//pr�dko�� wiatru
			float	m_duration_wind;	//czas trwania wiatru
		};
	}//	namespace wind
}//namespace weather
#endif//H_WIND_JACK
