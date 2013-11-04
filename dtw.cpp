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


    //le arquivo de entrada
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

    }

    infile.close();


    //le arquivo de treino (templates)
    infile.open("treino.txt");


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

    templateSeries.resize(totalLines);
    cout <<"total lines:" << totalLines << endl;

    i = 0;
    while(!infile.eof())
    {
        getline(infile, sLine);

        istringstream eachLine(sLine);

        while(!eachLine.eof())
        {
            eachLine >> stmp;
            templateSeries[i].push_back(atof(stmp.c_str()));

        }
        i++;

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

    for(int i = 0; i < templateSeries.size(); i++)
    {
        cout <<"serie " << i<<endl;
        for(it = templateSeries[i].begin(); it != templateSeries[i].end(); it++)
        {

            cout << *it << " ";
        }

        cout << endl;
    }

}

double calcDTW()
{
    int lengthMySeries, lengthTemplateSeries;


    //testaremos só a primeira séries
    //TAMANHO ESTA DANDO ERRADO
    lengthMySeries = mySeries[5].size();
    lengthTemplateSeries = templateSeries[0].size();

    cout <<"tamanhos " << lengthMySeries << "  e " << lengthTemplateSeries << endl;


    //aloca linhas
    dtw.resize(lengthMySeries);

    //aloca as colunas da matriz
    for(int i = 0; i < lengthMySeries; i++)
    {   //tamanho de cada serie do template
        dtw[i].resize(lengthTemplateSeries);
    }

    //inicia linhas com distancia ate o ponto
    //zero
    for(int i = 0; i < lengthMySeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtw[i][0] = 999;

    }


    //tamanho da template serie
    for(int i = 0; i < lengthTemplateSeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtw[0][i] = 999;
    }


    list<double>::iterator it1, it2;

    it1 = mySeries[5].begin();

    for(int i = 1; i < lengthMySeries -1; i++, it1++)
    {
        it2 = templateSeries[0].begin();

        for(int j = 1; j < lengthTemplateSeries; j++, it2++)
        {

           // cout <<"recebendo: " << fabs(*it1 - *it2) << endl;
            //cout << "exc: " << myMin(dtw[i-1][j], dtw[i][j-1], dtw[i-1][j-1]) << endl;
            //cout <<"i e j: " << i <<" "<< j << endl;


            dtw[i][j] = fabs(*it1 - *it2) + myMin(dtw[i-1][j], dtw[i][j-1], dtw[i-1][j-1]);
            printf("lendo: %lf\n", dtw[i][j]);
        }
    }

    cout << "retornando: " << dtw[lengthMySeries-2][lengthTemplateSeries-2]<< endl;

    //return dtw[lengthMySeries][lengthTemplateSeries];

    return 1.0;


}


//Funcoes auxiliares
double myMin(double a, double b, double c)
{
    return min(min(a, b), c);
}
