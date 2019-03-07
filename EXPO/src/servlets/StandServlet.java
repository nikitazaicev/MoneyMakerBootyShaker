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
		
		String nr = request.getHeader("nr");
		
		HttpSession session = request.getSession(false);
	
		
		if(session==null) {
				session = request.getSession(true);
			}
		session.setAttribute("vote",0);
		
		int vote = (int) session.getAttribute("vote");
		
		String id = "1";
		
		Stand stand = eao.getStand(id);
		
		
		
		if(stand!=null) {
	session.setAttribute("Stand", stand);
		}
		
		request.getRequestDispatcher("WEB-INF/Stand.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
	}

}
