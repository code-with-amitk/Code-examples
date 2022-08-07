**Etherium Blockchain**
- [1. Get ether balance of My account](#g1)

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
   
$ vim test.py
from requests import get    #For making http requests
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
