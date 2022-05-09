use http::header::{HeaderMap, HeaderValue}; //Create HTTP Header
use http::header::{ACCEPT, CONTENT_TYPE};
use log::warn; //Logging
use reqwest::Client; //Create, Send HTTP Packets
use reqwest::StatusCode;
use std::collections::HashMap;
use tokio::time::timeout;

extern crate argon2; //Hashing repo
pub const SCHEME: &str = "https";
pub const HOST: &str = "1.1.1.1"; //To be read from config file
pub const PORT: &str = "8443"; //To be read from config file
pub const OAUTH_PATH: &str = "/oauth_token/"; //Get oauth token from this path
pub const TCP_KEEPALIVE_SEC: u64 = 100;
pub const IDLE_POOL_PER_HOST: usize = 100;
const REQUEST_TIMEOUT: u64 = 50;

pub struct Sender {}
impl Sender {
    pub fn create_header(username: String) -> Result<HeaderMap, String> {
        const FN_NAME: &str = "create_header";
        warn!("{}", FN_NAME);

        let mut header_map = HeaderMap::new();
        let username_header_value = match HeaderValue::from_str(&username) {
            Ok(h) => h,
            Err(e) => {
                let err_str = format!("{} {:?}", FN_NAME, e);
                warn!("{}", err_str);
                return Ok(header_map);
            }
        };
        let content_type = match HeaderValue::from_str("application/x-www-form-urlencoded") {
            Ok(h) => h,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };

        let accept_value = match HeaderValue::from_str("application/json") {
            Ok(h) => h,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };

        let _ = header_map.insert("auth_header", username_header_value);
        let _ = header_map.insert(CONTENT_TYPE, content_type);
        let _ = header_map.insert(ACCEPT, accept_value);
        Ok(header_map)
    }

    fn build_url(path: &str) -> String {
        const FN_NAME: &str = "build_url";
        warn!("{}", FN_NAME);

        format!("{}//{}:{}{}", SCHEME, HOST, PORT, path)
    }

    pub async fn build_client() -> Result<Client, String> {
        const FN_NAME: &str = "build_client";
        warn!("{}", FN_NAME);

        let keep_alive = std::time::Duration::from_secs(TCP_KEEPALIVE_SEC);
        let builder = Client::builder()
            .danger_accept_invalid_certs(true)
            .tcp_keepalive(keep_alive)
            .pool_max_idle_per_host(IDLE_POOL_PER_HOST);
        let client = match builder.build() {
            Ok(c) => c,
            Err(e) => {
                let err = format!("{} {}", FN_NAME, e);
                //error!("{}", err);
                return Err(err);
            }
        };
        Ok(client)
    }

    pub async fn send(username: String, dir_hash: Option<String>) -> Result<StatusCode, String> {
        const FN_NAME: &str = "send";
        warn!("{}", FN_NAME);

        let url = Self::build_url(OAUTH_PATH);
        let auth_header = match Self::create_header(username) {
            Ok(a) => a,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };

        //For time being authenticate using username,password
        let username = "test";
        let password = "passw0rd";
        let str = match dir_hash {
            Some(s) => s,
            None => "".to_string(),
        };
        let dir_hash1 = str.as_str();

        let mut params = HashMap::new();
        let _ = params.insert("grant_type", "client_credentials");
        let _ = params.insert("client_id", username);
        let _ = params.insert("grant_type", password);
        let _ = params.insert("dir_hash", dir_hash1);

        let klient = match Self::build_client().await {
            Ok(k) => k,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };

        let fut = klient.post(url).form(&params).headers(auth_header).send();
        let timeout_future = timeout(std::time::Duration::from_secs(REQUEST_TIMEOUT), fut);
        let result = match timeout_future.await {
            Ok(r) => r,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };

        let resp = match result {
            Ok(r) => r,
            Err(e) => {
                return Err(format!("{} {}", FN_NAME, e));
            }
        };
        let status = resp.status();

        Ok(status)
    }
}
