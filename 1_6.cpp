//
// Created by nikita on 06.07.19.
//

#include <fstream>
#include <iostream>
#include <vector>

void matrixPrinter(std::vector<std::vector<int> > matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void swapQuad(std::vector<std::vector<int> > & matrix, int i, int j, int N){
    int x1, y1, x2, y2, x3, y3, x4, y4, p1, p2, p3, p4;
    y1 = i;
    x1 = j;
    y2 = x1;
    x2 = N - 1 - y1;
    y3 = x2;
    x3 = N - 1 - y2;
    y4 = x3;
    x4 = N - 1 - y3;
    p1 = matrix[y1][x1];
    p2 = matrix[y2][x2];
    p3 = matrix[y3][x3];
    p4 = matrix[y4][x4];
    matrix[y2][x2] = p1;
    matrix[y3][x3] = p2;
    matrix[y4][x4] = p3;
    matrix[y1][x1] = p4;
}

int main(){
    int N;
    std::cin >> N;
    std::vector<std::vector<int> > matrix;
    std::vector<int> emptyVector;
    //std::ifstream fin("input.txt");
    for (int i = 0; i < N; i++){
        matrix.push_back(emptyVector);
        for (int j = 0; j < N; j++){
            int num;
            std::cin >> num;
            matrix[i].push_back(num);
        }
    }

    for (int i = 0; i < matrix.size() / 2; i++){
        for (int j = 0; j < matrix[0].size() / 2; j++){
            swapQuad(matrix, i, j, N);
        }
    }

    if (N % 2 == 1){
        int j = N / 2;
        for (int i = 0; i < N / 2; i++){
            swapQuad(matrix, i, j, N);
        }
    }

    matrixPrinter(matrix);
    return 0;
}