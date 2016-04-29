#pragma once

#include "json/json.h"

class IJsonDeserializable
{
public:
   virtual ~IJsonDeserializable( void ) {};
   virtual void Deserialize( Json::Value& root) = 0;
};
