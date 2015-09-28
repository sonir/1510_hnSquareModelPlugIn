
//
//  SquareModel.cpp
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#include "SquareModel.h"

SquareModel::SquareModel(){
    
    notice = slNotice::instance();
    notice->addEvent("BORN",this);
    
}


void SquareModel::setup(){
    
    metro = new slMetro(CLOCK_INTERVAL);
    
}

void SquareModel::update(){
    

    if(metro->alart()){
        model.update();
        calcAvg();
    }
    
    
}

void SquareModel::draw(){
    
    //Draw param
    ofSetColor(255);
    ofDrawBitmapString("AVG Pool: "+ofToString(pool_avg)+" / Born Target:"+ofToString(BORN_LINE_OF_POOL),20,20);
    
    //Draw grids
    for(int i=0;i<model.grids.size();i++){

        float bright = (float)model.grids[i].resource/SUGAR_INIT;
        ofSetColor(255*(1.0-bright));
        ofDrawBitmapString(ofToString(i), LEFT_MARGIN+(i*INTERVAL_NODE), HEADER_MARGIN);
        
    }
    
    //Draw ants
    for(int i=0;i<model.ants.size();i++){
        
        Ant *a = &model.ants[i];
        color_t color = model.ants[i].color;
        ofSetColor(color.red,color.green,color.blue);
        ofDrawBitmapString(ofToString(i), LEFT_MARGIN+(a->position*INTERVAL_NODE), HEADER_MARGIN+LINE_HEIGHT+(i*LINE_HEIGHT));
        
    }
    
}


void SquareModel::calcAvg(){
    
    pool_avg = 0.0f;
    
    int num = model.ants.size();
    for(int i=0; i<num; i++){
        
        pool_avg+=model.ants[i].pool;
        
    }
    
    pool_avg /= (float)num;
    
}