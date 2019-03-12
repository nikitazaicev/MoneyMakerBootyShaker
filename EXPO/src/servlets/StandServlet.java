package servlets;

import java.io.IOException;

import javax.ejb.EJB;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.eclipse.persistence.sessions.Session;

import objects.Stand;
import objects.StandEAO;
import objects.TimeStats;

/**
 * Servlet implementation class StandServlet
 */
@WebServlet("/StandServlet")
public class StandServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;
	@EJB
	StandEAO eao;
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String nr = request.getParameter("nr");
		
		if(nr==null||!nr.matches("[0-9]+")||nr.length()>3){
			request.getRequestDispatcher("WEB-INF/Fail.jsp").forward(request, response);
		}else {
		
			HttpSession session = request.getSession(false);
			
			if(session==null) {
					session = request.getSession(true);
				}
			
			Stand stand = eao.getStand(nr);
	
			session.setAttribute("stand", stand);	
		
			request.getRequestDispatcher("WEB-INF/Stand.jsp").forward(request, response);
	
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession session = request.getSession(false);
		
		if(session==null) {
			request.getRequestDispatcher("WEB-INF/Fail.jsp").forward(request, response);
			
			}else {
		
		Stand stand = (Stand) session.getAttribute("stand");	
		String nr = request.getParameter("nr");
		String Svote = (String) session.getAttribute("vote");
		String SnyVote = (String) request.getParameter("nyVote");
		int nyVote = 0;
		
		
		
		if(Svote==null) {//bruker har ikke stemt på denne stenden tidligere
			if(!SnyVote.equals("0")) {
				nyVote = Integer.parseInt(SnyVote);
				TimeStats ts = stand.vote(nyVote);
				session.setAttribute("vote"+nr,nyVote);
				eao.update(ts);
				eao.update(stand);
			}
		}else {
			if(!SnyVote.equals("0")) {
				int vote = Integer.parseInt(Svote);
				TimeStats ts = stand.reVote(vote,nyVote);
				session.removeAttribute("vote"+nr);
				session.setAttribute("vote"+nr,nyVote);
				eao.update(ts);
				eao.update(stand);
			}
		}
		
		request.getRequestDispatcher("WEB-INF/Ferdig.jsp").forward(request, response);	
		}
	}

}
