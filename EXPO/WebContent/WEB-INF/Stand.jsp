<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
<link href="CSS/stylesheet1.css" rel="stylesheet" type="text/css">
<meta charset="ISO-8859-1">
<title>Stand "${nr}"</title>
</head>
<body>
<c:set var="stand" value="stand${nr}" />
stand ${sessionScope[stand].id}
<br>
score ${sessionScope[stand].score}
<br>
<form method="post" action="StandServlet">
<input type="radio"  name="nyVote" value="0" checked="checked"/>
<input type="radio"  name="nyVote" value="1" />
<input type="radio"  name="nyVote" value="2"/>
<input type="radio"  name="nyVote" value="3" />
<input type="radio"  name="nyVote" value="4"/>
<input type="radio"  name="nyVote" value="5"/>
<input type="submit" name="nyVote">
</form>
<br>

<!-- 
<div id="wrapper">
<input type="radio" id="star1" name="star" />
<label for="star1">stjerne1</label>
<input type="radio" id="star2" name="star" />
<label for="star2">stjern2</label>
<input type="radio" id="star3" name="star" checked="checked"/>
<label for="star3">stjern</label>
<input type="radio" id="star4" name="star" />
<label for="star4">star</label>
<input type="radio" id="star5" name="star" />
<label for="star5">patrick</label>
</div>
 -->

</body>
</html>