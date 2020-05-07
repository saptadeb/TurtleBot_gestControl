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
conditional filtering on z axis (understanding the different axes)
write a readme
*/

string ans;
int s=0, fc=0, flag=0, nframes=100;
int pn=0, gc=0, tn=0;
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
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

int startpage(){
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
    fc+=1;
  }else if (ans == "no"){
    cout << "------------------------------------------------\n";
    cout << "ok Byee!\n";
    cout << "------------------------------------------------\n";
    s=1;
  }else {
    cout << "Enter 'yes' or 'no' (case sensitive).\n";
  }
}

void cldcb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
  //cout<<"to save"<<endl;
  if (fc==0){
    startpage();
  }
  else if (fc>0 && fc<=40){
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*input,pcl_pc2);
    pcl::fromPCLPointCloud2(pcl_pc2,*cloud);
    
    string pth = ntos(fc) + ".pcd";

    pcl::io::savePCDFileASCII (pth, *cloud);
    float per = (fc*100.0)/40;
    //print recording ---- (counter*100)/40 --- percent done
    cout << "Recording now " << per << " percent done.\n";
    fc+=1;
  }
  else {
    fc=0;
    
    cout << "------------------------------------------------\n";
    cout << "Recording done for->\nPerson: "<< pn << "\nGesture Class: " << gc << "\nAttempt: " << tn << "\n";
    cout << "------------------------------------------------\n";    

    tohome();
  }
}

int main (int argc, char** argv){
  //cout<<flag<<endl;
  ros::init (argc, argv, "rns");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1000, cldcb);
  if (s==1)
  {
    ros::shutdown();
  }
  //cout<<flag<<endl;
  //flag=0;
  //cout<<flag<<endl;
  //int dec = 1;
  //string ans;
  //int pn, gc, tn;


  ros::spin ();


}
