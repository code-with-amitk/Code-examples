https://github.com/confluentinc/librdkafka/blob/master/CONFIGURATION.md

**rdkafka config variables**
- [max.poll.interval.ms](mpim)

<a name=mpim></a>
### [max.poll.interval.ms](https://github.com/confluentinc/librdkafka/blob/master/CONFIGURATION.md)
#### What?
- This is maximum amount of time (in milliseconds) that a consumer is allowed to go without sending a request to the Kafka broker.
- If the consumer does not send a request within this interval, it is considered inactive or unresponsive, and the Kafka broker assumes that the consumer has encountered an issue and is no longer functioning properly.
- After max.poll.interval.ms, broker will trigger a rebalance, reassigning its partitions to other consumers in the consumer group.
#### When this timer is useful?
- When consumer performs some lengthy processing or operations after receiving a batch of records from Kafka
#### Value of max.poll.interval.ms
- Value should be greater than `max.poll.records` + time for consumer to process the fetched records.
  - `max.poll.records:` maximum number of records fetched in a single poll request
