https://github.com/confluentinc/librdkafka/blob/master/CONFIGURATION.md

**rdkafka config variables**
- [queued.max.messages.kbytes](#qmm)
- [max.poll.interval.ms](mpim)
- [session.timeout.ms](stm)

<a name=qmm></a>
### queued.max.messages.kbytes
- maximum size in kilobytes (KB) that the local consumer queue can reach before additional messages from the broker are fetched.
- Default=65536

<a name=mpim></a>
### [max.poll.interval.ms](https://github.com/confluentinc/librdkafka/blob/master/CONFIGURATION.md)
#### What?
- This is maximum amount of time (in milliseconds) that a consumer is allowed to go without sending a request to the Kafka broker. OR  maximum time interval between poll requests from a consumer to the Kafka broker.
- If the consumer does not send a request within this interval, it is considered dead, and the Kafka broker assumes that the consumer has encountered an issue and is no longer functioning properly.
- After max.poll.interval.ms, broker will trigger a rebalance, reassigning its partitions to other consumers in the consumer group.
#### When this timer is useful?
- When consumer performs some lengthy processing or operations after receiving a batch of records from Kafka
#### Value of max.poll.interval.ms
- Value should be greater than `max.poll.records` + time for consumer to process the fetched records.
  - `max.poll.records:` maximum number of records fetched in a single poll request

<a name=stm></a>
### session.timeout.ms
- max time interval between heartbeats from consumer to broker.
- If a consumer does not send heartbeats within this timeout period, the broker will initiate a rebalance to reassign its partitions to other consumers in the consumer group.
```c
max.poll.interval.ms <= session.timeout.ms
```
