#include "filter.h"


Filter::Filter() {
	width = height = 1;
	kernel = {1.f};
}

Filter::Filter(const std::string& filename) {
	read(filename);
}

void Filter::read(std::string filename) {
	std::ifstream ifs(filename);
	ifs >> width >> height;
	float f;
	kernel.clear();
	for(int i=0;i<width*height;i++){
		ifs >> f;
		kernel.push_back(f);
	}
	ifs.close();
	normalize();
}

void Filter::normalize() {
	float sum = 0;
	for(int i=0;i<width*height;i++)
		sum += kernel[i];
	for(int i=0;i<width*height;i++)
		kernel[i] /= sum;
}

const float& Filter::at(int x, int y) const {
	return kernel[y * width + x];
}

