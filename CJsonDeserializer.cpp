#include "CJsonDeserializer.h"
 
bool CJsonDeserializer::Deserialize( IJsonDeserializable* pObj, std::string& input )
{
   if (pObj == NULL)
      return false;
 
   Json::Value deserializeRoot;
   Json::Reader reader;
 
   if ( !reader.parse(input, deserializeRoot) )
      return false;
 
   pObj->Deserialize(deserializeRoot);
 
   return true;
}