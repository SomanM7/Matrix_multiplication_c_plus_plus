#include <iostream>
#include <vector>
#include "Matrix.h"
#include <fstream>
#include <iterator>
#include <sstream>
using namespace std;

Matrix::Matrix(){

}


int Matrix::fill_from_file(char *path){

    ifstream infile(path);
    string line;

    if (!infile){
        cout << "file doesn't exist"<< "\n";
        return EXIT_FAILURE;
    }
    else{

    
    
    while (getline(infile, line)){
        vector<int> Tval;
        istringstream iss(line);

        int num;
        while (iss >> num){
            Tval.push_back(num);          // fills matrix with value from file
            C++;
        }

        _matrix.push_back(Tval);
        R++;
    }
    }

return 0;
}




// returns a value from the matrix
int Matrix::index(int row, int column){
    if(row > R-1 || column > C/R - 1 ){
        cout << "index out of range";
        return -1;
    }
    else{
        cout << _matrix[row][column];
    }
    
    return 0;
}



int Matrix::rows(){
    cout << R << "\n";                  //returns rows
    return 0;
}


int Matrix::columns(){                      //returns columns
    cout << C/R;
    return 0;
}

int Matrix::store_in_file(char *path){

    
    ofstream outfile(path);
    ostream_iterator<int> output_iterator(outfile, " ");
    for ( int j = 0 ; j < _matrix.size() ; j++ ) {
        copy(_matrix.at(j).begin(), _matrix.at(j).end(), output_iterator);
        outfile << '\n';
    }
        return 0;
}

 int Matrix::mult(Matrix *m,char *path){
    _mat2 = _matrix;
    
    m->fill_from_file(path);

    if (R != m->C/m->R){
        cout << "Vectors not the right size";
        return -1;
    }
    else{

        Rcount = m-> R;
        Ccount = m-> C/R;


       
        for(int i = 0; i<R;i++){
            for(int j = 0;j<C/R; j++){
                _matrix[i][j] = 0;
                for (int k = 0; k < C/R; k++){
                    _matrix[i][j] = _matrix[i][j] + m->_matrix[k][j] *  _mat2[i][k];
                    
                }
            }
        }
    }

    Rcount = R;
    Ccount = m->C/m->R;
    return 0;
 }

//multiplies matrix by scalar value
 int Matrix::mult(int val){
    for(int i = 0; i<R;i++){
        for(int j = 0;j<C/(R); j++){
           _matrix[i][j] *= val;
    }
    }
    Rcount = R;
    Ccount = C/R;
    return 0;
 }

int Matrix::add(Matrix *m,char *p){
    _mat2 = _matrix;
    
    m->fill_from_file(p);                            //matrix  matrix addition

    if (R != m->R || C != m->C ){
        cout << "Vectors not the same size";
        return -1;
    }
    
    else{
    for(int i = 0; i<R;i++){
        for(int j = 0;j<C/(R); j++){
           m->_matrix[i][j] = m->_matrix[i][j] + _mat2[i][j];
    }
    }
    _matrix = m->_matrix;
    }

    Rcount = R + 1;
    Ccount = C/R + 1;
    return 0;

}

//adds scalar to matrix
int Matrix::add(int val){

    for(int i = 0; i<R;i++){
        for(int j = 0;j < C/R; j++){
           _matrix[i][j] += val;
    }
    }

    Rcount = R + 1;
    Ccount = C/R + 1;
    return 0;
}

 

//prints matrix on console
void Matrix::print(){

    for(int i = 0; i<Rcount;i++){
        for(int j = 0;j < Rcount; j++){
          cout <<  _matrix[i][j] << " ";
    }
    cout << "\n";
    }

  
}






    

    
    