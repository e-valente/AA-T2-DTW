#include "dtw.h"

using namespace std;
Series mySeries;
Series templateSeries;
DTW dtw;

void readFile()
{

    ifstream infile;
    string sLine, stmp;
    int totalLines;


    infile.open("teste.txt");

    totalLines = 0;
    while(!infile.eof())
    {
        if(!infile.eof())
        {
            getline(infile, sLine);
            totalLines++;
        }
    }



    //rewind
    infile.clear();
    infile.seekg(0, std::ios::beg);

    mySeries.resize(totalLines);
    cout <<"total lines:" << totalLines << endl;

    int i = 0;
    while(!infile.eof())
    {
        getline(infile, sLine);

        istringstream eachLine(sLine);



        while(!eachLine.eof())
        {
            eachLine >> stmp;
            mySeries[i].push_back(atof(stmp.c_str()));


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

    for(int i = 0; i < mySeries.size(); i++)
    {
        cout <<"serie " << i<<endl;
        for(it = mySeries[i].begin(); it != mySeries[i].end(); it++)
        {

            cout << *it << " ";
        }

        cout << endl;
    }

}

double calcDTW()
{
    int lengthMySeries;

    lengthMySeries = mySeries.size();

    dtw.resize(lengthMySeries);

    for(int i = 0; i < lengthMySeries; i++)
        //tamanho de cada serie do template
        dtw[i].resize(900);

    for(int i = 0; i < lengthMySeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtw[i][0] = 9999;

    }


    //tamanho da template serie
    for(int i = 0; i < lengthMySeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtw[0][i] = 9999;
    }


    for(int i = 0; i < lengthMySeries; i++)
    {
        for(int j = 0; j < 900; j++)
        {
            //dtw[i][j] =

        }
    }





}
