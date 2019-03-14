package graph;

import java.util.Iterator;
import java.util.Set;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.HashSet;

import javax.ejb.EJB;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.xy.XYSeries;
import org.jfree.data.xy.XYSeriesCollection;
import org.jfree.ui.ApplicationFrame;
import org.jfree.ui.RefineryUtilities;

import objects.Stand;
import objects.StandEAO;
import objects.TimeStats;

public class XYSeriesDemo extends ApplicationFrame {

	/**
	 * A demonstration application showing an XY series containing a null value.
	 *
	 * @param title the frame title.
	 */

	public XYSeriesDemo(final String title) {

		super(title);

		final XYSeriesCollection data = new XYSeriesCollection();
		XYSeries series = new XYSeries("Stand");
		StandEAO eao = new StandEAO();
		Stand stand = eao.getStand("1");
		Set<TimeStats> statistikk = stand.getHistorikk();
		series = new XYSeries("Stand");
		
		Iterator<TimeStats> iter = statistikk.iterator();
		while (iter.hasNext()) {
			TimeStats ts = iter.next();
			series.add(ts.getTime().getTime(), ts.getScore());
		}
		
		data.addSeries(series);

		final JFreeChart chart = ChartFactory.createXYLineChart("XY Series Demo", "X", "Y", data,
				PlotOrientation.VERTICAL, true, true, false);
		final ChartPanel chartPanel = new ChartPanel(chart);
		chartPanel.setPreferredSize(new java.awt.Dimension(500, 270));
		setContentPane(chartPanel);

	}

// ****************************************************************************
// * JFREECHART DEVELOPER GUIDE                                               *
// * The JFreeChart Developer Guide, written by David Gilbert, is available   *
// * to purchase from Object Refinery Limited:                                *
// *                                                                          *
// * http://www.object-refinery.com/jfreechart/guide.html                     *
// *                                                                          *
// * Sales are used to provide funding for the JFreeChart project - please    * 
// * support us so that we can continue developing free software.             *
// ****************************************************************************

	/**
	 * Starting point for the demonstration application.
	 *
	 * @param args ignored.
	 */
	public static void main(final String[] args) {

		final XYSeriesDemo demo = new XYSeriesDemo("XY Series Demo");
		demo.pack();
		RefineryUtilities.centerFrameOnScreen(demo);
		demo.setVisible(true);

	}

}