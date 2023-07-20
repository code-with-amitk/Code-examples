**notify-rs**
- [RecommendedWatcher vs PollWatcher](#vs)
- [Code](#code)
  - [RecommendedWatcher](#rw)
  - [PollWatcher](#pw)

### notify-rs
- notify-rs is a Rust crate that provides cross-platform file system event notification.
- It allows Rust applications to monitor changes to files/directories in a platform-independent way. This is particularly useful for applications that need to respond to changes in the file system, such as updating cached data, synchronizing files, or triggering specific actions when certain files are modified, created, or deleted.

<a name=vs></a>
### RecommendedWatcher vs PollWatcher
||RecommendedWatcher|PollWatcher|
|---|---|---|
|What|Implementation of Watcher trait provided by the notify crate |same|
|How|Watches inodes. Drawback on linux: on every file change, linux creates new inode. Hence we get 2 events write,Remove. Where remove is false positive.|Watches Paths(not inodes). This does not generate Remove event on file edit.|

<a name=code></a>
### Code
<a name=rw></a>
#### RecommendedWatcher
```rs
    fn main() {
            let mut rt = tokio::runtime::new().unwrap();
            let local = LocalSet::new();
            local.block_on(&mut rt, async {
                match do_main().await {
                    Ok (_o) => {
                        println!("Success");
                    }
                    Err (e) => {
                        println!("do_main failed");
                    }
                }
            });
        }
        pub async fn do_main() -> Result<(), String> {
            match do_start().await {
                Ok (join_handles) => {
                    for join in join_handles {
                        if let Err(e) = join.await {
                            println!("join failed {}", e);
                        }
                    }
                }
                Err(e) => {
                    return Err(str);
                }
            }
            Ok(())
        }
        pub async fn do_start() -> Result<Vec<JoinHandles<()>>, ()> {
            loop {
                match Monitor::spawn_task().await {
                    Ok (h) => {
                        join_handles.push(h);
                    }
                    Err (e) => {
                        println!(e);
                        break;
                    }
                }
                break;
            }
        }
        pub struct Monitor{}
        impl Monitor {
            pub async fn spawn_task () -> Result<tokio::task::JoinHandle<()>, Box<dyn std::error::Error> >{
                let handle = tokio::spawn(async {
                    let Err (e) = Self::async_watch(path).await {
                        match e.kind {
                            notify::ErrorKind::Io(_) => {
                                prinlnt!("{} IO Error", e);
                            }
                            _ => {}
                        }
                    }
                });
                Ok(handle)
            }
            async fn async_watcher() -> notify::Result<(RecommendedWatcher, Receiver<notify::Result<Event>>)> {
                let (mut tx, rx) = channel(1);
            
                let watcher = RecommendedWatcher::new(
                    move |res| {
                        futures::executor::block_on(async {
                            tx.send(res).await.unwrap();
                        })
                    },
                    Config::default(),
                )?;
                Ok((watcher, rx))
            }
            async fn async_watch<P: AsRef<Path>>(path: P) -> notify::Result<()> {
                let (mut watcher, mut rx) = async_watcher()?;
            
                watcher.watch(path.as_ref(), RecursiveMode::Recursive)?;
            
                while let Some(res) = rx.next().await {
                    match res {
                        Ok(event) => {
                            println!("changed: {:?}", event);
                            match event.kind {
                                notify::Eventkind::Remove(notify::event::Removekind::File) => {
                                    // Rewatch
                                    watcher.watch (path.as_ref(), RecursiveMode::Recursive)?;
                                },
                                _ => {}
                            }
                        },
                        Err(e) => println!("watch error: {:?}", e),
                    }
                }
                Ok(())
            }
        }
```

<a name=pw></a>
#### PollWatcher
```rs
    fn main() {
            let mut rt = tokio::runtime::new().unwrap();
            let local = LocalSet::new();
            local.block_on(&mut rt, async {
                match async_watch(path).await {
                    Ok (_o) => {
                        println!("Success");
                    }
                    Err (e) => {
                        println!("do_main failed");
                    }
                }
            });
        }
        async fn async_watch(path: &str) -> notify::Result<()> {
            enum Message {
                Event(notify::Result<notify::Event>),
            }
        
            let (tx, rx):(async_channel::Sender<Message>, async_channel::Reciever<Message>) = async_channel::unbounded();
            let tx_c = tx.clone();

            let mut watcher = PollWatcher::new(
                move |watch_event| {
                    tx_c.send(Message::Event(watch_event)).unwrap();
                },
                Config::default(),
            )?;
        
            watcher.watch(path.as_ref(), RecursiveMode::Recursive)?;
        
            while let Ok(res) = rx.recv().await {
                match res {
                    Message::Event(e) => println!("Watch event {e:?}"),
                    Message::Scan(e) => println!("Scan event {e:?}"),
                }
            }
        
            Ok(())
        }
```
