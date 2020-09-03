//
//  DE.hpp
//  search
//
//  Created by WU,MENG-TING on 2020/8/7.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef DE_hpp
#define DE_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>

#include "Ackley.hpp"

using namespace std;

class DE{
public:
    DE();
    DE(int gen, int NP, double F, double Cr, double L, double H, int Dim);
    double Fitness(int dim,vector<double> p){return ack::function(dim,p);}
    void Ackley();
    void Initialization();
    vector<vector<double> > get_random_v(int t);
    vector<double> get_donor_v(int t,vector<vector<double> > random_v);
    vector<double> get_trial_v(vector<double> v, int t);
    void Check_Boundaries();
    void Select(int i);
    void Update_Best(int i);
    double get_result_value(int iter){return result_value[iter];}
    vector<vector<double> > get_result(){return result;}
private:
    int Gen;
    int NP;
    double F; //[0,2]
    double Cr; //[0,1]
    double L; //-30
    double H; //30
    int Dim;
    vector<vector<double> > X;
    vector<double> X_value;
    vector<vector<double> > V;
    vector<vector<double> > U;
    vector<vector<double> > Next_Gen;
    vector<double> Next_Gen_value;
    vector<double> best;
    double best_value;
    vector<vector<double> > result;
    vector<double> result_value;
};


#endif /* DE_hpp */
