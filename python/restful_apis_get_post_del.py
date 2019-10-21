# pip install virtualenv
# mkdir test;  virtualenv test; cd test; source bin/activate; 
#(test) [root@<>] # pip install flask flask_restful;                                //Every virtualenv will have its set of softwares

# vim test.py
from flask import Flask                                                         #Step-1: import Flask class from package flask
from flask_restful import Api, Resource, reqparse                        #API module adds functionality to flask which helps to add routes, resources

app = Flask(__name__)                                                         #Step-2: Give python file a unique name
api = Api(app)
users = [                                                                              #Step-3: list. Create list of users to simulate data store. Actual data store will be DB.
    {"name": "Nicholas", "age": 42, "occupation": "Network Engineer"},  #Dictionary1
    {"name": "Elvin", "age": 32, "occupation": "Doctor"},                       #Dictionary2
    {"name": "Jass", "age": 22, "occupation": "Web Developer"}               #Dictionary3
]

class User(Resource):                                                            #Step-4: 4 APIs will be defined inside user resource class
    def get(self, name):                                                          #Step-5: Restful-API GET end point. Retrieve particular user details by specifying the name
        for user in users:                                                          #iterate through the list
            if(name == user["name"]):                                        #if name if found return it. 200OK
                return user, 200
        return "User not found", 404

    def post(self, var):                                                        #Step-6: Restful-API POST endpoint. Create a new user
        parser = reqparse.RequestParser()                                  #Get Object(parser) of reqparse class using RequestParser() function
        parser.add_argument("age")                                             #Add age, occupation variable to Object(parser).
        parser.add_argument("occupation")
        args = parser.parse_args()                                            #Store Object(parser) in args
        for x in users:                                                        #if user already exists, we will return user exists
            if(var == x["name"]):
                return "User with name {} already exists".format(var), 400
        user = {"name": name, "age": args["age"], "occupation": args["occupation"]}    #Else we will create a new user and return 201
        users.append(user)
        return user, 201

    def put(self, name):                                                            #Step-7: Restful-API PUT. Update record. Create new one if does not exist
        parser = reqparse.RequestParser()
        parser.add_argument("age")
        parser.add_argument("occupation")
        args = parser.parse_args()
        for x in users:                                                                #Loop thru the Users List
            if(name == x["name"]):                                                                            # if Users list contains the name which is passed as function argument. ie User already exists
                x["age"] = args["age"]                                                                           # Update age present in Users list with age received in parsed arguments.
                x["occupation"] = args["occupation"]                                                      # Update occupation present in Users list with occupation received in parsed arguments.
                return x, 200
        x = {"name": name, "age": args["age"], "occupation": args["occupation"]}       # else. User is not present in Users list, Lets create and append to Users List and return 201
        users.append(x)
        return x, 201

    def delete(self, test):                                                        #Step-8: Restful-API DELETE. To delete a user from DB
        global users                                                                #Specify 'users' in global scope
        users = [x for x in users if x["name"] != test]                 # Remove entry named (test) from list and update the "users" list.
        return "{} is deleted.".format(test), 200

api.add_resource(User, "/user/<string:name>")                        #Step-9: Add resource. This creates a route. add_resource(imported_class, route_to_the_class)
app.run(debug=True)                                                            # Run in debug mode gives helpful warning messages if something went wrong. It is useful in development setting, but should never be used in production setting.
# python test.py
 * Serving Flask app "test" (lazy loading)
 * Environment: production
   WARNING: This is a development server. Do not use it in a production deployment.
   Use a production WSGI server instead.
 * Debug mode: on
 * Running on http://127.0.0.1:5000/ (Press CTRL+C to quit)
 * Restarting with stat
 * Debugger is active!
 * Debugger PIN: <>


#2. Accessing APIs using Clients
#    a. Using client Insomnia
#    - Install "Insomnia" client application to send RestAPI calls in chrome. Access it using (chrome://apps/)
#        GET: 127.0.0.1:5000/user/Elvin
#        POST: 127.0.0.1:5000/user/Amit 
#        DELETE: 127.0.0.1:5000/user/Amit
#    b. Using firefox web Browser:        http://127.0.0.1:5000/user/Elvin
#    c. Using Python Code    https://www.geeksforgeeks.org/get-post-requests-using-python/
