**Shield**
- [Levels of Protection](#lp)
- [WAF vs Sheild](/System-Design/Concepts/AWS/Security/WAF/README.md#vs)

## Shield
Service to protect against [DDoS(Distributed DOS)](/Networking/OSI-Layers/Layer-3/Security/Security_Vulnerabilities/DOS/).

<a name=lp></a>
### Levels of Protection
#### 1. Standard
- It automatically protects all AWS customers at no cost.
- This uses variety of analysis techniques to detect malicious traffic in real time and automatically mitigates it.

#### 2. Advanced (Paid Service)
- Provides detailed attack diagnostics, detects and mitigate sophisticated DDoS attacks
- It integrates with other services eg(Amazon CloudFront, Route 53, Elastic Load Balancing).
- We can integrate AWS Shield with AWS WAF by writing custom rules to mitigate complex DDoS attacks.
