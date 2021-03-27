# Basic sql Syntax: 
---------------------



## What Can SQL do? 
- can create stored procedures in a database, create views, can set permission, procedures & views
RDBMS - Relational Database Management System ( basis of SQL, is stored in database objects called tables) 

- SQL keywords are not case sensitive. 

## Some most important SQL Commands - 
- select ( extracts data from database) 
- update(updates data in database) 
- delete( deletes data from a database) 
- insert into ( insert new data into a database) 
- create database  ( creates a new database ) 
- alter database ( modifies a database ) 
- create table ( creates a new table ) 
- alter table ( modifies a table ) 
- drop table ( deletes a table ) 
- create an index( create an index(search key) ) 
- drop index  ( deletes an index ) 

## Basic Queries
```sql
    show databases;
    use database_name;
    show tables;
    show columns from table_name;
    select * from table_name; 
    -- fully qualified name:
    select table_name.column_name from table_name; 

    -- create table
    create table table_name(
        column_name data_type,
        column_name2 data_type

        primary key(column_name)

    );

```
## SQL constraints
    - not null, unique, primary key, default, check, auto increment

## SELECT keyword - 
```sql 
    select column1, column2, ... 
    from table_name; 
```
```sql
-- SELECT DISTINCT Statement -  ( used to return only distinct different values ) 
    select distinct column1, column2, ...
    from table_name; 
```
```sql 
    select count(distinct country) from customers; 
    or, select count(*) as distinct_countries from ( select distinct country from customers) 
```
```sql 
-- WHERE Clause- 
    select column1, column2, ..
    from table_name
    where condition;     /*<> not equal, <= less equal than, between, like , in */
``` 
```sql
-- SQL AND, OR, NOT Operators- 
    select column1, column2, .. 
    from table_name
    where condition1 and condition2 or  condition 3 or not condition  .. ; 
``` 
```sql 
-- SQL Order By Keyword - ( is used to sort the result-set in ascending or descending ) 
    select column1, column2, .. 
    from table_name
    order by column1, column2, ... asc | desc; 
```

### SQL INSERT INTO Statement - 
```sql 
    insert into table_name( column1, column2, column3, ... )   /*if all data inserted sequencially then no need of columns, few column can be inserted*/
    values ( value1, value2, value 3, ... ) ; 
```

### IS NULL / IS NOT NULL Syntax - 
```sql 
    select column_names
    from table_name
    where column_name is null; 
``` 

### Update Statement - 
```sql
    update table_name
    set column1=value, column2 = value
    where condition; 
    /* be careful to provide the where caluse, if it is not provided then all columns will be updated */ 
```

### DELETE Statement - 
```sql
    delete from table_name
    where condition; 
    /*if where clause omitted then all records in the table will be deleted */ 
```

### LIMIT Syntax - (mysql)
```sql
    select column_names
    from table_name
    where condition
    limit number; 
    -- limit starting_position_number, number_of_records_we_want
    -- limit 3,4
    -- pickup 4 records starting from 3rd position

``` 

### MIN() / MAX()/ COUNT()/ AVG()/ SUM() Syntax - 
```sql
    select min(column_name)
    from table_name
    where condition; 
``` 
### LIKE/ NOT LIKE Syntax - 
```sql
    select column1, column2, .. 
    from table_name
    where columnN like pattern; 

/*  
a% (value starts with a)
_r ( any value that have r in 2nd position ) 
a_%_% ( start with a and at least 3 character long) 
that % and _ are called Wildcard
[bsp]% (any one of b, s or p as start of any string ) 
[a-c] ( a to c ) 
[!bsp] ( anything except  b,s or p ) 
*/ 
```

### SQL IN Operator - 
```sql 
    select column_names
    from table_name
    where column_name in ( value1, value2, value3, ... ) ; 
or
    select column_names
    from table_name
    where column_names in ( select statement ) ; 
    --- not in 
```

### SQL BETWEEN - 
```sql
    select column_name(s)
    from table_name
    where column_name between value1 and value2;
```
### SQL Aliases - 

