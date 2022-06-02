**Simple HTTP Server**
- [How it works](#h)

### Simple HTTP Server
<a name=h></a>
#### How it works
Server exposes 4 endpoints to http clients.
```rs
//Here we have taken Resource=user.

GET /users         | returns all users                              |   get_users()
GET /users/{id}    | returns the user with a given id               |   get_user_by_id()
POST /users        | takes in a JSON payload and creates a new user |   post_add_user()
DELETE /users/{id} | deletes the user with a given id               |   delete_user()
```

**Cargo.toml**
```rs
$ cargo init --bin rest-based-http-server      //1. Create project
$ Cargo.toml                                   //2. Include dependencies (actix,reqwest,serde)
[package]
name = "rest-based-http-server"
version = "0.1.0"
authors = ["amit"]
edition = "2018"

[dependencies]
actix-web = "2.0.0"
actix-web-httpauth = { git = "https://github.com/actix/actix-web-httpauth" }
chrono = { version = "0.4.10", features = ["serde"] }
derive_more = "0.99.2"
diesel = { version = "1.4.2", features = ["postgres","uuidv07", "r2d2", "chrono"] }
dotenv = "0.15.0"
futures = "0.3.1"
r2d2 = "0.8.8"
serde = "1.0"
serde_derive = "1.0"
serde_json = "1.0"
actix-service = "1.0.1"
alcoholic_jwt = "1.0.0"
reqwest = "0.9.22"
actix-rt = "1.0.0"
openssl = { version = "0.10", features = ["vendored"] }
```

**src/main.rs**
```rs
use actix_web::{web, App, HttpServer};
pub(crate) mod handlers;

#[actix_rt::main]                             //3. Mark main function to be executed by the actix runtime using the actix_rt::main attribute
async fn main() -> std::io::Result<()> {
    std::env::set_var("RUST_LOG", "actix_web=debug");

    HttpServer::new(move || {                 //4. Start http server
        App::new()      //Add a App
            .route("/users", web::get().to(handlers::get_users))            //5. Mapped http://ip:port/users    => get_users()
            .route("/users/{id}", web::get().to(handlers::get_user_by_id))  //          http://ip:port/users/1  => get_user_by_id()
            .route("/users", web::post().to(handlers::post_add_user))       //
            .route("/users/{id}", web::delete().to(handlers::delete_user))
    })
    .bind("127.0.0.1:8080")?        //Run on localhost on a given port
    .run()
    .await
}
```

**src/handlers.rs**
```rs
use actix_web::Responder;
pub async fn get_users() -> impl Responder {              //6. GET CRUD Method
    format!("Http GET get_users()")
}
pub async fn get_user_by_id() -> impl Responder {         
    format!("Http GET/id get_user_by_id()")
}
pub async fn post_add_user() -> impl Responder {          //7. POST CRUD Method       
    format!("Http POST post_add_user()")
}
pub async fn delete_user() -> impl Responder {            //8. DELETE_user
    format!("Http DELETE delete_user()")
}
```

**Build & Run**
```rs
$ cargo build
$ cargo run
..

//Run from command prompt
cmd> curl 127.0.0.1:8080/users            //GET www.127.0.0.1:8080/users HTTP/1.1
Http GET get_users()
cmd> curl -X POST 127.0.0.1:8080/users    //POST www.127.0.0.1:8080/users HTTP/1.1
Http POST post_add_user()
```
