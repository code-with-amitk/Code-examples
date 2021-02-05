## Exception class
- **What** Exception class is used to create our own exception types.
- **Why own exception types are needed?**
  - *1.* We want to display custom message to user at time of exception.
  - *2.* Perform some logging on Log server
  - *3.* Block security sensitive information from being dumped. An exception might contain sensitive information, we donot want to show this to user.
