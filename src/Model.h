//
//  Model.h
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#ifndef __squareModel__Model__
#define __squareModel__Model__

#include <stdio.h>
#include <iostream>
#include <vector>
#include "slNotice.h"
#include "Ant.h"
class Ant;

class Grid {
    
public:
    void decrease(int num){
        
        resource-=num;
        if(resource<0)resource=0;
        
    }
    void recovery(){
        
        resource+=SUGAR_RECOVERY_NUM;
        if(resource>SUGAR_INIT)resource=SUGAR_INIT;
        
    }
    int resource=ofRandom(SUGAR_INIT+1);
    
};




class Model {
    
    public:
        Model();
        void behaveAnts();
        void gridsRecovery();
        void update();
        void bornAndDeath();
        std::vector<Grid>grids;
        std::vector<Ant>ants;
        slNotice *notice;
    
};


#endif /* defined(__squareModel__Model__) */
