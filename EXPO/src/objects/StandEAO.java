package objects;

import java.util.ArrayList;
import java.util.Set;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import javax.persistence.PersistenceContext;


@Stateless
public class StandEAO {

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
}
