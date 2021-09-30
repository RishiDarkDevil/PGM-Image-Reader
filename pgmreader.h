#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// Custom Data type for storing image components
struct P5{
	string imageName;
	int width;
	int height;
	int max_value;
	unsigned char **matrix;
};

// Reads image
void imageRead(P5 *p5){
	char filename[100];
	p5->width = 0; p5->height = 0;	string format;
	cout << "Enter P5 image name(along with extension): ";
	cin >> filename;
	p5->imageName = filename;

	// Reads Header
	ifstream image(filename, ios::in | ios::binary);
	image >> format;
	if(format.compare("P5") != 0){
		cout << "Invalid File Format!/File Not Availalbe!";
		exit(0);
	}
	
	image >> p5->width >> p5->height;
	image >> p5->max_value;
	
	if(p5->max_value != 255){
		cout << "Corrupt File!";
		exit(0);
	}

	// Deals with comments
	char comment[1000]; char ch;
	image.getline(comment, 1000);
	image.read((char *)&ch, 1);
	while(ch == '#'){
		image.getline(comment, 100);
		image.read((char *)&ch, 1);
		cout << comment << endl;
	}
	image.seekg(-1, ios::cur);

	// Allocates the image matrix
	p5->matrix = new unsigned char*[p5->height]();
	for(int i = 0; i < p5->height; i++){
			p5->matrix[i] = new unsigned char[p5->width]();
			image.read((char *)p5->matrix[i], sizeof(unsigned char) * p5->width);
	}

	image.close();
}

// Prints image details
void imageInfo(P5 *p5){
	cout << "PGM(P5) Image Details" << endl;
	cout << "File Name: " << p5->imageName << endl;
	cout << "Height: " << p5->height << ", Width: " << p5->width << endl;
	cout << "Max Gray Value: " << p5->max_value << endl;
}

// Prints image matrix
void matrixPrint(P5 *p5){
	for(int i = 0; i < p5->height; i++){
		for(int j = 0; j < p5->width; j++){
			cout << p5->matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Frees up Dynamically allocated memory
void freeImageData(P5 *p5){
	for(int i = 0; i < p5->height; i++){
		delete p5->matrix[i];
	}

	delete p5;
}

// Writes the image matrix to another file names "out-<filename.pgm>"
void matrix_to_p5(P5 *p5){
	// Enter the output image name with extension.
	cout << "Enter the output Image name: ";
	cin >> p5->imageName;

	ofstream image(p5->imageName, ios::out | ios::binary);
	image << "P5\n";
	image << p5->width << " " << p5->height << "\n";
	image << p5->max_value << "\n";
	for(int i = 0; i < p5->height; i++)
		image.write((char *)p5->matrix[i], sizeof(unsigned char)*p5->width);
	image.close();
}