
### Plugins
Simply put, plug-in is a computer software that adds new functions to a host program without altering the host program itself. 
```py
# cat discover_plugin.py
import importlib
import pkgutil

discovered_plugins = {
    name: importlib.import_module(name)
    for finder, name, ispkg
    in pkgutil.iter_modules()
    if name.startswith('ftp')
}

print (discovered_plugins)

> python.exe .\discover_plugins.py
{'ftplib': <module 'ftplib' from 'C:\\Users\\amitk\\AppData\\Local\\Programs\\Python\\Python310\\lib\\ftplib.py'>}
> 
```
