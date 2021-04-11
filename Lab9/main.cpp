// A simple-SVG program example -- Michel Pasquier, 28 March 2021
//
// This demo program uses the Simple-SVG library to draw lines and create
// images for CMP 305 labs. All graphic code is provided so one can focus
// solely on the logic of the application and recursively drawing shapes.
//
// Change the code where indicated below to implement your own function,
// calling drawline(a, b) as necessary. See sample usage, also to create
// points... Change the title as you wish e.g., to display your name/s.
//
// Compile on macOS in the Terminal with: g++ -std=c++11 -o test demo.cpp
// Run the program in the Terminal with:  ./demo
// Drag and drop the created SVG image in your web browser to see it.
//
// The library consists of a single header file, included below, and can
// be found at https://github.com/adishavit/simple-svg (was from Google).
// The following code is adapted from the given main program example.

#include "simple_svg_1.0.0.hpp"
using namespace svg;
#include <string>
using namespace std;

void drawline( Point a, Point b, Document& doc, Color color ) {
    doc << (Polyline{ Stroke{1, color}} << a << b );
}

// draw a single H, centered at x,y of the given side length
void drawH( double x, double y, double len, Document& doc, Color color ) {
    // compute the coordinates of the 4 tips of the H
    double x0 = x-len/2, x1 = x+len/2, y0 = y-len/2, y1 = y+len/2;
    // draw the 3 line segments of the H: left, right, horizontal
    drawline( Point{x0,y0}, Point{x0,y1}, doc, color );
    drawline( Point{x1,y0}, Point{x1,y1}, doc, color );
    drawline( Point{x0,y}, Point{x1,y}, doc, color );
}

//  plot a H-tree of order n centered at x,y of the given length
void drawHtree( int n, double x, double y, double len, Document& doc, Color color ) {
   
    //Your code goes here
   
   
 
}

int main() {
    const int SIZE {340};             // dimensions of the square image
    string FILE {"ztest_image.svg"};  // name of the saved image file
    string TITLE {"H-tree Fractal"};  // title text displayed at top left
    
    Dimensions dim{ SIZE, SIZE };
    Document doc{ FILE, Layout{ dim, Layout::TopLeft }};
    doc << Rectangle{ Point{0, 0}, dim.width, dim.height, Color::Black };
    doc << Text{ Point{10, 16}, TITLE, Color::Green, Font{ 10, "Verdana" }};

   
    drawH(SIZE/2, SIZE/2, SIZE/2, doc, Color::Green);
    //drawHtree( 3, SIZE/2, SIZE/2, SIZE/2, doc, Color::Green );

    // end of your code
    doc.save();
}


