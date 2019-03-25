package servlets;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

//import org.apache.openejb.server.httpd.HttpSession;

/**
 * Servlet implementation class LoggInnServletv2
 */
@WebServlet("/login")
public class LoggInnServletv2 extends HttpServlet {
	private static final long serialVersionUID = 1L;
  

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String loginMessage = "";
		
		if (request.getParameter("feilInnlogging") != null) {
			loginMessage = "Feil passord, prøv igjen";
		} else if(request.getParameter("requiresLogin") != null){
			loginMessage = "Du må skrive inn passord";
		}
		
		request.setAttribute("loginMessage", loginMessage);
		request.getRequestDispatcher("WEB-INF/LoggInn.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String pass = request.getParameter("passord");
		
		if(pass.equals("test")) {
			HttpSession session = request.getSession(false);
			if (session != null) {
				session.invalidate();
			}
			session = request.getSession(true);
			session.setMaxInactiveInterval(60);
			session.setAttribute("test", "test");
			
			response.sendRedirect("StatsServlet"); // godkjent innlogging
		} else {
			response.sendRedirect("login" + "?feilInnlogging");
		}
	}

}