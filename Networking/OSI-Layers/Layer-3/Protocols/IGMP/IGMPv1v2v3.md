# Comparison IGMPv1 v2 v3

| | IGMPv1 | IGMPv2 | IGMPv3 |
| --- | --- | --- | --- |
| Supported Messages | <ul><li>Membership Query</li></ul> <ul><li>Membership Report</li></ul> <ul><li>No Leave message</li></ul> | <ul><li>Membership Query</li></ul> <ul><li>Membership Report</li></ul> <ul><li>Leave Group</li></ul> | <ul><li>Same as v2</li></ul> |
| Leave Message (v2, v3) | <ul><li>No Leave Message present</li></ul> <ul><li>*Situation*: Router sends periodic query messages to hosts after 1 min</li></ul> <ul><li>if host is no longer running IGMP it does not reply and router waits for 3 min more. **Wastage of time**</li></ul> | <ul><li>Leave Message introduced in IGMPv2</li></ul> <ul><li> Host sends leave who is not intrested anymore in existant multicast group saving wait time of router</li></ul> | |
| Default timers | query message timer=60sec | Timers are tunable | |
| Querier Election | not present | In case of more than 1 router, this process decides which router to send query messages | |
| Group-Specific Query | <ul><li>not present</li></ul> <ul><li>Query is sent to all the hosts</li></ul> | <ul><li>Earlier query was sent on 224.0.0.1</li></ul> <ul><li>if host-1 is member of multicast-group-1, host-2 is member of group-2, then query for that specific group is sent to particular host</li></ul> |
| Source-specific-multicast (v3) | | | <ul><li>Router can select multicast server from where he want to recieve multicast traffic</li></ul> <ul><li>This happens when 2 or more servers on internet are serving same multicast group</li></ul> |
