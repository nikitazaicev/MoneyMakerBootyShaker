package objects;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;


@Stateless
public class StandDAO {

	@PersistenceContext(name = "expo")
    private EntityManager em;
	
//	public StandEAO() {
//		EntityManagerFactory emf = Persistence.createEntityManagerFactory("EXPO");
//		em = emf.createEntityManager();
//	}
	
	public Stand getStand(String id) {
		return em.find(Stand.class, id);
	}

	public void update(Stand stand) { 
		em.merge(stand);
	}
/**
 * legger en NY tidspunkt i databasen 
 * @param ts tidspunk endringen var gjort av type TimeStats
 */
	public void update(TimeStats ts) {
		em.persist(ts);
		
	}
	/**
	 * 
	 * @return all statistikk over en stand med gitt id
	 */
	public ArrayList<TimeStats> standInfo(String id) {
		Stand stand = getStand(id);
		
		return stand.getHistorikk();
	}
	public List<Stand> getAllStands(){
		Query q = em.createQuery("SELECT s FROM Stand s", Stand.class);
		return q.getResultList();	
	}
	
	public List<Stand> getTopStands(int antall){
		Query q = em.createQuery("SELECT s FROM Stand s", Stand.class);
		List<Stand> stands = q.getResultList() ;
		stands.sort((x1,x2)->x1.getScore()-x2.getScore());	
		List<Stand> top = stands.subList(0, antall);
		return top;
	}


}
