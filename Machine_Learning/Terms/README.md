- [Overfitting](#of)
- [Sampling Bias](#sb)

<a name=of></a>
### Overfitting
- Means that the model performs well on the training data, but it does not generalize well, because there is too of much uneccessary data(noise) in traning data.
- **Regularization:** Constraining a model to make it simpler and reduce the risk of overfitting.

<a name=bs></a>
### Sampling Bias
- We should use a training data set that is representative of the cases we want model to predict.
- if the sample is too small, you will have sampling noise (i.e., nonrepresentative data as a result of chance), but even very large samples can be nonrepresentative if the sampling method
is flawed. This is called sampling bias
