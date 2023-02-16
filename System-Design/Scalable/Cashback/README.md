**Cashback**
- [Requirements](#r)

## Cashback System
**What is Cashback?**
- When you buy something, you get a percentage of the amount it cost paid back to you. Merchants (Eg: Gpay) decides on percent of amount to be returned to customer. Cashback can be on credit and debit cards.

### Requirements
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

### BOE
- Storage will be decided on number of transactions.
- Some users will do multiple, while some will not do any transaction. So we will assume 1 transaction/user.
- India: 80CR people using paytm. 80Cr transactions/day
Storage Estimates
