<%@ page import="Model.User" %>
<%@ page import="java.util.Set" %>
<%@ page import="java.util.Enumeration" %><%--
  Created by IntelliJ IDEA.
  User: Andreas
  Date: 5/19/2020
  Time: 5:24 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Insert title here</title>
</head>
<body>
<%
    User user = (User) session.getAttribute("user");
    if (user.getPlayerNo()==0) {
        boolean ok=true;
        out.println("<p style='text-align: center; font-size: 30px; font-weight: bold;'>Welcome " + user.getUsername()+"</p>");

    }
    else if(user.getPlayerNo()==1)
    {
        out.println("<p style='text-align: center; font-size: 30px; font-weight: bold;'>Start Game</p>");

    }
    else
    {
        out.println("<p style='text-align: center; font-size: 30px; font-weight: bold;'>Sorry " + user.getUsername() + " there are already " + user.getPlayerNo() + " players playing this game</p>");


    }
%>
<form action="StartGameServlet" method="get">
    <input type="submit" value="Try to Start Game" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>
<form action="LogOutServlet" method="get">
    <input type="submit" value="Logout" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>
</body>
</html>