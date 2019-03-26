<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
<link rel="stylesheet" href="https://unpkg.com/purecss@1.0.0/build/pure-min.css" 
integrity="sha384-nn4HPE8lTHyVtfCBi5yW9d20FjT8BJwUXyWZT9InLYax14RDjBj46LmSztkmNP9w" crossorigin="anonymous">
<link href="css/stylesheet.css" rel="stylesheet" type="text/css">
<meta charset="ISO-8859-1">
<title>Stand ${stand.id}</title>
</head>
<body>

<div class="topnav">
<input type="text" placeholder="Søk etter Stand">


<div class="dropdown">
  <button class="dropbtn">Meny</button>
  <div class="dropdown-content">
    <a href="StatsServlet">Statistikk</a>
    <a href="StandServlet">Stand liste</a>
  </div>
</div>
</div>

<div class="container">

<p> ${feil}</p>
<br>
You have visited Stand #${param.nr}
<br>
stand ${stand.id}
<br>
score ${stand.score}
<br>

<form method="post" action="StandServlet">
0 is no vote

<input type="radio"  name="nyVote" value="0" checked="checked">0
<br>
<input type="radio"  name="nyVote" value="1" />1
<input type="radio"  name="nyVote" value="2"/>2
<input type="radio"  name="nyVote" value="3" />3
<input type="radio"  name="nyVote" value="4"/>4
<input type="radio"  name="nyVote" value="5"/>5
<input type="hidden" name="nr" value="${param.nr}">
<br>
<input type="submit" name="nr" value="Gi stemme">
</form>
<br>
</div>

</body>
</html>