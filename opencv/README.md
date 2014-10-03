### install package
```
sudo apt-get install build-essential libgtk2.0-dev libjpeg-dev libtiff4-dev libjasper-dev libopenexr-dev cmake python-dev python-numpy python-tk libtbb-dev libeigen2-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev libqt4-dev libqt4-opengl-dev sphinx-common texlive-latex-extra libv4l-dev libdc1394-22-dev libavcodec-dev libavformat-dev libswscale-dev
```

### download opencv-2.4.9
```
wget -O OpenCV-2.4.9.zip http://fossies.org/linux/misc/opencv-2.4.9.zip
unzip OpenCV-2.4.9.zip
```

### build
```
cd opencv-2.4.9
mkdir debug ; cd debug
cmake -D CMAKE_INSTALL_PREFIX=/usr/local/opencv  -g ..
make -j8 ; sudo make install
```

###add library path
```
sudo vim /etc/ld.so.conf.d/opencv.conf
/usr/local/opencv/lib
sudo ldconfig
ldconfig -p | ag 'opencv'
```

### bashrc configure
```
~/.bashrc
PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/opencv/lib/pkgconfig
export PKG_CONFIG_PATH
```

### test
```
cd opencv-2.4.9/samples/c
./build_all.sh
./facedetect lena.jpg
```

