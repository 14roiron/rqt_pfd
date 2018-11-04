/***************************************************************************//**
 * @file example/WidgetPFD.h
 * @author  Marek M. Cel <marekcel@marekcel.pl>
 * @author Dave Culp <daveculp@cox.net>
 *
 * @section LICENSE
 *
 * Copyright (C) 2018 Marek M. Cel, Dave Culp
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
 * Copyright (C) 2018 Marek M. Cel, Dave Culp
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
#ifndef WIDGETPFD_WRAP_H
#define WIDGETPFD_WRAP_H

////////////////////////////////////////////////////////////////////////////////

#include <QObject>
#include <rqt_gui_cpp/plugin.h>
#include "ui_WidgetPFD.h"
#include "WidgetPFD.h"
#include <QWidget>

/*RQT*/
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>
/*ROS*/
#include <ros/ros.h>
#include <ros/macros.h>
#include <cv_bridge/cv_bridge.h>
#include <float.h>
#include <image_transport/image_transport.h>
#include <tf/transform_datatypes.h>
/*ROS-msg*/
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Vector3Stamped.h>
#include "ScalarTimeStamped.h"



#include <qfi_PFD.h>

#include <LayoutSquare.h>

////////////////////////////////////////////////////////////////////////////////

namespace rqt_pfd
{

////////////////////////////////////////////////////////////////////////////////

class WidgetPFDWrapper : public rqt_gui_cpp::Plugin
{
    //Q_OBJECT

public:

    explicit WidgetPFDWrapper();

    virtual ~WidgetPFDWrapper();

    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings,
            qt_gui_cpp::Settings& instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
            const qt_gui_cpp::Settings& instance_settings);


private:
    rqt_pfd::WidgetPFD* widget_;
    Ui::WidgetPFD _ui;
    ros::NodeHandle* _nh;
    /*ROS*/
    QVector<ros::Subscriber> _subs;
    ros::Rate* _rate;
    ros::Subscriber _angles;

    void testCallback(const std_msgs::String::ConstPtr& msg);
    void orientationCallback(const geometry_msgs::Vector3Stamped& msg);
    void pressureCallback(const isbl_base_station::ScalarTimeStamped& msg);
    void altitudeCallback(const geometry_msgs::Vector3Stamped& msg);
////////////////////////////////////////////////////////////////////////////////
};}
#endif // WIDGETPFD_H
