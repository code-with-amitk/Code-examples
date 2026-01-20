1. import pandas (We will convert data from csv to dataframe using pandas.)
2. Use DecisionTreeRegressor, Random Forest from Scikit Learn
2. Import train_test_split to split the data into 2 sets
2. import mean_absolute_error for calculating MEA later in code
3. read_csv() (From Pandas): Read csv data into dataframe using

4. dropna() (From Pandas): Clean the data by removing empty rows

We only have 1 set of data, from which we will seperate traning and prediction data
5. Traning data: 'Duration','Pulse','Maxpulse'
6. Prediction data: 'Calories'

7. Create DecisionTreeRegressor, RandomForestRegressor models
8. fit() (From scikit-learn) Feed the training and prediction data to model. Supervised learning
9. predict(on Training data 2) (From scikit-learn) Output of model. Predict the calories based on traninig data. You will see model gives same values for calories as fed. This is overfitting

11. Validate the model using mean absolute error

12. Output: MAE of Random Forest is Far less than Decision Tree

```
---------- Splitting Data ----------
Raw data
    Duration  Pulse  Maxpulse  Calories
0        60    110     130.0     409.1
1        60    117     145.0     479.0
2        60    103     135.0     340.0
3        45    109     175.0     282.4
4        45    117     148.0     406.0
5        60    102     127.0     300.5
6        45    104     134.0       NaN
Cleaned data:
    Duration  Pulse  Maxpulse  Calories
0        60    110     130.0     409.1
1        60    117     145.0     479.0
2        60    103     135.0     340.0
3        45    109     175.0     282.4
4        45    117     148.0     406.0
5        60    102     127.0     300.5
train_X:
    Duration  Pulse  Maxpulse
3        45    109     175.0
0        60    110     130.0
4        45    117     148.0
val_X:
    Duration  Pulse  Maxpulse
5        60    102     127.0
2        60    103     135.0
1        60    117     145.0
train_y:
 3    282.4
0    409.1
4    406.0
val_y:
 5    300.5
2    340.0
1    479.0
---------- Splitting End ----------
---------- Predictions Start ----------
Decision Tree prediction:
 [409.1 409.1 409.1]
Random Forest prediction:
 [355.576 355.576 397.104]
---------- Predictions End ----------
---------- Mean Absolute Error ----------
decision Tree MAE: 82.53333333333335
Random Forest MAE: 50.849333333333355
```
