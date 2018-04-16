#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "math.h"
#include <chrono>
#include <thread>


ros::Publisher pub;

void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud)
{
  
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  if(cloud->size() > 300) {//Mindestgröße der PC zur Berechnung des Deskriptors

    pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);

    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimation; 
    normal_estimation.setInputCloud (cloud);
    normal_estimation.setSearchMethod (kdtree);
    pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud< pcl::Normal>);
    normal_estimation.setRadiusSearch (_normalRadius);//_normalRadius muss angepasst werden!
    normal_estimation.compute (*normals);

    PFHShapeReco<pcl::PointXYZ> pfh;
    pfh.ComputePFH(0.5, cloud, normals);//Berechnung des Deskriptors 
    for(int i = 0; i < 625; i++){//_histSize muss auf 625 gesetzt werden für diesen Deskriptor
      float f = pfh.GetObjectModel()[i];//Extraktion und Schreiben jedes Wertes in eine Datei
    }
  }

  // Create a container for the data.
  sensor_msgs::PointCloud2 output;

  // Do data processing here...
  output = *cloud;

  // Publish the data.
  pub.publish (output);
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "tc");
  ros::NodeHandle nh;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1, cloud_cb);



  // Create a ROS publisher for the output point cloud
  pub = nh.advertise<sensor_msgs::PointCloud2> ("output", 1);

  // Spin
  ros::spin ();
}