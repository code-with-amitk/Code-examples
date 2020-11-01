## std::async
- **What** This is used to create asynchronous task and execute in parallel.
- **Why** std::async is used when calling thread wants value to be returned back. 
  - **promise(input side)** For passing value from calling to called thread.
  - **future(output side)** For retreving values returned by called thred into main() thread. `auto returned_value = get_future()`
  
