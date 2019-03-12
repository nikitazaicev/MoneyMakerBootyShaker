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
		
		if(nr==null||!nr.matches("[0-1000]")) {
			request.getRequestDispatcher("WEB-INF/Fail.jsp").forward(request, response);
		}else {
		
		Stand stand = eao.getStand(nr);
	
	    request.setAttribute("stand", stand);
		
		request.getRequestDispatcher("WEB-INF/Stand.jsp").forward(request, response);
	
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		HttpSession session = request.getSession(false);
	
		if(session==null) {
				session = request.getSession(true);
			}
		
		String score = (String)session.getAttribute("Vote");
		String nyScore = (String)session.getAttribute("nyVote");
		
		int vote = Integer.parseInt(score);
		int nyVote = Integer.parseInt(nyScore);
		
		Stand stand = (Stand) request.getAttribute("stand");
		
		if(vote==0) {
			stand.vote(nyVote);
		}else {
			stand.reVote(vote,nyVote);
		}
		request.getRequestDispatcher("WEB-INF/Stand.jsp").forward(request, response);	
	}

}
