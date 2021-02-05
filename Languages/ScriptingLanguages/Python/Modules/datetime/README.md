## datetime module
- **What** Contains classes for manipulating dates and times.

### 1. Print number of days between two dates
```
from datetime import date
fdate = date(2014, 7, 2)
ldate = date(2014, 7, 11)
diff = ldate - fdate
print(diff.days)
```
