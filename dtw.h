#ifndef DTW_H
#define DTW_H
#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <limits.h>
#include <iomanip>

#define INFNT 1000

typedef std::vector< std::list<double> > Series;
typedef std::vector< std::vector<double> > DTWMatrix;


//principais funcoes
void readFile();
void readData();
double calcDTW(int index_x, int index_y);
void DTW();

//funcoes auxiliares
double myMin(double a, double b, double c);



#endif // DTW_H
