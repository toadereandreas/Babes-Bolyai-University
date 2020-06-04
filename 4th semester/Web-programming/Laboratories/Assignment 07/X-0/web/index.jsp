<%--
  Created by IntelliJ IDEA.
  User: Andreas
  Date: 5/19/2020
  Time: 5:33 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Login</title>
</head>
<body>
<br>
<form action="LoginServlet" method="post">
  Enter username : <input type="text" name="username" style="width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; box-sizing: border-box;"> <BR>
  Enter password : <input type="password" name="password" style = "width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; box-sizing: border-box;"> <BR>
  <input type="submit" value="Login" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>
</body>
</html>