package servlets;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
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
import objects.StandDAO;
import objects.TimeStats;
import org.json.simple.JSONObject;

import com.fasterxml.jackson.databind.ObjectMapper;
/**
 * Servlet implementation class StatsServlet
 */
@WebServlet("/StatsServlet")
public class StatsServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	@EJB
	StandDAO eao;


	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		HttpSession s = request.getSession(false);
		
		if(s == null || s.getAttribute("LoggetInn") == null) {
			response.sendRedirect("login"+"?requiresLogin");
			return;
		}

			s = request.getSession(true);
			
			List<Stand> all = eao.getAllStands();
			for(int i=0;i<all.size();i++) {
			ArrayList<TimeStats> set = all.get(i).getHistorikk();
			set.sort((x1,x2)->x1.compareTo(x2));
			ArrayList<Long> xCoordinates = new ArrayList<Long>();
			ArrayList<Integer> yCoordinates = new ArrayList<Integer>();
			Iterator<TimeStats> iter = set.iterator();
			while(iter.hasNext()){
				
				TimeStats  ts = (TimeStats) iter.next();
				
				xCoordinates.add(ts.getTime().getTime());
				yCoordinates.add(ts.getScore());
				
			}
			request.setAttribute("x"+i, xCoordinates);
			request.setAttribute("y"+i, yCoordinates);
			}
		request.getRequestDispatcher("WEB-INF/Stats.jsp").forward(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
