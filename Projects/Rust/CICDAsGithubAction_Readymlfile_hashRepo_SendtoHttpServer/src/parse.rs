use clap::{App, Arg};
use log::warn;

/// Parser module for parsing Command line and config file
#[derive(Debug)]
pub struct Parser {
    pub username: String,
}
impl Parser {
    fn defaults() -> Self {
        Self {
            username: String::from("admin"),
        }
    }

    pub fn parse_command_line() -> Self {
        const FN_NAME: &str = "parse_command_line";
        warn!("{}", FN_NAME);

        let mut parser = Self::defaults();
        let matches = App::new("Oblivious")
            .version("0.1")
            .arg(
                Arg::with_name("username")
                    .short("u")
                    .help("username to be parsed from service.yaml")
                    .required(true)
                    .takes_value(true)
                    .default_value("test"),
            )
            .get_matches();

        if let Some(c) = matches.value_of("username") {
            println!("Value for username: {}", c);
            parser.username = c.to_string();
        }
        parser
    }

    pub fn _parse_config_file() {}
}
