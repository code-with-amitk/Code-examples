**Google AdWords CTR**

### [Google Adwords CTR](https://sre.google/workbook/non-abstract-design/)
- Google Adwords service displays text advertisements on Google Web Search.
- 1 adv can have _multiple search terms_ which user can add to adv, on every search item this adv will be shown.
- CTR(Click thru rate) = (number of times adv clicked / number of times adv shown)

**Online Coaching Center**
```c
        ---- Dashboard (1 day data) ----
Campaign(Search Terms)        CTR
 Best Maths classes           4/5
 Best Coaching center         9/18
```

## Requirements
### Functional
- _1._ Display CTR for each adv on dashboard
- _2._ Dashboard data requirements.
  - Dashboard should load quickly. (99.9% 0f dashboard queries completes in < 1 sec)
  - Data on dashboard should be recent. (99.9% of the time, the CTR data displayed is less than 5 minutes old)

### Non-Functional
#### 1. CTR(Click thru rate) = (number of times adv clicked / number of times adv shown)
- Matrix to tell Advertisers how well their advertisement is performing.
