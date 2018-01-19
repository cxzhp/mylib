//c++ drawLine.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm> // std::min

#define MAXX 20
#define MAXY 20
char data[MAXX][MAXY];

//set value of a point
inline void paint(int x, int y, char c){
  if ((x<0)||(x>MAXX)||(y<0)||(y>MAXY)){
    printf("Range error: %d, %d", x,y);
    exit(1);
  }
  data[x][y] = c;
  //if(c != '.'){
  //  printf("%d,%d %c\n", x,y,c);
  //}
  return;
}


void data_init(void){
  int i,j;
  for (j=0;j<MAXY;j++) for (i=0;i<MAXX;i++) paint(i,j,'.');
}

void data_print(void){
  int i,j;
  for (j=(MAXY-1);j>=0;j--)
    for (i=0;i<MAXX;i++)
      printf("%c%c", data[i][j], i==MAXX-1?'\n':' ');
  printf("\n");


  //for (j=(MAXY-1);j>=0;j--)
  //  for (i=0;i<MAXX;i++)
  //  {
  //      //if(data[i][j] != '.'){
  //          printf("%d,%d %c", i,j,i==MAXX-1?'\n':' ');
  //      //}
  //  }
  //  printf("\n");

}



// Code from https://github.com/miloyip/line/blob/master/line_bresenham.c
// Modified from  https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
void bresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;

    while (paint(x0, y0,'X'), x0 != x1 || y0 != y1) {
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 <  dy) { err += dx; y0 += sy; }
    }
}



void getLine(int x0, int y0, int x1, int y1)
{

    bresenham(x0, y0, x1, y1);
    return;

}



main(){

  //
  //  X0
  //
  //
  //
  //             X1
  //
  //////////////////////
  data_init();
  getLine(1,5,6,2);
  printf("(%d,%d) (%d,%d)\n", 1,5,6,2);
  data_print();


  //
  //            X1 
  //
  //
  //
  //  X0           
  //
  //////////////////////
  data_init();
  getLine(1,1,5,8);
  printf("(%d,%d) (%d,%d)\n", 1,1,5,8);
  data_print();


  //
  //   X1 
  //
  //
  //
  //                X0           
  //
  //////////////////////
  data_init();
  getLine(6,2,1,5);
  printf("(%d,%d) (%d,%d)\n", 6,2,1,5);
  data_print();



  //
  //                X1 
  //
  //
  //
  // X0           
  //
  //////////////////////
  data_init();
  getLine(5,8,1,1);
  printf("(%d,%d) (%d,%d)\n", 5,8,1,1);
  data_print();


  //
  //
  //
  //
  // X0             X1
  //
  //////////////////////
  data_init();
  getLine(1,3,6,3);
  printf("(%d,%d) (%d,%d)\n", 1,3,6,3);
  data_print();


  //
  //
  //
  //
  // X1             X0
  //
  //////////////////////
  data_init();
  getLine(6,3,1,3);
  printf("(%d,%d) (%d,%d)\n", 6,3,1,3);
  data_print();


  //
  //        X1
  //
  //
  //
  //        X0
  //
  //////////////////////
  data_init();
  getLine(3,1,3,6);
  printf("(%d,%d) (%d,%d)\n", 3,1,3,6);
  data_print();


  //
  //        X0
  //
  //
  //
  //        X1
  //
  //////////////////////
  data_init();
  getLine(3,6,3,1);
  printf("(%d,%d) (%d,%d)\n", 3,6,3,1);
  data_print();

  return 0;

}
