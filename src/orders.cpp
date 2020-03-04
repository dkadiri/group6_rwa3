#include <../include/group6_rwa2/orders.h>
#include <ros/ros.h>


Orders::Orders() {

	orders_subscriber = node.subscribe(
			"/ariac/orders", 10,
			&MyCompetitionClass::order_callback, &comp_class);
}


void Orders::order_callback(const osrf_gear::Order::ConstPtr & order_msg) {
	ROS_INFO_STREAM("Received order:\n" << *order_msg);
	received_orders_.push_back(*order_msg);
}


