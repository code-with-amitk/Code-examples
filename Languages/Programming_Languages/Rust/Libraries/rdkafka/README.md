**rdkafka**
- [Writing kafka client](#kc)

## [rust-rdkafka](https://docs.rs/rdkafka/0.8.1/rdkafka/index.html)
- Rust based Kafka client library(based on [librdkafka](/System-Design/Concepts/MOM_ESB/Apache_Kafka#lrdk)).

<a name=kc></a>
### Writing kafka client
- _1._ Create a [StreamConsumer](/System-Design/Concepts/MOM_ESB/Apache_Kafka#st) object using [bootstrap broker server](/System-Design/Concepts/MOM_ESB/Apache_Kafka#br)
  - _1a._ Extract StreamConsumer
- _2._ Create [topics](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#tp) vector on which we want to listen.
- _3._ [Subscribe to topics]()
```rs
thread_spawn run_consumer (my_topics: &Vec<String>) {
  let result:Result<StreamConsumer<CustomContext>,...> = ClientConfig::new()                  //1
            .set("group.id", --)
            .set("bootstrap.servers", --)
            .set("enable.partition.eof", "false")
            .set("session.timeout.ms", "8000")
            .set("enable.auto.commit", "true")
            .set_log_level(RDKafkaLogLevel::Debug)
            .create_with_context(context);

  let consumer:StreamConsumer<CustomContext> = match result {                   //1a
    Ok(consumer) => consumer,
    Err(e) => {
      let error = format!("Consumer creation failed {}",e);
      error!("{}", &error);
      return Err(error);
    }
  };
  
  let mut topics: Vec<&str> = vec![];
  for t in my_topics {                                                         //2
    topics.push(t.as_str());
  }
  
  if let Err(e) = consumer.subscribe(&topics) {                                 //3
    let error = format!("Subscription to topic failed {}", e);
    error!("{}", &error);
    return Err(error);
  }
}
```
