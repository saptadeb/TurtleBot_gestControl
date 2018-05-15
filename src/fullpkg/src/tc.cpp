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

template class PFHShapeReco<pcl::PointXYZ>;

ros::Publisher hist;

void cloud_cb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
    ROS_INFO("callback");
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(*input,pcl_pc2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromPCLPointCloud2(pcl_pc2,*cloud);
    if(cloud->size() > 300) {
        ROS_INFO("if loop");
        pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);
        ROS_INFO("1");
        pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimation; 
        ROS_INFO("2");
        normal_estimation.setInputCloud (cloud);
        ROS_INFO("3");
        normal_estimation.setSearchMethod (kdtree);
        ROS_INFO("4");
        pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud< pcl::Normal>);
        ROS_INFO("5");
        normal_estimation.setRadiusSearch (0.03);
        ROS_INFO("6");
        normal_estimation.compute (*normals);
        ROS_INFO("7");
        PFHShapeReco<pcl::PointXYZ> pfh;
        ROS_INFO("8");
        pfh.ComputePFH(0.5, cloud, normals);
        ROS_INFO("9");
        std_msgs::Float32MultiArray arr;
        for(int i = 0; i < 625; i++){
            float f = pfh.GetObjectModel()[i];
            arr.data.push_back(f);
        }
        hist.publish (arr);
    }
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "tc");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1, cloud_cb);

  // Create a ROS publisher for the output point cloud

  hist = nh.advertise<std_msgs::Float32MultiArray>("arr", 10);
  //cld = nh.advertise<sensor_msgs::PointCloud2>("output", 1);

  // Spin
  ros::spin ();
}