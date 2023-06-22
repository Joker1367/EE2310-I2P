// EE2310 Extra lab 1. PPM class for an image object
// ID, Name
// Date

class PIXEL {						// Pixel class
	public:
		PIXEL(void) {};				// uninit constructor
		PIXEL(unsigned char pr, unsigned char pg, unsigned char pb):
			r(pr), g(pg), b(pb) {};	// init constructor
		unsigned char R();			// get R component
		unsigned char G();			// get G component
		unsigned char B();			// get B component
		void setR(unsigned char v);	// set R component to v
		void setG(unsigned char v);	// set G component to v
		void setB(unsigned char v);	// set B component to v
		void setAll(unsigned char pr, unsigned char pg,		// set all colors
					unsigned char pb);
		void setAll(PIXEL &px);		// set all colors
	private:
		unsigned char r, g, b;		// three color components
};

class PPM {							// an image class
	public:
		PPM(void);					// uninit constructor
		PPM(PPM &p1);				// copy constructor
		PPM(char *fin);				// init constructor, read in from a file
		void out(char *fout);	// output image to a file
		PPM cvt(PPM &EE, PPM &NTHU, int x1, int x2, int y1, int y2);
								// create a new image as lab14
		PPM bw(void);			// create a new black and white image
		void addBox(int x1, int y1, int x2, int y2, int lw, PIXEL color);
									// add a box in pixel color
									//   line width: lw
		void waterMark(PPM &p1, int q, PIXEL color);
									// add p1 as a colored water mark,
									// q: quadrant
									//    0: center,
									//    1: top-right corner,
									//    2: top-left corner,
									//    3: bottom-left corner,
									//    4: bottom-right corner.
		void stamp(PPM &p1, int q);	// add p1 as a stamp, q: quadrant
		void addGrid(int xs, int ys, int lw, PIXEL color);
									// add color grid lines with horizontal
									// (xs) and vertical (ys) spacing
		PPM mosaic(int bw, int bh); // create a mosaic picture with
                                    // block width bw and block height bh
									//   line width, lw
	private:
		char header[3];				// header, either P3 or P6
		int W, H;					// image width and height
		int level;					// intensity level of each color component
		PIXEL **PX;					// two-dimensional array for all the pixels
};
