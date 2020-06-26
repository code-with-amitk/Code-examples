## Twitter Design

### A. REQUIREMENTS
#### A1. FUNCTIONAL
  1. Searching
     - User can find other users using names.
  2. Newsfeed:
     - Followers should get notifiications on their wall as person posts.
  3. Tagging
     - if user tags posts to someone, tagged should see post on his timeline.
     
#### A2. NON-FUNCTIONAL
  - S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
    - Scalable, Secure, SOA
    - Logging, Load, Latency
    - Cache(Invalidation, negative cache)
    - Available, Accurate, Analyze, Authenticate
    - Reliable, Redundant(Using DB)
    - Fast
     
### B. HLD
#### B1. 3 users(A,B,C) Design
  - 3 files. User A writes to file-a. Changes are pushed to user-B,C.
  - 
