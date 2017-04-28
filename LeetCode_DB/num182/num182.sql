# FileName: num182.py
# Author: lxw
# Date: 2017-04-17


/*
Num 182: Duplicate Emails
sources: https://leetcode.com/problems/duplicate-emails/#/description

Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+
Note: All emails are in lowercase.
*/


# Write your MySQL query statement below
#select distinct Email from Person;
select Email from Person group by Email having count(*) > 1;
