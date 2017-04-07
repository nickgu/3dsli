#ifndef __3D_H__
#define __3D_H__

#include <vector>

class Point_t {
public:
	float _x;
	float _y;
	float _z;

};

typedef Point_t Vector_t;

class Point2d_t {
	float _x;
	float _y;
};


template <typename T>
class Edge_t {
public:
	T _a;
	T _b;
};

typedef Edge_t<Point_t> Edge3d_t;
typedef Edge_t<Point2d_t> Edge2d_t;

class Triangle_t {
public:
	Point_t _p[3];
};

class NormTriangle_t {
public:
	Point_t _p[3];
	Vector_t _norm;
};

class Mesh_t {
public:
	std::vector<NormTriangle_t> _triangles; 
};

class Poly_t {
public:
	std::vector<Edge2d_t> _edges; 
};

#endif