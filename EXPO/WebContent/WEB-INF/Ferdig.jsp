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
<title>Vote succesfull</title>
</head>
<body>
<div class="topnav">
<input type="text" placeholder="Søk etter Stand">
</div>


<div class="dropdown">
  <button class="dropbtn">Meny</button>
  <div class="dropdown-content">
    <a href="StatsServlet">Statistikk</a>
    <a href="StandServlet">Stand liste</a>
  </div>
</div>

<div class="container">
Din stemme har blitt registrert
<br>
stand: ${stand.id}
<br>
stemme: ${nyVote}
<br>
</div>
</body>

</html>