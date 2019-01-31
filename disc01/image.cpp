#include "image.h"
#include "lodepng.h"


Image::Image() {
	width = height = 0;
}

Image::Image(const std::string& filename) {
	read(filename);
}

Image::Image(const unsigned& w, const unsigned& h)
: width(w), height(h), data(4 * w * h) {

}

void Image::read(std::string filename) {
	//decode
	unsigned error = lodepng::decode(data, width, height, filename);
	//if there's an error, display it
	if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

void Image::write(std::string filename) const {
	//Encode the image
	unsigned error = lodepng::encode(filename, data, width, height);
	//if there's an error, display it
	if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

uint8_t* Image::at(int x, int y) {
	return &data[(y * width + x) * 4];
}

Image Image::operator*(const Filter& filter) {
	Image result(width, height);
	for(int c=0;c<4;c++){
		for(int x=0;x<width;  x++){
			for(int y=0;y<height;y++){
                float newValue = 0;
				for(int i=0;i<filter.width;i++){
					for(int j=0;j<filter.height;j++){
						int x_pos = x - filter.width/2 + i;
						int y_pos = y - filter.height/2 + j;
						if(x_pos < 0 || x_pos >= width || y_pos < 0 || y_pos >= height)
                            continue;
						newValue += at(x_pos, y_pos)[c] * filter.at(i, j);
					}
				}
				*(result.at(x, y) + c) = (uint8_t)newValue;
			}
		}
	}
	return result;
}