### SQL JOINS - 
```sql
    select table1.colum1, table1.column2, table2.column1, table2.column2
    from table1, table2
    where table1.column1 = table2.column1

    select t1.colum1, t1.column2, t2.column1, t2.column2
    from table1 as t1, table2 as t2
    where t1.column1 = t2.column1

    -- inner join (same as join, return if match between tables)
    select column_name(s)
    from table table1 inner join table2 
    on table1.column_name = table2.column_name

    -- left outer join

    -- right outer join



```

### SQL UNION - 
```sql
    -- 'union` or 'union all'
    -- combine result-sets of two or more select statement
    -- multiple database into a single dataset and remove duplicates(union), does not remove duplicates(union all)

    select column_name(s) from table1
    union -- (or) union all
    select column_name(s) from table2
```

### SQL GROUP BY - 
```sql
    SELECT column_name(s)
    FROM table_name
    WHERE condition
    GROUP BY column_name(s)
    ORDER BY column_name(s);

    SELECT Shippers.ShipperName,COUNT(Orders.OrderID) AS NumberOfOrders FROM Orders
    LEFT JOIN Shippers ON Orders.ShipperID = Shippers.ShipperID
    GROUP BY ShipperName;

```
### SQL HAVING - 
The HAVING clause was added to SQL because the WHERE keyword could not be used with aggregate functions.
```sql
    SELECT Employees.LastName, COUNT(Orders.OrderID) AS NumberOfOrders
    FROM (Orders
    INNER JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID)
    WHERE LastName = 'Davolio' OR LastName = 'Fuller'
    GROUP BY LastName
    HAVING COUNT(Orders.OrderID) > 10;
```

### SQL EXISTS  - 
```sql
    SELECT SupplierName
    FROM Suppliers
    WHERE EXISTS (SELECT ProductName FROM Products WHERE Products.SupplierID = Suppliers.supplierID AND Price = 22);
```
### SQL ANY / ALL - 
```sql
    SELECT ProductName
    FROM Products
    WHERE ProductID = ALL (SELECT ProductID FROM OrderDetails WHERE Quantity = 10);
```

### SQL SELECT INTO - 

### SQL Stored Procedures - 
```sql 
    create procedure procedure_name
    as
    sql_statement
    go; 

/*execute procedure-*/    exec procedure_name; 
/*parameterize*/
    create procedure selectAllCustomers @city nvarchar(30), @PostalCode nvarchar(10)
    as
    select * from customers where city = @city and postalcode = @postalcode
    go; 

exec selectallcustomers city="london" , postalcode = "wal 1dp"; 
```
    
### SQL Comments -  
```sql 
    Single line comments  --comment
    multi line comments /* comment*/ 
```


## rename table: 
```sql
rename table from_table_name to to_table_name;
```

## add column
```sql 
alter table table_name add column_name decimal(10) default 0 null;  
-- #decimal type& default value 0 & accept null 
``` 
## delete column
```sql
    alter table table_name 
    drop column column_name;
```
## rename column
```sql
    alter table table_name
    change column_name_from column_name_to data_type;
```
## rename table 
```sql
    rename table from_table_name to to_table_name; 
```
## delete table
```sql
    drop table table_name; 
```

## custom columns
```sql
    select concat(col_name1, ',', col_name2) from table_name;
    select concat(col_name1, ',', col_name2) as new_column_name from table_name;
    select col1, col2, sal+500 as sal_with_incre from table_name; 
```

## Function
```sql
    select column1, upper(column2) as upper_column2 from table_name; 
    select sqrt(salary) from table_name;
    select avg(salary) from table_name; 
    select sum(salary) from table_name; 
    select min(salary) from table_name; 
```

## Subquery
```sql
    -- find those whoose salary is greater than average
    select avg(salary) from employees;

    select * from employees
    where salary > 3100;

    -- we can do it easily by subquery
    select * from employees
    where salary > (select avg(salary) from employees); 
```

## permission
CREATE USER 'billing'@'119.148.4.18' IDENTIFIED BY 'root';

grant all privileges on *.* to 'billing'@'119.148.4.18';