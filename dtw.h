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


typedef std::vector< std::list<double> > Series;
typedef std::vector< std::vector<double> > DTW;



void readFile();
void readData();
double calcDTW();


#endif // DTW_H
