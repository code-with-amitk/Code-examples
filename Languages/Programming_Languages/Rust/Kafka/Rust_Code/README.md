**Rust Code for kafka Consumer, Producer**
- [1. kafka Consumer](#c)
- [2. kafka Producer](#p)

<a name=c></a>
## 1. kafka Consumer
-  Start [kafka broker & zookeper 1st](/Languages/Programming_Languages/Rust/Kafka/Using_CLI#s1)
- **Cargo.toml**
```rs
[package]
name = "consumer"
version = "0.1.0"
authors = ["amit"]
edition = "2018"

[dependencies]
chrono = {version="0.4"}
clap = {version="2.32"}
env_logger = "0.7"
futures = {version = "0.3"}
log = {version="0.4"}
rdkafka = {version="0.24"}
serde = {version="1.0"}
serde_derive = {version="1.0"}
serde_json = {version="1.0"}
tokio = { version = "^0.2.6", features = ["macros", "sync", "stream", "time", "rt-core", "rt-util"]}
uuid = {version = "0.7", features = ["v4"]}
```
- **src/main.rs**
  - _1._ Create [StreamConsumer](/System-Design/Concepts/MOM_ESB/Apache_Kafka#st) using [broker](/System-Design/Concepts/MOM_ESB/Apache_Kafka#br)
  - _2._ Subscribe to topic
  - _3._ Start consumer to read on stream.
  - _4._ Wait on future that resolves to the next item in the stream.
  - 5. When message is recieved
    - _5a._ Extract Key
    - _5b._ Extract payload
```rs
#[macro_use]
extern crate serde_derive;
use futures::StreamExt;
use rdkafka::{
  client::ClientContext,
  config::{ClientConfig, RDKafkaLogLevel},
  consumer::stream_consumer::StreamConsumer,
  consumer::{CommitMode, Consumer, ConsumerContext, Rebalance},
  error::KafkaResult,
  message::{Headers, Message},
};
struct CustomContext;

#[derive(Debug, Serialize, Deserialize)]
pub struct Message {
    #[serde(rename = "Message")]
    msg: String,
}

#[tokio::main]
async fn main() {
  let broker = "localhost:9092";
  let topic = "test-topic";
  
  let consumer: LoggingConsumer = ClientConfig::new()   //1
      .set("bootstrap.servers", broker)                 
      .set_log_level(RDKafkaLogLevel::Debug)
      .create_with_context(context)
      .expect("kafka Consumer creation failed");
      
  consumer.subscribe(&[topic])                          //2
  .expect("subscribe failed");
  
  let mut message_stream = consumer.start();            //3
  
  while let Some(msg: Result<BorrowedMessage, kafkaError>) = message_stream.next().await {   //4
    match msg {
      Ok(msg1) => {
        
        let payload = match msg1.payload_view::<str>() {                //5a. Extract payload
          Some(Ok(pay)) => pay,
          Some(Err(e)) => println!("payload error: {}", e),
        };
        
        if let Some(key) = msg1.key() {                                 //5b. extract Key
          let m: Messafe = match serde_json::from_str(&payload) {
            Ok(m) => m,
            Err(e) => println("No Key");
          };
          let msg_str = serde_json::to_string_pretty(&m);
          println!("key: '{:?}', message: '{:?}', topic: {}, String::from(key), &m);
        };

      },//Ok(msg1)
      Err(e) => println!("Msg error: {}", e),
    }//match msg
  }//while
}
```

<a name=p></a>
## 2. kafka Producer
**$ Cargo.toml**
```rs
[package]
name = "producer"
version = "0.1.0"
authors = ["amit"]
edition = "2018"

[dependencies]
chrono = {version="0.4"}
futures = {version = "0.3"}
log = {version="0.4"}
rdkafka = {version="0.24"}
serde = {version="1.0"}
serde_derive = {version="1.0"}
serde_json = {version="1.0"}
tokio = { version = "^0.2.6", features = ["macros", "sync", "stream", "time", "rt-core", "rt-util"]}
uuid = {version = "0.7", features = ["v4"]}
```
**$ main.rs**
```rs
#[macro_use]
extern crate serde_derive;
use futures::StreamExt;
use rdkafka::{
  client::ClientContext,
  config::{ClientConfig, RDKafkaLogLevel},
  consumer::stream_consumer::StreamConsumer,
  consumer::{CommitMode, Consumer, ConsumerContext, Rebalance},
  error::KafkaResult,
  message::{Headers, Message},
};
struct CustomContext;

#[derive(Debug, Serialize, Deserialize)]
pub struct Message {
    #[serde(rename = "Message")]
    msg: String,
}

#[tokio::main]
async fn main() {
  let broker = "localhost:9092";
  let topic = "test-topic";
  
  let producer: &FutureProducer = &ClientConfig::new()
    .set("bootstrap.servers", broker)
    .create()
    .expect("producer error");

}  
```
