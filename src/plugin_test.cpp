#include "plugin_test.h"
#include <pluginlib/class_list_macros.h>


//register this planner as a BaseGlobalPlanner plugin
PLUGINLIB_EXPORT_CLASS(plugin_test::PluginTest, nav_core::BaseGlobalPlanner)

using namespace std;

//Default Constructor
namespace plugin_test {

    PluginTest::PluginTest (){
        ROS_INFO("PluginTest constructor called");
    }

    PluginTest::PluginTest(std::string name, costmap_2d::Costmap2DROS* costmap_ros){
        initialize(name, costmap_ros);
    }


    void PluginTest::initialize(std::string name, costmap_2d::Costmap2DROS* costmap_ros){

    }

    bool PluginTest::makePlan(const geometry_msgs::PoseStamped& start, const geometry_msgs::PoseStamped& goal,  std::vector<geometry_msgs::PoseStamped>& plan ){
        ROS_INFO("PluginTest makePlan() called");
        plan.push_back(start);
        PluginTest::addPointToPath(plan, -1, 1);
        plan.push_back(goal);
         
        return true;
    }

    void PluginTest::addPointToPath(std::vector<geometry_msgs::PoseStamped>& plan, double x, double y) {
        geometry_msgs::PoseStamped pose;
        pose.pose.position.x = x;
        pose.pose.position.y = y;
        pose.pose.position.z = 0.0;
        pose.pose.orientation.x = 0.0;
        pose.pose.orientation.y = 0.0;
        pose.pose.orientation.z = 0.0;
        pose.pose.orientation.w = 1.0;

        plan.push_back(pose);
    }
};
