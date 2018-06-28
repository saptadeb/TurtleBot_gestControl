//includes
#include <ros/ros.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include <sys/stat.h>
#include <string>
#include <sstream>

#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/PCLPointCloud2.h>
#include <pcl/conversions.h>
#include <pcl_ros/transforms.h>
#include <pcl/filters/voxel_grid.h>
#include "pfh_shape_reco.h"
#include "math.h"
#include <chrono>
#include <thread>
#include <pcl/features/normal_3d.h>
#include <pcl/pcl_base.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <string>    
#include <stdlib.h>

#include <pcl/filters/crop_box.h>

using namespace std;

/*
TODO
a check on gesture number, to prevent silly mistakes
conditional filtering on z axis (understnading the different axes)
write a readme
*/

string hme = "/home/fdai5587/ws/testdata";

template <typename T>
string ntos(T pNumber){
	ostringstream oOStrStream;
  	oOStrStream << pNumber;
  	return oOStrStream.str();
}

void maked(string d, int n){
  	string ds = d + ntos(n);
  	const char * dsc = ds.c_str();
  	int dsd = mkdir(dsc, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

void tohome(){
	int dd;
	const char * hh = hme.c_str();
  	dd = chdir(hh);
}

void dir(int a, int b, int c){
  	maked ("p", a);
  	string s = hme + "/p" + ntos(a);
  	const char * cs = s.c_str();
  	int dd;
  	dd = chdir(cs);  
  	//char the_path[256];
  	//getcwd(the_path, 255);
  	//cout<< the_path<<endl;

  	maked ("g", b);
  	string s1 = s + "/g" + ntos(b);
  	const char * cs1 = s1.c_str();
  	dd = chdir(cs1);
  	//getcwd(the_path, 255);
  	//cout<< the_path<<endl;

  	maked ("t", c);
  	string s2 = s1 + "/t" + ntos(c);
  	const char * cs2 = s2.c_str();
  	dd = chdir(cs2);
  	//getcwd(the_path, 255);
  	//cout<< the_path<<endl;
}

void save(int c, const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
	pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*input,pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2,*cloud);

	string pth = ntos(c) + ".pcd";
    const char * pch = pth.c_str();

	pcl::io::savePCDFileASCII (pth, *cloud);
  	//cout << "Saved " << cloud.points.size() << " data points to "<<cc<<".pcd.\n";
	//frame to pcd -- saving format -- p_person number_gesture class_try number_frame number(counter) 
}

void record(int p, int g, int t, const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
  	//p = person number, g = gesture class, t = try number
  	//start the timer 
  	//time_t now = time(0);
  	//frame counter set to zero
    int fc=0;
  	//while (timer<=2 secs and counter <=40)
    cout<<"------------------------------------------------\n";
    while (fc<=40){
      	float per = (fc*100.0)/40;
    	//print recording ---- (counter*100)/40 --- percent done
      	cout << "Recording now " << per << " percent done.\n";
    	//function save   
    	save (fc, input);
    	//counter ++
      	fc+=1;           
    } 
  	//print person number gesture class try_number done.. 
    cout << "------------------------------------------------\n";
    cout << "Recording done for->\nPerson: "<< p << "\nGesture Class: " << g << "\nAttempt: " << t << "\n";
    cout << "------------------------------------------------\n";
}


void cloud_cb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
	int dec = 1;
    while (dec == 1) {
    	string ans;
    	int pn, gc, tn;
    	//cout << "------------------------------------------------\n";
    	cout << "Do you want to start a new recording? (yes/no): ";
    	getline (cin, ans);
    	if (ans == "yes"){
      	cout << "------------------------------------------------\n";
      	cout << "Enter person number (1-10): "; 
      	cin >> pn;
      	cout << "Enter gesture class (1-4): "; 
      	cin >> gc;
      	cout << "Enter try number (1-10): "; 
      	cin >> tn;
  		  //make and change directory
  		  dir(pn,gc,tn);
      	//record
      	record(pn,gc,tn,input);
      }else if (ans == "no"){
      	cout << "------------------------------------------------\n";
      	cout << "ok Byee!\n";
      	cout << "------------------------------------------------\n";
      	ros::shutdown();
        dec=0;
      }else {
      	cout << "Enter 'yes' or 'no' (case sensitive).\n";
    	}
    	//change to home directory
    	tohome();
  	}
}

int main (int argc, char** argv){
  ros::init (argc, argv, "rns");
  ros::NodeHandle nh;

  //subscriber to callback
  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1, cloud_cb);

  ros::spin ();
}