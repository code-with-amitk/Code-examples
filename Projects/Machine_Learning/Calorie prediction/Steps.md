## Steps
1.  We are provided with Raw data(data.csv containing Duration,Pulse,Maxpulse,Calories). We will:
- Clean the raw data ie remove empty rows
```
data.csv(Raw data)
    Duration  Pulse  Maxpulse  Calories
Duration,Pulse,Maxpulse,Calories
60,      110,    130,    409.1
60,      117,    145,    479.0
60,      103,    135,    340.0
45,      109,    175,    282.4
45,      117,    148,    406.0
60,      102,    127,    300.5
45    104     134.0       NaN

Cleaned data:
Duration  Pulse  Maxpulse  Calories
60,      110,    130,    409.1
60,      117,    145,    479.0
60,      103,    135,    340.0
45,      109,    175,    282.4
45,      117,    148,    406.0
60,      102,    127,    300.5
```

2. Split the data ie seperate traning('Duration','Pulse','Maxpulse') and prediction data(Calories)
```
X = Data, y = prediction

      |- train_X (traning data 1)
      |- val_X (training data 2)
data -|- train_y (prediction for 1)
      |- val_y (prediction for 2)
```

3. Feed model with traning and prediction data
4. Now model is ready for predictions, feed the model with real world data. get predictions
5. Measure how far model deviated by comparing predictions from traning, Real world data using mean absolute error.
