- [R2: Take home challenge](#r)

## R2. THC
### Question
Design CI/CD tool as github action.
- _1._ .oblivious folder, .oblivious/service.yaml exists in repository
- _2._ Confirm service.yaml confirms to json schema.
```c
{
	"person": {
		"amit": "admin",
		"ram": "user"
	}
}
```
- _3._ Write a program 
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
### [Code](/Projects/Rust/CICDAsGithubAction_Readymlfile_hashRepo_SendtoHttpServer/)
