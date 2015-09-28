//
//  SquareModel.h
//  squareModel
//
//  Created by sonir on 9/3/15.
//
//

#ifndef __squareModel__SquareModel__
#define __squareModel__SquareModel__

//Screen Setup
#define SC_W 1024
#define SC_H 768
#define HEADER_MARGIN 320
#define INTERVAL_NODE 100
#define LINE_HEIGHT 15
#define LEFT_MARGIN 150
#define SPACER 40

#include <stdio.h>
#include <vector>
#include "slAppManager.h"
#include "Model.h"
#include "slMetro.h"
#include "slNotice.h"


class SquareModel : public slAppManager, public slObserver {
    
    public:
        SquareModel();
        void setup();
        void update();
        void draw();
        void calcAvg();
        void event(event_type tag, void *data){
            int *pnum = (int *)data;
            metro->set( (CLOCK_INTERVAL / (float)*pnum)*CLOCK_INCREASING_FIX );
            
        }


        Model model;
        slMetro *metro;
        slNotice *notice;
        float pool_avg;
    
    
};

#endif /* defined(__squareModel__SquareModel__) */
