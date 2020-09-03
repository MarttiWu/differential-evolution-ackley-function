//
//  Ackley.hpp
//
//  Created by WU,MENG-TING on 2020/7/29.
//  Copyright © 2020 WU,MENG-TING. All rights reserved.
//

#ifndef Ackley_hpp
#define Ackley_hpp

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

//using namespace std;
const double a = 20, b = 0.2, c =2*M_PI;

namespace ack {
double function(const int dim,const std::vector<double> x);
}


#endif /* Ackley_hpp */
