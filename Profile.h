#ifndef PROFILE_H
#define PROFILE_H

#pragma once

#include <vector>
#include "IJsonDeserializable.h"
#include "Edge.h"


class Profile: public IJsonDeserializable
{
public:
	/// Constructor
	Profile();
	/// Destructor
	virtual ~Profile();

	/// Deserialzes the extrusion profiles so that they can be represented in memory.
    /// \param root The reference to the top-hierarchial JSON attribute.
	virtual void Deserialize( Json::Value& root);
 
	/// Retrieves the list of segments. 
    /// \return The reference to the edge array.
	std::vector<Edge>& GetSegments();

	/// Retrieves the list of nodes. 
    /// \return The reference to the vertex array.
	std::vector<Vertex>& GetNodes();

private:
	/// Retrieves the matching vertex. 
    /// \param id The vertex id. 
    /// \return The pointer to the matched vertex.
	Vertex* MatchNode(std::string id);	

	std::vector<Edge>	m_segments;	// the edge array
	std::vector<Vertex> m_nodes;	// the vertex array
};

#endif