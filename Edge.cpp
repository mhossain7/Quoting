#include "Edge.h"

Edge::Edge(std::string id, Vertex* start,  Vertex* end)
{
	m_id = id;
	m_type = LINE;
	m_nodes[0] = start;
	m_nodes[1] = end;
}

Edge::Edge(std::string id, Vertex* start, Vertex* end, std::vector<double> center, Vertex* clockwiseFrom)
{
	m_id = id;
	m_type = ARC;
	m_nodes[0] = start;
	m_nodes[1] = end;
	m_center = center;
	m_clockwiseFrom = clockwiseFrom;
}

EdgeType Edge::GetType() const 
{ 
	return m_type;
}

void Edge::GetNodes(Vertex* &start, Vertex* &end) const 
{
	start = m_nodes[0];
	end = m_nodes[1];
}

std::vector<double> Edge::GetCenter() const 
{
	return m_center;
}

Vertex* Edge::GetClockwiseNode() const 
{
	return m_clockwiseFrom;
}
