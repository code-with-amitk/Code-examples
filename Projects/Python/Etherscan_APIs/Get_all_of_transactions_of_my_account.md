
## Get all transactions of my account


```py
$ vim get_all_of_transactions_of_my_account.py
from requests import get
from matplotlib import pyplot as plt
from datetime import datetime

API_KEY="W2TBAC3SXSHU3RDZN6WWFK66IZ2BGBE2W7"
address = "0xc5102fE9359FD9a28f877a67E36B0F050d81a3CC"
BASE_URL = "https://api.etherscan.io/api"

# 1. We need to create this API and make http GET request on it
'''
https://api.etherscan.io/api
   ?module=account
   &action=txlist
   &address=0xc5102fE9359FD9a28f877a67E36B0F050d81a3CC
   &startblock=0
   &endblock=99999999
   &page=1
   &offset=10
   &sort=asc
   &apikey=YourApiKeyToken
'''

        # module, action, address   //positional arguments
        # kwargs    //variable number of arguments stored as dictionary
        # f is fstrings allows to embed expression inside curly braces
def create_req(module, action, address, startblock, endblock, page, offset, sort):
    url = BASE_URL + f"?module={module}&action={action}&address={address}&startblock={startblock}&endblock={endblock}&page={page}&offset={offset}&sort={sort}&apikey={API_KEY}"
    return url

        # module = account
        # action = balance
        # address =
        # tag = latest
def get_all_transactions(address):    
    etherscan_url = create_req("account", "txlist", address, 0, 99999999, 1, 10, "asc")
    response = get(etherscan_url)
    data = response.json()["result"]

    for x in data:
        to = x["to"]
        from_t = x["from"]
        value = x["value"]
        gas = x["gasUsed"]
        time = datetime.fromtimestamp(int(x['timeStamp']))
        print("------------------------")
        print("To:", to)
        print("From:", from_t)
        print("Value:", value)
        print("GasUsed:", gas)
        print("Timestamp:", time)
    
print (get_all_transactions(address))      # This will print all data

$ python3 get_all_of_transactions_of_my_account.py
------------------------
To:
From: 0x9aa99c23f67c81701c772b106b4f83f6e858dd2e
Value: 0
GasUsed: 4457269
Timestamp: 2022-06-08 05:30:11
------------------------
To: 0xc5102fe9359fd9a28f877a67e36b0f050d81a3cc
From: 0x9aa99c23f67c81701c772b106b4f83f6e858dd2e
Value: 0
GasUsed: 57168
Timestamp: 2022-06-08 05:32:50
------------------------
To: 0xc5102fe9359fd9a28f877a67e36b0f050d81a3cc
From: 0x9aa99c23f67c81701c772b106b4f83f6e858dd2e
Value: 0
GasUsed: 57168
Timestamp: 2022-06-08 05:34:00
------------------------
.........
....
```
