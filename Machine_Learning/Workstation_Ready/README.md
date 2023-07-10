**Making Machine Ready**

```py
$ sudo apt-get update
$ sudo  apt-get upgrade
$ sudo apt-get python3

// Install python and pip
$ sudo python3 --version
$ sudo apt install python3-pip python3-dev

// BLAS library (makes keras operations run faster on CPU)
$ sudo apt-get install build-essential cmake git unzip pkg-config libopenblas-dev liblapack-dev

// Numpy, SciPy and Matplotlib
$ sudo apt-get install python3-numpy python3-scipy python3-matplotlib python3-yaml

// HDF5. Library to store large files of numeric data in an efficient binary format. Saves Keras models to disk quickly and efficiently
$ sudo apt-get install libhdf5-serial-dev python3-h5py

// Graphviz, pydot-ng to visualize Keras models
$ sudo apt-get install graphviz
$ sudo pip3 install pydot-ng

// Optional. opencv (face recognization)
$ sudo apt-get istall python-opencv

// Theano (optional)
$ sudo pip3 install theano

// keras
$ sudo pip3 install keras

// tensorflow
$ sudo pip3 install tensorflow
```
