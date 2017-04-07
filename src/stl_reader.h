#ifndef _STL_READER_H_
#define _STL_READER_H_

#include <cstdio>

#include "3d.h"

class StlReader_t {
public:
	StlReader_t() {}
	~StlReader_t() {}

	Mesh_t read(const FILE* stream);	
	Mesh_t read_binary(const FILE* stream);

private:
};



#endif