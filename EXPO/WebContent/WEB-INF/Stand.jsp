<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
<link href="CSS/stylesheet.css" rel="stylesheet" type="text/css">
<meta charset="ISO-8859-1">
<title>Stand "${nr}"</title>
</head>
<body>
<p>stand "${nr}"</p>
<p>scoere "${stand.score}"<p/>
<h1>hei, er dette fint nå?</h1>
<h2>
<div id="wrapper">
<input type="radio" id="star1" name="star" />
<label for="star1"></label>
<input type="radio" id="star2" name="star" />
<label for="star2"></label>
<input type="radio" id="star3" name="star" checked="checked"/>
<label for="star3"></label>
<input type="radio" id="star4" name="star" />
<label for="star4"></label>
<input type="radio" id="star5" name="star" />
<label for="star5"></label>
</div>
</h2>

</body>
</html>