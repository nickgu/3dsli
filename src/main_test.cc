

#include "3d.h"
#include "stl_reader.h"

#include <vector>

Poly_t slice(const Mesh_t& mesh, const float z_value) {
	Poly_t ans;
	for (size_t i=0; i<mesh._triangles.size(); ++i) {
		std::vector<Point2d_t> m;
		for (size_t j=0; j<3; ++j) {
			// generate polys.
			check_edges(m, mesh._triangles[i]._p[j], mesh._triangles[i]._p[(j+1) % 3]);
		}
		if (m.size() == 2) {
			ans._edges.push_back( Edge2d_t(m[0], m[1]) );
		}
	}
	return ans;
}


int main(int argc, const char** argv) {
	StlReader_t reader = StlReader_t();
	Mesh_t mesh = reader.read(argv[1]);

	float z_value_begins = -10.0;
	float z_value_ends = 10.0;
	float z_value_intervals = 0.02;

	vector<Poly_t> all_layers;
	for (float z_value = z_value_begins; z_value < z_value_ends; z_value += z_value_intervals) {
		Poly_t poly = slice(mesh, z_value);
		all_layers.push_back(poly);
	}
	return 0;
}
