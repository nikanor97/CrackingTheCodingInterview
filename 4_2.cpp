//
// Created by nikita on 06.07.19.
//

#include <vector>
#include <iostream>

typedef std::vector<std::vector<int> > Matrix;

void matrixPrinter(Matrix matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


void DFS(int & v, int & timer, std::vector<int> & colors, std::vector<int> & timeIn,
         std::vector<int> & timeOut, Matrix & matrix){
    colors[v] = 1;
    timeIn[v] = timer++;
    for (int u = 0; u < matrix[v].size(); u++){
        if (matrix[v][u] == 1 and colors[u] == 0){
            DFS(u, timer, colors, timeIn, timeOut, matrix);
        }
    }
    timeOut[v] = timer++;
    colors[v] = 2;
}


int main(){
    const int INF = 10000;
    Matrix matrix;
    int N, timer(0), nodeFrom, nodeTo;
    std::cin >> N >> nodeFrom >> nodeTo;
    std::vector<int> emptyVector, colors(N,0), timeIn(N, INF), timeOut(N, INF);
    for (int i = 0; i < N; i++){
        matrix.push_back(emptyVector);
        for (int j = 0; j < N; j++){
            int num;
            std::cin >> num;
            matrix[i].push_back(num);
        }
    }

    //matrixPrinter(matrix);

    DFS(nodeFrom, timer, colors, timeIn, timeOut, matrix);

    /*for (int i = 0; i < N; i++){
        std::cout << timeIn[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < N; i++){
        std::cout << timeOut[i] << " ";
    }*/

    if (colors[nodeTo] == 2){
        std::cout << "Route exists";
    }
    else{
        std::cout << "There is no route";
    }

    return 0;
}