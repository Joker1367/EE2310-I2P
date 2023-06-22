// EE2310 Lab14. Image Processing
// 109061217, 林峻霆
// 2020/01/04

#include <stdio.h>
#include <stdlib.h>

typedef struct sPIXEL {      // a single pixel
	unsigned char r, g, b;   // three color component
} PIXEL;

typedef struct sIMG {        // an image of PPM style
	char header[3];          // header, either P3 or P6
	int w, h;                // width and height of the image
	int level;               // intensity level of each color component
	PIXEL **PX;              // two-dimentional array for all the pixels
} IMG;

IMG *PPMin(char *inFile);             // a function read in data from image
									  // a function process the image data
IMG *PPMcvt(IMG *p1, IMG *ee, IMG *nthu, int x1, int y1, int x2, int y2);
void PPMout(IMG *pic, char *outFile); // a function output the data

int main(int argc, char *argv[])
{
	IMG *p1;                                    // the image of students
	IMG *ee;                                    // NTHUEE logo
	IMG *nthu;                                  // NTHU logo
	int x1, y1, x2, y2;                         // boundary of block

	p1 = PPMin(argv[1]);                        // read in image p1
	ee = PPMin(argv[2]);                        // read in image ee
	nthu = PPMin(argv[3]);                      // read in image nthu
	x1 = 120;                                   // set the boundary
	x2 = p1->w - x1;
	y1 = p1->h - ee->h -150;
	y2 = nthu->h;
	
	p1 = PPMcvt(p1, ee, nthu, x1, y1, x2, y2);  // processing thr images

	PPMout(p1, argv[4]);                        // output the image
	return 0;                                   // end the program
}

IMG *PPMin(char *inFile)
	// This function opens an input file, reads in data and stores to a new
	// data structure
{
	int i, j;    // parameter for loop
	IMG *pic;    // a data structure storing data of image
	FILE *fin;   // input file

	pic = (IMG*)malloc(sizeof(IMG));                    // allocate memory
	fin = fopen(inFile, "r");                           // open file
	fscanf(fin, "%s", pic->header);                     // read in data
	fscanf(fin, "%d %d\n%d\n", &pic->w, &pic->h, &pic->level);

	pic->PX = (PIXEL**)malloc(pic->w * sizeof(PIXEL*)); // allocate memory
	for (i = 0; i < pic->w; i++) 
		pic->PX[i] = (PIXEL*)malloc(pic->h * sizeof(PIXEL*));
	for (j = 0; j < pic->h; j++) {                      // read in data
		for (i = 0; i < pic->w; i++) {
			pic->PX[i][j].r = getc(fin);
			pic->PX[i][j].g = getc(fin);
			pic->PX[i][j].b = getc(fin);
		}
	}

	fclose(fin);                                       // close the file
	return pic;                                        // return result
}

IMG *PPMcvt(IMG *p1, IMG *ee, IMG *nthu, int x1,int y1, int x2, int y2)
	// This function process the data in the following order:
	// 		steps 1. convert image to gray-scale, instead of myself
	// 		steps 2. draw the boundary of the block
	// 		steps 3. put on NTHU logo
	// 		steps 4. put on NTHUEE logo
	// 		steps 5. return processed image
{
	int i, j;           // parameter for loop and index
	int x_dir, y_dir;   // the coordinate of NTHUEE logo
	char gray_level;    // variable for gray-scale converting

	PIXEL blue;         // a pixel of blue color
	blue.r = 0;
	blue.g = 183;
	blue.b = 255;

	// convert everyone in the image instead of me into gray-scale.
	for (i = 0; i < p1->w; i++) {
		for (j = 0; j < p1->h; j++) {
			if (i < 1100 || i > 1320 || j < 1350 || j > 1650) { 
				gray_level = 0.2126 * p1->PX[i][j].r + 0.7152 *
							p1->PX[i][j].g + 0.0722 * p1->PX[i][j].b;
				p1->PX[i][j].r = gray_level;   // convert to gray-scale
				p1->PX[i][j].g = gray_level;   // convert to gray-scale
				p1->PX[i][j].b = gray_level;   // convert to gray-scale
			}
		}
	}

	// draw the boundary of block
	for (j = 0; j < 10; j++) {
		for (i = x1; i <= x2; i++) { 
			p1->PX[i][y1 + j] = blue;      // set the color blue
			p1->PX[i][y2 + j] = blue;      // set the color blue
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = y2; j <= y1; j++) {
			p1->PX[x1 + i][j] = blue;      // set the color blue
			p1->PX[x2 + i][j] = blue;      // set the color blue
		}
	}

	// put the NTHU logo on the upper-left corner
	for (i = 0; i < nthu->w; i++) {
		for (j = 0; j < nthu->h; j++) {
			if (nthu->PX[i][j].r != 255 && nthu->PX[i][j].g != 255 && 
				nthu->PX[i][j].b != 255) { // check whether pixel is white
				p1->PX[i][j].r = 255;	   // set the color intensity
				p1->PX[i][j].b = 255;
			}
		}
	}

	// put th NTHUEE logo on the bottom-middle part of image
	x_dir = (p1->w - ee->w) / 2;            // calculate the coordinate
	y_dir = p1->h - ee->h;                  // calculate the coordinate
	for (i = 0; i < ee->w; i++) {
		for (j = 0; j < ee->h; j++) {
			if (ee->PX[i][j].r != 255 && ee->PX[i][j].g != 255 &&
				ee->PX[i][j].b != 255) {    // check if the pixel is white
				p1->PX[x_dir + i][y_dir + j - 180] = ee->PX[i][j];
			}
		}
	}
		
	return p1;                              // return the processed image
}

void PPMout(IMG *pic, char *outFile)
	// a function output the data from the data structure to output file
{
	int i, j;                                       // parameter for loop
	FILE *fout;                                     // output file

	fout = fopen(outFile, "w");                     // open the file
	fprintf(fout, "%s\n%d %d\n%d\n", pic->header, pic->w, pic->h, 
	        pic->level);
	for (j = 0; j < pic->h; j++) {                  // output the data
		for (i = 0; i < pic->w; i++) {
			fprintf(fout, "%c", pic->PX[i][j].r);
			fprintf(fout, "%c", pic->PX[i][j].g);
			fprintf(fout, "%c", pic->PX[i][j].b);
		}
	}
	
	fclose(fout);                                   // close the file
}

