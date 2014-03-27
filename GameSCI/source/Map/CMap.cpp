/*
 _____________________________________
| CMap.cpp - implementacja klasy.     |
| Jack Flower October 2012.           |
| basic version October 2012.         |
|_____________________________________|

*/

#include "CMap.h"
#include "CMapObjectDescriptor.h"
#include "../ResourceManager/CResourceManager.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Rendering/Drawable/Layers.h"

using namespace rapidxml;
using namespace resource;
using namespace mapengine;
using namespace rendering::displayable;

namespace mapengine
{
	//Konstruktor
	CMap::CMap(void)
	:
		m_map_filename			(""),
		m_map_header			(NULL),
		m_view_rectangle			(0,0,0,0),
		m_size				(0,0),
		m_map_object_types		(NULL),
		m_map_object_descriptors	(NULL)
	{
		fprintf(stderr, "CMap::CMap()\n");
	}

	//Konstruktor kopiuj�cy
	CMap::CMap(const CMap& CMapCopy)
	:
		m_map_filename			(CMapCopy.m_map_filename),
		m_map_header			(CMapCopy.m_map_header),
		m_view_rectangle			(CMapCopy.m_view_rectangle),
		m_size				(CMapCopy.m_size),
		m_map_object_types		(CMapCopy.m_map_object_types),
		m_map_object_descriptors    (CMapCopy.m_map_object_descriptors)
	{
		fprintf(stderr, "CMap::CMap(const CMap& CMapCopy)\n");
	}

 
	//Destruktor
	CMap::~CMap(void)
	{
		m_map_filename			= "";
		m_map_header			= NULL;
		//m_view_rectangle		not edit
		//m_size				not edit
		//m_map_object_types		not edit
		//m_map_object_descriptors	not edit
		fprintf(stderr, "CMap::~CMap(void)\n");
	}

	//Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach 
	//pochodnych
	void CMap::Drop()
	{
		fprintf(stderr, "CMap::Drop()\n");
		
		delete m_map_header;
		ClearMapObjects();
		delete this;
	}

	//Metoda rozstawiam wczytane z pliku mapy obiekty na scenie
	void CMap::RespawnMapObjects(bool load_complete_map)
	{
	//p�ki co, przy wywo�aniu metody flag� nale�y ustawi� na true
        for (unsigned int i = 0; i < m_map_object_descriptors.size(); i++)
        {
            if (load_complete_map)
                m_map_object_descriptors[i]->Create();
        }
	}


	//Metoda �aduj�ca dane
	bool CMap::Load(const std::string &filename)
	{
		fprintf(stderr, "map %s loaded...\n", filename.c_str());
		return LoadFromXML(filename);
	}


	//Metoda �aduj�ca dane z pliku xml
	bool CMap::LoadFromXML(const std::string &filename)
	{
		m_map_filename = filename;	//nazwa pliku mapy
		CXml xml(filename, "map");	//wszystkie pliki xml z mapami � 
							//maj� nag��wek root <map>
		xml_node<>* node;			//wska�nik na w�ze� dokumentu xml
		std::string str_data;		//nazwa dla danych �adowanych z 
							//xml

        //tworzymy nag��wek mapy
        m_map_header = new MapHeader();

	//sprawdzamy, czy obowi�zuj�ca wersja mapy jest poprawna
        m_map_header->m_map_version = xml.GetInt("version");
        if(m_map_header->m_map_version != CURRENT_MAP_VERSION)
		{
			fprintf(stderr, "Invalid map version (%d, expected %d) for map %s", m_map_header->m_map_version, CURRENT_MAP_VERSION, filename.c_str());
			return false;
        }

		//wype�niamy danymi struktur� opisuj�c� map�
		m_map_header->m_map_width_in_tile = xml.GetInt( "width" );
		m_map_header->m_map_height_in_tile = xml.GetInt( "height" );
		m_size.x = m_map_header->m_map_width_in_tile;
		m_size.y = m_map_header->m_map_height_in_tile;

        //typy fabryczne dla physicali na danej mapie
		CMapObjectType* p_map_object_type;

		for (node = xml.GetChild(xml.GetRootNode(), "objtype"); node; node = xml.GetSibling(node, "objtype"))
		{
			str_data = xml.GetString(node, "file");
			if(gResourceManager.LoadPhysicalTemplate(str_data) == false)
			{
				fprintf(stderr, "Cannot load object template file: %ls", str_data.c_str());
				return false;
			}
			p_map_object_type = new CMapObjectType();
			p_map_object_type->SetCode(xml.GetString(node, "code"));
			p_map_object_type->SetTemplate(gResourceManager.GetPhysicalTemplate(str_data));
			m_map_object_types.push_back(p_map_object_type);
        }

		//physical's (potwory, drzewka, domki, to co potrafimy utworzy�)
		CMapObjectDescriptor *p_map_object;
		for (node = xml.GetChild(xml.GetRootNode(), "obj"); node; node = xml.GetSibling(node, "obj"))
		{
			str_data = xml.GetString(node, "code");
			int i = GetMapObjectTypeIndex(str_data);
			if (i < 0)
				return false;
			p_map_object = new CMapObjectDescriptor();

			p_map_object->SetCode(str_data);//nazwa wzorca (fabryczna
			p_map_object->SetName(xml.GetString(node, "name"));//nazwa obiektu
			p_map_object->SetXPosition(xml.GetFloat(node, "x"));
			p_map_object->SetYPosition(xml.GetFloat(node, "y"));
			p_map_object->SetRotationBody(xml.GetFloat(node, "rotation_body"));
			p_map_object->SetRotationHead(xml.GetFloat(node, "rotation_head"));
			p_map_object->SetSmooth(xml.GetBool(node, "smooth"));
			
			p_map_object->SetTemplate(m_map_object_types[i]->GetTemplate());
			m_map_object_descriptors.push_back(p_map_object);
		}
        return true;//je�li pomy�lnie zosta�y za�adowane dane - zwracamy true
	}


	//Metoda usuwa z wektora wska�niki na obiekty klasy CMapObjectDescriptor i dane pod tymi wska�nikami
	void CMap::ClearMapObjects()
	{
		//obiekty
		for (unsigned i = 0; i < m_map_object_descriptors.size(); i++)
			delete m_map_object_descriptors[i];
		m_map_object_descriptors.clear();
	}
	
	//Metoda zwraca indeks wzorca na podstawie nazwy
	int CMap::GetMapObjectTypeIndex(const std::string &map_object_type_name)
	{
		for (unsigned int i = 0; i < m_map_object_types.size(); i++)
			if (m_map_object_types[i]->GetCode() == map_object_type_name)
				return i;
		// zwraca -1, wiec to chyba nie jest niezbedne?
		//tego nie analizowa�, ja Jack Flower - m�czy�em si�
		//i nawet nie pami�tam, czy ten temat "zamiot�em"?
		fprintf(stderr, "failed to find object template code %s\n",map_object_type_name.c_str());
		return -1;
	}

	//Metoda zwraca nazw� pliku z map�
	const std::string& CMap::GetFilename()
	{
		return m_map_filename;
	}

	//Metoda zwraca wektor z rozmiarem mapy w kaflach
	sf::Vector2<int> CMap::GetSize()
	{
		return m_size;
	}

	//Metoda zwraca wersj� mapy
	int CMap::GetVersion()
	{
		return m_map_header->m_map_version;
	}

} //namespace mapengine
