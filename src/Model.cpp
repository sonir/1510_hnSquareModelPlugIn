//
//  Model.cpp
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#include "Model.h"

using namespace std;

Model::Model(){

    
    //Init notifier as singleton
    notice = slNotice::instance();
    
    for(int i=0;i<GRID_NUM_INIT;i++){
        
        Grid g;
        grids.push_back(g);
        
    }

    for(int i=0;i<ANT_NUM_INIT;i++){
        
        Ant a(this);
        ants.push_back(a);
        
    }
    
}

void Model::update(){
    
    behaveAnts();
    gridsRecovery();
    bornAndDeath();
    
}


void Model::behaveAnts(){
    
    
    for(int i=0; i<ants.size();i++){
        
        ants[i].move();
        ants[i].eat();
        
    }
    
    
}


void Model::gridsRecovery(){
    
    for(int i=0;i<grids.size();i++){
        
        grids[i].recovery();
        
    }
    
}

void Model::bornAndDeath(){
    
    for(int i=0; i<ants.size();i++){

        if(ants[i].pool>=BORN_LINE_OF_POOL){
            
            //Decreases it's pool
            ants[i].pool *= 0.5;
            Ant a(this);
            a.pool = ants[i].pool;
            ants.push_back(a); //Add new offspring
            
            //Notification the born event to square for changing clock time
            int num = ants.size();
            notice->notify("BORN" , &num);
            
        }else if (ants[i].pool<=DEARH_LINE_OF_POOL){
            
            ants[i].death = true;
            
        }
        
    }

    //Remove flg agents
    auto it = ants.begin();
    while (it != ants.end()) {
        if (it->death == true) {
            it = ants.erase(it);
        } else ++it;
    }

    
}

