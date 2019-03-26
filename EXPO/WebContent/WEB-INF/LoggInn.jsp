<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
	<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<!-- Fra https://purecss.io/ -->
<!-- <link rel="stylesheet" -->
<!-- 	href="https://unpkg.com/purecss@1.0.0/build/pure-min.css"> -->
<link href="css/LoggInn.css" rel="stylesheet" type="text/css">
<title>Logg inn</title>
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

	<h2 id="overskrift">Logg inn</h2>
	<font color="red" id="melding">${loginMessage}</font>
	<form action="login" method="post" class="pure-form pure-form-aligned" id="form">
			<div class="pure-control-group" id="div1">
<!-- 				<label for="passord">Passord:</label>  -->
				<input type="password" name="passord" placeholder="Passord"/>
			</div>
			<div class="pure-controls" id="knapp">
				<button class="small green button">Logg Inn</button>
			</div>
	</form>
	
</div>

</body>
</html>