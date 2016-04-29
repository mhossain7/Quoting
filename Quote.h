#pragma once

#include "Profile.h"

class Quote
{
public:	
	/// Computes the quote for laser cutting. 
    /// \param p The input profile.
	/// \return The quote of the cutting. 
	double GetQuote(Profile& p);

	/// Processes the list of segments. 
    /// \param segements The edge array.
	void TraverseSegments(const std::vector<Edge>& segements);

	/// Processes the list of nodes. 
    /// \param nodes The vertex array.
	void ComputeBoudingBox(const std::vector<Vertex>& nodes);

private:
	double m_cuttingTime;		// total cutting time
	double m_boundingWidth;		// width of the axis-aligned bounding box
	double m_boundingHeight;	// height of the axis-aligned bounding box

	static const double s_padding;			// padding distance (inch)
	static const double s_materialCost;		// unit material cost (inch^2)
	static const double s_cutterSpeed;		// laser cutter speed (inch/sec)
	static const double s_machiningCost;	// machine time cost (/sec)
};
