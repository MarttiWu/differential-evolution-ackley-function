//
//  main.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/7/19.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "execute.hpp"

using namespace std;

void prompt(const int Algo,const int runs,const int iterations);

int main(int argc, const char * argv[]) {
    const string algo = argv[1];
    const int runs = stoi(argv[2]);
    const int iterations = stoi(argv[3]);
    string filename= argv[4];
    cout<<"filename: "<<filename<<endl;
    const int population = stoi(argv[5]);
    const double F = stod(argv[6]);
    const double Cr = stod(argv[7]);
    const double L = stod(argv[8]);
    const double H = stod(argv[9]);
    const int dim = stoi(argv[10]);
    
    if (algo=="de"){
        prompt(1, runs, iterations);
        execute(1, runs, iterations, filename, population, F, Cr, L, H, dim);
    }
    else{
        cerr<<"No such algorithm!"<<endl;
    }
    return 0;
}


void prompt(const int Algo,const int runs,const int iterations){
    cout<<"Problem: Ackley's Function"<<endl;
    cout<<"----------------------------------------"<<endl;
    switch (Algo) {
        case 1:
            cout<<"Differential Evolution Algorithm:"<<endl;
            break;
        default:
            break;
    }
    cout<<"Runs: "<<runs<<endl;
    cout<<"Generations: "<<iterations<<endl;
    cout<<"----------------------------------------"<<endl;
}
