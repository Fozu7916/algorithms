#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

int main(){

auto start_time = std::chrono::high_resolution_clock::now();
std::ifstream in;
in.open("input.txt");


int E = 0;
int N = 0;
int a = 0;

in >> E;
in >> N;

int currentPoint = 0;
std::vector<int> points;

for(int i = 0; i < N; i++){
    in >> a;
    points.push_back(a);
}

// Замер времени
auto end_time1 = std::chrono::high_resolution_clock::now();
auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time1 - start_time);
std::cout << "\nВремя выполнения: " << duration1.count() << " мс" << std::endl;



for(int i = 1; i <= N; i++){
    a = points[i-1];
    int delta = (currentPoint - i) + a;

    if(E - delta - a >= 0){
        if( delta > 0){
            E = E + delta;
            currentPoint = i;
        }
    }

}

int start = (currentPoint == 0) ? 1 : currentPoint;
for(int i = start; i <= N; i++){
    a = points[i-1];
    int delta = (currentPoint - i) + a;

    if(E - delta - a >= 0){
        if( delta == 0){
            currentPoint = i;
        }
    }
}

start = (currentPoint == 0) ? 1 : currentPoint;
for(int i = start; i <= N; i++){
    a = points[i-1];
    int delta = (currentPoint - i) + a;

    if(E - delta - a >= 0){
        if( delta < 0 and E + delta > 0){
            E = E + delta;
            currentPoint = i;
        }
    }
}



if(currentPoint < N){
    std::cout<< "-1";
} else {
    std::cout<<E-1;
}

// Замер времени
auto end_time = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
std::cout << "\nВремя выполнения: " << duration.count() << " мс" << std::endl;


}