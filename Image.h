// 	Copyright (C) Kevin Suffern 2000-2007.
// 	Copyright (C) Stefan Brumme 2005.
// 	Copyright (C) Sverre Kvaale 2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

// This is not a texture
// The Image class stores an image in PPM format
// This is used for image based textures, including ramp textures such as marble and sandstone
// I originally chose the PPM format because it's simple to parse
#ifndef IMAGE_H
#define IMAGE_H 
#pragma once
#include <vector>		
#include "ColorRGB.h"
using namespace std;

//--------------------------------------------------------------------- class Image

class Image {	
	public:
	
		Image(void);								

		Image(const Image& image);					

		Image& 										
		operator= (const Image& image);		

		~Image(void) ;								
		
		void read_ppm_file(const char* file_name);
		
		int get_hres(void);	
		
		int get_vres(void);	
				
		ColorRGB get_color(const int row, const int col) const;		
		ColorRGB get_color(int& index) const;		
		
	public:
		int 				hres;			// horizontal resolution of image
		int					vres;			// vertical resolution of image
		vector<ColorRGB> 	pixels;
}; 
 
//--------------------------------------------------------------------- get_hres

inline int
Image::get_hres(void) {
	return (hres);
}


//--------------------------------------------------------------------- get_vres

inline int
Image::get_vres(void) {
	return (vres);
}
#endif