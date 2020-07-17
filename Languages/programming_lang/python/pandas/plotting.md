## What is Plotting?
This means drawing a 2-D plot from dataframes.

### plot(): Produce plot visualizations
```
# predefined df
print('{}\n'.format(df))

df.plot()
plt.show()
```
![Imgurl](https://i.ibb.co/rQNmFDY/plot.png)

### savefig(): save the plot to a PNG or PDF file.
```
# predefined df
print('{}\n'.format(df))

df.plot()
plt.savefig('df.png')  # save to PNG file
```

### Creating Histogram or boxplots
By setting the kind keyword argument in plot, we can create other plots like histograms or boxplots
```
# predefined df
print('{}\n'.format(df))

df.plot(kind='hist')
df.plot(kind='box')
plt.show()
```

