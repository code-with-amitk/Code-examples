**Making Machine Ready**

```py
$ sudo su -
$ apt-get update
$ apt-get upgrade
$ apt-get python3

// Install python and pip
$ python3 --version
$ apt install python3-pip python3-dev

// BLAS library (makes keras operations run faster on CPU)
$ apt-get install build-essential cmake git unzip pkg-config libopenblas-dev liblapack-dev

// Numpy, SciPy and Matplotlib
$ apt-get install python3-numpy python3-scipy python3-matplotlib python3-yaml

// HDF5. Library to store large files of numeric data in an efficient binary format. Saves Keras models to disk quickly and efficiently
$ apt-get install libhdf5-serial-dev python3-h5py

// Graphviz, pydot-ng to visualize Keras models
$ apt-get install graphviz
$ pip3 install pydot-ng

// Optional. opencv (face recognization)
$ apt-get istall python-opencv

// Theano (optional)
$ pip3 install theano

// keras
$ pip3 install keras
```
