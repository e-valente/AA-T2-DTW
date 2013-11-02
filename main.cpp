#include "dtw.h"

using namespace std;

extern Series mySeries;


int main(int argc, char *argv[])
{

    mySeries.resize(1200);

    readFile();
    readData();


    return 0;
}

