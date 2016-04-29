#include <vector>
#include "Quote.h"

using namespace std;

const double Quote::s_padding = 0.1;
const double Quote::s_materialCost = 0.75;
const double Quote::s_cutterSpeed = 0.5;
const double Quote::s_machiningCost = 0.07;

const double PI = 3.141592653589;

double Quote::GetQuote(Profile& profile)
{
	vector<Edge> segments = profile.GetSegments();	
	vector<Vertex> nodes = profile.GetNodes(); 

	ComputeBoudingBox(nodes);
	TraverseSegments(segments);

	double cuttingCost = Quote::s_machiningCost * m_cuttingTime;

	double stockArea = (m_boundingWidth + Quote::s_padding) * (m_boundingHeight + Quote::s_padding);
	double stockCost = Quote::s_materialCost * stockArea;

	return cuttingCost + stockCost;
}

void Quote::TraverseSegments(const vector<Edge>& segments)
{
	m_cuttingTime = 0;

	for(vector<Edge>::const_iterator it = segments.begin(); it != segments.end(); ++it)
	{
		EdgeType type = it->GetType(); 

		Vertex *start, *end;
		it->GetNodes(start, end);

		if(LINE == type) 
		{
			double lengthTraversed = start->MeasureDistance(*end);
			m_cuttingTime += lengthTraversed / Quote::s_cutterSpeed;
		}
		else if(ARC == type)
		{
			vector<double> center = it->GetCenter();
			Vertex* clockwiseNode = it->GetClockwiseNode();

			double radius = clockwiseNode->MeasureDistance(center);
			double lengthTraversed = radius * PI;
			double cutterSpeedInCircularArc = Quote::s_cutterSpeed * exp( -1.0 / radius );
			m_cuttingTime += lengthTraversed / cutterSpeedInCircularArc;

			/// Check if the circular arc is exterior, if so add the area contributed by the segment
			if(clockwiseNode == end)
			{
				double startX, startY, endX, endY;
				start->GetPosition( startX, startY);
				end->GetPosition( endX, endY);
				if(startX == endX) {
					m_boundingWidth += radius;
				}
				else if(startY == endY) {
					m_boundingHeight += radius;
				}

			}
		}
	}
}

void Quote::ComputeBoudingBox(const std::vector<Vertex>& nodes)
{
	double x_min = DBL_MAX, x_max = DBL_MIN;
	double y_min = DBL_MAX, y_max = DBL_MIN;
	for(vector<Vertex>::const_iterator it = nodes.begin(); it != nodes.end(); ++it)
	{
		double posX, posY;
		it->GetPosition(posX, posY);
		x_min = min (x_min, posX);
		x_max = max (x_max, posX);
		y_min = min (y_min, posY);
		y_max = max (y_max, posY);
	}
	m_boundingWidth = x_max - x_min;
	m_boundingHeight = y_max - y_min;
}
