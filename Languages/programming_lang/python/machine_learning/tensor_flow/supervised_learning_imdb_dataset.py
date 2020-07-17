"""     supervised_learning_imdb_dataset.py

Binary Classification using KERAS.

SITUATION/TASK?
- Load imdb dataset from keras, predict nearly accurate prediction of review.
- 50k reviews are in DB, Classify Review as +ve or -ve based on text of review.

SUPERVISED LEARNING?
Machines are trained with training data that is tagged with correct results. 
When the machine encounters actual data it produces nearly correct predictions(since it had learned from training data).

IMDB(Internet Movie Database) DATASET(https://keras.io/datasets/):
a. What is imdb?
      This dataset contains 50k movie reviews and is packed with keras.
      Reviews are split into two categories: 25k for training and 25k for testing.
      Each set consisting of 50% negative and 50% positive reviews.
      IMDB dataset is already Preprocessed:
       - Reviews=(Sequence of words) is transformed to (Sequence of Integers).
       - Each integer stands for a specific word in dictionary.

B. Where?
      Data is stored in NPZ file(/root/.keras/datasets/imdb.npz)
# ls -ltr /root/.keras/datasets/imdb.npz
-rw-r--r--. 1 root root 17464789 Mar 30 23:02 /root/.keras/datasets/imdb.npz
      NPZ is a file format by numpy that provides storage of array data using
      gzip compression.
      Look into npz file: python3 opening-imdb-npz.py


************STEP-1*************
-Load imdb dataset
Retrieve tuple from (/root/.keras/datasets/imdb.npz)


***********STEP-2**************
[JUST FOR FUN/NOT REQUIRED] Decode movie review to English words


**********STEP-3***************
- Create Input data for Neural Network.
- Convert input list[] into vector of 10k-dimension of 0 & 1 to be fed into Neural Network 
- ie 1-D array of 0&1s of 10k elements.
- Data
    - Traninig data = Array of 0 & 1s {10k elements}
    - Test data = Array of 0 & 1s {10k elements}
- Labels should be vectorized also


******STEP-4. CREATING NEURAL NETWORK******
Input: data=vector, label=scalar(of 0&1s)
Best N/W for such input: Connected-dense-layers with relu-activation

    Layer   hidden-Units    Activation
      1      16             relu(rectified linear unit)
      2      16             relu
      3      1              sigmoid

Why relu? This function zeroes out negative values.
Why sigmoid? “squashes” arbitrary values into [0, 1] interval giving
something that can be interpreted as a probability.
    
TERMS
 A. Units: dimensionality of the output space
 B. Activation: activation function to use. Types:
  Types                       Input-tensor   Output
  1.relu(rectified linear unit)  x               
  2.tanh(Hyperbolic tangent)     x           (exp(x)-exp(-x))/(exp(x)+exp(-x))       
  3.sigmoid:                     x           (1 / (1 + exp(-x))
  4.hard_sigmoid                 x           `0`if`x < -2.5`, `1`if`x > 2.5`,`0.2 * x + 0.5` if `-2.5 <= x <= 2.5`
  5.exponential                  x           K.exp(x)
  6.linear                       x           x   //return input tensor unchanged. (Default)

A. Medium-Capacity-Network:        
    input nD tensor. Most common 2D shape(batch_size,input_dim)
            \/
   -----------------------------------------
  |Layer-1: Dense(units=16)(activation=relu)|
   -----------------------------------------
            \/ nD tensor
   -----------------------------------------
  |Layer-2: Dense(units=16)(activation=relu)|<------
   -----------------------------------------        |
            \/ nD tensor                            |
   -----------------------------------------        |
  |Layer-3 Dense(units=1)(activation=sigmoid)|      |
   -----------------------------------------        |
            \/                                      |
        output(probability)                         |
            \/                                      |
    |loss function|                                 |
            \/                                      |
            loss score  ------|optimizer|-----------

B. Low-Capacity-Network:
    input nD tensor
            \/
   -----------------------------------------
  |Layer-1: Dense(units=4)(activation=relu)|
   -----------------------------------------
            \/ nD tensor
   -----------------------------------------
  |Layer-2: Dense(units=4)(activation=relu)|<------
   -----------------------------------------        |
            \/ nD tensor                            |
   -----------------------------------------        |
  |Layer-3 Dense(units=1)(activation=sigmoid)|      |
   -----------------------------------------        |
            \/                                      |
        output(probability)                         |
            \/                                      |
    |loss function|                                 |
            \/                                      |
            loss score  ------|optimizer|-----------

C. High-Capacity-Network:
    input nD tensor
            \/
   -----------------------------------------
  |Layer-1: Dense(units=512)(activation=relu)|
   -----------------------------------------
            \/ nD tensor
   -----------------------------------------
  |Layer-2: Dense(units=512)(activation=relu)|<------
   -----------------------------------------        |
            \/ nD tensor                            |
   -----------------------------------------        |
  |Layer-3 Dense(units=1)(activation=sigmoid)|      |
   -----------------------------------------        |
            \/                                      |
        output(probability)                         |
            \/                                      |
    |loss function|                                 |
            \/                                      |
            loss score  ------|optimizer|-----------


**********STEP-5: DEFINE LOSS FUNCTION***************
LOSS FUNCTION? Measures how far output of model is from expected output.
binary_crossentropy: 
 - Since this is Binary classification problem & output is probability, its best to use binary_crossentropy loss. 
 - Computes the cross-entropy loss between true labels and predicted labels.
 - Use this cross-entropy loss when there are only two label classes (assumed to be 0 and 1)
mse loss function:


**********STEP-6. DEFINE Optimizer**************
- rmsprop optimizer: divides the gradient by a running average of its recent magnitude


*********STEP-7. RESERVE 10k SAMPLES AS TRAINING DATA********
Create a validation set by setting 10k samples from imdb dataset.
Remember,input data should be splitted into 3 sets.   
    a. Training data set: Train the model using this
    b. Validation data set: Validate model's output using this
    c. Test data set: Once model is ready for actual data, test model using this.


*********STEP-8. TRAIN THE MODEL*****************
10K samples are splitted into 20 blocks of 512 samples each. 512*20=10k
These blocks are also called epochs. Data is fed into NN in 20 epochs.
  - At the end of every epoch, there is a slight pause as the model computes its loss and accuracy.
At the end of every epoch, there is a slight pause as the model computes its loss and accuracy.
Data is fed and model's behaviour is noted.


***********STEP-9. DRAW GRAPHS/PLOTS***************
- using matplotlib create following graphs.
- validation_loss & validation_accuracy are measured during Step-8.
9a. TRAINING VS VALIDATION_LOSS
        |
        |
 Traning|               //Traning Loss will decrease with every epoch
         ---------------
         validation loss
       
9b. TRANING VS VALIDATION_ACCURACY       
        |
        |
 Traning|               //Traninig accuracy increases with every epoch
         ---------------
         validation accuracy


**********STEP-10. PREDICT REVIEWS(+ve or -ve)***********
/usr/local/lib64/python3.6/site-packages/keras/engine/training.py
def evaluate():


#>>> train_data[0]
#[1, 14, 22, 16, ... 178, 32]
>>> train_labels[0]
1
>>> max([max(sequence) for sequence in train_data])     #Because we restricted to top 10,000 words,
no word index will exceed 10,000
9999
"""

