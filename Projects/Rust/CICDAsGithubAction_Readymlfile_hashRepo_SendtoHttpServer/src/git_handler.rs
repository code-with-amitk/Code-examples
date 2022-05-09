use argon2::{self, Config};
use git2::Repository;
use log::{error, warn};
use serde_json::Value;
use std::collections::HashMap;
use std::fs::File;
use std::io::prelude::*;

pub const REPOSITORY_URL: &str = "https://github.com/amitkumar50/test-repo";
pub const FILE: &str = ".oblivious/services.yml";
pub const PATH_TO_CLONE: &str = "C:/Oblivious/";
pub const DEFAULT_FILE: &str = "C:/test";
pub const ADMIN: &str = "admin";

#[derive(Debug)]
pub struct Git {
    hm: HashMap<String, String>,
    file_hash: Option<String>,
}
impl Git {
    pub fn new() -> Self {
        Self {
            hm: HashMap::new(),
            file_hash: None,
        }
    }

    pub fn is_user_admin(user: String) -> (bool, Option<String>) {
        const FN_NAME: &str = "is_user_admin";
        warn!("{}", FN_NAME);

        let git = Self::checkout_read_yaml();
        let dir_hash = git.file_hash;

        //Is user present in services.yml on github?
        let role = git.hm.get(&user).unwrap();
        if role.is_empty() {
            warn!("User not found in yml file");
            return (false, dir_hash);
        }
        if !role.eq(ADMIN) {
            warn!("User role is not admin");
            return (false, dir_hash);
        }
        (true, dir_hash)
    }

    pub fn calc_hash(file: &mut File) -> Option<String> {
        const FN_NAME: &str = "calc_hash";
        warn!("{}", FN_NAME);

        let mut contents = String::new();
        let file_str = file
            .read_to_string(&mut contents)
            .expect("Unable to read file as string")
            .to_be_bytes();

        let salt = b"randomsalt";
        let config = Config::default();
        let file_hash = match argon2::hash_encoded(&file_str, salt, &config) {
            Ok(f) => f,
            Err(e) => {
                error!("{} {}", FN_NAME, e);
                "".to_string()
            }
        };
        Some(file_hash)
    }

    pub fn checkout_read_yaml() -> Self {
        const FN_NAME: &str = "checkout_read_yaml";
        warn!("{}", FN_NAME);

        let mut a = Self::new();
        let services_yaml = PATH_TO_CLONE.to_owned() + FILE;
        let _repo = match Repository::clone(REPOSITORY_URL, PATH_TO_CLONE) {
            Ok(r) => r,
            Err(e) => panic!("{} failed to clone {} ", FN_NAME, e),
        };

        //Open and Read services.yml file
        let mut file = match File::open(services_yaml) {
            Ok(a) => a,
            Err(e) => {
                error!("{} Error {}", e, FN_NAME);
                File::create(DEFAULT_FILE).unwrap()
            }
        };

        a.file_hash = Self::calc_hash(&mut file);

        //Parse services.yml and fill in json object
        let json: Value = match serde_json::from_reader(file) {
            Ok(a) => a,
            Err(e) => {
                error!("{} Error {}", FN_NAME, e);
                Value::default()
            }
        };

        //Parse json and store in <key=role, value=username> format

        let person = &json["person"];
        for (key, value) in person.as_object().unwrap() {
            a.hm.insert(key.to_string(), value.to_string());
        }
        //println!("json:{}", json);
        a
    }
}
