<%@ page import="Model.User" %><%--
  Created by IntelliJ IDEA.
  User: Andreas
  Date: 5/19/2020
  Time: 7:04 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Won the game</title>
</head>
<body>
<%
    User user = (User) session.getAttribute("user");
    out.println(user.getUsername()+ " you are number one !");
%>
</body>
<form action="LogOutServlet" method="get">
    <input type="submit" value="Logout" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>
</html>
