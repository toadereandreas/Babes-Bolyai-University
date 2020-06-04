In this lab you will have to develop a server-side web application in PHP. The web application has to manipulate a Mysql database with 1 to 3 tables and should implement the following base operations on these tables: select, insert, delete, update. Also the web application must use AJAX for getting data asynchronously from the web server and the web application should contain at least 5 web pages (client-side html or server-side php).

For the database, you can use the mysql database on www.scs.ubbcluj.ro. On this myql server you have an account, a password and a database, all identical to your username and password on the SCS network.

Documentation can be found at:
1) http://www.cs.ubbcluj.ro/~forest/wp
2) http://www.php.net/manual/en
3) http://www.w3schools.com/php
4) http://www.w3schools.com/ajax

Write a web application which implements a guest book. 
A guest book record is identified by: author (email), title, comment, date. 
A client of the application should be able to add new entries in the guest book, 
but only the administrator of the site can delete or modify them. 
Also the administrator should be able to browse the list of guest book entries based on 
(grouped by) their author and title using AJAX. Guest book browsing should be 
paged - entries are displayed on pages with maximum 4 entries on a page (you should be able to go to the previous and the next page).
