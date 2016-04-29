#include <string>
#include <cmath>
#include <vector>
#include "Vertex.h"

#define Square(x) ((x)*(x))

Vertex::Vertex(std::string id, std::vector<double> pos): 
m_id(id), m_pos(pos) 
{
}


double Vertex::MeasureDistance(Vertex target) 
{
	double dis = 0.0;
	dis += Square( target.m_pos[0] - m_pos[0] );
	dis += Square( target.m_pos[1] - m_pos[1] );
	return sqrt(dis);
}

double Vertex::MeasureDistance(std::vector<double> target) 
{
	double dis = 0.0;
	dis += Square( target[0] - m_pos[0] );
	dis += Square( target[1] - m_pos[1] );
	return sqrt(dis);
}

std::string Vertex::GetId() 
{ 
	return m_id;
}

void Vertex::GetPosition(double& x, double&  y) const 
{
	x = m_pos[0];
	y = m_pos[1];
}
