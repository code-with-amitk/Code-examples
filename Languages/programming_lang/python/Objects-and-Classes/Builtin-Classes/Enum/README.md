## Enum class
- class in python for creating enumerations
  - The name of the enum is displayed using ‘name’ keyword.
  - Using type() we can check the enum types.

### Creating enum
```
from enum import Enum     #from class import function-name
class Country(Enum):
  india = 93
  usa = 355
  france = 213
print('name= {}'.format(Country.india.name))             #name=india
print('value= {}'.format(Country.india.value))           #Value=93
```
