## Policy & Route based
> Underlying IPsec functionality is essentially the same in terms of traffic being encrypted.

### Policy-Based VPN
- Policy is defined (Eg: based on source IP, destination IP, application, and respective to- and from-zones).
- Traffic satisfying particular policy is passed thru VPN tunnel.
- Proxy IDs are derived from the firewall policy.

### Route-Based VPN
- These uses a Virtual Interface(called secure tunnel interface (st0 interface)).
- All traffic routed into the interface will be sent into a VPN.
- Traffic to be sent into st0 is decided on routing, hence name route-based VPN.
