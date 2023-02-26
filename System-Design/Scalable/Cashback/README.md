**Cashback**
- [Requirements](#r)
- [BOE](#b)
- [API Design](#api)
- [DB Design](#db)
- [HLD](#hld)

## Cashback System
**What is Cashback?**
- When you buy something, you get a percentage of the amount it cost paid back to you. Merchants (Eg: Gpay) decides on percent of amount to be returned to customer. Cashback can be on credit and debit cards.

<a name=r></a>
### 1. Requirements
System should meet needs of the users and merchants.
#### Functional
- _1. User Registration and Authentication:_ User entry (username,password) should be there in cashback system
- _2. Merchant Registration:_ Merchant should register with following details (business name, contact information, and payment methods).
- _3. Transaction Record:_ System should be able to record each transaction made by a user and merchant, including the transaction amount, date, and time
- _4. Cashback Calculation:_ System must calculate the cashback amount based on the transaction amount and the cashback percentage or amount offered by the merchant.
- _5. Cashback Redemption:_ users can redeem their cashback rewards. Either on future transactions or transfer to bank
#### Non Functional
- _1. Reporting and Analytics:_ Provide detailed reports and analytics on transaction history, cashback earned, and other key metrics to Users,Merchants.
- _2. Security and Privacy:_ Must ensure the security and privacy of user and merchant data, including the use of encryption, secure authentication protocols, and data backup procedures.
- _3. Customer Support:_ help with account issues, transaction problems, and cashback redemption inquiries.

<a name=b></a>
### 2. BOE
- Storage will be decided on number of transactions.
- Some users will do multiple, while some will not do any transaction. So we will assume 1 transaction/user.
- India: 80CR people using paytm. 80Cr transactions/day
#### Storage Estimates
- **Transactions Storage:** 1KB = 1 transaction. 80x10<sup>9</sup> x 10 kB = 80TB/Day. 
- User, Merchant data storage is seperate

> Note: These are only estimates, actual may depend on variety of factors, including user behavior, market conditions, and system performance.

<a name=api></a>
### 3. API Design
API's inline with requirements
```c
// User Management APIs
HTTP_Code user_registration (username, password, 2_factor_auth)
HTTP_Code user_login (username, password, 2_factor_auth)
HTTP_Code user_account_management (username, auth_token, method="delete|update", timestamp)

// Merchant Management APIs

// Transaction Tracking, Processing APIs
Json_Response get_all_transactions (userId or merchantId, auth_token)

// Cashback API
Json_Response get_cashback_details (userId or merchantId, auth_token, start_time, end_time)
Http_code set_cashback_rule (productId, percent, eligiblity_rules, admin_token)    //Should be used by admin

// Payment Gateway Integration APIs
Http_code connect_to_payment_gateway (MerchantID, gatewayID, merchant_token)      //Merchant to add new payment gateway

// Reporting & Analytics APIs
json_response get_cashback_report (userId|merchantId, auth_token, startTime, endTime)    //Get detailed reports and analytics on the cashback transactions
json_response get_activity_report (userId|merchantId, auth_token, startTime, endTime)    //Get detailed reports on user activity
```

<a name=db></a>
### 4. DB Design
- [How to do DB Design?](/System-Design/Database_Design/)
#### 1. Nouns/Entities
```c
User
Merchant
Transaction
Cashback (or Rewards)
```
#### 2. ERD Diagram
```c
  1 -------- * (Cashback)
  1 -------- * (Trasaction)
User

  1 -------- * (Trasactions)
Merchant    

  1 -------- * (User)
  1 -------- * (Merchant)
Transaction

  1          *
  ------------
Cashback     User

  1             1
  ---------------
Transaction   Cashback
```
#### 3. DB Tables
**4 Main tables**
```c
// Users Table
| user_id(pk) | name | email_id | password | address | DOB | etc |

CREATE TABLE users (
   user_id serial PRIMARY KEY,  
   name varchar(50) NOT NULL,
   email varchar(150) NOT NULL,
   address varchar(255) NOT NULL,
   dob DATE
);


// Merchants table
| MerchantID(pk) | Name | Email | Address | etc

CREATE TABLE merchants (
   merchant_id serial PRIMARY KEY,
   name varchar(50) NOT NULL, 
   email varchar(150) NOT NULL,
   address varchar(255) NOT NULL
);


// Transactions Table
| TransactionID(pk) | UserID(fk) | MerchantID(fk) | Amount | Date | etc

CREATE TABLE transactions (
   transaction_id serial PRIMARY KEY,
   amount integer,
   order_date DATE,
   user_id INTEGER NOT NULL,
   merchant_id INTEGER NOT NULL,
   CONSTRAINT user_id FOREIGN KEY (user_id) REFERENCES users (user_id),
   CONSTRAINT merchant_id FOREIGN KEY (merchant_id) REFERENCES merchants (merchant_id)
);


// Cashback Table
| cashbackID | UserID(fk) | TransactionID(fk) |  Amount |  Date | etc

CREATE TABLE cashback (
   cashback_id serial PRIMARY KEY,
   amount integer,
   order_date DATE,
   user_id INTEGER NOT NULL,
   transaction_id INTEGER NOT NULL,
   CONSTRAINT user_id FOREIGN KEY (user_id) REFERENCES users (user_id),
   CONSTRAINT transaction_id FOREIGN KEY (transaction_id) REFERENCES transactions (transaction_id)
);

# \dt
            List of relations
 Schema |     Name     | Type  |  Owner
--------+--------------+-------+----------
 public | cashback     | table | postgres
 public | merchants    | table | postgres
 public | transactions | table | postgres
 public | users        | table | postgres

```

#### Nosql vs SQL
- **Not use nosql DB:**
  - Nosql DB are eventual consistent, but this system might need strong consistency
  - nosql does not support complex queries & require join and aggregation.

<a name=hld></a>
### 4. HLD
#### 1. User interface:
- User initiates transaction
- Transaction data is sent to transaction processing system
#### 2. Transaction processing system:
- Transaction data is received and processed
- Cashback amount is calculated based on the cashback rules engine
- Cashback amount is added to the user's cashback balance in the database
#### 3. Cashback rules engine:
- Defines the rules and conditions for cashback, such as transaction amount, product category, or promotion type
- Calculates cashback amount based on the rules
#### 4. Database:
- Stores user information, transaction data, and cashback balances
- Updates user's cashback balance with the calculated cashback amount
#### 5. Analytics and reporting:
- Provides insights into cashback program performance, such as transaction volume, cashback redemption rates, and user engagement
- Integration with payment gateways

**Diagram Image**
<image src=images/cashback_system.png width=900/>

**[Text File Diagram](/System-Design/Scalable/Cashback/images/cashback_system.txt)**
