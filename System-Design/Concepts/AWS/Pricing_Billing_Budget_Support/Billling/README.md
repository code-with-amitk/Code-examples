**Billing**
- [Billing DashBoard](#bd)
- [Consolidated Billing](#cb)
  - [Benefits/Advantages](#b)


<a name=bd></a>
## Billing & Cost Management dashboard
- This is used to check/pay your AWS bill, monitor your usage, and analyze and control your costs.
- Compare your current month-to-date balance with the previous month, and get a forecast of the next month based on current usage.
  - View month-to-date spend by service, View Free Tier usage by service, Access Cost Explorer and create budgets, Purchase and manage Savings Plans, Publish AWS Cost and Usage Reports.

<a name=cb></a>
## Consolidated Billing
- For all AWS accounts belonging to 1 organization a consolidated bill can be generated.
- Consolidated billing feature of [AWS Organizations](/System-Design/Concepts/AWS/Security/AWS_Organizations) enables you to receive a single bill for all AWS accounts in your organization.
```c
                  Primary Account
                        |
         ----------------------------------
         |                |               |
     AWS_Account1    AWS_Account2   AWS_Account3
      $20.00            $80.90        $49.99
```

<a name=b></a>
### Benefits/Advantages
- **1. Avail volume pricing, Reserved Instance Discounts:**
  - Combine usage across all accounts in your organization & get discounts and Savings Plans.
  - This solution can result in a lower charge compared to the use of individual standalone accounts.
