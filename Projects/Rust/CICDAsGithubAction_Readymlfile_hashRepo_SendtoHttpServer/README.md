- [Question](#q)
- **[Crates used](#cu)**
- **[Code Architecture](#a)**

<a name=q></a>
### Question
- _1._ Checkout repository .oblivious from github.
  - .oblivious contains services.yml file
```c
> cat oblivious/services.yml
{
	"person": {
		"amit": "admin",
		"ram": "user"
	}
}
```
- _2._ Take command line argument from program.
```c
$ ./a.exe username
  - Checkout repo, Read username from services.yml
  - compare username(entered at command line with), username from services.yml
  - if (role != admin) {
      //throw error
  } else    //role=admin
    - Create packet.
      - auth_header=username
      - body:
          Hash of complete repo
          meta-data=branch,date,repo name ----------{auth_header,body}--------> Server
                                          <--------Hello<username>------------
  }
```

<a name=cu></a>
### Crates Used
- argon2id: Hashing
- reqwest: HTTP request sending
- tokio: async programming
- git2: Checkout repo
- serde_json: Reading username, role from services.yml file


<a name=ca></a>
### Code Architecture
- **src\main.rs**
  - Start tokio runtime for async programming
  - call common module's work() to do rest of work.

**src\common.rs**
- *work():* Does all work
  - *Parse:* calls parser module

**src\parse.rs**
- *Parser:* Parse Command line Argument & store command line argument in struct.
```c
USAGE:
    Oblivious.exe -u <username>

FLAGS:
    -h, --help       Prints help information
    -V, --version    Prints version information

OPTIONS:
    -u <username>        username to be parsed from service.yaml [default: test]
```

**src\git_handler.rs**
- This module does all handling related to git, at present "checkout"
- Checkout the repository having services.yml to C:\Oblivious
  - if repository does not have services.yml file throw error
