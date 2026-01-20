import pandas as pd
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error     

# This function takes the raw data and cleans it
def clean_the_data(file):
	df = pd.read_csv(file)                          
	print("Raw data\n", df.to_string())
	clean_df = df.dropna(axis=0)
	print("Cleaned data:\n", clean_df.to_string())
	return clean_df

# split the data into traning and validation(testing data)
# 		|- train_X (traning data 1)
# 		|- val_X (training data 2)
# data -|- train_y (prediction for 1)
# 		|- val_y (prediction for 2)
def split_data(data):
	features = ['Duration','Pulse','Maxpulse']
	X = data[features]
	y = data.Calories
    # X = Training, y = prediction
    # split data into half
	train_X, val_X, train_y, val_y = train_test_split(X, y, random_state = 0, test_size=0.5)
	print("train_X:\n", train_X.to_string())
	print("val_X:\n", val_X.to_string())
	print("train_y:\n", train_y.to_string())
	print("val_y:\n", val_y.to_string())
	return train_X, val_X, train_y, val_y
	
# Train using traninig, prediction data
# Get Decision Tree Model
def get_DecisionTreeRegressor_model(train_X, train_y):
	dtree = DecisionTreeRegressor(random_state=1)
	dtree.fit(train_X, train_y)
	return dtree
    
# Get Random Forest Model
def get_RandomForest_model(train_X, train_y):
	forest_model = RandomForestRegressor(random_state=1)
	forest_model.fit(train_X, train_y)
	return forest_model

# Let model predict over training data 2
def model_predict(model, val_X):
	return model.predict(val_X)

def get_mean_absolute_error(prediction_from_data1, prediction_from_data2):
	return mean_absolute_error(prediction_from_data1, prediction_from_data2)
	
print("---------- Splitting Data ----------")
clean_df = clean_the_data("data.csv")
train_X, val_X, train_y, val_y = split_data(clean_df)
print("---------- Splitting End ----------")

model_dtree = get_DecisionTreeRegressor_model(train_X, train_y)
model_rforest = get_RandomForest_model(train_X, train_y)       

print("---------- Predictions Start ----------")
dtree_prediction = model_predict(model_dtree, val_X)         
rforest_prediction = model_predict(model_rforest, val_X)     
print("Decision Tree prediction:\n", dtree_prediction)
print("Random Forest prediction:\n", rforest_prediction)
print("---------- Predictions End ----------")

print("---------- Mean Absolute Error ----------")
print("decision Tree MAE:",
    get_mean_absolute_error(dtree_prediction, 
                            val_y))
print("Random Forest MAE:",
    get_mean_absolute_error(rforest_prediction, 
                            val_y))
