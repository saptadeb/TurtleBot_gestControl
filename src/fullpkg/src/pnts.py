#! /usr/bin/env python

import roslib
import numpy as np
import rospy
import cv2
import sys, time
from sensor_msgs.msg import PointCloud2



class ellipse_detection:

    def __init__(self):
        self.image_sub = rospy.Subscriber("/softkinetic_camera/depth/points",PointCloud2,self.callback)

    def callback(self,data):

            img = self.bridge.imgmsg_to_cv2(data, "bgr8")



       # hL = cv2.getTrackbarPos('H Low','thresh')
       # sL = cv2.getTrackbarPos('S Low','thresh')
        vL = cv2.getTrackbarPos('V Low','thresh')
       # hH = cv2.getTrackbarPos('H High','thresh')
        sH = cv2.getTrackbarPos('S High','thresh')
        #vH = cv2.getTrackbarPos('V High','thresh')
      #  thresh = cv2.getTrackbarPos('thresh','thresh')
       # dili = cv2.getTrackbarPos('dilation','thresh')
       # erri = cv2.getTrackbarPos('errosion','thresh')
        ker= cv2.getTrackbarPos('kernel','thresh')
      
        kernel = np.ones((ker,ker),np.uint8)        
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        lower_hsv = np.array([0,0,vL])
        upper_hsv = np.array([255,sH,255])
        mask = cv2.inRange(hsv, lower_hsv, upper_hsv)
        
        res = mask
        res = cv2.erode(res,kernel,iterations = 2)
        res = cv2.dilate(res,kernel,iterations= 2)


        cv2.imshow('thresh1', mask)# remove this line(we don't need to show the output)
        cv2.imshow('mywindow', res)# remove this line(we don't need to show the output)
        cv2.waitKey(1)

    def getTrackValue(self, value):
        return value

def main(args):
    ed = ellipse_detection()
    rospy.init_node('ellipse_detection', anonymous=True)
    try:
        rospy.spin()
    except KeyboardInterrupt:
        print("Shutting down ellipse_detection")
    cv2.destroyAllWindows()

if __name__ == '__main__':
	main(sys.argv)
