#include <iostream>
#include <fstream>
#include <string.h>
#include "pgmreader.h"
using namespace std;

void image_process(P5 *);

int main(){
	P5 *p5 = new P5; 

	imageRead(p5);
	// matrixPrint(p5);	
	imageInfo(p5);
	// Here add the function that processes the image.
	image_process(p5);
	matrix_to_p5(p5);

	freeImageData(p5);
	return 0;
}

// Image Processing - Invert Colors
void image_process(P5 *p5){
	for(int i = 0; i < p5->height; i++){
		for(int j = 0; j < p5->width; j++)
			p5->matrix[i][j] = 255 - p5->matrix[i][j];
	}
}