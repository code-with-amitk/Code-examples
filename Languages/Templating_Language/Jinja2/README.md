**Jinja2**

### [Jinja2](https://ttl255.com/jinja2-tutorial-part-1-introduction-and-variable-substitution/)
- Templating languages allow creation of text based documents where some of the content can be dynamically generated.
- Resulting files can be HTML, JSON, XML, or anything that uses pure text as the encoding.

<a name=vs></a>
### Variable Substitution
- Check which parts can remain unchanged, and which can be parametrized. 
```c
hostname abc-test               //Variable
no ip domain lookup             //Static
ip name-server 1.1.1.1          //Variable
ntp server 0.pool.ntp.org       //Variable

//Variable are filled with templates
hostname {{ hostname }}                 
no ip domain lookup
ip name-server {{ name_server }}    
ntp server {{ ntp_server }}
```
**Python jinja Example**
```py
> Open vscode
$ pip install jinja2
$ vim test.py

from jinja2 import Template
template = """
hostname {{ hostname }}
no ip domain lookup
ip name-server {{ name_server }}
ntp server {{ ntp_server }}
client-secret {client_secret}
"""

data = {
    "hostname": "abc-test",
    "name_server": "1.1.1.1",
    "ntp_server": "0.pool.ntp.org",
}

print(Template(template).render(data))

$ python.exe .\test1.py
hostname abc-test
no ip domain lookup
ip name-server 1.1.1.1
ntp server 0.pool.ntp.org
client-secret {client_secret}             //jinja only parse {{ }}
```
