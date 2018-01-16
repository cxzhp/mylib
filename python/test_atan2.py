#!/usr/bin/env python
#-*-coding:utf-8 -*-


import math

if __name__ == '__main__':
##角度=弧度*180.0f/PI
##弧度=角度*PI/180.0f



    x0 = 1
    y0 = 3
    
    x1 = 5
    y1 = 6
    
    
    theta = math.atan2( y1-y0, x1-x0)
    
    
    x0_ = x0 * math.cos(theta) + y0 * math.sin(theta)
    y0_ = y0 * math.cos(theta) - x0 * math.sin(theta)   #may be is 0?
    
    
    x1_ = x1 * math.cos(theta) + y1 * math.sin(theta)
    y1_ = y1 * math.cos(theta) - x1 * math.sin(theta)   #may be is 0?
    


    print "x0:",x0, "y0:",y0
    print "x1:",x1, "y1:",y1

    print "x0_:",x0_, "y0_:",y0_
    print "x1_:",x1_, "y1_:",y1_


    
    x2_ = abs(x1_ + x0_)/2 + x0
    y2_ = 3
    
    
    x2 = x2_ * math.cos( -theta) + y2_ * math.sin( -theta)
    y2 = y2_ * math.cos( -theta) - x2_ * math.sin( -theta)
    
    
    print "x2:",x2, "y2:",y2

    thetaNormalVector = theta + math.radians(90)

    print "theta:",math.degrees(theta)
    print "thetaNormalVector:",math.degrees(thetaNormalVector)



#x0__ = -1 * ( (x1_ - x0_)/2 );
#y0__ = y0_   #may be is 0?
#
#
#x1__ = (x1_ - x0_)/2;
#y1__ = y1_   #may be is 0?
#
#x2__ = 0
#y2__ = 10




##start (0,0)
##end(2,1)
#    x = 2-0
#    y = 1-0
#
##start (0,0)
##end(0,1)
#    x = 0
#    y = 1-0
##start (0,0)
##end(1,0)
#    x = 1-0
#    y = 0
#
#    radians = math.atan2(y,x) #弧度
#    degree = math.degrees(radians)#角度
#    #radians(x)#弧度
#    print "atan2(",x,",",y,")" , radians, degree 
#
#    print "10 radians:" , math.degrees(10)
#    print "1.3 radians:" , math.degrees(1.3)
#    print "10 degrees:" , math.radians(10)
#    print "30 degrees:" , math.radians(30)
#    print "50 degrees:" , math.radians(50)
#    print "60 degrees:" , math.radians(60)
#    print "0.001585 radians:" , math.degrees(0.001585)
#    print "1 degrees:" , math.radians(1)
#    print "0.1 degrees:" , math.radians(0.1)
#
#    print "x0:" , math.radians(1.166527)
#    print "xx:" , math.radians(-6.23448)
#
#    radians_30 = math.radians(30)
#    tan_30 = math.tan(radians_30)
#
#    print "tan_30:",math.tan(math.radians(30))
#    print "tan_150:",-math.tan(math.radians(150))
#    print "tan_210:",-math.tan(math.radians(210))
#    print "tan_330:",math.tan(math.radians(330))
#    print "tan_330+360:",math.tan(math.radians(690))
#
#    print "tan_-10:",math.tan(math.radians(-10))
#    print "tan_-44:",math.tan(math.radians(-44))
#    print "tan_129:",-math.tan(math.radians(129))
#
