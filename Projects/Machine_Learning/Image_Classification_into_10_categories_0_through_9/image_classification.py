from keras import models
from keras import layers
from keras.datasets import mnist

"""
1. Create Neural Network
"""
network = models.Sequential()
network.add(layers.Dense(512, activation='relu', input_shape=(28*28,)))
network.add(layers.Dense(10, activation='softmax'))
network.compile(optimizer='rmsprop', loss='categorical_crossentropy',metrics=['accuracy'])

"""
2. Prepare input data for neural network
"""
try:
    (train_images, train_labels), (test_images, test_labels) = mnist.load_data()
except Exception as e:
    print("Exception in load_data():",e)
train_images = train_images.reshape ((60000, 28*28))
test_images = test_images.reshape ((10000, 28*28))
train_images = train_images.astype ('float32') / 255
test_images = test_images.astype ('float32') / 255
train_labels = to_categorical(train_labels)
test_labels = to_categorical(test_labels) 

"""
3. Create training loop
"""
try:
    network.fit(train_images, train_labels, epochs=5, batch_size=128)
except Exception as e:
    print("Exception: ", e)

"""
 4. Run training data
> python mnist.py
Epoch 1/5
60000/60000 [==============================] - 9s - loss: 0.2524 - acc: 0.9273
Epoch 2/5
51328/60000 [========================>.....] - ETA: 1s - loss: 0.1035 - acc: 0.969

 5. Run on testing data
>>> test_loss, test_acc = network.evaluate(test_images, test_labels)
>>> print('test_acc:', test_acc)
test_acc: 0.9785
"""
