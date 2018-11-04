/***************************************************************************//**
 * @file example/WidgetPFD.cpp
 * @author  Marek M. Cel <marekcel@marekcel.pl>
 *
 * @section LICENSE
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * This file is part of QFlightInstruments. You can redistribute and modify it
 * under the terms of GNU General Public License as published by the Free
 * Software Foundation; either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Further information about the GNU General Public License can also be found
 * on the world wide web at http://www.gnu.org.
 *
 * ---
 *
 * Copyright (C) 2013 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef WIDGETPFD_CPP
#define WIDGETPFD_CPP
#endif
#include "WidgetPFD_wrapper.h"
#include "WidgetPFD.h"
#include "ui_WidgetPFD.h"
#include <pluginlib/class_list_macros.h>
#include <QStringList>
////////////////////////////////////////////////////////////////////////////////

rqt_pfd::WidgetPFDWrapper::WidgetPFDWrapper() :
    rqt_gui_cpp::Plugin( ),
    widget_(0)
{
    setObjectName("PFD");

}

////////////////////////////////////////////////////////////////////////////////

rqt_pfd::WidgetPFDWrapper::~WidgetPFDWrapper()
{
}

////////////////////////////////////////////////////////////////////////////////

void rqt_pfd::WidgetPFDWrapper::initPlugin(qt_gui_cpp::PluginContext& context)
{
// access standalone command line arguments
  QStringList argv = context.argv();
// create QWidget
  widget_ = new WidgetPFD();
    //_ui.setupUi(widget_);
    context.addWidget((QWidget*)widget_);


 //init rosnode and map nodeHandle object
    _nh = &(getNodeHandle());
    _rate = new ros::Rate(30); //30ms rate
   //Adding custom types for ROS data transmission
    qRegisterMetaType<QVector<float> >("QVector<float>");



    ros::NodeHandle nh = getNodeHandle();
    ROS_DEBUG("@connect with drone");
    /*SUBSCRIBERS*/
    //ros::Subscriber droneNavDataSub = nh.subscribe("/ardrone/navdata",1,&MainWindow::navDataCallback,this);
    //ROS_DEBUG("Subbed to navdata");
    ros::Subscriber testSub = nh.subscribe("/origin_boat/orientation",1,&rqt_pfd::WidgetPFDWrapper::orientationCallback,this);
    ros::Subscriber plateform_orientation = nh.subscribe("/test",1,&rqt_pfd::WidgetPFDWrapper::testCallback,this);
    ros::Subscriber pressure = nh.subscribe("/sensors/ext_pressure",1,&rqt_pfd::WidgetPFDWrapper::pressureCallback,this);
    ros::Subscriber altitude = nh.subscribe("/boat_plateform/position",1,&rqt_pfd::WidgetPFDWrapper::altitudeCallback,this);
    ROS_DEBUG("Subbed to test sub");
    //ros::Subscriber filterStateSub=getNodeHandle().subscribe("/ardrone/predictedPose",1,&MainWindow::autopilotFilterCallback,this);
    //ros::Subscriber goalStatusSub = nh.subscribe("/move_base/result",1,&MainWindow::goalStatusCallback,this);
    //ROS_DEBUG("Subbed to goal status");

    /*sub management*/
    //_subs.append(droneNavDataSub);
    _subs.append(testSub);
    _subs.append(plateform_orientation);
    _subs.append(pressure);
    _subs.append(altitude);


}

void rqt_pfd::WidgetPFDWrapper::orientationCallback(const geometry_msgs::Vector3Stamped& msg) {
    widget_->setHeading(msg.vector.x);
    widget_->setPitch(msg.vector.y);
    widget_->setRoll(msg.vector.z);
    //ROS_INFO("data received %f",msg.vector.x);
}
void rqt_pfd::WidgetPFDWrapper::altitudeCallback(const geometry_msgs::Vector3Stamped& msg) {
    widget_->setAltitude(msg.vector.z);
}
void rqt_pfd::WidgetPFDWrapper::pressureCallback(const isbl_base_station::ScalarTimeStamped& msg) {
    widget_->setPressure(msg.data);
}
void rqt_pfd::WidgetPFDWrapper::testCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}
void rqt_pfd::WidgetPFDWrapper::shutdownPlugin()
{
  // unregister all publishers here
  //Unregister all ROS publishers here
    for (int i = 0; i < _subs.size(); ++i) {
        _subs[i].shutdown();
    }
}

void rqt_pfd::WidgetPFDWrapper::saveSettings(qt_gui_cpp::Settings& plugin_settings,
    qt_gui_cpp::Settings& instance_settings) const
{
  // instance_settings.setValue(k, v)
}

void rqt_pfd::WidgetPFDWrapper::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
    const qt_gui_cpp::Settings& instance_settings)
{
  // v = instance_settings.value(k)
}

/*bool hasConfiguration() const
{
  return true;
}
void triggerConfiguration()
{
  // Usually used to open a dialog to offer the user a set of configuration
}*/
PLUGINLIB_DECLARE_CLASS(rqt_pfd, WidgetPFDWrapper, rqt_pfd::WidgetPFDWrapper, rqt_gui_cpp::Plugin)
