#include "graphics.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

class point {
protected:
          int x;
          int y;
          int color;
public:
       point();
       point(int xx, int yy);
       point(int xx, int yy, int cc);
       void draw();
       void hide();
       void move(int dx, int dy);
       void set(int xx, int yy, int cc);
};

point::point(int xx, int yy) {
      x = xx;
      y = yy;
      setcolor(color);
}

point::point(int xx, int yy, int cc) {
      x = xx;
      y = yy;
      color = cc;
}

void point::draw() {
     putpixel(x, y, color);
}

void point::hide() {
     putpixel(x, y, 0);
}

void point::move(int dx, int dy) {
     setcolor(color);
     x = x + dx;
     y = y + dy;
}

void point::set(int xx,int yy, int cc) {
	x = xx;
	y = yy;
	color = cc;
	point::draw();
}

class Line:public point {
      protected:
                int dx;
                int dy;
      public:
             Line();
             Line(int xl1, int yl1, int xl2, int yl2);
             void draw();
             void hide();
             void rotate(double fi);
             void move(int xl2, int yl2);
};

Line::Line(int xl1, int yl1, int xl2, int yl2):point(xl1, yl1) {
               dx = xl2;
               dy = yl2;
}

void Line::draw() {
     line(x, y, dx, dy);
}

void Line::hide() {
     color = 0;
}

void Line::rotate(double fi) {
    int xl2; int yl2;
    dx = (xl2 * cos(fi)) - (yl2 * sin(fi));
    dy = (xl2 * sin(fi)) + (yl2 * cos(fi));
}

void Line::move(int xl2, int yl2) {
     line(x + xl2, y + yl2, dx + xl2, dy + yl2);
     }

void circle( int x, int y, int radius );

class square:public Line {
public:
      square(int xs1, int ys1, int xs2, int ys2);
      void draw();
      void hide();
      void move(int xs, int ys);
      void rotate(double fi);
};

square::square(int xs1, int ys1, int xs2, int ys2):Line(xs1, ys1, xs2, ys2) {
    x = xs1;
    y = ys1;
}

void square::draw() {
     line(x, y, dx, dy);
     line(x, y + 100, dx - 100, dy);
     line(x - 100, y, dx, dy - 100);
     line(x - 100, y, dx - 100, dy);
}

void square::hide() {
     color = 0;
}

//square::

void square::rotate(double fi) {
    int xs2; int ys2;
     dx = (xs2 * cos(fi)) - (ys2 * sin(fi));
     dy = (xs2 * sin(fi)) + (ys2 * cos(fi));
}

void square::move(int xs, int ys) {
     line(x + xs, y + ys, dx + xs, dy + ys);
     line(x + xs, y + 100 + ys, dx - 100 + xs, dy + ys);
     line(x - 100 + xs, y + ys, dx + xs, dy - 100 + ys);
     line(x - 100 + xs, y + ys, dx - 100 + xs, dy + ys);
}

class romb:public square {
public:
    romb(int xr1, int yr1, int xr2, int yr2);
    void draw();
    void hide();
    void move(int xr, int yr);
    void rotate(double fi);
};

romb::romb(int xr1, int yr1, int xr2, int yr2):square(xr1, yr1, xr2, yr2) {
}

void romb::draw() {
    line(x,y,dx,dy);
	line(x,y,x+x/2,dy);
	line(x,dy+y,x+x/2,dy);
	line(dx,dy,x,dy+y);
}

void romb::hide() {
     color = 0;
}

void romb::rotate(double fi) {
    int xr2; int yr2;
     xr2 = (xr2 * cos(fi)) - (yr2 * sin(fi));
     yr2 = (xr2 * sin(fi)) + (yr2 * cos(fi));
}

void romb::move(int xr, int yr) {
    line(x + xr,y + yr,dx + xr,dy + yr);
	line(x + xr,y + yr,x+x/2 + xr,dy + yr);
	line(x + xr,dy+y + yr,x+x/2 + xr,dy + yr);
	line(dx + xr,dy + yr,x + xr,dy+y + yr);
}

class paral:public romb {
public:
    paral(int xp1, int yp1, int xp2, int yp2);
    void draw();
    void hide();
    void move(int xp, int yp);
    void rotate(double fi);
};

paral::paral(int xp1, int yp1, int xp2, int yp2):romb(xp1, yp1, xp2, yp2) {
}

void paral::draw() {
	line(x,y,dx,dy);
    line(x,y,x+y,x);
    line(x+y,x,dx+dy,x);
    line(dx,y,dx+dy,x);
}

void paral::hide() {
     color = 0;
}

void paral::rotate(double fi) {
    int xp2; int yp2;
     xp2 = (xp2 * cos(fi)) - (yp2 * sin(fi));
     yp2 = (xp2 * sin(fi)) + (yp2 * cos(fi));
}

void paral::move(int xp, int yp) {
	line(x + xp,y + yp,dx + xp,dy + yp);
    line(x + xp,y + yp,x+y + xp,x + yp);
    line(x+y + xp,x + yp,dx+dy + xp,x + yp);
    line(dx + xp,y + yp,dx+dy + xp,x + yp);
}

void rectangle( int left, int top, int right, int bottom );

int main() {

    int gddriver = DETECT, gmode, errorcode;
    initgraph(&gddriver, &gmode, "");

    point p( 100, 100, 15 );
    p.set( 100, 100, 15);
    delay(2000);
    p.move( 50, 50 );
    p.draw();
    delay(2000);
    p.move( 50, 50 );
    p.draw();
    delay(2000);
    p.hide();

    delay(2000);

    setcolor(1);
    Line l( 300, 150, 550, 150 );
    l.draw();
    delay(2000);
    l.move( 100, 100 );
    l.draw();
    delay(2000);
    l.rotate(90);
    l.draw();

    delay(2000);

    circle( 300, 300, 150);
    delay(2000);
    circle( 150, 150, 150);

    delay(2000);
/*
    square s( 200, 200, 200, 300);
    s.draw();
    delay(3000);
    s.move( 25, 150 );
    s.draw();
*/
    setcolor(4);
    square s( 400, 100 , 400, 200);
    s.draw();
    delay(2000);
    s.move( 125, 125);
    //s.rotate(45);
    s.draw();

    delay(2000);

    setcolor(14);
    romb r( 200,100,100,200 );
    r.draw();
    delay(2000);
    r.move( 300, 300 );
    r.draw();
    delay(2000);
    r.rotate(45);
    r.draw();

    delay(2000);

    setcolor(2);
    paral pa( 200,50,400,50 );
    pa.draw();
    delay(2000);
    pa.move( 300, 300 );
    pa.draw();
    delay(2000);
    pa.rotate(45);
    pa.draw();

    delay(2000);

    setcolor(4);
    rectangle( 500, 350, 550, 450 );
    delay(2000);
    rectangle( 300, 150, 350, 250 );

    getch();
    closegraph();
    return 0;
}
