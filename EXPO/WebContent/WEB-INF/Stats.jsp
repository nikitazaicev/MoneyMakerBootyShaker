<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE HTML>
<html>
<head>

<script>
window.onload = function () {
	
	var x = ${xCoordinates};
	var y = ${yCoordinates};
	var myData =[];
	var i;
	for (i = 0; i<x.length;i++){
	myData.push({
		x: x[i],
		y: y[i]
	});
	}
	
	var chart = new CanvasJS.Chart("chartContainer", {
		animationEnabled: true,
		theme: "light2",
		title:{
			text: "Site Traffic"
		},
		axisX:{
			valueFormatString: "DD MMM",
			crosshair: {
				enabled: true,
				snapToDataPoint: true
			}
		},
		axisY: {
			title: "Number of Visits",
			crosshair: {
				enabled: true
			}
		},
		toolTip:{
			shared:true
		},  
		legend:{
			cursor:"pointer",
			verticalAlign: "bottom",
			horizontalAlign: "left",
			dockInsidePlotArea: true,
			itemclick: toogleDataSeries
		},
		data: [{
			type: "line",
			showInLegend: true,
			name: "Total Visit",
			markerType: "square",
			xValueFormatString: "DD MMM, YYYY",
			color: "#F08080",
			dataPoints: myData
		}]
	});
	chart.render();

	function toogleDataSeries(e){
		if (typeof(e.dataSeries.visible) === "undefined" || e.dataSeries.visible) {
			e.dataSeries.visible = false;
		} else{
			e.dataSeries.visible = true;
		}
		chart.render();
	}

	}
</script>

</head>
<body>
<div id="chartContainer" style="height: 300px; width: 100%;"></div>
<script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
</body>
</html>