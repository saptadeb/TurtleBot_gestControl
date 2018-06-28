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
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>

using namespace std;


string hme = "/home/fdai5587/ws/testdata/p2/g2/t2";

template <typename T>
string ntos(T pNumber){
    ostringstream oOStrStream;
    oOStrStream << pNumber;
    return oOStrStream.str();
}

int main ()
{
    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    pcl::PointCloud<pcl::PointXYZ>::Ptr body(new pcl::PointCloud<pcl::PointXYZ>);
    int fc=1;
    int dd;
    const char * hh = hme.c_str();
    dd = chdir(hh);
    while (fc<=40){
        string pth = ntos(fc) + ".pcd";
        pcl::io::loadPCDFile (pth, *body);
        viewer.showCloud (body,"Cloud Viewer");
        fc+=1;
    }

    while (!viewer.wasStopped ())
    {
    }
    return 0;
}