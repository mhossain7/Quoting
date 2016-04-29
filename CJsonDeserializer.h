#pragma once

#include "IJsonDeserializable.h"

class CJsonDeserializer
{
public:
   static bool Deserialize( IJsonDeserializable* pObj, std::string& input );
 
private:
	CJsonDeserializer( void ) {};
};