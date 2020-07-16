# DropBox/Google Drive/Cloud File Storage

## A. REQUIREMENTS
#### A1. FUNCTIONAL
- **Word or Xls Document or Videos** User should be able to
  - ***Upload***
    - Create document
    - Write into document
    - Document should be auto-saved.
  - ***Download*** the documents.
  - ***Share*** files with other users
  - ***Synchronization*** Automatic synchronization between devices, i.e., after updating a file on one device, it should get synchronized on all devices.
  - ***Offline upload/edits*** User should be able to upload/edit while he's offline, information should go on drive as he comes online.
#### A2. NON-FUNCTIONAL
- S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
  - Scalable, Secure, SOA
  - Logging, Load, Latency
  - Cache(Invalidation, negative cache)
  - Available, Accurate, Analyze, Authenticate
  - Reliable, Redundant(Using DB)
  - Fast
#### A3. Extended 
- **Snaphot of data** System should support snapshotting of the data, so that users can go back to any version of the files.

## B. BOE Calculations
#### B1. Free Account User
- Free account user can use = 15 GB space.
- This is collective space, user can use it in docs, xls, videos (any way they want) but sum up should be < 15 GB.

| | Word Document | Xls Document | Videos |
| --- | --- | --- | --- |
| Max Size/Document | 2 MB | 20 MB | 1 GB |
| No of documents | 1000 | 100 | 10 |
| Size occupied | 2x10<sup>9</sup> | 2x10<sup>9</sup> | 1x10<sup>9</sup> |
> Total size occupied = 14 GB

#### B2. For paid account
- 15 TB space allocated for basic paid account.

| | Word Document | Xls Document | Videos |
| --- | --- | --- | --- |
| Max Size/Document | 200 MB | 2000 MB | 1 TB |
| No of documents | 10000 | 10000 | 10 |
| Size occupied | 2x10<sup>12</sup> | 2x10<sup>12</sup> | 1x10<sup>12</sup> |
> Total size occupied = 15 TB

#### B3. How many users are using Google Drive/Gmail?
- All users using Gmail are given their personal google-drive.

| Percentage & Population | |
| --- | --- |
| World Population(2019) | 7 Billion(10<sup>9</sup>) |
| 40% using internet | 28x10<sup>8</sup> |
| 50% of this 40% using Gmail | 28x10<sup>7</sup> |
| <ul><li>Free Users(50%)</li></ul> <ul><li>Paid Users(50%)</li></ul>| <ul><li>Space used by free Users(14x10<sup>7</sup>x15 GB)</li></ul> <ul><li>Space used by paid Users(14x10<sup>7</sup>x15 TB)</li></ul> |
> Total Space used = 14x15x10<sup>16</sup> + 14x15x10<sup>19</sup> = 210x10<sup>19</sup> = 10<sup>22</sup> bytes
