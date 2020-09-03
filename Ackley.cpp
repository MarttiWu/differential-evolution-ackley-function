//
//  Ackley.cpp
//
//  Created by WU,MENG-TING on 2020/7/29.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#include "Ackley.hpp"


double ack::function(const int d,const std::vector<double> x){
    double p1=0.0,p2=0.0;
    for (int i=0;i<d;i++){
        p1+=pow(x[i],2);
        p2+=cos(c*x[i]);
    }
    p1/=d;
    p2/=d;
    return -a*exp(-b*pow(p1,0.5))-exp(p2)+a+exp(1.0);
}
