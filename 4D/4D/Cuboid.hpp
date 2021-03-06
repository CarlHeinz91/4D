#ifndef CUBOID_HPP
#define CUBOID_HPP

#include "SFML\Graphics.hpp"
#include <vector>
#include "Object.hpp"
#include "ourVectors.hpp"

// Describes a 4D cuboid with generically different lengths of the edges
class Cuboid : public Object
{
private:
    fd::Vector4f mPosition;
    fd::Vector4f mDiagonal; // vector of the diagonal of the cube from the position vector
    //The order is given by: start with the edge at the position vector, then add the diagonal componentwise wrt the schema 0000, 0001, 0010, ..., 1111
    std::vector<fd::Vector4f> mCorners;

    std::vector<fd::Vector4i> mEdgeMap; //Idea: EdgeMap contains 64 dual numbers of length 4 which describe pairwise the connected vertices.
    std::vector<int> mEdgeMapIndex; //Contains the EdgeMap, but with the index of the corresponding Edge instead of the dual number


public:
    Cuboid(fd::Vector4f _position, fd::Vector4f _diagonal);
    ~Cuboid() override;

    void handleEvents() override;
    void update(sf::Time &elapsed) override;
    void render(sf::RenderWindow *pRenderWindow, fd::Matrix44f *view, fd::Vector4f *position) override;

    void fillCorners(); //Writes the coordinates which follow from the mPosition and mDiagonal into mCorners

    void fillEdgeMap();

    fd::Vector4f getPosition();

};

#endif // CUBOID_HPP
