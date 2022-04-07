**Cloudwatch = Grafanna**


## CloudWatch
- This is a web service that monitor various metrics(Eg: CPU Usage, requests/sec) and generates alarms based on data from those metrics.
- AWS services send metrics to CloudWatch. CloudWatch uses these metrics to create graphs automatically showing performance over time. 
```c
  Service-1 --------\
                    Cloudwatch //Displays metrics on Dashboard
  Service-2 --------/
```

### CloudWatch alarms
- We can create alarms those automatically perform actions if the value of a metric goes above or below a predefined threshold.

### Cloudwatch Dashboard
- This enables you to access all the metrics for your resources from a single location.
