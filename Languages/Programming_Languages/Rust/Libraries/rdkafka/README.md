- [rdkafka](#rd_


- **kafka Traits**
  - [ConsumerContext](#cc)
  - [Consumer](#con)
  - [StreamConsumer](#sc)
  - [MessageStream](#ms)

<a name=rd></a>
## [rust-rdkafka](https://docs.rs/rdkafka/0.8.1/rdkafka/index.html)
- Rust based Kafka client library(based on [librdkafka](/System-Design/Concepts/MOM_ESB/Apache_Kafka#lrdk)).

## Kafka Producer Consumer
<a name=c1></a>


<a name=rc></a>
### 2. Rust Code

- _6._ On return from future, Get topic,paylod from Message.
```rs

pub const TOPIC1: &str = "topic-1";
pub const TOPIC2: &str = "topic-2";

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
  
  let mut msg_stream:MessageStream<CustomContext, ..., ...> = consumer.start(); //4
  
  while let Some(msg: Result<BorrowedMessage, KafkaError>) = msg_stream.next().await {  //5
    match message {
      Err(e: KafkaError) => warn!("Msg Stream error: {}", e),
      Ok(m: BorrowedMessage) => {
        let payload = match m.payload_view::<str>() {                     //6
          None => "",
          Some(Ok(s)) => s,
          Some(Err(e)) => {
            warn!("Error message payload: {:?}",e);
          }
        };
        match m.topic() {                                                       
          TOPIC-1 => {
            let msg_type = TOPIC-1.to_string();                           //
          },
          TOPIC-2 => {
          },
        }
      }
  }
}
```

