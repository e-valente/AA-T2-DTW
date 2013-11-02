#include "dtw.h"

using namespace std;
Series mySeries;

void readFile()
{

    ifstream infile;
    string sLine, stmp;


    infile.open("teste.txt");

    int i = 0;
    while(!infile.eof())
    {
        getline(infile, sLine);

        istringstream eachLine(sLine);



        while(!eachLine.eof())
        {
            eachLine >> stmp;
            mySeries[i].push_back(atof(stmp.c_str()));
            //cout << stmp;

        }
        i++;

        //cout << "proximo" << endl;

    }

    infile.close();

}

void readData()
{

    //percorrendo

    list<double>::iterator it;

    for(int i = 0; i < 960; i++)
    {
        cout <<"serie " << i<<endl;
        for(it = mySeries[i].begin(); it != mySeries[i].end(); it++)
        {

            cout << *it << " ";
        }

        cout << endl;
    }

}

