//
// Created by nikita on 06.07.19.
//

#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > Matrix;

void matrixPrinter(Matrix matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main(){
    Matrix matrix;
    std::vector<int> emptyVector, badRows, badCols;
    int M, N;
    std::cin >> M >> N;
    for (int i = 0; i < M; i++){
        matrix.push_back(emptyVector);
        for (int j = 0; j < N; j++) {
            int num;
            std::cin >> num;
            if (num == 0){
                badCols.push_back(j);
                badRows.push_back(i);
            }
            matrix[i].push_back(num);
        }
    }
    for (int i = 0; i < badRows.size(); i++){
        for (int j =  0; j < N; j++){
            matrix[badRows[i]][j] = 0;
        }
    }
    for (int j = 0; j < badCols.size(); j++) {
        for (int i = 0; i < M; i++){
            matrix[i][badCols[j]] = 0;
        }
    }
    matrixPrinter(matrix);
    return 0;
}