from keras.datasets import imdb
import numpy as np

#STEP-1: Load imdb dataset
#/usr/local/lib/python3.6/site-packages/tensorflow/python/keras/datasets/imdb.py
#def load_data(path='imdb.npz',
#              num_words=None,  //10000 is size of traning data
#              ...)
# return: tuple of array (train_data, train_label), (test_data, test_label)
# train_data,test_data: List[] of reviews. Each review is a list[] of words
# train_label,test_label: List[] of 0,1. 0 means -ve, 1 means +ve review.
# train_data[0] -> [1, 14, 22, 16, ... 178, 32]
(train_data, train_labels),(test_data, test_labels) = imdb.load_data(num_words=10000)
print(train_data)


#Step-2: [JUST FOR FUN/NOT REQUIRED] Decode movie review to English words
#2a. Read word:index mapping from *.json file
# vim /root/.keras/datasets/imdb_word_index.json
#   {"fawn": 34701, "tsukino": 52006, "nunnery": 52007, "sonja": 16816, "vani": 63951, "woods": 1408, 
# "spiders": 16115, .....}
#/usr/local/lib/python3.6/site-packages/tensorflow/python/keras/datasets/imdb.py
#  def get_word_index(path='/root/.keras/datasets/imdb_word_index.json')
#    return above_map {{"fawn": 34701, "tsukino": 52006, ......}
word_index = imdb.get_word_index()

#2b. Reverse the mapping. index:word
# reverse_word_index = {34701: 'fawn', 52006: 'tsukino', 52007: 'nunnery' ......}
reverse_word_index = dict([(value, key) for (key, value) in word_index.items()])

#2c. Join words present in train_data
decoded_review = ' '.join([reverse_word_index.get(i - 3, '?') for i in train_data[0]])
print("--------------")
print(decoded_review)
print("--------------")


