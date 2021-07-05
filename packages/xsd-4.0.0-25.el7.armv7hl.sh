echo "Downloading Boost148 libraries"
wget https://armv7.dev.centos.org/repodir/epel-pass-1/xsd/4.0.0-25.el7/armv7hl/xsd-4.0.0-25.el7.armv7hl.rpm
wget https://armv7.dev.centos.org/repodir/epel-pass-1/boost148/1.48.0-7.el7/armv7hl/boost148-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/libcutl-1.8.1-1.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-iostreams-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-serialization-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-python-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-program-options-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-math-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-locale-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-date-time-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-regex-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-graph-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-signals-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-timer-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-chrono-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-filesystem-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-random-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-thread-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-wave-1.48.0-7.el7.armv7hl.rpm
wget http://repos.tilab.tuwien.ac.at/public/el7/armhfp/epel/boost148-system-1.48.0-7.el7.armv7hl.rpm
echo "Installing Boost148 using YUM"
sudo yum install -y ./boost148-wave-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-thread-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-random-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-filesystem-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-system-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-chrono-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./boost148-timer-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./boost148-signals-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./boost148-graph-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-regex-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./boost148-date-time-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./boost148-locale-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-math-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-program-options-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y./boost148-python-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-serialization-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./boost148-iostreams-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y  ./libcutl-1.8.1-1.el7.armv7hl.rpm
sudo yum install -y  ./boost148-1.48.0-7.el7.armv7hl.rpm
sudo yum install -y ./xsd-4.0.0-25.el7.armv7hl.rpm
echo "Cleaning downloaded files"
sudo rm *.el7.armv7hl.rpm



