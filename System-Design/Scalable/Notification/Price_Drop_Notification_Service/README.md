**Price Drop Notification Service**
- [HLD](#hld)


## Price Drop Notification Service
- _1._ How do you find out that the price has dropped for a product?
- _2._ How does the system send emails,whatsapp etc?

<a name=hld></a>
### HLD
- Always follow this path `1 user, 1 product` > `2 user, 100 products` > `1M user, 1B products`
#### A. 1 user 1 product
- Company PC have product.csv file, which holds data about product.
- Product:
  - View: There is no read lock, view any number of times
  - Change Price: Admin can change price(taking Write lock on Row) in product.csv
  - Buy: Customer can buy if no write lock and count>1
- Notification: [inotify]() will keep monitoring products.csv as soon change happens it sends HTTP POST to buyer and notifies
```c
//product.csv
productId   sellerId  price   count   category  mfgDate expDate sold/unsold review/ratings 

  Admin to change price
      \/
  |----Company PC---|             |-----Buyer------|
  | products.csv    | ====LAN==== |                |
  |   /\            |             |                |
  | (inotify)thread -price change->                |
  |-----------------|   HTTP POST |----------------|
```
#### B. A. 2 user 100 product
- Design Same as above, table will have 100 entries.

#### C. 1M user, 1B products
- products.csv will become shared DB
- Taken from [Build Operational Analytics Pipeline](https://d1.awsstatic.com/architecture-diagrams/ArchitectureDiagrams/build-operational-analytics-pipeline-on-AWS-modern-data-architecture.pdf?did=wp_card&trk=wp_card)

<img src=images/price-drop-notification-service.JPG width=900/>
