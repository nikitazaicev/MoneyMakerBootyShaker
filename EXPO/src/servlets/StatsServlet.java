package servlets;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import objects.Stand;
import objects.StandEAO;
import objects.TimeStats;
import org.json.simple.JSONObject;
/**
 * Servlet implementation class StatsServlet
 */
@WebServlet("/StatsServlet")
public class StatsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	@EJB
	StandEAO eao;


	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HttpSession s = request.getSession(false);

		if (s != null) {
			s.invalidate();
		}
			s = request.getSession(true);
			
			Stand stand = eao.getStand("1");
			ArrayList<TimeStats> set = stand.getHistorikk();
			set.sort((x1,x2)->x1.compareTo(x2));
			
			JSONObject obj = new JSONObject();
			obj.put(stand, stand.getHistorikk());
			
			ArrayList<Long> xCoordinates = new ArrayList<Long>();
			ArrayList<Integer> yCoordinates = new ArrayList<Integer>();
			Iterator<TimeStats> iter = set.iterator();
			while(iter.hasNext()){
				
				TimeStats  ts = (TimeStats) iter.next();
				
				xCoordinates.add(ts.getTime().getTime());
				yCoordinates.add(ts.getScore());
				
			}
			
			request.setAttribute("xCoordinates", xCoordinates);
			request.setAttribute("yCoordinates", yCoordinates);	
		request.getRequestDispatcher("WEB-INF/Stats.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
