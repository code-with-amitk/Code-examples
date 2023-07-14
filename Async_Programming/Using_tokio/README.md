- Comparison
  - [futures::executor::block_on() vs tokio::task::spawn_blocking](#v1)

## Comparison
<a name=vs1></a>
### futures::executor::block_on() vs tokio::task::spawn_blocking()
> These are 2 different approaches to execute async tasks in tokio

|| futures::executor::block_on | tokio::task::spawn_blocking() |
|---|---|---|
|What|Run 1 future to completion and there is only thread within tokio<li>There are no other tasks on tokio</li>|<li>This spawn a blocking task into a separate thread from the Tokio runtime's thread pool.</li><li>while there can be other non-blocking tasks on tokio runtime</li>|
