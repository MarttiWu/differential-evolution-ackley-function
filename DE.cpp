//
//  DE.cpp
//  search
//
//  Created by WU,MENG-TING on 2020/8/7.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "DE.hpp"


DE::DE(){
    
}

DE::DE(int Gen, int NP, double F, double Cr, double L, double H, int Dim):Gen(Gen),NP(NP),F(F),Cr(Cr),L(L),H(H),Dim(Dim){
    vector<vector<double> > temp1(NP,vector<double>(Dim,0));
    vector<double> temp2(NP,0);
    vector<double> temp3(Dim,0);
    vector<vector<double> > temp4(Gen,vector<double>(Dim,0));
    vector<double> temp5(Gen,0);
    X = temp1;
    X_value = temp2;
    V = temp1;
    U = temp1;
    Next_Gen = temp1;
    Next_Gen_value = temp2;
    best = temp3;
    best_value = 100.0;
    result = temp4;
    result_value = temp5;
}

void DE::Ackley(){
    Initialization();
    int gen=0;
    while(gen<Gen&&best_value>0){
        for (int i=0;i<NP;i++){
            vector<vector<double> > random_v = get_random_v(i);
            V[i] = get_donor_v(i,random_v);
            U[i] = get_trial_v(V[i],i);
            Select(i);
            Update_Best(i);
        }
        X = Next_Gen;
        X_value = Next_Gen_value;
        result[gen] = best;
        result_value[gen] = best_value;
        gen++;
    }
}

void DE::Initialization(){
    for (int i=0;i<X.size();i++){
        for (int j=0;j<X[0].size();j++){
            //[-30,30]
            X[i][j] = (((double)rand())/RAND_MAX-0.5)*(H-L);
        }
        X_value[i] = Fitness(Dim,X[i]);
        if (X_value[i]<best_value){
            best = X[i];
            best_value = X_value[i];
        }
    }
    
}

vector<double> DE::get_donor_v(int t,vector<vector<double> > random_v){
    vector<double> donor_v(Dim);
    for (int i=0;i<Dim;i++){
        donor_v[i] = random_v[0][i] + F*(random_v[1][i]-random_v[2][i]);
    }
    return donor_v;
}

vector<vector<double> > DE::get_random_v(int t){
    vector<int> cards(NP-1);
    for (int i=0;i<NP;i++){
        if (i<t)
            cards[i] = i;
        else if (i>t)
            cards[i-1] = i;
    }
    random_shuffle(cards.begin(),cards.end());
    vector<vector<double> > random_v(3,vector<double>(Dim,0));
    for (int i=0;i<3;i++){
        random_v[i] = X[cards[i]];
    }
    return random_v;
}

vector<double> DE::get_trial_v(vector<double> v, int t){
    vector<double> U(Dim);
    for (int i=0;i<Dim;i++){
        double r = (((double)rand())/RAND_MAX)*2;
        if (r<=Cr||t==i){
            //Check Boundaries
            if (v[i]>H||v[i]<L){
                U[i] = (((double)rand())/RAND_MAX-0.5)*(H-L);
            }
            else
                U[i] = v[i];
        }
        else
            U[i] = X[t][i];
    }
    return U;
}

void DE::Select(int i){
    double new_value = Fitness(Dim,U[i]);
    if (new_value<X_value[i]){
        Next_Gen[i] = U[i];
        Next_Gen_value[i] = new_value;
    }
    else{
        Next_Gen[i] = X[i];
        Next_Gen_value[i] = X_value[i];
    }
}

void DE::Update_Best(int i){
    if (X_value[i]<best_value){
        best_value = X_value[i];
        best = X[i];
    }
}
