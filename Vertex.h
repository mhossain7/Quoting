#pragma once

#include <string>
#include <vector>

/// Encapsulation of a Vertex in the profile.
class Vertex {
public:
	/// Constructor for vertex.
    /// \param id The vertex id.
    /// \param pos The (x,y) co-ordinates of the vertex.
	Vertex(std::string id, std::vector<double> pos); 

	/// Retrieves the id of the vertex.
	/// \return The vertex id.
	std::string GetId();

	/// Retrieves the (x,y) co-ordinates of the vertex.
    /// \param x The reference to x co-ordinate of the vertex.
    /// \param y The reference to y co-ordinate of the vertex.
	void GetPosition(double& x, double&  y) const;

	/// Computes the distance between two vertex. 
    /// \param target The target vertex.
	/// \return The distance of the vertex from the target.
	double MeasureDistance(Vertex target);

	/// Computes the distance between two vertex. 
    /// \param target The target (x,y) co-ordinates.
	/// \return The distance of the (x,y) co-ordinates of the vertex from the target.
	double MeasureDistance(std::vector<double> target);


private:
	std::string m_id;	// vertex id
	std::vector<double> m_pos;	// vertex (x,y) co-ordinates
};

