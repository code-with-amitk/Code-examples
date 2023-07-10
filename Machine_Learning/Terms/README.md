- [Artificial Intelligence, Machine Learning, Deep Learning](#vs)
- [Overfitting](#of)
- [Bias](#sb)
- [CNTK](#cntk)
- [Keras](#keras)
- [Tensorflow](#tf)
- [New Page: Tensor, vectors, scalar](Tensor)
- [Underfitting](#uf)


<a name=vs></a>
## Artificial Intelligence, Machine Learning, Deep Learning
```c
           |       AI                          |       ML                 |      DL 
-----------|-----------------------------------|--------------------------|-------------------------
Originated |     1950                          |       1960               |   1970
What       | Simulated Intelligence in Machines| Machine making decisions | Using Neural networks to solve complex problems
                                                 without being programmed |
Objective  | Building machines which can       | Algo which can learn thru |Neural n/w to identify patterns 
             think like humans                 | data
```

<a name=of></a>
## Overfitting
- Means that the model performs well on the training data, but it does not generalize well(ie produces good results on real world/unseen data), because there is too of much uneccessary data(noise) in traning data.
- **Regularization:** Constraining a model to make it simpler and reduce the risk of overfitting.

<a name=bs></a>
## Bias/Sampling Bias
- We should use a training data set that is representative of the cases we want model to predict.
- if the sample is too small, you will have sampling noise (i.e., nonrepresentative data as a result of chance), but even very large samples can be nonrepresentative if the sampling method is flawed. This is called sampling bias.

<a name=cntk></a>
## CNTK
This is Microsoft Cognitive Toolkit (CNTK) backend, plugged with keras.

<a name=keras></a>
## Keras
- Library(in Python) which provides functions/APIs to build deep-learning models.
- Different backends can be plugged with keras
```c
                  Keras
     Tensorflow / Theano / CNTK
      CUDA           BLAS,Eigen
      GPU            CPU
```

<a name=tf></a>
## Tensorflow
- This is ML Open source library(EXPOSING APIs) for numerical computation and large-scale ML supports CPUs & GPUs. 
- Python Front-end APIs & backend written in c++ for high performance.


<a name=uf></a>
## Underfitting
- Does not produces good results on traning data.

<a name=v></a>
### Variance
- Variance is the tendency to learn random things unrelated to the real signal 
