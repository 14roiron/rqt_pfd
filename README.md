# Principal flight display and artificial flight horizon for RQT

This code base on https://sourceforge.net/projects/qfi/ which provide the base widget
and this project https://github.com/JdeRobot/ThirdParty/tree/master/qflightinstruments which provide a python version of the same module.

Here only the Principal Flight Display have been implemented, but other should be easy to deploy, especially the python version of them.

To install the project, you need to download and install the base plugin
from this link https://sourceforge.net/projects/qfi/
```bash
cd folder
mkdir build
qmake ..
make -j
sudo make install
```

If needed you may need to compile and install the square layout files.

Then you can add and compile this project in your catkin_ws
To start RQT, you may need, to force discovery
```bash
rqt --force-discover
```

