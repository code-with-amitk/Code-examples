[restful-apis-webservice.py](https://codeburst.io/this-is-how-easy-it-is-to-create-a-rest-api-8a25122ab1f3),
[Article-2](https://gist.github.com/leon-sleepinglion/97bfd34132394e23ca5905ec730f776a)

## STEPS
### 1. Create virtual Enviornment
```python
- Every virtualenv will have its set of softwares.
# pip install virtualenv
# mkdir test;  
# virtualenv test; 
# cd test; 
# source bin/activate; 
(test) [root@<>] # pip install flask flask_restful;
```

### 2. Create & Run Web-Service
- 1. import flask_restful
- 2. Give python file as unique name
- 3. Create userDB using lists
- 4. Create class to define restful APIs.
```python
    def get():  //get particular user or all users
    def post(): //Create a new user in DB
    def put():  //Update DB, add new user
    def delete():   //delete 1 record from DB
```    
- 5.  Create a route to web service, Run in debug mode.

### 3. Access the Restful APIs using clients
- 1. Using client Insomnia
```python
   - Install "Insomnia" client application to send RestAPI calls in chrome. Access it using (chrome://apps/)
        GET: 127.0.0.1:5000/user/Elvin
        POST: 127.0.0.1:5000/user/Amit 
        DELETE: 127.0.0.1:5000/user/Amit
```        
- 2. Using firefox web Browser:        http://127.0.0.1:5000/user/Elvin
- 3. Using Python Code    https://www.geeksforgeeks.org/get-post-requests-using-python/

### Code
```python
"""
#1. import Flask class from package flask
# API module adds functionality to flask which helps to add routes, resources
from flask import Flask
from flask_restful import Api, Resource, reqparse

#2. Give python file a unique name
app = Flask(__name__)
api = Api(app)

#3. Create list of users to simulate data store. Actual data store will be DB.
users = [
    {"name": "Nicholas", "age": 42, "occupation": "Network Engineer"},  #Dictionary1
    {"name": "Elvin", "age": 32, "occupation": "Doctor"},                       #Dictionary2
    {"name": "Jass", "age": 22, "occupation": "Web Developer"}               #Dictionary3
]

#4. Create class to define RESTFUL APIs
# get(): Retrieve particular user details by specifying the name
class User(Resource):
    def get(self, name):
        for user in users:
            if(name == user["name"]):
                return user, 200
        return "User not found", 404

# post(): Create a new user
#   parser is Object(parser) of reqparse class using RequestParser() function
#   Add age, occupation variable to Object(parser).
#   store Object(parser) in args
#   check user's list,
#       if user already exists, we will return user exists
#       else create a new user and return 201
    def post(self, var):
        parser = reqparse.RequestParser()
        parser.add_argument("age")
        parser.add_argument("occupation")
        args = parser.parse_args()
        for x in users:
            if(var == x["name"]):
                return "User with name {} already exists".format(var), 400
        user = {"name": name, "age": args["age"], "occupation": args["occupation"]}
        users.append(user)
        return user, 201    

# put(): Update record. Create new one if does not exist
# Loop thru the Users List
#   if Users list contains the name which is passed as function argument. ie User already exists
#       - Update age present in Users list with age received in parsed arguments.
#   else. User is not present in Users list, Lets create and append to Users List and return 201
    def put(self, name):
        parser = reqparse.RequestParser()
        parser.add_argument("age")
        parser.add_argument("occupation")
        args = parser.parse_args()
        for x in users:
            if(name == x["name"]):
                x["age"] = args["age"]
                x["occupation"] = args["occupation"]
                return x, 200
        x = {"name": name, "age": args["age"], "occupation": args["occupation"]}
        users.append(x)
        return x, 201

# delete(): To delete a user from DB
# Specify 'users' in global scope
# Remove entry named (test) from list and update the "users" list.
    def delete(self, test):
        global users
        users = [x for x in users if x["name"] != test]
        return "{} is deleted.".format(test), 200    

# 5: Add resource. This creates a route. add_resource(imported_class, route_to_the_class)
# Run in debug mode gives helpful warning messages if something went wrong.
# It is useful in development setting, but should never be used in production setting.
api.add_resource(User, "/user/<string:name>")    
app.run(debug=True)

-> ACCESS WEBSERVICE USING METHODS PROVIDED IN DESCRIPTION.
``` 
