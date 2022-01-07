**Rust Code for kafka Consumer, Producer**
- [1. Start kafka broker & zookeper 1st](/Languages/Programming_Languages/Rust/Kafka/Using_CLI#s1)
- [2. kafka Consumer](#c)
- [3. kafka Producer](#p)
- **kafka Traits**
  - [ConsumerContext](#cc)
  - [Consumer](#con)
  - [StreamConsumer](#sc)
  - [MessageStream](#ms)


<a name=c></a>
## 2. kafka Consumer
**Cargo.toml**
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
use rdkafka;
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
          let m: Message = match serde_json::from_str(&payload) {
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
$ ./consumer
payload {
  "Message": "test",
}
key: '"Key 1"'
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
use rdkafka;

#[derive(Debug, Serialize, Deserialize)]
pub struct Payload {
    #[serde(rename = "Message")]
    msg: String,
}
impl Payload {
    pub fn add_payload() -> Self {
        Self {
            msg: String::from("test"),
        }
    }
}

#[tokio::main]
async fn main() {
  let broker = "localhost:9092";
  let topic = "test-topic";
  
  let producer: &FutureProducer = &ClientConfig::new()
    .set("bootstrap.servers", broker)
    .create()
    .expect("producer error");

  let payl = Payload::add_payload();

  producer.send()(                            //send <topic, payload(key, value)>
    FutureRecord::to(topic)
    .payload(&payl.to_string())
    .key(&format!("Key {}", 1))
  ).await;
}

$ ./producer
serialized {
  "Message": "test",
}
```

## Kafka Traits
<a name=cc></a>
### ConsumerContext
User-defined object used to provide custom callbacks for consumer events. 
<a name=con></a>
### rdkafka::consumer::Consumer
Common trait for all consumers.
```rs
fn subscribe(&self, topics: &[&str]) -> KafkaResult<()> //Subscribe the consumer to a list of topics.
```
<a name=sc></a>
### rdkafka::consumer::stream_consumer
- [kafka Stream?](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#st). This is Consumer with an associated polling thread. This return all consumed messages as a Stream.
```c
pub struct StreamConsumer<C: ConsumerContext + 'static> {
}
fn start(&mut self) -> MessageStream    //Starts StreamConsumer with default configuration(100ms polling interval and no NoMessageReceived notifications).
```
<a name=ms></a>
### [rdkafka::consumer::stream_consumer::MessageStream](https://docs.rs/rdkafka/0.10.0/rdkafka/consumer/stream_consumer/struct.MessageStream.html)
A Stream of Kafka messages. It can be used to receive messages as they are received.
```c
pub struct MessageStream { /* fields omitted */ }

fn next(&mut self) -> Next<'_, Self>      //Creates a future that resolves to the next item in the stream.
```
<a name=bm></a>
### [rdkafka::message::BorrowedMessage](https://docs.rs/rdkafka/0.14.0/rdkafka/message/struct.BorrowedMessage.html)
A zero-copy Kafka message. The content of the message is stored in the receiving buffer of the consumer or the producer. As such, BorrowedMessage cannot outlive the consumer or producer it belongs to.
```c
pub struct BorrowedMessage<'a> { /* fields omitted */ }

fn topic(&self) -> &str                           //Returns the source topic of the message.

fn payload_view<P: ?Sized + FromBytes>(&self) -> Option<Result<&P, P::Error>>
//Converts the raw bytes of the payload to a reference of the specified type, that points to the same
//data inside the message and without performing any memory allocation
```
