#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/pfh.h>

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
#include <iostream>
#include <fstream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <string>
#include <stdio.h>     
#include <stdlib.h>  

#include <vector>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Int32MultiArray.h"
#include "fullpkg/mesg.h"

#include <pcl_ros/point_cloud.h>

#include <pcl/filters/conditional_removal.h>
 #include <pcl/visualization/cloud_viewer.h>

/*TODO -- clear the sea of unused include files*/

template class PFHShapeReco<pcl::PointXYZ>;

ros::Publisher hist;
ros::Publisher sc;

std_msgs::Float32MultiArray msg;

void cloud_cb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
    //ROS_INFO("callback");
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*input,pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr smallcloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr boxcloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2,*cloud);
    
    pcl::VoxelGrid<pcl::PointXYZ> voxel_grid;
    voxel_grid.setInputCloud (cloud);
    voxel_grid.setLeafSize (0.01f, 0.01f, 0.01f);
    voxel_grid.filter(*smallcloud); 

    //pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
    //viewer.showCloud (smallcloud);
    //while (!viewer.wasStopped ())
    //{
    //}

    sc.publish (smallcloud);

    //can add a conditionalRemover filter here and save in boxcloud
    /*
    ///// build the condition
    pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ> ());
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::GT, 0.10)));
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::LT, 0.20)));

    ///// build the filter
    pcl::ConditionalRemoval<pcl::PointXYZ> condrem (range_cond);
    condrem.setInputCloud (smallcloud);
    condrem.setKeepOrganized(true);
    condrem.filter (*boxcloud);
    */
    msg.data.clear();

    if(smallcloud->size() > 3) {        
        //ROS_INFO("small cloud size %lu", smallcloud->size());
        //ROS_INFO("boxcloud size %lu", boxcloud->size());
        pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);
        pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimation; 
        normal_estimation.setInputCloud (smallcloud);
        normal_estimation.setSearchMethod (kdtree);
        pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud< pcl::Normal>);
        normal_estimation.setRadiusSearch (0.03);  // maybe bigger?
        normal_estimation.compute (*normals);
        PFHShapeReco<pcl::PointXYZ> pfh;
        pfh.ComputePFH(0.5, smallcloud, normals);
        std::vector<long double> arr; 
        long double f = 0;
        for(int i = 0; i < 625; i++){
            f = pfh.GetObjectModel()[i];
            arr.push_back(f);
        }
        std::vector<long double>::const_iterator itr, end(arr.end());
        for(itr = arr.begin(); itr!= end; ++itr) {
          msg.data.push_back(*itr); 
        }
        hist.publish (msg);
        //ROS_INFO("arr size");
    }  
}

int main (int argc, char** argv)
{
  ros::init (argc, argv, "tc");
  ros::NodeHandle nh;

  msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
  msg.layout.dim[0].size = 625;
  msg.layout.dim[0].stride = 1;
  msg.layout.dim[0].label = "x"; 

  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1000, cloud_cb);

  sc = nh.advertise<pcl::PointCloud<pcl::PointXYZ>> ("smallCloud", 1000);
  hist = nh.advertise<std_msgs::Float32MultiArray>("arr", 1000);

  ros::spin ();
}