/*
 __________________________________
| LayerIndexValue.h - wyliczenie.  |
| SCI - March 2012.                |
|__________________________________|

*/
#ifndef H_LAYER_SCI
#define H_LAYER_SCI

namespace rendering
{
	namespace drawable
	{
		///
		///Lista warto�ci dla zdefiniowanych warstw, na kt�rych b�dzie renderowana grafika
		///algorymt "m a l a r z a"
		///
		const int Z_MAX						= 100;
		const int Z_TILE					= 90;
		const int Z_BLOOD_SPLATS			= 85;
		const int Z_PHYSICAL_SHADOWS_BODY	= 83;
		const int Z_DEAD_BODY				= 80;
		const int Z_ITEM					= 55;
		const int Z_PHYSICAL_BODY			= 50;
		const int Z_PHYSICAL_SHADOWS_HEAD	= 49;
		const int Z_PHYSICAL_HEAD			= 48;
		const int Z_CURSOR					= 1;
		const int Z_ZERO					= 0;
		const int Z_FLORA_SHADOW_BODY		= 98;	//flora body shadow
		const int Z_FLORA_BODY				= 97;	//flora body
		const int Z_FLORA_SHADOW_HEAD		= 96;	//flora head shadow
		const int Z_FLORA_HEAD				= 95;	//flora head
	}//namespace drawable
}//namespace rendering
#endif //H_LAYER_SCI
