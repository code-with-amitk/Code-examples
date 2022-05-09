use crate::create_send::Sender;
use crate::git_handler::Git;
use crate::parse::Parser;
use http::StatusCode;
use log::warn;
use tokio::task::LocalSet;

pub async fn work(_local: &LocalSet) -> Result<(), ()> {
    const FN_NAME: &str = "work";
    warn!("{}", FN_NAME);

    //Parse Command Line arguments
    let parser = Parser::parse_command_line();

    //Checkout service.yml and read user
    let (admin, dir_hash) = Git::is_user_admin(parser.username.clone());
    if admin == true {
        //if user's role is admin
        //Create Packet and send
        let _a = match Sender::send(parser.username, dir_hash).await {
            Ok(a) => a,
            Err(e) => {
                warn!("{} {}", FN_NAME, e);
                StatusCode::NO_CONTENT
            }
        };
    } else {
        warn!("{} User entered on command line is not admin", FN_NAME);
    }

    Ok(())
}
