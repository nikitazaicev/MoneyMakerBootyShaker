package objects;

import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.PersistenceContext;


@Stateless
public class StandEAO {

	@PersistenceContext(name = "expo")
    private EntityManager em;
	
	public Stand getStand(String id) {
		return em.find(Stand.class, id);
	}

	public void update(Stand stand) { 
		em.merge(stand);
	}

	public void update(TimeStats ts) {
		em.persist(ts);
		
	}
	public TimeStats getStats(String id) {
		return em.find(TimeStats.class, id);
	}
	
}
