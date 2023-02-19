Database Design

### Database Design

1. List all objects/Nouns/Entities:
```c
- product
- user
- company
- review
- question
- answer
- report
```

2. Find ERD amongst them:
```c
	   1	 *
user ----- product

		    1     *
company ------- product

		    1      *
product -------- reviews

		    1   		*
survey ---------- questions

		     1		1
question ------- answer
```

3. Create Tables
a. Data Tables
```c
- product
	name, productid(pk), price, exe_size, companyid(fk), category

- user
	name, email, country, job_title, company_revenue, userid(primary-key)

- Company
	name, companyid(pk), no_of_employees, address, estb, 

- Survey
	id, title, number_of_ques, 
	
- Questions
	id(pk), desc, survery-id(fk), type(0:sub, 1:obj)

- answer
	id(pk), ques-id(fk), text, choices

- report
```
b. Relationship tables (should be separate from User,Product tables)
```c
Responder table	//user who has responded to survey=x of product=y
  entryid, userid, survery-id, productid

Response table	//Store responses of user
  userid(pk), surveyid(fk), pro
```
