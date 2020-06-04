<%@ page import="Model.User" %><%--
  Created by IntelliJ IDEA.
  User: Andreas
  Date: 5/19/2020
  Time: 5:04 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>X0 game</title>
</head>
<body>
<%
    String board = (String) session.getAttribute("Board");
    User user = (User) session.getAttribute("user");
    int activePlayer = (Integer) session.getAttribute("activePlayer");
    out.println("<table border=1 frame=void rules=rows style='margin-left:auto; margin-right:auto; table-layout: fixed; width: 25%; height: 50%; font-size: 100px; border: 1px solid black; '>");
    for(int i=0;i<3;i++) {
        out.println("<tr>");
        for (int j = 0; j < 3; j++) {
            out.println("<td style='border: 1px solid black; text-align: center; vertical-align: middle;'>");
            if( board.charAt(i * 3 + j) == '-')
                out.println(' ');
            else
                out.println(board.charAt(i * 3 + j));
            out.println("</td>");
        }
        out.println("</tr>");
    }
    out.println("</table>");
    out.println("<br>");
    if( activePlayer == user.getPlayerNo())
    {
        out.println("<p style='text-align: center; font-size: 30px; font-weight: bold;' >Your turn</p>");
    }
    else
    {
        out.println("<p style='text-align: center; font-size: 30px; font-weight: bold;'>Your opponent's turn: refresh</p>");
    }
%>

<form action="MoveServlet" method="post" onsubmit="return validate();">
    Enter column : <input id="a" type="text" name="column" style="width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; box-sizing: border-box;"> <BR>
    Enter row : <input id="b" type="text" name="row" style="width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; box-sizing: border-box;"> <BR>
    <input type="submit" value="Move/Refresh" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>

<script type="text/javascript">
    function validate()
    {
        var c = document.getElementById("a").value;
        var d = document.getElementById("b").value;
        var valid = true;
        if(isNaN(c) || isNaN(d)) {
            alert("Enter a number");
            valid = false;
        }
        return valid;
    };
</script>

<form action="LogOutServlet" method="get">
    <input type="submit" value="Logout" style="background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0; border: none; cursor: pointer; width: 100%;"/>
</form>
</body>
</html>
