<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE HTML>
<html>
<head>

<script>
window.onload = function () {
	
	var x0 = ${x0};
	var y0 = ${y0};
	var x1 = ${x1};
	var y1 = ${y1};
	var x2 = ${x2};
	var y2 = ${y2};
	var myData0 =[];
	var myData1 =[];
	var myData2 =[];
	var i;
	for (i = 0; i<x0.length;i++){
	myData0.push({
		x: x0[i],
		y: y0[i]
	});}
	var i1;
	for (i1 = 0; i1<x1.length;i1++){
	myData1.push({
			x: x1[i1],
			y: y1[i1]
	});}
	var i2;
	for (i2 = 0; i2<x2.length;i2++){
	myData2.push({
		x: x2[i2],
		y: y2[i2]
	});}
	
	var chart = new CanvasJS.Chart("chartContainer", {
		animationEnabled: true,
		theme: "light2",
		title:{
			text: "Statistic"
		},
		axisX:{
			valueFormatString: "DD MMM",
			crosshair: {
				enabled: true,
				snapToDataPoint: true
			}
		},
		axisY: {
			title: "Score",
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
			name: "Stand 1",
			color: "#F08080",
			yValueFormatString: "#0.## ",
			dataPoints: myData0
		},
		{
			type: "line",
			showInLegend: true,
			name: "Stand 2",
			color: "#F08030",
			yValueFormatString: "#0.## ",
			dataPoints: myData1
		},
		{
			type: "line",
			showInLegend: true,
			name: "Stand 3",
			color: "#F08000",
			yValueFormatString: "#0.## ",
			dataPoints: myData2
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