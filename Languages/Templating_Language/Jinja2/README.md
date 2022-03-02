**Jinja2**
- [Variable Substitution](#v)
- [Dictionary](#d)
- [Undefined Variables](#u)

### [Jinja2](https://ttl255.com/jinja2-tutorial-part-1-introduction-and-variable-substitution/)
- Templating languages allow creation of text based documents where some of the content can be dynamically generated.
- Resulting files can be HTML, JSON, XML, or anything that uses pure text as the encoding.

<a name=v></a>
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

<a name=d></a>
### Dictionary Keys
```py
> Open vscode
$ pip install jinja2
$ vim test.py

from jinja2 import Template
template = """
hostname {{ interface.name }}
no ip domain lookup
ip name-server {{ interface.ip }}
"""

d = {
"interface": {                                          //key
    "name": "GigabitEthernet1/1",                       //values
    "ip": "10.0.0.1/31",
  }
}
print(Template(template).render(d))

$ python.exe .\test1.py
hostname GigabitEthernet1/1
no ip domain lookup
ip name-server 10.0.0.1/31
```

<a name=u></a>
### Undefined Variables
#### Leaving string empty
```py
from jinja2 import Template

template = "Device {{ name }} is of type: {{ type }}."
data = {
    "name": "abc",
}
print(Template(template).render(data))

# python3.exe test1.py
Device abc is of type: .                    //type is not rendered
```
#### StrictUndefined 
```py
from jinja2 import Template, StrictUndefined
template = "Device {{ name }} is of type: {{ type }}."
data = {
    "name": "abc",
}
print(Template(template, undefined=StrictUndefined).render(data))
$ python3.exe test1.py
Error                                               //Error if a variable is not found
```
