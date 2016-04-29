#include <iostream>
#include <algorithm>
#include <cassert>
#include "Profile.h"

using namespace std;

void Profile::Deserialize( Json::Value& root )
{
	/// Read the vertex data
	Json::Value vertexList = root["Vertices"];
	Json::Value::Members& vertexIds = vertexList.getMemberNames();
	int index = 0; 
	for (Json::ValueIterator it = vertexList.begin(); it != vertexList.end(); ++it, ++index)
	{
		Json::Value vertex_descriptor = *it;
		assert(vertex_descriptor);

		Json::Value position = vertex_descriptor.get("Position","");
		assert(position);

		double posX = position.get("X", DBL_MAX).asDouble();
		double posY = position.get("Y", DBL_MAX).asDouble();
		assert(DBL_MAX != posX && DBL_MAX != posY);
		vector<double> pos;
		pos.push_back(posX);
		pos.push_back(posY);
		
		Vertex point( vertexIds[index], pos );
		m_nodes.push_back(point);
	}

	/// Read the edge data
	Json::Value edgeList = root["Edges"];
	Json::Value::Members& edgeIds = edgeList.getMemberNames();
	index = 0; 
	for (Json::ValueIterator it = edgeList.begin(); it != edgeList.end(); ++it, ++index)
	{
		Json::Value segement_descriptor = *it;
		assert(segement_descriptor);

		string type_descriptor = segement_descriptor.get("Type","").asString();
		assert("" != type_descriptor);

		EdgeType type = UNDEFINED; 
		if("LineSegment" == type_descriptor) 
			type = LINE;
		else if("CircularArc" == type_descriptor) 
			type = ARC;

		string start_id = segement_descriptor.get("Vertices","")[0].asString();
		Vertex* start = MatchNode(start_id);
		string end_id = segement_descriptor.get("Vertices","")[1].asString();
		Vertex* end = MatchNode(end_id);

		if( LINE == type) {
			Edge link( edgeIds[index], start, end );
			m_segments.push_back(link);
		}
		else if ( ARC == type) {
			Json::Value position = segement_descriptor.get("Center","");
			assert(position);

			double centerX = position.get("X", DBL_MAX).asDouble();
			double centerY = position.get("Y", DBL_MAX).asDouble();
			assert(DBL_MAX != centerX && DBL_MAX != centerY);
			vector<double> center;
			center.push_back(centerX);
			center.push_back(centerY);

			string clockwiseNodeId = segement_descriptor.get("ClockwiseFrom","").asString();
			Vertex* clockwiseNode = MatchNode( clockwiseNodeId);
			assert( clockwiseNode == start || clockwiseNode == end );
		
			Edge link( edgeIds[index], start, end, center, clockwiseNode );
			m_segments.push_back(link);
		}
	}
}

Vertex* Profile::MatchNode(string id)
{
	for( vector<Vertex>::iterator it = m_nodes.begin(); it != m_nodes.end(); ++it) 
	{	
		if( 0 == id.compare(it->GetId()) ) {
			return &(*it);
		}
	}
	return NULL;
}

vector<Edge>& Profile::GetSegments()
{
	return m_segments;
}

vector<Vertex>& Profile::GetNodes()
{
	return m_nodes;
}


Profile::Profile()
{
}

Profile::~Profile()
{
	/// Clean up stroage
	vector<Edge>().swap(m_segments);
	vector<Vertex>().swap(m_nodes);
}