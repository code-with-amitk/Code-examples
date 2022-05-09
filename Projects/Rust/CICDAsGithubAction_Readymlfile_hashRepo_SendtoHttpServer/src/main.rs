/* Things to do:
1. If Oblivious directory exists, remove it
2. if inside Oblivious services.yml does not exists return.
3. Check unused variables.
4. Replace println!() with error, warn, debug
5. write inside structure, not in main
*/

use tokio::task::LocalSet;

mod common;
mod create_send;
mod git_handler;
mod parse;

fn main() -> Result<(), ()> {
    let mut rt = tokio::runtime::Runtime::new().unwrap();
    let local = LocalSet::new();

    local.block_on(&mut rt, async {
        match common::work(&local).await {
            Ok(a) => a,
            Err(e) => e,
        }
    });

    Ok(())
}
