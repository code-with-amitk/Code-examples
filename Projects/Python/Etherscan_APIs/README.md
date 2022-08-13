**Etherium Blockchain**
- **Code**
  - [1. Get ether balance of My account on Eherium](#g1)
  - [2. Get all transactions of my account on Eherium](#g2)
  
[Tim's youtube](https://www.youtube.com/watch?v=GoXwIVyNvX0)

## [Etherscan APIs](https://docs.etherscan.io/)
- Etherscan is a blockchain explorer/search/API/analytics platform for Ethereum, a decentralized smart contracts platform.
- These APIs can:
1. Get all transcations of specific account(or address)
2. Ask smart contract
3. Get price of etherium
4. many others things

<a name=g1></a>
### [1. Get ether balance of My account](https://docs.etherscan.io/api-endpoints/accounts)
```py
# API call we need to make to get account balance
'''
https://api.etherscan.io/api  
   ?module=account
   &action=balance
   &address=0xde0b295669a9fd93d5f28d9ec85e40f4cb697bae
   &tag=latest
   &apikey=YourApiKeyToken                      #Create account on etherscan.io, and create API_KEY
'''

$ sudo apt-get install python3-matplotlib

$ vim test.py
from requests import get    #For making http requests
from matplotlib import pyplot as plt
API_KEY="W2TBAC3SXSHU3RDZN6WWFK66IZ2BGBE2W7"            #API_KEY from etherscan.io after creating account
address = "0xde0b295669a9fd93d5f28d9ec85e40f4cb697bae"
BASE_URL = "https://api.etherscan.io/api"
ETHER_VALUE = 10 ** 18  #10pow18

# module, action, address   //positional arguments
# kwargs    //variable number of arguments stored as dictionary
# f is fstrings allows to embed expression inside curly braces
def create_url(m, ac, ad, **kwargs):    #Create url
    url = BASE_URL + f"?module={m}&action={ac}&address={ad}&apikey={API_KEY}"
    for key,value in kwargs.items():
        url += f"&{key}={value}"    #Adding tag="latest"
    return url

def get_account_balance(address):
    etherscan_url = create_req("account", "balance", address, tag="latest", x="2")
    response = get(etherscan_url)
    data = response.json()
    #print("In wei:" + data)
    return int(data["result"]) / ETHER_VALUE    #Value in ether

print (get_account_balance(address))

$ python3 test.py 
342270.6259031858
```

<a name=g2></a>
## 2. Get all transactions of my account
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