#Step-3: Prepare data to be fed to Neural Network.
#Convert data into 10k dimensional vector of 0,1
# /usr/local/lib64/python3.6/site-packages/numpy/matlib.py
#  def zeros(shape, dtype=None, order='C'):
#    return 0 matrix of size=dimension
def vectorize_sequences(sequences, dimension=10000):
    results = np.zeros((len(sequences), dimension))     #3a. results is 10k sized array of 0 elements
    for i, sequence in enumerate(sequences):            #3b. Place 1 at specific locations
        results[i, sequence] = 1
    return results
x_train = vectorize_sequences(train_data)           #Convert traning data into array of 0 & 1 of size=10k
x_test = vectorize_sequences(test_data)             #Convert test data into array of 0 & 1 of size=10k
y_train = np.asarray(train_labels).astype('float32')#vectorize the labels
y_test = np.asarray(test_labels).astype('float32')  #label vectorization
print('============')
print(x_train)
print('!!!!!!!!!!!!')
print(x_test)
print('!!!!!!!!!!!!')
print(y_train)                                      #[0. 1. 1. ... 0. 0. 0.]
print('!!!!!!!!!!!!')
print(y_test)                                       #[0. 1. 1. ... 0. 0. 0.]
print('============')


#Step-4. Creating Neural Network
# /usr/local/lib64/python3.6/site-packages/keras
#  def relu():             //activations.py
#   return K.relu(x, alpha=alpha, max_value=max_value, threshold=threshold)
from keras import models
from keras import layers
model = models.Sequential()
model.add(layers.Dense(16, activation='relu', input_shape=(10000,)))
model.add(layers.Dense(16, activation='relu'))  #/usr/local/lib64/python3.6/site-packages/keras/layers/core.py
model.add(layers.Dense(1, activation='sigmoid'))


#Step-5,6: Passing Optimizer, Loss function
#/usr/local/lib64/python3.6/site-packages/keras/engine/training.py
# class Model():
#  def compile(optimizer='rmsprop',loss='binary_crossentropy',metrics=['accuracy']):
#
#/usr/local/lib64/python3.6/site-packages/keras/losses.py
# class BinaryCrossentropy(LossFunctionWrapper):
#  //Computes the cross-entropy loss between true labels and predicted labels
#  //This is used when there are only two label classes (assumed to be 0 and 1).
# 
#/usr/local/lib64/python3.6/site-packages/keras/optimizers.py
# class RMSprop(Optimizer):
model.compile(optimizer='rmsprop',loss='binary_crossentropy',metrics=['accuracy'])


#Step-7: Creating Validation Set of 10k samples
x_val = x_train[:10000]             #x_train[] is matrix to be inputted into NN
partial_x_train = x_train[10000:]
y_val = y_train[:10000]
partial_y_train = y_train[10000:]


#Step-8:
#/usr/local/lib64/python3.6/site-packages/keras/engine/training.py
# class Model():  //Configures the model for training
#  def fit(numpy_array_x,partial_y_train,epochs=20,batch_size=512,validation_data=(x_val, y_val)):
#   - Return: History Object.
#     history.history is dictionary contains following key and value pair, that is noted during traning of model.
#        {key:                      value}
#        accuray
#        loss
#        validation_accuracy
#        validation_loss
history = model.fit(partial_x_train,partial_y_train,
        epochs=20,batch_size=512,
        validation_data=(x_val, y_val))
print('Traning Complete')
print(history.history.keys())       #dict_keys(['val_loss', 'val_accuracy', 'loss', 'accuracy'])


#Step-9a. PLOTTING TRANING vs VALIDATION_LOSS
import matplotlib.pyplot as plt
history_dict = history.history
acc = history_dict['accuracy']
loss_values = history_dict['loss']
val_loss_values = history_dict['val_loss']
epochs = range(1, len(acc) + 1)
plt.plot(epochs, loss_values, 'bo', label='Training loss')
plt.plot(epochs, val_loss_values, 'b', label='Validation loss')
plt.title('Training and validation loss')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()
plt.show()


#Step-9ab. PLOTTING TRANING vs VALIDATION_ACCURACY
plt.clf()
acc_values = history_dict['accuracy']
val_acc_values = history_dict['val_accuracy']
plt.plot(epochs, acc, 'bo', label='Training acc')
plt.plot(epochs, val_acc_values, 'b', label='Validation acc')
plt.title('Training and validation accuracy')
plt.xlabel('Epochs')
plt.ylabel('Loss')
plt.legend()
plt.show()


#Step-10
print(model.evaluate(partial_x_train,partial_y_train))
"""
# python3.6 -m doctest k-imbdb.py 
"""
