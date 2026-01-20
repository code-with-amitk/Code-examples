## Model Validation (Mean Absolute Error = MEA)
### Predictive Accuracy? 
What is quality of prediction that model made? How close are model's predictions to actual result?

### How to measure?
- Compare predicted values from training data and actual predicted values from real world data. It will mix of good and bad predictions
- Looking through a list of 10,000 predicted and actual values would be pointless. We need to summarize this into a single metric.
- Mean Absolute Error (MAE): Average of abs value of (actual - predicted)

MEA = ((200-190) + abs(300-310))/2 = 10

Random Forest is better than Decision Tree, due to low MEA
