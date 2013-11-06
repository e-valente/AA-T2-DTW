#include "dtw.h"

using namespace std;
Series mySeries;
Series templateSeries;
DTWMatrix dtwmatrix;

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

void DTW()
{
    int myBestClass;
    double myMinDbl, myDbl;
    int totalHits, correctClass;
    list<double>::iterator it;


    totalHits = 0;

    //series a serem testadas
    for(int k = 0; k < 500; k++)
    {
        myMinDbl = INFINITY;

        //series templates
        for(int i = 0; i < templateSeries.size() -1; i++)
        {
            myDbl = calcDTW(k, i);
            if(myDbl < myMinDbl)
            {
                it = templateSeries[i].begin();
                myBestClass = *it;
                //cout << "mybest class rcebendo: " << myBestClass << endl;
                myMinDbl = myDbl;
            }

        }
        it = mySeries[k].begin();
        correctClass = *it;

       if(myBestClass == correctClass)totalHits++;
       else cout << " mybest class: " << myBestClass << " corretct class: " << correctClass << "mindbl " << myMinDbl << endl;

    }

   cout <<"Total de acertos: " << totalHits << endl;
   cout << " mybest class: " << myBestClass << " corretct class: " << correctClass << "mindbl " << myMinDbl << endl;
}

double calcDTW(int index_x, int index_y)
{
    int lengthMySeries, lengthTemplateSeries;

    //testaremos só a primeira séries
    //TAMANHO ESTA DANDO ERRADO
    lengthMySeries = mySeries[index_x].size();
    lengthTemplateSeries = templateSeries[index_y].size();

    //cout <<"tamanhos " << lengthMySeries << "  e " << lengthTemplateSeries << endl;
   //cout <<"index x e y " << index_x << " " << index_y << endl;


    //aloca linhas
    dtwmatrix.resize(lengthMySeries);

    //aloca as colunas da matriz
    for(int i = 0; i < lengthMySeries; i++)
    {   //tamanho de cada serie do template
        dtwmatrix[i].resize(lengthTemplateSeries);
    }

    //inicia linhas com distancia ate o ponto
    //zero
    for(int i = 1; i < lengthMySeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtwmatrix[i][0] = INFNT;

    }


    //tamanho da template serie
    for(int i = 1; i < lengthTemplateSeries; i++)
    {
        //distancia de qualquer ponto
        // até o ponto zero é inf
        dtwmatrix[0][i] = INFNT;
    }

    dtwmatrix[0][0] = 0.0;

    list<double>::iterator it1, it2;

    it1 = mySeries[index_x].begin();
    it1++;




    for(int i = 1; i < lengthMySeries; i++, it1++)
    {
        it2 = templateSeries[index_y].begin();
        it2++;

        for(int j = 1; j < lengthTemplateSeries; j++, it2++)
        {

            // cout <<"recebendo: " << fabs(*it1 - *it2) << endl;
            //cout << "exc: " << myMin(dtw[i-1][j], dtw[i][j-1], dtw[i-1][j-1]) << endl;
            //cout <<"it1 e it2 e j: " << *it1 <<" "<< *it2 << endl;


            dtwmatrix[i][j] = ((*it1 - *it2) * (*it1 - *it2)) + myMin(dtwmatrix[i-1][j], dtwmatrix[i][j-1], dtwmatrix[i-1][j-1]);
            //printf("lendo: %lf\n", dtwmatrix[i][j]);
        }
    }

    //cout << "retornando: " << dtwmatrix[lengthMySeries-1][lengthTemplateSeries-1]<< endl;

    return dtwmatrix[lengthMySeries - 1][lengthTemplateSeries - 1];


    //retorna a classe calculada

    //return 1.0;


}


//Funcoes auxiliares
double myMin(double a, double b, double c)
{
    return min(min(a, b), c);
}
