#pragma once

#include "Vertex.h"

/// Enumeration of type of edges
enum EdgeType
{
	LINE, // edge of type "line segement"
	ARC, // edge of type "circular arc"
	UNDEFINED
};

/// Encapsulation of an Edge in the profile.
class Edge {
public:
	/// Constructor for line segment.
    /// \param id The edge id.
    /// \param start The first vertex of the edge.
    /// \param end The other vertex of the edge.
	Edge(std::string id, Vertex* start,  Vertex* end);

	/// Constructor for circular arc.
    /// \param id The edge id.
    /// \param start The first vertex of the edge.
    /// \param end The other vertex of the edge.
    /// \param center The center of the circular segment. 
    /// \param clockwiseFrom The vertex from which the circular arc may be drawn clockwise until it reaches the other vertex of that edge.
	Edge(std::string id, Vertex* start,  Vertex* end, std::vector<double> center, Vertex* clockwiseFrom);

	/// Retrieves the type of the edge.
	/// \return The edge type.
	EdgeType GetType() const;

	/// Retrieves the two vertex that defines an edge.
    /// \param start The reference to the first vertex of the edge.
    /// \param end The reference to the other vertex of the edge.
	void GetNodes(Vertex* &start,  Vertex* &end) const;

	/// Retrieves the center of the circular segment.
	/// \return The center of the circular arc.
	std::vector<double> GetCenter() const;

	/// Retrieves the vertex from which the circular arc may be drawn clockwise until it reaches the other vertex of that edge.
	/// \return The clockwiseFrom vertex.
	Vertex* GetClockwiseNode() const;

private:
	std::string		m_id; // edge id
	EdgeType		m_type;	// edge type
	Vertex*			m_nodes[2]; // edge endpoints
	std::vector<double> m_center; // center of circular arc
	Vertex*			m_clockwiseFrom; // point that defines clockwise traversal for circular arc
};
