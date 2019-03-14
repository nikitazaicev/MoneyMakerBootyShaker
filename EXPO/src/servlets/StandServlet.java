package servlets;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

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
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		String nr = request.getParameter("nr");

		if (nr == null || !nr.matches("[0-9]+") || nr.length() > 3) {
			request.getRequestDispatcher("WEB-INF/Fail.jsp").forward(request, response);
		} else {

			HttpSession session = request.getSession(false);

			if (session == null) {
				session = request.getSession(true);
				
			}

			Map<String, Integer> votes = new HashMap<String, Integer>();
			votes =  (Map<String, Integer>) session.getAttribute("votes");
			if(votes==null) {
				votes = new HashMap<String, Integer>();
				session.setAttribute("votes", votes);
			}
		
			
			Stand stand = eao.getStand(nr);
			
			session.setAttribute("stand", stand);
			
			request.getRequestDispatcher("WEB-INF/Stand.jsp").forward(request, response);
			
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		HttpSession session = request.getSession(false);

		if (session == null) {
			
			request.getRequestDispatcher("WEB-INF/Fail.jsp").forward(request, response);

		} else {

			Stand stand = (Stand) session.getAttribute("stand");
			Map<String, Integer> votes = new HashMap<String, Integer>();
			String nr = stand.getId();
			String id = request.getParameter("nr");
			
			if(!request.getParameter("nr").equals(nr)) {
				String feil = "Klarte ikke � registrere stemmen, try again. "
						+ "Grunnen er at du gikk inn p� en annen stand uten � stemme ferdig p� denne";
				session.setAttribute("feil", feil);
				response.sendRedirect("http://localhost:14193/Prosjekt/StandServlet?nr="+id);
				return;
			}
			
			votes =  (Map<String, Integer>) session.getAttribute("votes");
			if(!votes.containsKey(nr)) {
				votes.put(nr, 0);
			}
			String StringNyVote = (String) request.getParameter("nyVote");
			int nyVote = 0;

			if (StringNyVote != null && !StringNyVote.equals("0")) {
				nyVote = Integer.parseInt(StringNyVote);
				TimeStats ts = stand.reVote(votes.get(nr),nyVote);
				session.setAttribute("nyVote", nyVote);
				eao.update(ts);
				eao.update(stand);
				votes.put(nr, nyVote);
			}
		}
		session.removeAttribute("feil");
		request.getRequestDispatcher("WEB-INF/Ferdig.jsp").forward(request, response);
	}

}
