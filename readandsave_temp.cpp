//includes
#include <ros/ros.h>


void save(take in string path value){

	//frame to pcd -- saving format -- p_person number_gesture class_try number_frame number(counter) 

}

void record(person_number gesture_class try_number){

	//start the timer 
	//frame counter set to zero
	//while (timer<=2 secs and counter <=40)
		//print recording ---- (counter/40)*100 --- percent done
		//function save		
		//counter ++

	//stop the timer
	//print person number gesture class try_number done.. 
}


void cloud_cb(const boost::shared_ptr<const sensor_msgs::PointCloud2>& input){
	//dec = 1
	//while (dec == 1)
		//ask do u wanna start or stop (start/stop)
		//if ans == start
			//take in person number -- gesture class -- try number 
			//function record
		//else if ans == stop
			//dec = 0
		//else
			//print Enter start or stop (case sensitive)

	

}

int main (int argc, char** argv)
{
  ros::init (argc, argv, "tc");
  ros::NodeHandle nh;

  //subscriber to callback
  ros::Subscriber sub = nh.subscribe ("/softkinetic_camera/depth/points", 1, cloud_cb);

  ros::spin ();
}